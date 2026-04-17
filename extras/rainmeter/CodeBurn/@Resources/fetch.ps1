$ErrorActionPreference = 'SilentlyContinue'
$env:PATH = "$env:APPDATA\npm;$env:PATH"

$dir      = Split-Path -Parent $MyInvocation.MyCommand.Path
$jsonFile = "$env:TEMP\codeburn_rm_export.json"
$dataFile = "$dir\data.txt"

function FmtCost($v) { [math]::Round([double]$v, 2).ToString('0.00') }

$utf8 = New-Object System.Text.UTF8Encoding $false

function WriteDefault {
    $blank = @(
        'TODAY_COST=0.00', 'TODAY_CALLS=0',
        'WEEK_COST=0.00',  'WEEK_CALLS=0',
        'MONTH_COST=0.00', 'MONTH_CALLS=0',
        'MODEL1_NAME=--',  'MODEL1_COST=0.00', 'MODEL1_CALLS=0',
        'MODEL2_NAME=--',  'MODEL2_COST=0.00', 'MODEL2_CALLS=0',
        'MODEL3_NAME=--',  'MODEL3_COST=0.00', 'MODEL3_CALLS=0',
        'ACT1_NAME=--',    'ACT1_COST=0.00',   'ACT1_TURNS=0',
        'ACT2_NAME=--',    'ACT2_COST=0.00',   'ACT2_TURNS=0',
        'ACT3_NAME=--',    'ACT3_COST=0.00',   'ACT3_TURNS=0',
        'MODEL1_PCT=0',    'MODEL2_PCT=0',      'MODEL3_PCT=0',
        'ACT1_PCT=0',      'ACT2_PCT=0',        'ACT3_PCT=0',
        'MODEL1_SEG0_H=1', 'MODEL1_SEG1_H=1', 'MODEL1_SEG2_H=1', 'MODEL1_SEG3_H=1', 'MODEL1_SEG4_H=1',
        'MODEL1_SEG5_H=1', 'MODEL1_SEG6_H=1', 'MODEL1_SEG7_H=1', 'MODEL1_SEG8_H=1', 'MODEL1_SEG9_H=1',
        'MODEL2_SEG0_H=1', 'MODEL2_SEG1_H=1', 'MODEL2_SEG2_H=1', 'MODEL2_SEG3_H=1', 'MODEL2_SEG4_H=1',
        'MODEL2_SEG5_H=1', 'MODEL2_SEG6_H=1', 'MODEL2_SEG7_H=1', 'MODEL2_SEG8_H=1', 'MODEL2_SEG9_H=1',
        'MODEL3_SEG0_H=1', 'MODEL3_SEG1_H=1', 'MODEL3_SEG2_H=1', 'MODEL3_SEG3_H=1', 'MODEL3_SEG4_H=1',
        'MODEL3_SEG5_H=1', 'MODEL3_SEG6_H=1', 'MODEL3_SEG7_H=1', 'MODEL3_SEG8_H=1', 'MODEL3_SEG9_H=1',
        'CACHE_HIT=100',
        'READ_PER_SESSION=0',
        'EXPENSIVE_MODEL_FLAG=0', 'EXPENSIVE_MODEL_NAME=--', 'EXPENSIVE_MODEL_TKS=0',
        'DISPATCH_FLAG=0',        'DISPATCH_CALLS=0',
        'ONE_SHOT_PCT=100',       'ONE_SHOT_EDIT_TURNS=0',
        'BASH1_NAME=--',  'BASH1_CALLS=0',  'BASH1_PCT=0',
        'BASH2_NAME=--',  'BASH2_CALLS=0',  'BASH2_PCT=0',
        'BASH3_NAME=--',  'BASH3_CALLS=0',  'BASH3_PCT=0',
        'BASH4_NAME=--',  'BASH4_CALLS=0',  'BASH4_PCT=0',
        'BASH5_NAME=--',  'BASH5_CALLS=0',  'BASH5_PCT=0',
        'BASH6_NAME=--',  'BASH6_CALLS=0',  'BASH6_PCT=0',
        'BASH7_NAME=--',  'BASH7_CALLS=0',  'BASH7_PCT=0',
        'BASH8_NAME=--',  'BASH8_CALLS=0',  'BASH8_PCT=0',
        'BASH9_NAME=--',  'BASH9_CALLS=0',  'BASH9_PCT=0',
        'BASH10_NAME=--', 'BASH10_CALLS=0', 'BASH10_PCT=0'
    )
    [System.IO.File]::WriteAllText($dataFile, ($blank -join "`n") + "`n", $utf8)
}

& codeburn export --format json --output $jsonFile 2>$null
if (-not (Test-Path $jsonFile)) { WriteDefault; exit }

$j = Get-Content $jsonFile -Raw | ConvertFrom-Json
if (-not $j) { WriteDefault; exit }

$td = $j.periods.Today
$wk = $j.periods.'7 Days'
$mo = $j.periods.'30 Days'

$lines = @(
    "TODAY_COST=$(FmtCost $td.summary.'Cost (USD)')",
    "TODAY_CALLS=$($td.summary.'API Calls')",
    "WEEK_COST=$(FmtCost $wk.summary.'Cost (USD)')",
    "WEEK_CALLS=$($wk.summary.'API Calls')",
    "MONTH_COST=$(FmtCost $mo.summary.'Cost (USD)')",
    "MONTH_CALLS=$($mo.summary.'API Calls')"
)

$models = @($wk.models | Sort-Object 'Cost (USD)' -Descending | Select-Object -First 3)
for ($i = 0; $i -lt 3; $i++) {
    if ($i -lt $models.Count -and $models[$i]) {
        $lines += "MODEL$($i+1)_NAME=$($models[$i].Model)"
        $lines += "MODEL$($i+1)_COST=$(FmtCost $models[$i].'Cost (USD)')"
        $lines += "MODEL$($i+1)_CALLS=$($models[$i].'API Calls')"
    } else {
        $lines += "MODEL$($i+1)_NAME=--"
        $lines += "MODEL$($i+1)_COST=0.00"
        $lines += "MODEL$($i+1)_CALLS=0"
    }
}

$acts = @($td.activity | Sort-Object 'Cost (USD)' -Descending | Select-Object -First 3)
for ($i = 0; $i -lt 3; $i++) {
    if ($i -lt $acts.Count -and $acts[$i]) {
        $lines += "ACT$($i+1)_NAME=$($acts[$i].Activity)"
        $lines += "ACT$($i+1)_COST=$(FmtCost $acts[$i].'Cost (USD)')"
        $lines += "ACT$($i+1)_TURNS=$($acts[$i].Turns)"
    } else {
        $lines += "ACT$($i+1)_NAME=--"
        $lines += "ACT$($i+1)_COST=0.00"
        $lines += "ACT$($i+1)_TURNS=0"
    }
}

$weekTotal  = [double]($wk.summary.'Cost (USD)')
$todayTotal = [double]($td.summary.'Cost (USD)')

$maxModelCost = if ($models.Count -gt 0 -and $models[0]) { [double]$models[0].'Cost (USD)' } else { 0 }
for ($i = 0; $i -lt 3; $i++) {
    $pct = if ($maxModelCost -gt 0 -and $i -lt $models.Count -and $models[$i]) {
        [math]::Round(($models[$i].'Cost (USD)' / $maxModelCost) * 100, 1)
    } else { 0 }
    $lines += "MODEL$($i+1)_PCT=$pct"
}

$maxActCost = if ($acts.Count -gt 0 -and $acts[0]) { [double]$acts[0].'Cost (USD)' } else { 0 }
for ($i = 0; $i -lt 3; $i++) {
    $pct = if ($maxActCost -gt 0 -and $i -lt $acts.Count -and $acts[$i]) {
        [math]::Round(($acts[$i].'Cost (USD)' / $maxActCost) * 100, 1)
    } else { 0 }
    $lines += "ACT$($i+1)_PCT=$pct"
}

foreach ($n in 1, 2, 3) {
    $pctLine = $lines | Where-Object { $_ -match "^MODEL${n}_PCT=" }
    $pctVal  = if ($pctLine) { [double]($pctLine -replace "^MODEL${n}_PCT=", '') } else { 0 }
    $steps   = [math]::Round($pctVal / 100 * 10)
    for ($s = 0; $s -le 9; $s++) {
        $lines += "MODEL${n}_SEG${s}_H=$([int]($s -ge $steps))"
    }
}

$todayCalls = [int]($td.summary.'API Calls')
if ($todayCalls -eq 0) {
    $cacheHit = 100
} else {
    $todayInput      = [double](($td.daily | Measure-Object -Property 'Input Tokens'       -Sum).Sum)
    $todayCacheRead  = [double](($td.daily | Measure-Object -Property 'Cache Read Tokens'  -Sum).Sum)
    $todayCacheWrite = [double](($td.daily | Measure-Object -Property 'Cache Write Tokens' -Sum).Sum)
    $allInputTokens  = $todayInput + $todayCacheRead + $todayCacheWrite
    $cacheHit = if ($allInputTokens -gt 0) {
        [math]::Round(($todayCacheRead / $allInputTokens) * 100, 1)
    } else { 100 }
}
$lines += "CACHE_HIT=$cacheHit"

$todayApiCalls = [int]($td.summary.'API Calls')
$readTool      = $td.tools | Where-Object { $_.Tool -eq 'Read' } | Select-Object -First 1
$readCalls     = if ($readTool) { [double]$readTool.'Calls' } else { 0 }
$readPerSession = if ($todayApiCalls -gt 0) {
    [math]::Round($readCalls / $todayApiCalls, 2)
} else { 0 }
$lines += "READ_PER_SESSION=$readPerSession"

# --- Signal: expensive model on short turns ---
# Configurable: output tokens per call below which a turn is considered "short"
$SHORT_TURNS_THRESHOLD  = 500
# Configurable: model must account for > this % of 7-day cost to be flagged
$DOMINANT_PCT_THRESHOLD = 40
# Configurable: minimum $/call to exclude genuinely cheap models from triggering
$MIN_CPT_EXPENSIVE      = 0.02

$m1              = if ($models.Count -gt 0) { $models[0] } else { $null }
$m1OutputTokens  = if ($m1) { [double]$m1.'Output Tokens' } else { 0 }
$m1Calls         = if ($m1) { [int]$m1.'API Calls'        } else { 0 }
$m1CostPct       = if ($m1 -and $weekTotal -gt 0) { ($m1.'Cost (USD)' / $weekTotal) * 100 } else { 0 }
$m1OutputPerCall = if ($m1Calls -gt 0) { [math]::Round($m1OutputTokens / $m1Calls) } else { 0 }
$m1CostPerCall   = if ($m1Calls -gt 0) { $m1.'Cost (USD)' / $m1Calls } else { 0 }

$expensiveFlag = if (
    $m1CostPct       -gt $DOMINANT_PCT_THRESHOLD -and
    $m1OutputPerCall -lt $SHORT_TURNS_THRESHOLD  -and
    $m1OutputPerCall -gt 0                        -and
    $m1CostPerCall   -gt $MIN_CPT_EXPENSIVE
) { 1 } else { 0 }
$lines += "EXPENSIVE_MODEL_FLAG=$expensiveFlag"
$lines += "EXPENSIVE_MODEL_NAME=$(if ($m1) { $m1.Model } else { '--' })"
$lines += "EXPENSIVE_MODEL_TKS=$m1OutputPerCall"

# --- Signal: dispatch_agent / task heavy ---
# Configurable: dispatch calls as a fraction of total API calls
$DISPATCH_RATIO_THRESHOLD = 0.10

$dispatchTools = @($wk.tools | Where-Object { $_.Tool -eq 'dispatch_agent' -or $_.Tool -eq 'task' })
$dispatchCalls = if ($dispatchTools.Count -gt 0) {
    [int](($dispatchTools | Measure-Object -Property Calls -Sum).Sum)
} else { 0 }
$weekApiCalls  = [int]$wk.summary.'API Calls'
$dispatchRatio = if ($weekApiCalls -gt 0) { [math]::Round($dispatchCalls / $weekApiCalls, 3) } else { 0 }
$dispatchFlag  = if ($dispatchRatio -gt $DISPATCH_RATIO_THRESHOLD -and $dispatchCalls -gt 0) { 1 } else { 0 }
$lines += "DISPATCH_FLAG=$dispatchFlag"
$lines += "DISPATCH_CALLS=$dispatchCalls"

# --- Signal: low 1-shot rate for Coding (7 days) ---
# Configurable: 1-shot rate below this % triggers the signal
$ONE_SHOT_THRESHOLD = 30

$codingAct    = $wk.activity | Where-Object { $_.Activity -eq 'Coding' } | Select-Object -First 1
$editTurns    = if ($codingAct) { [int]$codingAct.'Edit Turns'    } else { 0 }
$oneShotTurns = if ($codingAct) { [int]$codingAct.'1-Shot Turns'  } else { 0 }
$oneShotPct   = if ($editTurns -gt 0) {
    [math]::Round($oneShotTurns / $editTurns * 100, 1)
} else { 100 }
$lines += "ONE_SHOT_PCT=$oneShotPct"
$lines += "ONE_SHOT_EDIT_TURNS=$editTurns"

# --- Shell commands (all time, top 10) ---
$bashCmds    = @($j.shellCommands | Sort-Object Calls -Descending | Select-Object -First 10)
$maxBashCalls = if ($bashCmds.Count -gt 0 -and $bashCmds[0]) { [double]$bashCmds[0].Calls } else { 0 }
for ($i = 0; $i -lt 10; $i++) {
    if ($i -lt $bashCmds.Count -and $bashCmds[$i]) {
        $pct = if ($maxBashCalls -gt 0) { [math]::Round($bashCmds[$i].Calls / $maxBashCalls * 100, 1) } else { 0 }
        $lines += "BASH$($i+1)_NAME=$($bashCmds[$i].Command)"
        $lines += "BASH$($i+1)_CALLS=$($bashCmds[$i].Calls)"
        $lines += "BASH$($i+1)_PCT=$pct"
    } else {
        $lines += "BASH$($i+1)_NAME=--"
        $lines += "BASH$($i+1)_CALLS=0"
        $lines += "BASH$($i+1)_PCT=0"
    }
}

[System.IO.File]::WriteAllText($dataFile, ($lines -join "`n") + "`n", $utf8)
