docker-machine start
del build/kernel8.elf
del kernel8.img
docker run --rm -v /c/Users/RaspOS/personal:/app -w /app smatyukevich/raspberry-pi-os-builder make
emulate