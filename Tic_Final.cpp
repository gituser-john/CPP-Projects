#include <iostream>
#include <cstdlib> // for rand()
using namespace std;

char y[3][3];
int q;

void display() {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << y[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
}

int check() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (y[i][0] == y[i][1] && y[i][0] == y[i][2] && (y[i][0] == 'X' || y[i][0] == 'O'))
            return 1;
        if (y[0][i] == y[1][i] && y[0][i] == y[2][i] && (y[0][i] == 'X' || y[0][i] == 'O'))
            return 1;
    }
    // Check diagonals
    if (y[0][0] == y[1][1] && y[0][0] == y[2][2] && (y[0][0] == 'X' || y[0][0] == 'O'))
        return 1;
    if (y[0][2] == y[1][1] && y[0][2] == y[2][0] && (y[0][2] == 'X' || y[0][2] == 'O'))
        return 1;

    return 0;
}

void add(char x, int a, int b) {
    if (y[a][b] == '-') {
        y[a][b] = x;
    } else {
        cout << "This position is already taken. Choose another.\n";
    }
}

void computerMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (y[row][col] != '-');
    y[row][col] = 'O';
    cout << "Computer placed O at " << row << ", " << col << endl;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            y[i][j] = '-';
        }
    }

    char a;
    int x, b, c, d = 0;
    cout << "Welcome to Tic-Tac-Toe\n";
    cout << "Enter 1 for PvP and 2 for vs Computer: ";
    cin >> x;

    switch (x) {
        case 1:
            do {
                display();
                cout << "P1 (X) Please enter position (row column): ";
                cin >> b >> c;
                if (b < 0 || b > 2 || c < 0 || c > 2) {
                    cout << "Invalid position. Please enter values between 0 and 2.\n";
                    continue;
                }
                add('X', b, c);
                q = check();
                if (q == 1) {
                    display();
                    cout << "P1 wins!\n";
                    break;
                }
                d++;

                if (d == 9) {
                    display();
                    cout << "It's a draw!\n";
                    break;
                }

                display();
                cout << "P2 (O) Please enter position (row column): ";
                cin >> b >> c;
                if (b < 0 || b > 2 || c < 0 || c > 2) {
                    cout << "Invalid position. Please enter values between 0 and 2.\n";
                    continue;
                }
                add('O', b, c);
                q = check();
                if (q == 1) {
                    display();
                    cout << "P2 wins!\n";
                    break;
                }
                d++;
            } while (d < 9 && q == 0);
            cout << "Game over\n";
            break;

        case 2:
            do {
                display();
                cout << "P1 (X) Please enter position (row column): ";
                cin >> b >> c;
                if (b < 0 || b > 2 || c < 0 || c > 2) {
                    cout << "Invalid position. Please enter values between 0 and 2.\n";
                    continue;
                }
                add('X', b, c);
                q = check();
                if (q == 1) {
                    display();
                    cout << "P1 wins!\n";
                    break;
                }
                d++;

                if (d == 9) {
                    display();
                    cout << "It's a draw!\n";
                    break;
                }

                display();
                computerMove();
                q = check();
                if (q == 1) {
                    display();
                    cout << "Computer wins!\n";
                    break;
                }
                d++;
            } while (d < 9 && q == 0);
            cout << "Game over\n";
            break;

        default:
            cout << "Enter a valid choice\n";
            break;
    }

    return 0;
}
