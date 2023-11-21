// Designed by 🍋Lemon in California

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int width = 20;  // Width of the game area
const int height = 20;  // Height of the game area
bool gameOver;  // Indicates whether the game is over or ongoing
int x, y, fruitX, fruitY, score;  // Coordinates and score variables
int tailX[100], tailY[100];  // Arrays to store tail coordinates
int nTail;  // Length of the tail
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };  // Enum for directions
eDirection dir;  // Current direction of the snake

void Setup() {
    gameOver = false;  // Initialize game state
    dir = STOP;  // Set initial direction to STOP
    x = width / 2;  // Initial X coordinate of the snake
    y = height / 2;  // Initial Y coordinate of the snake
    fruitX = rand() % width;  // Random X coordinate of the fruit
    fruitY = rand() % height;  // Random Y coordinate of the fruit
    score = 0;  // Initialize score to zero
}

void Draw() {
    system("clear");  // Clear the console screen

    // Draw the top wall of the game area
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Draw the game area, snake, fruit, and tail
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Draw side walls of the game area
            if (j == 0 || j == width - 1)
                cout << "#";
            // Draw the snake's head
            if (i == y && j == x)
                cout << "O";
            // Draw the fruit
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                // Check and draw the snake's tail segments
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        printTail = true;
                    }
                }
                // If not drawing tail, draw an empty space
                if (!printTail)
                    cout << " ";
            }
        }
        cout << endl;  // Move to the next line after drawing each row
    }

    // Draw the bottom wall of the game area
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << score << endl;  // Display the current score
}

void Input() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);  // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Change settings for reading input
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Apply new terminal settings

    char input;
    if (read(STDIN_FILENO, &input, 1) < 0)  // Read a single character input
        gameOver = true;  // Set game over if reading input fails

    // Update direction based on user input
    switch (input) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;  // Set game over if 'x' is pressed
            break;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore original terminal settings
}


void Logic() {
    // Logic to move the tail along with the head
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
 // Update snake's position based on the current direction
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
// Check for collisions with walls or itself
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
 // Increase score and reset fruit position when snake eats the fruit
    if (x >= width || x < 0 || y >= height || y < 0)
        gameOver = true;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));  // Seed random number generator
    Setup();  // Initialize game

    // Game loop
    while (!gameOver) {
        Draw();  // Draw the game
        Input();  // Get user input
        Logic();  // Update game logic
        usleep(100000); // Adjust game speed (microseconds)
    }

    cout << "Game Over!" << endl;  // Display game over message
    return 0;  // Return 0 to indicate successful completion
}
