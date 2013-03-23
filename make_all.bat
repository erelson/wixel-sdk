:: This Windows batch file will build all of the apps
:: and the libraries that they depend on.
:: You can run it by double-clicking on it.
mode con: cols=80 lines=80
@echo off
make
echo You may now close this window.
pause > nul