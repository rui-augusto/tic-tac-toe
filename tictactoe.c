#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tictactoe.h"

#define BOARD_SIZE 10
#define USER_POSITION 1
#define MACHINE_POSITION -1

struct t{
    char* board;
    int* valuesBoard;
    int move;
    int mmc; // MACHINE MATCH COUNTER
    int umc; // USER MATCH COUNTER
};

Ttt* structAllocation (){
    Ttt* aux = (Ttt*)malloc(sizeof(Ttt));
    aux->board = (char*) malloc(BOARD_SIZE * sizeof(char));
    for (int i = 1; i < BOARD_SIZE; i++){
        aux->board[i] = 48 + i; // shows the numbers between 1 and 9 in the beginning of the game
    }
    aux->valuesBoard = (int*) calloc(BOARD_SIZE, sizeof(int));
    aux->mmc = 0; aux->umc = 0;
    return aux;
}
void freeAllocation (Ttt* t){
    free (t->board);
    free (t->valuesBoard);
    free (t);
}

void showBoard (Ttt* t){
    system ("cls");
    printf ("           You:  [%d]      Machine:  [%d]  \n\n", t->umc, t->mmc);
    printf ("          |       |       \n");
    printf ("      %c   |   %c   |   %c   \n", t->board[7], t->board[8], t->board[9]);
    printf ("          |       |       \n");
    printf ("   _______|_______|_______\n");
    printf ("          |       |       \n");
    printf ("      %c   |   %c   |   %c   \n", t->board[4], t->board[5], t->board[6]);
    printf ("          |       |       \n");
    printf ("   _______|_______|_______\n");
    printf ("          |       |       \n");
    printf ("      %c   |   %c   |   %c   \n", t->board[1], t->board[2], t->board[3]);
    printf ("          |       |       \n");
    //system("Taskkill/IM cmd.exe");
}

void getUserMove (Ttt* t){
    do{
        printf ("Choose a position: ");
        scanf ("%d", &t->move);
        if (!verifyPosition(t))
            printf ("Please choose a valid position.\n");
    } while (!verifyPosition(t));

    t->board[t->move] = 'X';
    t->valuesBoard[t->move] = USER_POSITION;
}

int verifyPosition (Ttt* t){
    if (t->move >= 1 && t->move <= 9 && t->valuesBoard[t->move] == 0)
        return 1;
    else 
        return 0;
}

int isBoardFull (Ttt* t){
    for (int i = 1; i < BOARD_SIZE; i++){
        if (t->valuesBoard[i] == 0)
            return 0;
    }
    return 1;
}

int isPlayerWinner (Ttt* t){
    if (t->valuesBoard[7] + t->valuesBoard[5] + t->valuesBoard[3] == 3){
        t->umc++;
        return 1;
    }
    else if (t->valuesBoard[1] + t->valuesBoard[5] + t->valuesBoard[9] == 3){
        t->umc++;
        return 1;
    }
    else if (t->valuesBoard[7] + t->valuesBoard[4] + t->valuesBoard[1] == 3){
        t->umc++;
        return 1;
    }
    else if (t->valuesBoard[8] + t->valuesBoard[5] + t->valuesBoard[2] == 3){
        t->umc++;
        return 1;
    }
    else if (t->valuesBoard[9] + t->valuesBoard[6] + t->valuesBoard[3] == 3){
        t->umc++;
        return 1;
    }
    else if (t->valuesBoard[1] + t->valuesBoard[2] + t->valuesBoard[3] == 3){
        t->umc++;
        return 1;
    }
    else if (t->valuesBoard[4] + t->valuesBoard[5] + t->valuesBoard[6] == 3){
        t->umc++;
        return 1;
    }
    else if (t->valuesBoard[7] + t->valuesBoard[8] + t->valuesBoard[9] == 3){
        t->umc++;
        return 1;
    }
    return 0;
}

int isMachineWinner (Ttt* t){
    if (t->valuesBoard[7] + t->valuesBoard[5] + t->valuesBoard[3] == -3){
        t->mmc++;
        return -1;
    }
    else if (t->valuesBoard[1] + t->valuesBoard[5] + t->valuesBoard[9] == -3){
        t->mmc++;
        return -1;
    }
    else if (t->valuesBoard[7] + t->valuesBoard[4] + t->valuesBoard[1] == -3){
        t->mmc++;
        return -1;
    }
    else if (t->valuesBoard[8] + t->valuesBoard[5] + t->valuesBoard[2] == -3){
        t->mmc++;
        return -1;
    }
    else if (t->valuesBoard[9] + t->valuesBoard[6] + t->valuesBoard[3] == -3){
        t->mmc++;
        return -1;
    }
    else if (t->valuesBoard[1] + t->valuesBoard[2] + t->valuesBoard[3] == -3){
        t->mmc++;
        return -1;
    }
    else if (t->valuesBoard[4] + t->valuesBoard[5] + t->valuesBoard[6] == -3){
        t->mmc++;
        return -1;
    }
    else if (t->valuesBoard[7] + t->valuesBoard[8] + t->valuesBoard[9] == -3){
        t->mmc++;
        return -1;
    }
    return 0;
}

int searchPossibilities (Ttt* t){
    if (t->valuesBoard[7] + t->valuesBoard[5] + t->valuesBoard[3] == 2 || t->valuesBoard[7] + t->valuesBoard[5] + t->valuesBoard[3] == -2){
        if (t->valuesBoard[7] == 0)
            return 7;
        else if (t->valuesBoard[5] == 0)
            return 5;
        else if (t->valuesBoard[3] == 0)
            return 3;
    }
    else if (t->valuesBoard[1] + t->valuesBoard[5] + t->valuesBoard[9] == 2 || t->valuesBoard[1] + t->valuesBoard[5] + t->valuesBoard[9] == -2){
        if (t->valuesBoard[1] == 0)
            return 1;
        else if (t->valuesBoard[5] == 0)
            return 5;
        else if (t->valuesBoard[9] == 0)
            return 9;
    }
    else if (t->valuesBoard[7] + t->valuesBoard[4] + t->valuesBoard[1] == 2 || t->valuesBoard[7] + t->valuesBoard[4] + t->valuesBoard[1] == -2){
        if (t->valuesBoard[7] == 0)
            return 7;
        else if (t->valuesBoard[4] == 0)
            return 4;
        else if (t->valuesBoard[1] == 0)
            return 1;
    }
    else if (t->valuesBoard[8] + t->valuesBoard[5] + t->valuesBoard[2] == 2 || t->valuesBoard[8] + t->valuesBoard[5] + t->valuesBoard[2] == -2){
        if (t->valuesBoard[8] == 0)
            return 8;
        else if (t->valuesBoard[5] == 0)
            return 5;
        else if (t->valuesBoard[2] == 0)
            return 2;
    }
    else if (t->valuesBoard[9] + t->valuesBoard[6] + t->valuesBoard[3] == 2 || t->valuesBoard[9] + t->valuesBoard[6] + t->valuesBoard[3] == -2){
        if (t->valuesBoard[9] == 0)
            return 9;
        else if (t->valuesBoard[6] == 0)
            return 6;
        else if (t->valuesBoard[3] == 0)
            return 3;
    }
    else if (t->valuesBoard[1] + t->valuesBoard[2] + t->valuesBoard[3] == 2 || t->valuesBoard[1] + t->valuesBoard[2] + t->valuesBoard[3] == -2){
        if (t->valuesBoard[1] == 0)
            return 1;
        else if (t->valuesBoard[2] == 0)
            return 2;
        else if (t->valuesBoard[3] == 0)
            return 3;
    }
    else if (t->valuesBoard[4] + t->valuesBoard[5] + t->valuesBoard[6] == 2 || t->valuesBoard[4] + t->valuesBoard[5] + t->valuesBoard[6] == -2){
        if (t->valuesBoard[4] == 0)
            return 4;
        else if (t->valuesBoard[5] == 0)
            return 5;
        else if (t->valuesBoard[6] == 0)
            return 6;
    }
    else if (t->valuesBoard[7] + t->valuesBoard[8] + t->valuesBoard[9] == 2 || t->valuesBoard[7] + t->valuesBoard[8] + t->valuesBoard[9] == -2){
        if (t->valuesBoard[7] == 0)
            return 7;
        else if (t->valuesBoard[8] == 0)
            return 8;
        else if (t->valuesBoard[9] == 0)
            return 9;
    }
    return 0;
}

void getMachineMove (Ttt* t){
    t->move = searchPossibilities(t);
    if (t->move == 0){
        srand(time(NULL));
        do{
            printf ("eh aqui\n");
            t->move = rand () % 9 + 1; // getting numbers between 1 and 9
        } while (t->valuesBoard[t->move] != 0);
    }
    t->board[t->move] = 'O';
    t->valuesBoard[t->move] = -1;
}

void structReallocation (Ttt* t){
    for (int i = 0; i < BOARD_SIZE; i++){
        t->valuesBoard[i] = 0;
        t->board[i] = 48 + i;
    }
}