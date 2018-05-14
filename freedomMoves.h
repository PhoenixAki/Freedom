#ifndef FREEDOMMOVES
#define FREEDOMMOVES

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* board;

bool playerMove(char* board, int playerTurn, char input[]);
int convertToIndex(int row, int column);
void convertToInput(int index);
void printAvailableMoves();
int* getAvailableIndexes();
bool checkBoard();

#endif