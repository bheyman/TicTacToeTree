#include <stdbool.h> 	/* bool, true, false */
#include <stdio.h> 	/* printf() */
#include <stdlib.h>	/* calloc() */

#include <utils.h>	/* checkWinner(), copyBoard(), printBoard() */

struct boardState{
	int *board;			// 3x3 State of Board
	bool winner;			// Is this a winning state?
	struct boardState *nextMove;	// List of next turn boardStates
};

struct turnHeader{
	int count;			// How many boards
	struct boardState *boards;	// List of boardStates
};

void takeTurn(int *board, int turnNum);
void printTurn(struct turnHeader turn);

// HEADER FOR EACH TURN
struct turnHeader turns[10];

int main(){

	printf("Generating TicTacToeTree...\n\n");

	//INITIALIZE HEADER TO ZERO BOARDS
	for(int i = 0; i < 10; i++){
		turns[i].count = 0;
		turns[i].boards = (struct boardState *)malloc(turns[i].count*sizeof(struct boardState));
	}

	// TURN ZERO HAS ONE BOARD
	turns[0].count = 1;
	turns[0].boards = (struct boardState *)realloc(turns[0].boards,turns[0].count*sizeof(struct boardState));

	// INITIALIZE TURN ZERO BOARD
	turns[0].boards[0].winner = false;
	turns[0].boards[0].board = (int *)calloc(9,sizeof(int));
	
	takeTurn(turns[0].boards[0].board, 1);

	// FOR EACH TURN
	for(int i = 0; i < 10; i++){
		printf("Turn %02d (%d)\n\n", i,turns[i].count);
		printTurn(turns[i]);
	}

	return 0;

}

void takeTurn(int *board, int turnNum){

	// LOCAL COPY OF THE STARTING BOARD
	int *boardCopy;
	boardCopy = (int *) malloc(9*sizeof(int));

	// COPY STARTING BOARD
	copyBoard(board, boardCopy);

	// FOR EACH SPACE ON BOARD
	for(int i = 0; i < 9; i++){

		// IF SPACE IS EMPTY
		if(boardCopy[i] == 0){
		
			// PLACE IN THAT SPACE
			boardCopy[i] = (turnNum%2) ? 1 : 2;
	
			// CHECK IF THIS BOARD HAS BEEN SEEN
			bool skip = false;
			for(int j = 0; j < turns[turnNum].count; j++){
				skip = skip | compareBoard(turns[turnNum].boards[j].board, boardCopy);
			}

			// IF THIS IS A NEW BOARD
			if(!skip){

				// INCREMENT TURN COUNT, REALLOC
				turns[turnNum].count++;
				turns[turnNum].boards = (struct boardState *)realloc(turns[turnNum].boards,turns[turnNum].count*sizeof(struct boardState));

				// ADD NEW BOARD STATE
				turns[turnNum].boards[turns[turnNum].count-1].board = (int *) malloc(9*sizeof(int));
				copyBoard(boardCopy, turns[turnNum].boards[turns[turnNum].count-1].board);
				turns[turnNum].boards[turns[turnNum].count-1].winner = checkWinner(turns[turnNum].boards[turns[turnNum].count-1].board);

				// IF THE GAME IS NOT OVER, TAKE NEXT TURN
				if(!turns[turnNum].boards[turns[turnNum].count-1].winner){
					takeTurn(boardCopy, turnNum+1);
				}
			}

			// UNDO MOVE
			boardCopy[i] = 0;
		}
	}

	free(boardCopy);

}

void printTurn(struct turnHeader turn){

	// FOR EACH ROW
	for(int i = 0; i < 3; i++){
	
		// FOR EACH BOARD
		for(int j = 0; j < turn.count; j++){
		
			printf("%c|%c|%c\t", 
				(turn.boards[j].board[i*3+0] == 0) ? ' ' : (turn.boards[j].board[i*3+0] == 1) ? 'X' : (turn.boards[j].board[i*3+0] == 2) ? 'O' : '?', 
				(turn.boards[j].board[i*3+1] == 0) ? ' ' : (turn.boards[j].board[i*3+1] == 1) ? 'X' : (turn.boards[j].board[i*3+1] == 2) ? 'O' : '?', 
				(turn.boards[j].board[i*3+2] == 0) ? ' ' : (turn.boards[j].board[i*3+2] == 1) ? 'X' : (turn.boards[j].board[i*3+2] == 2) ? 'O' : '?'
			);	
		}
		printf("\n");
			
		if(i!=2){
			for(int j = 0; j < turn.count; j++){
				printf("-----\t");
			}
			printf("\n");
		}

	}

	printf("\n");

}
