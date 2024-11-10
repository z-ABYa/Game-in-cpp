#include <ncurses.h> // Include ncurses for macOS/Linux

const int WIDTH = 20; // Width of grid
const int HEIGHT = 10; // Height of grid

void drawGrid(int x, int y) {
    clear(); // Clears the screen

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == y && j == x) {
                mvprintw(i, j, "."); // Print the pointer at (x, y)
            } else {
                mvprintw(i, j, " "); // Print empty space
            }
        }
    }
    refresh(); // Refresh the screen to show changes
}

int main() {
    int x = WIDTH / 2; // Starting X position
    int y = HEIGHT / 2; // Starting Y position

    initscr(); // Initialize ncurses mode
    noecho(); // Don't print input characters
    curs_set(0); // Hide the cursor
    keypad(stdscr, TRUE); // Enable arrow keys
    nodelay(stdscr, TRUE); // Non-blocking input

    while (true) {
        drawGrid(x, y); // Draw the grid with the pointer

        int ch = getch(); // Get input

        switch (ch) {
            case KEY_UP: y = (y > 0) ? y - 1 : y; break; // Up arrow
            case KEY_DOWN: y = (y < HEIGHT - 1) ? y + 1 : y; break; // Down arrow
            case KEY_LEFT: x = (x > 0) ? x - 1 : x; break; // Left arrow
            case KEY_RIGHT: x = (x < WIDTH - 1) ? x + 1 : x; break; // Right arrow
            case 'q': goto end; // Exit if 'q' is pressed
        }

        napms(1); // Delay for smoother movement
    }

end:
    endwin(); // End ncurses mode
    return 0;
}