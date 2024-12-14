#include <stdbool.h> 	/* bool, true, false */
#include <stdio.h> 	/* printf() */

#include <utils.h>	/* printBoard() */

void takeTurn(int board[], bool player);

int main(){

	printf("Hello, World!\n");

	int board[9];

	printBoard(board);

	takeTurn(board, false);

	return 0;

}

void takeTurn(int board[], bool player){

	for(int i = 0; i < 9; i++){
		if(board[i] == 0){
			board[i] = (int)player + 1;
			printBoard(board);
			takeTurn(board,!player);
		}
	}

}
