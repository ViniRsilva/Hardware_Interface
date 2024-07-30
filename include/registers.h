#ifndef REGISTERS_H
#define REGISTERS_H

#include "interfaceControl.h"
#include <string.h>

void actionsR0(int action);
void actionsR1(int action);
void actionsR2(int action);
void actionsR3(int action, char *result);
void setWordInDisplay();

#endif // REGISTERS_H


