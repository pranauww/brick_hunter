# Breakout Game in C using Graphics

This is a simple **Breakout Game** written in C, using the `graphics.h` library. The objective of the game is to break all the bricks using a bouncing ball and paddle. The player has 3 lives, and the game ends when the player either loses all lives or breaks all the bricks.

## Features
- **Ball and Paddle Mechanics**: Control the paddle to keep the ball from falling off the screen.
- **Bricks**: Breakable bricks arranged in rows. Each brick broken gives points.
- **Lives System**: Player starts with 3 lives, and loses a life if they fail to bounce the ball.
- **Scoring System**: Players earn 100 points for each brick they destroy.
- **Power-ups** (Optional): You can easily extend this game by adding power-ups that affect paddle size, ball speed, etc.
  
## How to Play
- **Move Left**: Use the left arrow key (`←`) to move the paddle left.
- **Move Right**: Use the right arrow key (`→`) to move the paddle right.
- **Exit Game**: Press the `ESC` key to exit the game.
- **Winning Condition**: Destroy all the bricks to win the game.
- **Losing Condition**: If the player loses all 3 lives, the game will end.

## Installation

### Requirements
- **Turbo C** or **Borland C** Compiler with support for `graphics.h`.
- **Graphics Driver** (`BGI`) installed or accessible from your project directory.

### Setup
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/breakout-game.git
   ```

2. Open the project in your **Turbo C** or **Borland C** compiler.

3. Ensure that the `BGI` graphics driver is set up correctly. If not, set the path to the `BGI` folder using:
   ```c
   initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
   ```

4. Compile and run the `main.c` file.

### Compilation Command
```bash
gcc main.c -o breakout -lgraph
```
> Note: Use a compiler that supports `graphics.h`. The standard `gcc` may not work with graphics.

## Game Structure

### Main Game Loop
- The game runs in a loop until the player loses all lives or breaks all bricks.
- Ball movement is based on basic 2D collision detection.
- The player controls the paddle using the keyboard arrows to bounce the ball and break bricks.

### Game Files
- `main.c`: Contains the game logic and code.
- `README.md`: Documentation for the project.

## Contributing
Feel free to open an issue or submit a pull request if you would like to contribute. Any enhancements or bug fixes are welcome.
