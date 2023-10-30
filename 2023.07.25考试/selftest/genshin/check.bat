@echo off
copy "genshin1.in" "genshin.in" >nul
echo Test Case: 1
time<enter
"genshin.exe"
time<enter
fc "genshin.out" "genshin1.out"
pause
del "genshin.in"
del "genshin.out"
echo.

copy "genshin2.in" "genshin.in" >nul
echo Test Case: 2
time<enter
"genshin.exe"
time<enter
fc "genshin.out" "genshin2.out"
pause
del "genshin.in"
del "genshin.out"
echo.

copy "genshin3.in" "genshin.in" >nul
echo Test Case: 3
time<enter
"genshin.exe"
time<enter
fc "genshin.out" "genshin3.out"
pause
del "genshin.in"
del "genshin.out"
echo.

copy "genshin4.in" "genshin.in" >nul
echo Test Case: 4
time<enter
"genshin.exe"
time<enter
fc "genshin.out" "genshin4.out"
pause
del "genshin.in"
del "genshin.out"
echo.

copy "genshin5.in" "genshin.in" >nul
echo Test Case: 5
time<enter
"genshin.exe"
time<enter
fc "genshin.out" "genshin5.out"
pause
del "genshin.in"
del "genshin.out"
echo.

