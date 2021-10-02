# godll

# How to build dll? 

First, clone the project to your local computer, cd to it, and create a folder "build" inside it. Right then you need to open the CMake project in Visual Studio, open up "Manage Configurations" window, and select "x64-Debug" mode. This will
automatically prepare all of the cmake cache files. Now you may hit godll.dll button right on the top and wait until compiler finishes its execution. In CMakeSettings.json, 
you need to change values for build and install paths to the absolute path of the "build" folder you've created in the beginning. 

# How to build a go app? 

First of all, you need to have mingw-w64 installed and added to the PATH. Once it's done, you may type in the following command 
```bash 
  go build main.go
  main.exe
```
