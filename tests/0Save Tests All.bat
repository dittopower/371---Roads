echo off
title Roads Testing
cls
echo Getting exe...
copy /y /b ..\bin\Debug\Roads.exe .\
start ShortestPathsExpectedResults.pdf
cls
echo Press Any key to Finish
"0Display Tests All.bat" >> 0TEST_RESULTS.txt