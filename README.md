# MedNES
MedNES is a cycle-accurate NES emulator written in C++.
Supported mappers: NROM(0)

## Prerequisites: install SDL2

### From web site

[SDL2 library](https://www.libsdl.org/download-2.0.php)

### From apt (Ubuntu, Debian)

```bash
sudo apt install libsdl2-2.0-0 libsdl2-dev
```

### From pacman (ArchLinux)

```bash
sudo pacman -S libsdl2-2.0-0 libsdl2-dev
```

### From vcpkg (Windows, Linux, macOS)

```bash
vcpkg install sdl2
```

## Usage

[CMake](https://www.cmake.org/) is required to build MedNES.

```bash
git clone https://github.com/wpmed92/MedNES.git
mkdir build && cd build
cmake ../
make
./MedNES -insert <path/to/rom>
```

## Screenshots

Super Mario Bros

![alt text](https://github.com/wpmed92/MedNES/blob/master/screenshots/Super%20Mario%20Bros.png)

Donkey Kong

![alt text](https://github.com/wpmed92/MedNES/blob/master/screenshots/Donkey%20Kong.png)

Bomberman

![alt text](https://github.com/wpmed92/MedNES/blob/master/screenshots/Bomberman.png)

Pac-Man

![alt text](https://github.com/wpmed92/MedNES/blob/master/screenshots/Pac-Man.png)

Battle City

![alt text](https://github.com/wpmed92/MedNES/blob/master/screenshots/Battle%20City.png)

Antarctic Adventure

![alt text](https://github.com/wpmed92/MedNES/blob/master/screenshots/Antarctic%20Adventure.png)
