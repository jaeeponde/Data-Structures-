#include <stdio.h>
#define N 8 //as it's an 8 by 8 chessboard 

int issafe(int board[N][N], int row, int col) {
    int i, j;

    // if there is another queen in the same column, it's under attack
    for (i = 0; i < row; i++)
        if (board[i][col] == 1)  
            return 0;

    // if there is another queen in the upper left diagonal, it's under attack
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)  
            return 0;

     // if there is another queen in the upper right diagonal, it's under attack
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1) 
            return 0;

    return 1; //1 is only returned if the queen is safe
}

void printboard(int board[N][N]) { //printing the 8*8 matrix 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
int solvenqueens(int board[N][N], int row) {
    if (row >= N) {
        printBoard(board);   // print board when a solution is found
        printf("\n");        
        return 1;            // find next solution 
    }

    int count = 0; // store the number of solutions found from this row onward

    for (int col = 0; col < N; col++) { //check for all possible columns 
        if (issafe(board, row, col) == 1) {
            board[row][col] = 1;
            count += solvenqueens(board, row + 1);  // checks for all possible rowise solutions for that column 
            board[row][col] = 0;  // backtrack to find next solution 
        }
    }

    return count;
}

int main() {
    int board[N][N] = {0};  // Initialize all cells to 0

    int solutions = solvenqueens(board, 0);
    printf("Total solutions: %d\n", solutions);

    return 0;
}
