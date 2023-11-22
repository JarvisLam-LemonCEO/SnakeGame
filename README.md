# SnakeGame
Designed by 🍋Lemon in California

W - UP
A - Left
S - Down
D - Right

**Snake Game Manual**

Welcome to the Snake Game! This manual will guide you through playing and understanding the mechanics of the game.

### Objective
The objective of the Snake Game is to control the snake to eat fruits that appear on the screen, growing longer with each fruit consumed, while avoiding collisions with walls or the snake's own tail.

### Game Controls
- **Movement:** Use the keys 'a' (left), 'd' (right), 'w' (up), and 's' (down) to control the direction of the snake.
- **Exit Game:** Press 'x' to exit the game at any time.

### Gameplay
- **Snake:** The game starts with a snake represented by the character 'O'. The snake moves in the direction specified by the player.
- **Fruit:** Fruits appear randomly on the game area as the character 'F'. When the snake eats a fruit, it grows longer, and your score increases.
- **Walls:** The game area is bounded by walls ('#'). If the snake collides with the walls or itself, the game ends.

### Display
- **Game Area:** The game area is a grid with dimensions specified by the `width` and `height` constants at the beginning of the code.
- **Snake:** The snake's head is represented by 'O', and its tail by 'o'.
- **Fruit:** Fruits are represented by 'F'.
- **Score:** Your current score is displayed at the top of the game area.

### Code Explanation
The code consists of several functions:
- **Setup():** Initializes the game, setting the initial positions of the snake and fruit, and the score to zero.
- **Draw():** Displays the game area, snake, fruit, tail, and score on the console.
- **Input():** Reads user input to control the snake's direction.
- **Logic():** Manages the game logic, including movement, collision detection, and score updates.
- **Main():** Contains the game loop, continuously updating the game state until the game ends.

### Running the Game
1. **Compilation:** Compile the code using a C++ compiler.
2. **Execution:** Run the compiled executable.
3. **Gameplay:** Use the specified controls to move the snake, eat fruits, and avoid collisions.
4. **Game Over:** The game ends when the snake collides with the walls or itself. The final score is displayed, and you can exit the game by pressing 'x'.

### Tips
- Try to strategize movements to avoid colliding with walls or the snake's tail.
- Eating fruits increases your score and the snake's length.
- As the snake grows longer, maneuvering becomes more challenging.

Enjoy playing the Snake Game!
