#ifndef tictactoe_h
#define tictactoe_h

typedef struct t Ttt;

Ttt* structAllocation ();
void freeAllocation (Ttt*);
void showBoard (Ttt*);
void getUserMove (Ttt*);
int verifyPosition (Ttt*);
int isBoardFull (Ttt*);
int isPlayerWinner (Ttt*);
int isMachineWinner (Ttt*);
int searchPossibilities (Ttt* t);
void getMachineMove (Ttt*);
void structReallocation (Ttt*);

#endif /* tictactoe_h */
