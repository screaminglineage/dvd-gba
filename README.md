# Experimental DVD Animation
Experimental DVD Animation that runs on the [Gameboy Advance](https://en.wikipedia.org/wiki/Game_Boy_Advance). Note that it has only been tested on a emulator, and might not work well on actual hardware.

Inspired by [tonc](https://www.coranac.com/tonc/text/intro.htm).

## Building Instructions
### Prerequisites
- A toolkit for GBA development - [devkitPro](https://devkitpro.org/). ([Installation instructions](https://devkitpro.org/wiki/Getting_Started))
- `gbafix` to add the required headers to the executable. (Available in [this repo](https://github.com/devkitPro/gba-tools/tree/master))
- Emulator for running 

Finally, clone this repo and simply run `make` in the project directory. The `main.gba` file will be generated inside the `build` folder of the same.

Alternatively, do `make run`, to both compile and run. The `Makefile` uses the [mgba](https://mgba.io/) emulator by default which can be changed by editing the `GBAEMU` variable near the top.

