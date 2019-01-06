How to setup the environment:

1) Download MSYS2 (https://www.msys2.org/)

2) We will be using mingw-x64 that comes with it. To make things easier, 
you might want to add the path to the MSYS2 mingw-x64 bin folder to the PATH environment variable of your system.

3) Now that you should have MSYS2 up and running, and can call g++ from your cmd terminal.
MSYS2 comes with its own terminal, so open it to download the packages we will need.
The package application is called pacman. In order to have it up to date, follow steps 5 to 7 at:

https://www.msys2.org/

4) We need to download zlib and libpng. The following command downloads and install packages on pacman:

pacman -S <package name>

So you will need to use the commands:

pacman -S zlib
pacman -S mingw-w64-x86_64-libpng

5) With everything installed, open up a cmd terminal. Navigate to the main folder of the project.

6) Over there you will find a file named compiling.bat 
Either run it, or open it on a text editor and run each of the commands in there to compile the project.
Once compilation of all files are done (might take a bit), an executable file should be at the build folder.
Run the executable file from the terminal. If everything worked fine it should print "Hello" and terminate.