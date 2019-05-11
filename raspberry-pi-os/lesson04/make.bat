del build/kernel8.elf
del kernel8.img
docker run --rm -v /c/Users/RaspOS/raspberry-pi-os/lesson04:/app -w /app smatyukevich/raspberry-pi-os-builder make %1
emulate