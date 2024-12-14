#include <stdbool.h>	/* bool, false, true */
#include <stdio.h>	/* printf() */

#include <utils.h>

void printBoard(int board[]){

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
