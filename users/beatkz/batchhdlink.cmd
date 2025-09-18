@echo off
chcp 65001
cd /d "%~dp0"

for /f "eol=#" %%k in (build_target.txt) do (
echo %%k
call mkhdlink %%k
)

pause .
