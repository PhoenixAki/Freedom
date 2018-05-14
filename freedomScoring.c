#include "freedomScoring.h"

void determineScores(char* boardPassed){
	board = boardPassed;
	int playerOneScore = horizontal('W') + vertical('W') + diagonal('W'); //add up scores for player 1
	int playerTwoScore = horizontal('B') + vertical('B') + diagonal('B'); //add up scores for player 2

	printf("Player 1 score: %d\nPlayer 2 score: %d\n", playerOneScore, playerTwoScore);

	if(playerOneScore > playerTwoScore){
		printf("Player 1 wins!\n");
	}else if(playerOneScore == playerTwoScore){
		printf("Tie!\n");
	}else{
		printf("Player 2 wins!\n");
	}
}

int horizontal(char player){
	int score = 0;

	for(int i = 0; i < 97; ++i){ //once index is at 97, horizontal scores will only be 3 long, so stop checking then
		if(i % 10 == 7){
			i += 3; //horizontal scores can only start from indexes 0-6 of each row
		}

		if(board[i] == player){ //none of this matters if the current space is not the player we are checking for
			if(i % 10 == 0){ //if this is the first column of the row, we only need to check to the right of the score
				if(board[i+1] == player && board[i+2] == player && board[i+3] == player && board[i+4] != player){
					outputScore(player, i, i+3);
					++score;
				}
			}else{
				if(board[i-1] != player && board[i+1] == player && board[i+2] == player && board[i+3] == player && board[i+4] != player){
					outputScore(player, i, i+3);
					++score;
				}
			}
		}
	}

	return score;
}

int vertical(char player){
	int score = 0;

	for(int i = 0; i < 70; ++i){ //once index is at 70, vertical scores can only be 3 long, so stop checking then
		if(board[i] == player){ //none of this matters if the current space is not the player we are checking for

			if(i < 10){ //if in the first row, there is no need to check above
				if(board[i+10] == player && board[i+20] == player && board[i+30] == player && board[i+40] != player){
					outputScore(player, i, i+30);
					++score;
				}
			}else{
				if(board[i-10] != player && board[i+10] == player && board[i+20] == player && board[i+30] == player && board[i+40] != player){
					outputScore(player, i, i+30);
					++score;
				}
			}
		}
	}

	return score;
}

int diagonal(char player){
	int score = 0;

	//down-right
	for(int i = 0; i < 67; ++i){ //once index is at 67, diagonal down-right scores can only be 3 long, so stop checking then
		if(i % 10 == 7){ //diagonal down-right scores can't start after the index ending with 6 of that row
			i += 3;
		}

		if(board[i] == player){ //none of this matters if the current space is not the player we are checking for
			if(i < 11){ //if in the first row (or left column of row 2), there is no need to check above
				if(board[i+11] == player && board[i+22] == player && board[i+33] == player && board[i+44] != player){
					outputScore(player, i, i+33);
					++score;
				}
			}else{
				if(board[i-11] != player && board[i+11] == player && board[i+22] == player && board[i+33] == player && board[i+44] != player){
					outputScore(player, i, i+33);
					++score;
				}
			}
		}
	}

	//down-left
	for(int i = 0; i < 70; ++i){ ///once index is at 70, diagonal down-left scores can only be 3 long, so stop checking then
		if(i % 10 == 0){ //diagonal down-left scores can't start until the 4th column (3rd index) of each line
			i += 3;
		}

		if(board[i] == player){ //none of this matters if the current space is not the player we are checking for
			if(i < 10){ //if in the first row, there is no need to check above
				if(board[i+9] == player && board[i+18] == player && board[i+27] == player && board[i+36] != player){
					outputScore(player, i, i+27);
					++score;
				}
			}else{
				if(board[i-9] != player && board[i+9] == player && board[i+18] == player && board[i+27] == player && board[i+36] != player){
					outputScore(player, i, i+27);
					++score;
				}
			}
		}
	}

	return score;
}

void outputScore(char player, int a, int b){
	printf("Score for player %c found from ", player);
	convertToInput(a);
	printf(" to ");
	convertToInput(b);
	printf("\n");
}