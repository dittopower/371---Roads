echo off
title Roads Testing
cls
echo Getting exe...
copy /y /b ..\bin\Debug\Roads.exe .\
start ShortestPathsExpectedResults.pdf
cls

echo ---------------------------------------------
echo Complete Square
echo ---------------------------------------------
Roads.exe completesquare.txt

echo ---------------------------------------------
echo Incomplete Square
echo ---------------------------------------------
Roads.exe incompletesquare.txt

echo ---------------------------------------------
echo Line
echo ---------------------------------------------
Roads.exe line.txt

echo ---------------------------------------------
echo Shape
echo ---------------------------------------------
Roads.exe shape.txt

echo ---------------------------------------------
echo Five Random Points
echo ---------------------------------------------
Roads.exe five.txt

echo ---------------------------------------------
echo Ten Random Points
echo ---------------------------------------------
Roads.exe ten.txt

echo ---------------------------------------------
echo Ten Points (Disconnected Graph)
echo ---------------------------------------------
Roads.exe ten_disconnected.txt

echo ---------------------------------------------
echo Tests Finished
echo ---------------------------------------------
pause
