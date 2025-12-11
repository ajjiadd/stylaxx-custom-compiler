@echo off
cls

echo ========================================
echo       Stylaxx Compiler Build System
echo ========================================

:: 0. Clean Old Files
echo [0/4] Cleaning old files...
if exist lex.yy.c del lex.yy.c
if exist stylaxx.tab.c del stylaxx.tab.c
if exist stylaxx.tab.h del stylaxx.tab.h
if exist stylaxx.exe del stylaxx.exe

:: 1. Run Bison
echo [1/4] Running Bison...
bison -d stylaxx.y
if %errorlevel% neq 0 goto error

:: 2. Run Flex
echo [2/4] Running Flex...
flex stylaxx.l
if %errorlevel% neq 0 goto error

:: 3. Compile with GCC
echo [3/4] Compiling C Code...
gcc lex.yy.c stylaxx.tab.c -o stylaxx.exe
if %errorlevel% neq 0 goto error

:: 4. Run the Program
echo [4/4] Running Stylaxx...
echo.
echo ---------------- OUTPUT ----------------
stylaxx.exe code.laxx
echo ----------------------------------------
goto end

:error
echo.
echo [X] ERROR: Compilation Failed!
echo.
pause
exit /b

:end
echo.
echo [V] SUCCESS: Execution Finished.
pause