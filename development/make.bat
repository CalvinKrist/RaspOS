@echo off

:: Clear old artifacts
del build\kernel8.elf
del kernel8.img

:: Print docker compatable file path to 'path.tmp' and then read it in as a variable
:: Path in format of /c/Users . . . etc
echo_path.vbs
set /p docker_path=<path.tmp

docker run --rm -v %docker_path% -w /app smatyukevich/raspberry-pi-os-builder make
emulate