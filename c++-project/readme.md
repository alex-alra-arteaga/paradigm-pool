# rush03

a "cross-platform" system monitor written in c++ with ncurses

## install

```
git clone --recurse-submodules $URL
```

## modules

- battery info (status, charge)
- system info (hostname, username, OS, kernel, uptime, date, time)
- cpu info (model, frequency, number of cores, load average)
- ram info (total, used, free, physical, virtual)

## building

generate build files with `cmake` and compile with `make`

```
mkdir build
cd build
cmake ..
make
```

you can pass optional arguments to `cmake` to enable/disable modules

```
cmake -DENABLE_BATTERY=OFF ..
```

the full list of modules is

- `ENABLE_BATTERY`
- `ENABLE_SYSTEM`
- `ENABLE_CPU`
- `ENABLE_RAM`
- `ENABLE_PROCESS`

you can also select the main theme at compile time with

```
cmake -DTHEME=dark ..
```

the full list of themes is

- `default`
- `dark`
- `light`

# development

```
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_GRAPHICAL=OFF -DTHEME=LIGHT ..
```

## thanks

special thanks to gnu for the ncurses library and the creators of infoware.
