#ifndef INTERFACE_CONTROL_H
#define INTERFACE_CONTROL_H

#include "mapRegisters.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
unsigned int setBit(unsigned int registrador, int bit);
unsigned int clearBit(unsigned int registrador, int bit);
void setDisplaySpeed(unsigned int speed);
void onOffDisplay(unsigned int mode);
void setOperationLed(unsigned int mode);
void reset(unsigned int mode);
void setDisplayMode(unsigned int mode);
void setLedStatus(unsigned int color);
void setRedDisplay(unsigned int redColorIntesive);
void setGreenDisplay(unsigned int greencolorIntesive);
void setBlueDisplay(unsigned int blueColorIntesive);
int getBateryLevel();
int getCountSlidingDisplayMessages();
float getTemperature();
void setLetter(unsigned int letter, unsigned short *registrador, int bitShift);
void setDisplayWord(char word[100]);
void cleanDisplay();
void setDisplayBigWord(char word[100]);
void countSlidingDisplayMessages(unsigned int count);

#endif // INTERFACE_CONTROL_H
