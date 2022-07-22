@echo off
set /p number=Enter your number (or the file name without .c) that you want to compile: 
set /p count=Enter input-output count: 

gcc %number%.c -o %number%

for /l %%n in (1,1,%count%) do (
    echo "-input%%n-"
    %number% < input%%n.txt > output%%n-%number%.txt
    fc /l /n /c /t /lb200 "output%%n-%number%.txt" "output%%n.TXT"
)

PAUSE
