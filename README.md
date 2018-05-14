# Freedom
## Purpose
This was a project assignment in a programming class Spring 2018. The goal was to emulate a board game titled "Freedom", which plays similarly to a Connect 4-esque game. The 2 players use a 10x10 board with the goal of gaining points by having rows/columns/diagonals of *exactly* 4 pieces in length (not longer or shorter, else it doesn't count). The players take turns placing pieces on the board, but can *only* place a piece directly adjacent to the most recent piece. If this can not be done, the next player can choose anywhere on the board and the process starts again. When the board is full, the game ends and scores are calculated.

This was a very fun game to program and I'm quite happy with how the code functions. The game begins by initializing a board that will be output after every move. There are separate files that handle the functions related to moving pieces, scoring, and running the main game. 
## How to Run
Simply compile **freedomGame.c, freedomMoves.h, freedomMoves.c, freedomScoring.h, and freedomScoring.c** using a standard C compiler like Gcc, and run the output .exe file :)
