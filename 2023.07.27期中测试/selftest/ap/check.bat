@echo off
copy "ap1.in" "ap.in" >nul
echo Test Case: 1
time<enter
"ap.exe"
time<enter
fc "ap.out" "ap1.out" /W
pause
del "ap.in"
del "ap.out"
echo.

copy "ap2.in" "ap.in" >nul
echo Test Case: 2
time<enter
"ap.exe"
time<enter
fc "ap.out" "ap2.out" /W
pause
del "ap.in"
del "ap.out"
echo.

