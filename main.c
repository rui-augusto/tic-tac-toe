#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"
#define KEEP_PLAYING 2

void startValues (int*, int*, int*, int*);
void showResult (int);
void showFinalResults (int, int, int);


int main ()
{
    Ttt* tic = structAllocation();
    int endGame;
    int umc, mmc , dc;
    char playAgain;
    do{
        do{
            startValues(&umc, &mmc, &dc, &endGame);
            showBoard(tic);
            getUserMove(tic);
            showBoard(tic);
            if (isBoardFull(tic)){
                endGame = 0;
                dc;
                break;
            }
            else if (isPlayerWinner(tic)){
                endGame = 1;
                umc++;
                break;
            }
            getMachineMove(tic);
            showBoard(tic);
            if (isBoardFull(tic)){
                endGame = 0;
                dc;
                break;
            }
            else if (isMachineWinner(tic)){
                endGame = -1;
                mmc++;
                break;
            }
        } while (endGame == KEEP_PLAYING);
        showBoard(tic);
        showResult(endGame);
        scanf (" %c", &playAgain);
        if (playAgain == 'y' || playAgain == 'Y')        
            structReallocation(tic);
    }while (playAgain == 'y' || playAgain == 'Y');
    showFinalResults(umc, mmc, dc);
    freeAllocation(tic);
    return 0;
}

void startValues (int* umc, int* mmc, int* dc, int* endGame){
    *endGame = KEEP_PLAYING;
    *umc = 0;
    *mmc = 0;
    *dc = 0;
}

void showFinalResults (int umc, int mmc, int dc){
    system ("cls");
    printf ("-> Games played: [%d]\n", umc+mmc+dc);
    printf ("-> Games won: [%d]\n", umc);
    printf ("-> Lost games: [%d]\n", mmc);
    printf ("-> Tied games: [%d]\n", dc);
    printf ("\n\n-> Created by Rui Augusto. Thanks for playing :)\n");
}

void showResult (int endGame){
    if (endGame == 0){
        printf ("\n-> Draw! ");
    }
    else if (endGame == 1){
        printf ("\n-> You won! ");
    }
    else if (endGame == -1){
        printf ("\n-> You loose! ");
    }
    printf ("Do you want to play again?\n");
    printf ("\n-> Press Y for Yes or N for No: ");
}