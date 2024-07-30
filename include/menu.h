#ifndef MENU_H
#define MENU_H

#include "actionsTerminal.h"

void printMenuWithFrame(char bufferStringTerminal[][100], int qtdRownsMenu);
void menu();
void menuLigDeslDisplay();
void menuModoExibicao();
void menuDisplaySpeed();
void menuLigDeslLedOperacao();
void menuLedStatus();
void menuReset();
void menuRgbDisplay(int *element);
void menuBateryLevel(char level[]);
void menuCountDisplayMessages(char qtd[]);
void menuGetTemperature(char temp[]);
void menuSetWordInDisplay();

#endif // MENU_H
