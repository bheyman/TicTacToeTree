#include <stdbool.h> 	/* bool, true, false */
#include <stdio.h> 	/* printf() */
#include <stdlib.h>	/* calloc() */

#include <utils.h>	/* checkWinner(), copyBoard(), printBoard() */

void takeTurn(int *board, bool player);

int counter = 0;

int main(){

	printf("Hello, World!\n");

	int *board;
	board = (int *) calloc(9, sizeof(int));

	printBoard(board);

	takeTurn(board, false);

	free(board);

	printf("%d\n", counter);
	return 0;

}

void takeTurn(int *board, bool player){

	int *boardCopy;
	boardCopy = (int *) malloc(9*sizeof(int));

	copyBoard(board, boardCopy);

	for(int i = 0; i < 9; i++){
		if(boardCopy[i] == 0){
			boardCopy[i] = (int)player + 1;
			printBoard(boardCopy);
			if(!checkWinner(boardCopy)){
				takeTurn(boardCopy,!player);
			}else{
				counter++;
			}
			boardCopy[i] = 0;
		}
	}

	free(boardCopy);

}
