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
pause
cls

echo ---------------------------------------------
echo Incomplete Square
echo ---------------------------------------------
Roads.exe incompletesquare.txt
pause
cls

echo ---------------------------------------------
echo Line
echo ---------------------------------------------
Roads.exe line.txt
pause
cls

echo ---------------------------------------------
echo Shape
echo ---------------------------------------------
Roads.exe shape.txt
pause
cls

echo ---------------------------------------------
echo Five Random Points
echo ---------------------------------------------
Roads.exe five.txt
pause
cls

echo ---------------------------------------------
echo Ten Random Points
echo ---------------------------------------------
Roads.exe ten.txt
pause
cls

echo ---------------------------------------------
echo Ten Points (Disconnected Graph)
echo ---------------------------------------------
Roads.exe ten_disconnected.txt
pause
cls
