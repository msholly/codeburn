; =================== METERS: TIPS ===================

[MeterTipsHeader]
Meter=String
Text=READING THE DASHBOARD
X=#PAD#
Y=316
FontFace=#FF#
FontSize=9
FontColor=#Orange#
FontWeight=600
AntiAlias=1

[MeterCacheHitSignal]
Meter=String
Text=Cache hit
X=#PAD#
Y=332
W=200
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
AntiAlias=1

[MeterCacheHitValue]
Meter=String
MeasureName=MeasureCacheHit
Text=%1%
X=328
Y=332
W=110
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
StringAlign=Right
AntiAlias=1

[MeterCacheHitDesc]
Meter=String
Text=< 80% - system prompt not stable, or caching not enabled
X=#PAD#
Y=346
W=316
H=14
FontFace=#FF#
FontSize=8
FontColor=#TipMeaning#
AntiAlias=1

[MeterReadPerSessionSignal]
Meter=String
Text=Read calls / turn
X=#PAD#
Y=364
W=200
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
AntiAlias=1

[MeterReadPerSessionValue]
Meter=String
MeasureName=MeasureReadPerSession
Text=%1
X=328
Y=364
W=110
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
StringAlign=Right
AntiAlias=1

[MeterReadPerSessionDesc]
Meter=String
Text=> 2 per turn - agent re-reading same files, missing context
X=#PAD#
Y=378
W=316
H=14
FontFace=#FF#
FontSize=8
FontColor=#TipMeaning#
AntiAlias=1

[MeterTip3Signal]
Meter=String
Text=Coding 1-shot (7d)
X=#PAD#
Y=396
W=200
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
AntiAlias=1

[MeterTip3Value]
Meter=String
MeasureName=MeasureOneShotPct
Text=%1%
X=328
Y=396
W=140
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
StringAlign=Right
AntiAlias=1

[MeterTip3Desc]
Meter=String
Text=< 30% of edit turns on first try - agent stuck in retry loops
X=#PAD#
Y=410
W=316
H=14
FontFace=#FF#
FontSize=8
FontColor=#TipMeaning#
AntiAlias=1

[MeterTip4Signal]
Meter=String
MeasureName=MeasureExpensiveModelName
Text=%1
X=#PAD#
Y=428
W=200
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
ClipString=1
AntiAlias=1

[MeterTip4Value]
Meter=String
MeasureName=MeasureExpensiveModelTks
Text=%1 tok/call
X=328
Y=428
W=140
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
StringAlign=Right
AntiAlias=1

[MeterTip4Desc]
Meter=String
Text=>40% of 7d cost and < 500 tok/call - model may be overpowered
X=#PAD#
Y=442
W=316
H=14
FontFace=#FF#
FontSize=8
FontColor=#TipMeaning#
AntiAlias=1

[MeterTip5Signal]
Meter=String
Text=dispatch_agent / task
X=#PAD#
Y=460
W=200
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
AntiAlias=1

[MeterTip5Value]
Meter=String
MeasureName=MeasureDispatchCalls
Text=%1 calls (7d)
X=328
Y=460
W=140
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
StringAlign=Right
AntiAlias=1

[MeterTip5Desc]
Meter=String
Text=>10% of API calls - sub-agent fan-out, expected or excessive
X=#PAD#
Y=474
W=316
H=14
FontFace=#FF#
FontSize=8
FontColor=#TipMeaning#
AntiAlias=1

[MeterTip6Signal]
Meter=String
Text=No MCP usage shown
X=#PAD#
Y=492
W=140
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
ClipString=1
AntiAlias=1

[MeterTip6Meaning]
Meter=String
Text=No MCP servers, or config is broken
X=158
Y=492
W=170
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipMeaning#
ClipString=1
AntiAlias=1

[MeterTip7Signal]
Meter=String
Text=Bash: git status, ls dominant
X=#PAD#
Y=510
W=140
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
ClipString=1
AntiAlias=1

[MeterTip7Meaning]
Meter=String
Text=Agent exploring instead of executing
X=158
Y=510
W=170
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipMeaning#
ClipString=1
AntiAlias=1

[MeterTip8Signal]
Meter=String
Text=Conversation category dominant
X=#PAD#
Y=528
W=140
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipSignal#
ClipString=1
AntiAlias=1

[MeterTip8Meaning]
Meter=String
Text=Agent talking instead of doing
X=158
Y=528
W=170
H=16
FontFace=#FF#
FontSize=9
FontColor=#TipMeaning#
ClipString=1
AntiAlias=1

[MeterDiv5]
Meter=Image
SolidColor=#Line#
X=0
Y=546
W=#W#
H=1
