#ifndef actionsTerminal_H
#define actionsTerminal_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <string.h>


/* System UNIX or WIN */
#ifdef __unix__
    #define c "clear"
#elif defined(_WIN32) || defined(WIN32)
    #define c "cls"
#endif

void printFrameLastWall(int averageOfCountCaracteres , int leghtStrToPrint, int maxLeghtStrToPrint);
void countCharacterLenght(char contentTerminal[][100] ,int lenght, int *averageLenght, int *max);
void clearTerminal();
void centerAxeYTerminal();
void centerAxeXTerminal(int lenght, int putFrameWall);
void printInCenter(char textToPrint[], int averageOfCountCaracteres, int maxLenghtCaracteres);

/*Print Frame*/
void putLineFrame(int averageOfCountCaracteres, int maxLenghtCaracteres);
void printTopFrame(int averageOfCountCaracteres, int maxLenghtCaracteres);
void printBottomFrame(int averageOfCountCaracteres, int maxLenghtCaracteres);

#endif /* actionsTerminal_H */
