#include <stdbool.h>	/* bool, false, true */
#include <stdio.h>	/* printf() */

#include <utils.h>

bool checkWinner(int *board){

	bool winner = false;

	//HORIZONTAL LINES
	winner = winner | ((board[0] == board[1]) && (board[1] == board[2]) && ((board[0] == 1) || (board[0] == 2)));
	winner = winner | ((board[3] == board[4]) && (board[4] == board[5]) && ((board[3] == 1) || (board[3] == 2)));
	winner = winner | ((board[6] == board[7]) && (board[7] == board[8]) && ((board[6] == 1) || (board[6] == 2)));

	//VERTICAL LINES	
	winner = winner | ((board[0] == board[3]) && (board[3] == board[6]) && ((board[0] == 1) || (board[0] == 2)));
	winner = winner | ((board[1] == board[4]) && (board[4] == board[7]) && ((board[1] == 1) || (board[1] == 2)));
	winner = winner | ((board[2] == board[5]) && (board[5] == board[8]) && ((board[2] == 1) || (board[2] == 2)));

	//DIAGONAL LINES
	winner = winner | ((board[0] == board[4]) && (board[4] == board[8]) && ((board[0] == 1) || (board[0] == 2)));
	winner = winner | ((board[2] == board[4]) && (board[4] == board[6]) && ((board[2] == 1) || (board[2] == 2)));

	return winner;

}

void copyBoard(int *board, int *boardCopy){

	for(int i = 0; i < 9; i++){
		boardCopy[i] = board[i];
	}

}

void printBoard(int *board){

	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			if(board[i*3+j]==0){
				printf(" ");
			}else if(board[i*3+j]==1){
				printf("X");
			}else if(board[i*3+j]==2){
				printf("O");
			}else{
				printf("?");
			}
			
			if(j!=2){
				printf("|");
			}
		}
		printf("\n");
		if(i!=2){
			printf("-----");
		}
		printf("\n");

	}
}