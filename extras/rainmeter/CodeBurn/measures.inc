; =================== MEASURES ===================

[MeasureFetch]
Measure=Plugin
Plugin=RunCommand
Program=%COMSPEC%
Parameter=/c "#@#fetch.bat"
UpdateDivider=-1
FinishAction=[!UpdateMeasure MeasureData][!UpdateMeasure MeasureDataBash]

[MeasureTimer]
Measure=Calc
Formula=Counter
OnUpdateAction=[!CommandMeasure MeasureFetch "Run"]

[MeasureTime]
Measure=Time
Format=%H:%M

[MeasureData]
Measure=Plugin
Plugin=WebParser
URL=file://#@#data.txt
RegExp=(?si)TODAY_COST=([^\n]*)\nTODAY_CALLS=([^\n]*)\nWEEK_COST=([^\n]*)\nWEEK_CALLS=([^\n]*)\nMONTH_COST=([^\n]*)\nMONTH_CALLS=([^\n]*)\nMODEL1_NAME=([^\n]*)\nMODEL1_COST=([^\n]*)\nMODEL1_CALLS=([^\n]*)\nMODEL2_NAME=([^\n]*)\nMODEL2_COST=([^\n]*)\nMODEL2_CALLS=([^\n]*)\nMODEL3_NAME=([^\n]*)\nMODEL3_COST=([^\n]*)\nMODEL3_CALLS=([^\n]*)\nACT1_NAME=([^\n]*)\nACT1_COST=([^\n]*)\nACT1_TURNS=([^\n]*)\nACT2_NAME=([^\n]*)\nACT2_COST=([^\n]*)\nACT2_TURNS=([^\n]*)\nACT3_NAME=([^\n]*)\nACT3_COST=([^\n]*)\nACT3_TURNS=([^\n]*)\nMODEL1_PCT=([^\n]*)\nMODEL2_PCT=([^\n]*)\nMODEL3_PCT=([^\n]*)\nACT1_PCT=([^\n]*)\nACT2_PCT=([^\n]*)\nACT3_PCT=([^\n]*)\nMODEL1_SEG0_H=([^\n]*)\nMODEL1_SEG1_H=([^\n]*)\nMODEL1_SEG2_H=([^\n]*)\nMODEL1_SEG3_H=([^\n]*)\nMODEL1_SEG4_H=([^\n]*)\nMODEL1_SEG5_H=([^\n]*)\nMODEL1_SEG6_H=([^\n]*)\nMODEL1_SEG7_H=([^\n]*)\nMODEL1_SEG8_H=([^\n]*)\nMODEL1_SEG9_H=([^\n]*)\nMODEL2_SEG0_H=([^\n]*)\nMODEL2_SEG1_H=([^\n]*)\nMODEL2_SEG2_H=([^\n]*)\nMODEL2_SEG3_H=([^\n]*)\nMODEL2_SEG4_H=([^\n]*)\nMODEL2_SEG5_H=([^\n]*)\nMODEL2_SEG6_H=([^\n]*)\nMODEL2_SEG7_H=([^\n]*)\nMODEL2_SEG8_H=([^\n]*)\nMODEL2_SEG9_H=([^\n]*)\nMODEL3_SEG0_H=([^\n]*)\nMODEL3_SEG1_H=([^\n]*)\nMODEL3_SEG2_H=([^\n]*)\nMODEL3_SEG3_H=([^\n]*)\nMODEL3_SEG4_H=([^\n]*)\nMODEL3_SEG5_H=([^\n]*)\nMODEL3_SEG6_H=([^\n]*)\nMODEL3_SEG7_H=([^\n]*)\nMODEL3_SEG8_H=([^\n]*)\nMODEL3_SEG9_H=([^\n]*)\nCACHE_HIT=([^\n]*)\nREAD_PER_SESSION=([^\n]*)\nEXPENSIVE_MODEL_FLAG=([^\n]*)\nEXPENSIVE_MODEL_NAME=([^\n]*)\nEXPENSIVE_MODEL_TKS=([^\n]*)\nDISPATCH_FLAG=([^\n]*)\nDISPATCH_CALLS=([^\n]*)\nONE_SHOT_PCT=([^\n]*)\nONE_SHOT_EDIT_TURNS=([^\n]*)
UpdateRate=1
FinishAction=[!UpdateMeter *][!Redraw]

[MeasureTodayCost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=1

[MeasureTodayCalls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=2

[MeasureWeekCost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=3

[MeasureWeekCalls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=4

[MeasureMonthCost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=5

[MeasureMonthCalls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=6

[MeasureModel1Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=7

[MeasureModel1Cost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=8

[MeasureModel1Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=9

[MeasureModel2Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=10

[MeasureModel2Cost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=11

[MeasureModel2Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=12

[MeasureModel3Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=13

[MeasureModel3Cost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=14

[MeasureModel3Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=15

[MeasureAct1Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=16

[MeasureAct1Cost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=17

[MeasureAct1Turns]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=18

[MeasureAct2Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=19

[MeasureAct2Cost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=20

[MeasureAct2Turns]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=21

[MeasureAct3Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=22

[MeasureAct3Cost]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=23

[MeasureAct3Turns]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=24

[MeasureModel1Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=25

[MeasureModel2Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=26

[MeasureModel3Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=27

[MeasureAct1Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=28

[MeasureAct2Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=29

[MeasureAct3Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=30

[MeasureModel1Seg0H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=31

[MeasureModel1Seg1H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=32

[MeasureModel1Seg2H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=33

[MeasureModel1Seg3H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=34

[MeasureModel1Seg4H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=35

[MeasureModel1Seg5H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=36

[MeasureModel1Seg6H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=37

[MeasureModel1Seg7H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=38

[MeasureModel1Seg8H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=39

[MeasureModel1Seg9H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=40

[MeasureModel2Seg0H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=41

[MeasureModel2Seg1H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=42

[MeasureModel2Seg2H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=43

[MeasureModel2Seg3H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=44

[MeasureModel2Seg4H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=45

[MeasureModel2Seg5H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=46

[MeasureModel2Seg6H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=47

[MeasureModel2Seg7H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=48

[MeasureModel2Seg8H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=49

[MeasureModel2Seg9H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=50

[MeasureModel3Seg0H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=51

[MeasureModel3Seg1H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=52

[MeasureModel3Seg2H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=53

[MeasureModel3Seg3H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=54

[MeasureModel3Seg4H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=55

[MeasureModel3Seg5H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=56

[MeasureModel3Seg6H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=57

[MeasureModel3Seg7H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=58

[MeasureModel3Seg8H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=59

[MeasureModel3Seg9H]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=60

[MeasureCacheHit]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=61

[MeasureCacheHitCalc]
Measure=Calc
Formula=[MeasureCacheHit]
IfCondition=MeasureCacheHitCalc < 80
IfTrueAction=[!SetOption MeterCacheHitSignal FontColor "255,80,30,255"][!SetOption MeterCacheHitValue FontColor "255,80,30,255"][!UpdateMeter MeterCacheHitSignal][!UpdateMeter MeterCacheHitValue][!Redraw]
IfFalseAction=[!SetOption MeterCacheHitSignal FontColor "120,115,105,255"][!SetOption MeterCacheHitValue FontColor "120,115,105,255"][!UpdateMeter MeterCacheHitSignal][!UpdateMeter MeterCacheHitValue][!Redraw]

[MeasureReadPerSession]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=62

[MeasureReadPerSessionCalc]
Measure=Calc
Formula=[MeasureReadPerSession]
IfCondition=MeasureReadPerSessionCalc > 2
IfTrueAction=[!SetOption MeterReadPerSessionSignal FontColor "255,80,30,255"][!SetOption MeterReadPerSessionValue FontColor "255,80,30,255"][!UpdateMeter MeterReadPerSessionSignal][!UpdateMeter MeterReadPerSessionValue][!Redraw]
IfFalseAction=[!SetOption MeterReadPerSessionSignal FontColor "120,115,105,255"][!SetOption MeterReadPerSessionValue FontColor "120,115,105,255"][!UpdateMeter MeterReadPerSessionSignal][!UpdateMeter MeterReadPerSessionValue][!Redraw]

[MeasureExpensiveModelFlag]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=63

[MeasureExpensiveModelName]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=64

[MeasureExpensiveModelTks]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=65

[MeasureDispatchFlag]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=66

[MeasureDispatchCalls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=67

[MeasureExpensiveModelCalc]
Measure=Calc
Formula=[MeasureExpensiveModelFlag]
IfCondition=MeasureExpensiveModelCalc = 1
IfTrueAction=[!SetOption MeterTip4Signal FontColor "255,80,30,255"][!SetOption MeterTip4Value FontColor "255,80,30,255"][!UpdateMeter MeterTip4Signal][!UpdateMeter MeterTip4Value][!Redraw]
IfFalseAction=[!SetOption MeterTip4Signal FontColor "120,115,105,255"][!SetOption MeterTip4Value FontColor "120,115,105,255"][!UpdateMeter MeterTip4Signal][!UpdateMeter MeterTip4Value][!Redraw]

[MeasureDispatchCalc]
Measure=Calc
Formula=[MeasureDispatchFlag]
IfCondition=MeasureDispatchCalc = 1
IfTrueAction=[!SetOption MeterTip5Signal FontColor "255,80,30,255"][!SetOption MeterTip5Value FontColor "255,80,30,255"][!UpdateMeter MeterTip5Signal][!UpdateMeter MeterTip5Value][!Redraw]
IfFalseAction=[!SetOption MeterTip5Signal FontColor "120,115,105,255"][!SetOption MeterTip5Value FontColor "120,115,105,255"][!UpdateMeter MeterTip5Signal][!UpdateMeter MeterTip5Value][!Redraw]

[MeasureOneShotPct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=68

[MeasureOneShotEditTurns]
Measure=Plugin
Plugin=WebParser
URL=[MeasureData]
StringIndex=69

[MeasureOneShotCalc]
Measure=Calc
Formula=[MeasureOneShotPct]
IfCondition=MeasureOneShotCalc < 30
IfTrueAction=[!SetOption MeterTip3Signal FontColor "255,80,30,255"][!SetOption MeterTip3Value FontColor "255,80,30,255"][!UpdateMeter MeterTip3Signal][!UpdateMeter MeterTip3Value][!Redraw]
IfFalseAction=[!SetOption MeterTip3Signal FontColor "120,115,105,255"][!SetOption MeterTip3Value FontColor "120,115,105,255"][!UpdateMeter MeterTip3Signal][!UpdateMeter MeterTip3Value][!Redraw]

[MeasureDataBash]
Measure=Plugin
Plugin=WebParser
URL=file://#@#data.txt
RegExp=(?si)BASH1_NAME=([^\n]*)\nBASH1_CALLS=([^\n]*)\nBASH1_PCT=([^\n]*)\nBASH2_NAME=([^\n]*)\nBASH2_CALLS=([^\n]*)\nBASH2_PCT=([^\n]*)\nBASH3_NAME=([^\n]*)\nBASH3_CALLS=([^\n]*)\nBASH3_PCT=([^\n]*)\nBASH4_NAME=([^\n]*)\nBASH4_CALLS=([^\n]*)\nBASH4_PCT=([^\n]*)\nBASH5_NAME=([^\n]*)\nBASH5_CALLS=([^\n]*)\nBASH5_PCT=([^\n]*)\nBASH6_NAME=([^\n]*)\nBASH6_CALLS=([^\n]*)\nBASH6_PCT=([^\n]*)\nBASH7_NAME=([^\n]*)\nBASH7_CALLS=([^\n]*)\nBASH7_PCT=([^\n]*)\nBASH8_NAME=([^\n]*)\nBASH8_CALLS=([^\n]*)\nBASH8_PCT=([^\n]*)\nBASH9_NAME=([^\n]*)\nBASH9_CALLS=([^\n]*)\nBASH9_PCT=([^\n]*)\nBASH10_NAME=([^\n]*)\nBASH10_CALLS=([^\n]*)\nBASH10_PCT=([^\n]*)
UpdateRate=1
FinishAction=[!UpdateMeter *][!Redraw]

[MeasureBash1Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=1

[MeasureBash1Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=2

[MeasureBash1Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=3

[MeasureBash2Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=4

[MeasureBash2Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=5

[MeasureBash2Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=6

[MeasureBash3Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=7

[MeasureBash3Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=8

[MeasureBash3Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=9

[MeasureBash4Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=10

[MeasureBash4Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=11

[MeasureBash4Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=12

[MeasureBash5Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=13

[MeasureBash5Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=14

[MeasureBash5Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=15

[MeasureBash6Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=16

[MeasureBash6Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=17

[MeasureBash6Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=18

[MeasureBash7Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=19

[MeasureBash7Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=20

[MeasureBash7Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=21

[MeasureBash8Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=22

[MeasureBash8Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=23

[MeasureBash8Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=24

[MeasureBash9Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=25

[MeasureBash9Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=26

[MeasureBash9Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=27

[MeasureBash10Name]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=28

[MeasureBash10Calls]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=29

[MeasureBash10Pct]
Measure=Plugin
Plugin=WebParser
URL=[MeasureDataBash]
StringIndex=30
