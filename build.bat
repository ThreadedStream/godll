@echo off

if not exist ../build\ (
	echo creating a build folder...
	mkdir build 
) else (
	echo found build folder
)

cmake -G "Visual Studio 15 2017" -A x64 -Slib/ -B "build64" 
cmake --build build64 --target godll
	
