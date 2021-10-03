# godll

# Prerequisites
1) Working msvc compiler
2) Working mingw-w64 gcc compiler (here's a <a href="https://www.mingw-w64.org/downloads/">link</a>)
4) Opened "Developer Command prompt" or just cmd

# How to build the app? 

There's only one step to spin execution of the application up.
You only need to run build.bat script that will do everything for you.
Script accepts 1 parameter -- a generator type. Currently, 
script supports only two generators -- vs17 and vs19. Intuitively,
the first parameter will generate Visual Studio 2017 build files, whereas another 
option will let you do the same thing, but for Visual Studio 2019. 

# Some extraneous details

It took me about a day to get this whole stuff working. Most of the time was spent on preparing environment, i.e i don't use Windows on the regular basis, so 
it turned out to be a bit painful endeavour. 
