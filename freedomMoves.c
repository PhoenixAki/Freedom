#include "freedomMoves.h"

int indexCount = 0; //keeps track of how many elements are in the array of valid indexes for moves
int lastMoveIndex = 100; //keeps track of the last successful move index, initializes to 100 for comparison purposes, is reset to 100 if the player has "Freedom" to place a piece where they want

bool playerMove(char* passedBoard, int playerTurn, char input[]){
	board = passedBoard;
	int columnAscii = input[0], rowAscii = input[1]; //store the ascii values of current input for validation

	if(columnAscii < 65 || columnAscii > 74 || rowAscii < 48 || rowAscii > 57){ //checking if first input space is not capital letter A-J
		printf("Invalid input format. Available moves are:");
		printAvailableMoves();
		return false;
	}else{
		int index = convertToIndex(rowAscii, columnAscii); //convert current input into an array index

		if(lastMoveIndex == 100){ //lastMoveIndex is set to 100 when the player can place a piece wherever, so no move validation is required
			board[index] = (playerTurn == 1) ? 'W' : 'B';
			lastMoveIndex = index;
			printf("Player %d has made their move.\nAvailable next moves are:", playerTurn);
			printAvailableMoves();
		}else{
			int* validIndexes = getAvailableIndexes(); //check what indexes are valid based on the most recent move
			bool validChoice = false; //remains false unless one of the available indexes matches the current choice

			for(int i = 0; i < indexCount; ++i){
				if(validIndexes[i] == index){
					validChoice = true;
					break;
				}
			}

			if(validChoice){
				board[index] = (playerTurn == 1) ? 'W' : 'B';
				lastMoveIndex = index;
				printf("Player %d has made their move. Available next moves are:", playerTurn);
				printAvailableMoves();
			}else{
				printf("Invalid choice - available moves are:");
				printAvailableMoves();
				return false;
			}
		}
		return true;
	}
}

int convertToIndex(int row, int column){
	int indexRow = 9-(row-48), indexColumn = column-65;
	return 10*indexRow + indexColumn;
}

void convertToInput(int index){
	char input[2];
	char letters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	input[0] = letters[(index % 10)];//column
	input[1] = 9 - (index/10);//row

	printf("%c%d", input[0], input[1]);
}

int* getAvailableIndexes(){
	int* indexes = calloc(8, sizeof(int)); //calloc to keep reference to the available indexes from playerMove when done here
	indexCount = 0;

	//This is quite ugly looking, but it gets the job done - initial attempt at this was over 3x as long and much more repetitive
	if(lastMoveIndex > 9 && lastMoveIndex % 10 != 0 && board[lastMoveIndex-11] == ' '){ //diagonal up left
		indexes[indexCount] = lastMoveIndex-11;
		++indexCount;
	}
	if(lastMoveIndex > 9 && board[lastMoveIndex-10] == ' '){ //directly up
		indexes[indexCount] = lastMoveIndex-10;
		++indexCount;
	}
	if(lastMoveIndex > 9 && lastMoveIndex % 10 != 9 && board[lastMoveIndex-9] == ' '){ //diagonal up right
		indexes[indexCount] = lastMoveIndex-9;
		++indexCount;
	}
	if(lastMoveIndex % 10 != 0 && board[lastMoveIndex-1] == ' '){ //directly left
		indexes[indexCount] = lastMoveIndex-1;
		++indexCount;
	}
	if(lastMoveIndex % 10 != 9 && board[lastMoveIndex+1] == ' '){ //directly right
		indexes[indexCount] = lastMoveIndex+1;
		++indexCount;
	}
	if(lastMoveIndex < 90 && lastMoveIndex %10 != 0 && board[lastMoveIndex+9] == ' '){ //diagonal down left
		indexes[indexCount] = lastMoveIndex+9;
		++indexCount;
	}
	if(lastMoveIndex < 90 && board[lastMoveIndex+10] == ' '){ //directly down
		indexes[indexCount] = lastMoveIndex+10;
		++indexCount;
	}	
	if(lastMoveIndex < 90 && lastMoveIndex %10 != 9 && board[lastMoveIndex+11] == ' '){ //diagonal down right
		indexes[indexCount] = lastMoveIndex+11;
		++indexCount;
	}

	return indexes;
}

void printAvailableMoves(){
	int* availableMoves = getAvailableIndexes();

	if(indexCount == 0){
		printf(" Freedom! Next move can be anywhere on the board that is not filled yet.\n");
		lastMoveIndex = 100;
		return;
	}else{
		printf(" [");
	}

	for(int i = 0; i < indexCount; ++i){
		convertToInput(availableMoves[i]);
		i == indexCount-1 ? printf("]\n") : printf(", ");
	}
}

bool checkBoard(){
	for(int i = 0; i < 100; ++i){
		if(board[i] == ' '){
			return false;
		}
	}

	return true;
}