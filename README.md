# so-long

## Gameplay

Move around the map with 4 keys `W = up` `S = down` `A = left` `D = right` and collecting all bouncing collectibles.
An exit gate will appear once all collectibles have been collected, escape through it to win the game.
<br /><br />
You'll lose if coming into collision with enemies, although attacking animation indeed looks like 
it can slay a foe. Don't flatter yourself :zany_face:

## Installation
### 1. Install required dependencies:
#### For MacOS:
```
brew install glfw
brew install cmake
```

#### For Debian like (Ubuntu, Mint, Pop OS...):
```
sudo apt update
sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```

#### For Arch-linux (Manjaro, Endeavor, Garuda): 
```
sudo pacman -S glfw-x11
```

#### For sway/wlroots compositor or other wayland compositor:
```
sudo pacman -S glfw-wayland
```

### 2. Download and build:
```
git clone https://github.com/hoangfin/so-long.git
cd so-long
make
```

### 3. Run the game:
All maps are stored @ `assets/maps` [directory](https://github.com/hoangfin/so-long/tree/main/assets/maps)
```
./so-long assets/maps/map-1.ber
```
## Credits
[MLX42](https://github.com/codam-coding-college/MLX42) - Graphics library running on GLFW and OpenGL.<br />
[Pixel Frog - Tiny Swords](https://pixelfrog-assets.itch.io/tiny-swords) - Game assets.
