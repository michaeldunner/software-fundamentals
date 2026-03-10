#include <array>
#include <iostream>

void printBoard(std::array<std::array<int, 8>, 8> board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // 1
    // define board
    // all 0s by default
    std::array<std::array<int, 8>, 8> board = {0};

    // define movements from problem
    std::array<int, 8> horizontal{2, 1, -1, -2, -2, -1, 1, 2};
    std::array<int, 8> vertical{-1, -2, -2, -1, 1, 2, 2, 1};

    // define initial position
    int currentRow = 0;
    int currentColumn = 0;

    // make 64 moves
    for (int i = 1; i <= 64; i++) {
        // mark current position
        // if it doesn't = 0 it has already been set and failed to find a move
        if (board[currentRow][currentColumn] != 0) {
            std::cout << "Failed to find a move at move " << i << std::endl;
            break;
        }
        board[currentRow][currentColumn] = i;

        // check which move to make
        for (int j = 0; j < 8; j++) {
            if (currentRow + vertical[j] >= 0 && currentRow + vertical[j] < 8 &&
                currentColumn + horizontal[j] >= 0 &&
                currentColumn + horizontal[j] < 8 &&
                board[currentRow + vertical[j]]
                     [currentColumn + horizontal[j]] == 0) {
                currentRow += vertical[j];
                currentColumn += horizontal[j];
                break;
            }
        }
    }
    printBoard(board);

    // 2
    // array of accesibility
    std::array<std::array<int, 8>, 8> access{
        2, 3, 4, 4, 4, 4, 3, 2, 3, 4, 6, 6, 6, 6, 4, 3, 4, 6, 8, 8, 8, 8,
        6, 4, 4, 6, 8, 8, 8, 8, 6, 4, 4, 6, 8, 8, 8, 8, 6, 4, 4, 6, 8, 8,
        8, 8, 6, 4, 3, 4, 6, 6, 6, 6, 4, 3, 2, 3, 4, 4, 4, 4, 3, 2};

    // reset board and position
    board = {0};
    currentRow = 0;
    currentColumn = 0;

    // new minimum accessibility trackers
    int minimumAccessibility;
    int bestMove;

    // make 64 moves
    for (int i = 1; i <= 64; i++) {
        // mark current position
        // if it doesn't = 0 it has already been set and failed to find a move
        if (board[currentRow][currentColumn] != 0) {
            std::cout << "Failed to find a move at move " << i << std::endl;
            break;
        }
        board[currentRow][currentColumn] = i;

        // board has been set, now change the accessibility of the surrounding
        // squares by 1
        for (int j = 0; j < 8; j++) {
            if (currentRow + vertical[j] >= 0 && currentRow + vertical[j] < 8 &&
                currentColumn + horizontal[j] >= 0 &&
                currentColumn + horizontal[j] < 8) {
                access[currentRow + vertical[j]]
                      [currentColumn + horizontal[j]] -= 1;
            }
        }

        // reset minimum accessibility location higher than any possible
        // accessibility value
        minimumAccessibility = 9;

        // reset best move to something impossible
        bestMove = -1;

        // check which move to make using the accessibility array
        for (int j = 0; j < 8; j++) {
            if (currentRow + vertical[j] >= 0 && currentRow + vertical[j] < 8 &&
                currentColumn + horizontal[j] >= 0 &&
                currentColumn + horizontal[j] < 8 &&
                board[currentRow + vertical[j]]
                     [currentColumn + horizontal[j]] == 0) {
                // move is valid check accessibility
                if (access[currentRow + vertical[j]]
                          [currentColumn + horizontal[j]] <
                    minimumAccessibility) {
                    // change minimum accessibility
                    // save the current j as the best move so far
                    minimumAccessibility =
                        access[currentRow + vertical[j]]
                              [currentColumn + horizontal[j]];
                    bestMove = j;
                }
            }
        }
        // assign after the best location is chosen
        currentRow += vertical[bestMove];
        currentColumn += horizontal[bestMove];
    }
    printBoard(board);
}
