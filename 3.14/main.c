#include <stdio.h>
#define n 5
int row[] =    { 2, 1,-1,-2,-2,-1, 1, 2, 2};
int column[] = { 1, 2, 2, 1,-1,-2,-2,-1, 1};
void knight_tour(int chess_board_place[n][n], int x, int y, int move, int * possible_solutions);
int validate_move(int new_x,int new_y);
int main() {
    //chess_board_place matrix will hold the path made by the knight
    //each place in this matrix will store the move nr k made by the knight
    int chess_board_place[n][n],possible_solutions = 0;
    //setting chess board places to zero
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            chess_board_place[i][j] = 0;
        }
    }
    int move = 1;
    //starting from the upper left corner
    knight_tour(chess_board_place,0,0,move,&possible_solutions);
    //printing all possible solutions
    printf("The number of possible solutions is: %d",possible_solutions);
    return 0;
}
int validate_move(int new_x,int new_y){
    //checking if the new position is on the board
    if(new_x>=0 && new_x<n && new_y>=0 && new_y<n) return 1;
    return 0;
}
void knight_tour(int chess_board_place[n][n], int x, int y, int move, int * possible_solutions){
    chess_board_place[x][y] = move;
    //printing the solution when found
    if (move>=n*n){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                printf("%d ", chess_board_place[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        //adding solution
        (*possible_solutions)++;
        //backtrack
        chess_board_place[x][y] = 0;
        return;
    }
    //checking all the possible 8 moves and recur when a valid one is found
    for(int k=0;k<8;k++){
        int new_x = x + row[k];
        int new_y = y + column[k];
        if(validate_move(new_x,new_y) && !chess_board_place[new_x][new_y]){
            knight_tour(chess_board_place, new_x, new_y, move + 1, possible_solutions);
        }
    }
    //backtrack
    chess_board_place[x][y] = 0;
}