@echo off

set BUILD_TYPE=%2

if %1 == vs17 (
    cmake -G "Visual Studio 15 2017" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -A x64 -Slib/ -B "build64"
) else if %1 == vs19 (
    cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -A x64 -Slib/ -B "build64"
)

cmake --build build64 --target godll

go build main.go

echo.
echo.
echo =================================================
echo YOUR WINDOWS VERSION:
win.exe
echo.
echo =================================================