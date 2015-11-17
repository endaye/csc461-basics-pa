rmdir /S /Q Debug
rmdir /S /Q ipch
rmdir /S /Q Release
del /F /S /A:H *.suo
del /F /S /A:H *.opensdf

del /F /S *.sdf

rmdir /S /Q bloated\Debug
rmdir /S /Q bloated\Release


