@echo off


if %1 == vs17 (
    cmake -G "Visual Studio 15 2017" -A x64 -Slib/ -B "build64"
) else if %1 == vs19 (
    cmake -G "Visual Studio 16 2019" -A x64 -Slib/ -B "build64"
)

cmake --build build64 --target godll

go build main.go

echo.
echo.
echo =================================================
echo YOUR WINDOWS VERSION:
main.exe
echo.
echo =================================================