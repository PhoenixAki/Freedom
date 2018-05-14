#ifndef FREEDOMSCORING
#define FREEDOMSCORING

#include <stdio.h>
#include <stdbool.h>
#include "freedomMoves.h"

char* board;

void determineScores(char* boardPassed);
int horizontal(char player);
int vertical(char player);
int diagonal(char player);
void outputScore(char player, int a, int b);

#endif