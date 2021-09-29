#include <iostream>
using namespace std;

const int N = 8;

void showBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool posCheck(int board[N][N], int row, int col) {
    int i, j;

    //check left side
    for (i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }
    //check top-left 
    i = row - 1;
    j = col - 1;
    while(i >= 0 && j >= 0) {
        if(board[i][j] == 1) return false;
        i--;
        j--;
    }
    //check bottom-left
    i = row + 1;
    j = col - 1;
    while (i < N && j >= 0) {
        if (board[i][j] == 1) return false;
        i++;
        j--;
    }
    
    return true;
}

bool putQueen(int board[N][N], int col) {
    int i, j;
    
    if (col < N) {
        for (i = 0; i < N; i++) {
            if (posCheck(board, i, col)) {
                board[i][col] = 1;
                if (putQueen(board, col + 1)) return true;
                board[i][col] = 0;
            }
        }
    }
    else if (col == N) return true;
    
    return false;
}

int main() {
    int board[N][N];

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    showBoard(board);
    cout << endl;

    putQueen(board, 0);

    showBoard(board);


    return 0;
}