@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy protocols%1.in protocols.in >nul
time <enter
protocols
time <enter
fc protocols%1.out protocols.out
pause
del protocols.in
del protocols.out
goto end
:loop
  for %%i in (0 1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end