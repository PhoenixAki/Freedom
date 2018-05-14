#include "freedomMoves.h"
#include "freedomScoring.h"
#include <string.h>

char* setupBoard(){
	char* board = calloc(1, sizeof(char[10][10]));

	memset(board, ' ', 100);
	return board;
}

void printBoard(char* board){

	char letters[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //for use when printing the bottom row of the board

	for(int topRow = 0; topRow < 10; ++topRow){
		printf("--");
	}

	printf("--\n");

	for(int row = 0; row < 10; ++row){
		printf("%d%s", 9-row, "|");
		for(int column = 0; column < 10; ++column){
			printf("%c|", board[10*row + column]);
		}
		printf("\n");
	}

	for(int bottomDashes = 0; bottomDashes < 10; ++bottomDashes){
		printf("--");
	}

	printf("--\n |");

	for(int bottomRow = 0; bottomRow < 10; ++bottomRow){
		printf("%c ", letters[bottomRow]);
	}

	printf("\n\n");
}

int main(){	
	printf("Initializing game board.\n");
	char* board = setupBoard();
	printf("Game board initialized.\n");
	printBoard(board);

	//main game loop: accept inputs and pass to playerMove for verification and placement
	bool gameDone = false;
	char input[100];
	int playerTurn = 1; //1 = player one, 2 = player two

	while(!gameDone){
		memset(input, ' ', 100); //clear input array of any previous values

		printf("Select space in letter-number format (for example, A2 or D6): ");
		fgets(input, 100, stdin);

		if(input[0] == 'x'){ //cheat to test scoring early without needing to fill in all 100 spaces
			determineScores(board);
		}else{
			if(playerMove(board, playerTurn, input)){ //attempt to place a piece, if successful then it's the next player's turn
				playerTurn = (playerTurn == 1) ? 2 : 1;
			}

			printBoard(board);

			if(checkBoard()){ //check for game end condition (if the board is completely filled)
				gameDone = true;
			}
		}
	}

	determineScores(board);
	printf("Game over - thanks for playing!");
	free(board);
}