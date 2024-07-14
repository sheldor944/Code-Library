@echo off
setlocal enabledelayedexpansion

:: Compile C++ programs
g++ 2.cpp -o code.exe
g++ gen.cpp -o gen.exe
g++ 3.cpp -o brute.exe

:: Initialize a counter
set i=1

:loop
:: Generate input file using gen.exe
gen.exe !i! > input_file

:: Execute code.exe and save the output to myAnswer
code.exe < input_file > myAnswer

:: Execute brute.exe and save the output to correctAnswer
brute.exe < input_file > correctAnswer

:: Compare myAnswer and correctAnswer
fc /b myAnswer correctAnswer > nul

:: Check if the outputs match
if errorlevel 1 (
    echo WA on the following test:
    type input_file
    echo Your answer is:
    type myAnswer
    echo Correct answer is:
    type correctAnswer
    pause
    exit /b 1
) else (
    echo Passed test: !i!
    set /a i+=1
    goto loop
)