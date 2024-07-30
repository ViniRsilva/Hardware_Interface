#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>


#include "include/registers.h"
#include "include/menu.h"

#define FILE_PATH "registers.bin"

void clearBuffer() {
  char ch;
  do {
    ch = fgetc(stdin);
  } while (ch != '\n' && ch != EOF);
}

int main() {
  // initializeRegisters();

	int action = 0, numMenu = 0;
  menu();
  printf("Digite sua opcao : ");
  scanf("%d", &numMenu);

  clearBuffer();
  clearTerminal();

  switch (numMenu) {
  case 1:
    menuLigDeslDisplay();
    action = 1;
    actionsR0(action);
    break;
  case 2:
    menuModoExibicao();
    action = 2;
    actionsR0(action);
    break;
  case 3:
    menuDisplaySpeed();
    action = 3;
    actionsR0(action);
    break;
  case 4:
    menuLigDeslLedOperacao();
    action = 4;
    actionsR0(action);
    break;
  case 5:
    menuLedStatus();
    action = 5;
    actionsR0(action);
    break;
  case 6:
    menuReset();
    action = 6;
    actionsR0(action);
    break;
  case 7:
    menuRgbDisplay( & action);
    printf("%d\n", action);
    action == 3 ? actionsR2(action) : actionsR1(action);
    break;
  case 8:
    action = 1;
    char level[20] = {0};
    actionsR3(action,level);
    menuBateryLevel(level);
    break;
  case 9:
    action = 2;
    char cont[20] = {0};
    actionsR3(action,cont);
    menuCountDisplayMessages(cont);
    break;
  case 10:
    action = 3;
    char temp[20] ={0};
    actionsR3(action,temp);
    menuGetTemperature(temp);
    break;
  case 11:
    menuSetWordInDisplay();
    setWordInDisplay();
  default:

    break;
  }
}