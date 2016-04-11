echo off
title Roads Testing
cls
echo Getting exe...
copy /y /b ..\bin\Debug\Roads.exe .\
start ShortestPathsExpectedResults.pdf

echo Complete Square
Roads.exe completesquare.txt >> completesquare_RESULT.txt
echo Incomplete Square
Roads.exe incompletesquare.txt >> incompletesquare_RESULT.txt
echo Line
Roads.exe line.txt >> line_RESULT.txt
echo Shape
Roads.exe shape.txt >> shape_RESULT.txt
echo Five Random Points
Roads.exe five.txt >> five_RESULT.txt
echo Ten Random Points
Roads.exe ten.txt >> ten_RESULT.txt
echo Ten Points (Disconnected Graph)
Roads.exe ten_disconnected.txt >> ten_disconnected_RESULT.txt