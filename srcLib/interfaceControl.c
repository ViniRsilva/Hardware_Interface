#include "include/interfaceControl.h"

int __attribute__((constructor)) run_initializeRegisters(void) {
    return initializeRegisters();
}

// Function definitions
unsigned int setBit(unsigned int registrador, int bit) {
    return registrador | (0x1 << bit);
}

unsigned int clearBit(unsigned int registrador, int bit) {
    return registrador & ~(0x1 << bit);
}

void setDisplaySpeed(unsigned int speed) {
    unsigned int mascara = (0x77 << 3);
    *hardware.registradores[0] &= ~mascara;
    *hardware.registradores[0] |= (speed << 3);
}

void onOffDisplay(unsigned int mode) {
    *hardware.registradores[0] = mode ? setBit(*hardware.registradores[0], 0) : clearBit(*hardware.registradores[0], 0);
}

void countSlidingDisplayMessages(unsigned int count){
  unsigned int mask = (0xF << 2);
  *hardware.registradores[3] &= ~mask;
  *hardware.registradores[3] |= (count << 2);
}

void setOperationLed(unsigned int mode) {
    *hardware.registradores[0] = mode ? setBit(*hardware.registradores[0], 9) : clearBit(*hardware.registradores[0], 9);
}

void reset(unsigned int mode) {
    *hardware.registradores[0] = mode ? setBit(*hardware.registradores[0], 13) : clearBit(*hardware.registradores[0], 13);
}

void setDisplayMode(unsigned int mode) {
    unsigned int mascara = (0x3 << 1);
    *hardware.registradores[0] &= ~mascara;
    *hardware.registradores[0] |= (mode << 1);
}

void setLedStatus(unsigned int color) {
    unsigned mascara = (0x7 << 10);
    *hardware.registradores[0] &= ~mascara;
    *hardware.registradores[0] |= (0x1 << (9 + color));

    printf("%x", *hardware.registradores[0]);
}

void setRedDisplay(unsigned int redColorIntesive) {
    unsigned int mascara = (0xFF);
    *hardware.registradores[1] &= ~mascara;
    *hardware.registradores[1] |= redColorIntesive;
}

void setGreenDisplay(unsigned int greencolorIntesive) {
    unsigned int mascara = (0xFF << 8);
    *hardware.registradores[1] &= ~mascara;
    *hardware.registradores[1] |= (greencolorIntesive << 8);
}

void setBlueDisplay(unsigned int blueColorIntesive) {
    unsigned int mascara = (0xFF);
    *hardware.registradores[2] &= ~mascara;
    *hardware.registradores[2] |= blueColorIntesive;
}

int getBateryLevel() {
    unsigned int maskValue = (*hardware.registradores[3] & 0x0003);
    int bateryLevel = maskValue;
    return bateryLevel;
}

int getCountSlidingDisplayMessages() {
    unsigned int maskValue = (*hardware.registradores[3] &  0x003C) >> 2;
    int count = maskValue;
    return count;
}

float getTemperature() {
    int16_t maskValue = (*hardware.registradores[3] & 0xFFC0) >> 6;
    //aqui
    if (maskValue & (1 << 9)) {  
        maskValue -= (1 << 10);
    }

    float temperatura = maskValue / 10.0;

    return temperatura;
}

void setLetter(unsigned int letter, unsigned short *registrador, int bitShift) {
    unsigned int mask = (0xFF << bitShift);
    *registrador &= ~mask;
    *registrador |= (letter << bitShift);
}

void setDisplayWord(char word[100]) {
    char letter = ' ';

    int indexRegister = 0, i = 0;
    int bitShift = 0;
    cleanDisplay();
    for (i = 0; i < strlen(word) - 1; i++) {
        letter = word[i];
        bitShift = i % 2 == 0 ? 0 : 8;
        if(i % 2 == 0 && i != 0){
            indexRegister++;
        }
        setLetter(letter, hardware.registradores[4 + indexRegister], bitShift);
    }
}

void cleanDisplay(){
    for (int indexRegister = 0; indexRegister < 12; indexRegister++) {
        *hardware.registradores[4 + indexRegister] = 0x0000;
    }
}

void setDisplayBigWord(char word[100]){
    int tamPart = 24;
    int numParts = strlen(word) / tamPart;

    if (strlen(word) % tamPart != 0) {
        numParts++;  
    }

    char **stringParts = malloc(numParts * sizeof(char *));
    if (stringParts == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < numParts; i++) {
        stringParts[i] = malloc((tamPart + 1) * sizeof(char));  
        if (stringParts[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória para a parte %d.\n", i);
            exit(1);
        }
        
        strncpy(stringParts[i], word + i * tamPart, tamPart);
        stringParts[i][tamPart+1] = '\0';  
    }

    for (int i = 0; i < numParts; i++) {
        int startContOdWord = getCountSlidingDisplayMessages();
        int currentContWord = getCountSlidingDisplayMessages();
        setDisplayWord(stringParts[i]);
        while(startContOdWord == currentContWord){
            currentContWord = getCountSlidingDisplayMessages();
        }
        countSlidingDisplayMessages(getCountSlidingDisplayMessages() - 1);
    }
    setDisplayWord(stringParts[0]);
}
