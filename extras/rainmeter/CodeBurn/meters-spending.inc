; =================== METERS: TITLE + SPENDING ===================

[MeterTitleBG]
Meter=Image
SolidColor=#TitleBG#
X=0
Y=0
W=#W#
H=28

[MeterTitle]
Meter=String
Text=CodeBurn
X=#PAD#
Y=6
W=180
H=18
FontFace=#FF#
FontSize=13
FontColor=#Orange#
FontWeight=700
AntiAlias=1

[MeterUpdated]
Meter=String
MeasureName=MeasureTime
Text=updated %1
X=328
Y=9
W=160
H=14
FontFace=#FF#
FontSize=9
FontColor=#Dim#
StringAlign=Right
AntiAlias=1

[MeterDiv1]
Meter=Image
SolidColor=#Line#
X=0
Y=28
W=#W#
H=1

; --- Spending rows ---

[MeterTodayLabel]
Meter=String
Text=TODAY
X=#PAD#
Y=36
FontFace=#FF#
FontSize=10
FontColor=#Dim#
FontWeight=600
AntiAlias=1

[MeterTodayCost]
Meter=String
MeasureName=MeasureTodayCost
Text=$%1
X=212
Y=33
W=80
H=20
FontFace=#FF#
FontSize=12
FontColor=#Gold#
FontWeight=600
StringAlign=Right
AntiAlias=1

[MeterTodayCalls]
Meter=String
MeasureName=MeasureTodayCalls
Text=%1 calls
X=328
Y=37
W=110
H=16
FontFace=#FF#
FontSize=9
FontColor=#Dim#
StringAlign=Right
AntiAlias=1

[MeterWeekLabel]
Meter=String
Text=7 DAYS
X=#PAD#
Y=58
FontFace=#FF#
FontSize=10
FontColor=#Dim#
FontWeight=600
AntiAlias=1

[MeterWeekCost]
Meter=String
MeasureName=MeasureWeekCost
Text=$%1
X=212
Y=55
W=80
H=20
FontFace=#FF#
FontSize=12
FontColor=#Gold#
FontWeight=600
StringAlign=Right
AntiAlias=1

[MeterWeekCalls]
Meter=String
MeasureName=MeasureWeekCalls
Text=%1 calls
X=328
Y=59
W=110
H=16
FontFace=#FF#
FontSize=9
FontColor=#Dim#
StringAlign=Right
AntiAlias=1

[MeterMonthLabel]
Meter=String
Text=30 DAYS
X=#PAD#
Y=80
FontFace=#FF#
FontSize=10
FontColor=#Dim#
FontWeight=600
AntiAlias=1

[MeterMonthCost]
Meter=String
MeasureName=MeasureMonthCost
Text=$%1
X=212
Y=77
W=80
H=20
FontFace=#FF#
FontSize=12
FontColor=#Gold#
FontWeight=600
StringAlign=Right
AntiAlias=1

[MeterMonthCalls]
Meter=String
MeasureName=MeasureMonthCalls
Text=%1 calls
X=328
Y=81
W=110
H=16
FontFace=#FF#
FontSize=9
FontColor=#Dim#
StringAlign=Right
AntiAlias=1

[MeterDiv2]
Meter=Image
SolidColor=#Line#
X=0
Y=102
W=#W#
H=1
