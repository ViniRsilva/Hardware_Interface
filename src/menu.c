#include <stdio.h>
#include "../include/menu.h"

void printMenuWithFrame(char bufferStringTerminal[][100], int qtdRownsMenu) {
    /* average count of caracteres for align itens in the x axe */
    centerAxeYTerminal();

    int averageOfCountCaracteres = 0, maxLenghtCaracteres = 0;

    countCharacterLenght(bufferStringTerminal, qtdRownsMenu, &averageOfCountCaracteres, &maxLenghtCaracteres);

    printTopFrame(averageOfCountCaracteres, maxLenghtCaracteres);

    for (int i = 0; i < qtdRownsMenu; i++) {
        printInCenter(bufferStringTerminal[i], averageOfCountCaracteres, maxLenghtCaracteres);
    }
    printBottomFrame(averageOfCountCaracteres, maxLenghtCaracteres);

    centerAxeXTerminal(averageOfCountCaracteres * 2, 0);
}

void menu() {
    char bufferStringTerminal[][100] = {
        {"1-Liga/Desliga display"},
        {"2-Seleciona modo de exibicao"},
        {"3-Velocidade do display"},
        {"4-LED operacao"},
        {"5-Modificar LED Status"},
        {"6-Reset"},
        {"7-Definir RGB do Display"},
        {"8-Definir nivel da bateria"},
        {"9-Definir Quantidade de exibicao da mensagem no display"},
        {"10-Definir Temperatura do dispositivo"},
        {"11-Definir texto do display"}
    };

    printMenuWithFrame(bufferStringTerminal, 11);
}

void menuLigDeslDisplay() {
    char bufferStringTerminal[][100] = {
        {"1-Liga display"},
        {"0-Desliga display"}
    };
    printMenuWithFrame(bufferStringTerminal, 2);
}

void menuModoExibicao() {
    char bufferStringTerminal[][100] = {
        {"0-Exibicao estatica"},
        {"1-Exibicao deslizante"},
        {"2-Exibicao piscante"},
        {"3-Exibicao deslizante/piscante"}
    };
    printMenuWithFrame(bufferStringTerminal, 4);
}

void menuDisplaySpeed() {
    char bufferStringTerminal[][100] = {
        {"Digite a velocidade do display"}
    };
    printMenuWithFrame(bufferStringTerminal, 1);
}

void menuLigDeslLedOperacao() {
    char bufferStringTerminal[][100] = {
        {"1-Liga Led operacao"},
        {"0-Desliga Led operacao"}
    };
    printMenuWithFrame(bufferStringTerminal, 2);
}

void menuLedStatus() {
    char bufferStringTerminal[][100] = {
        {"1-Azul"},
        {"2-Verde"},
        {"3-Vermelho"}
    };
    printMenuWithFrame(bufferStringTerminal, 3);
}

void menuReset() {
    char bufferStringTerminal[][100] = {
        {"1-Reset"}
    };
    printMenuWithFrame(bufferStringTerminal, 1);
}

void menuRgbDisplay(int *element) {
    char bufferStringTerminal[][100] = {
        {"1-Definir o valor do R"},
        {"2-Definir o valor do G"},
        {"3-Definir o valor do B"}
    };

    printMenuWithFrame(bufferStringTerminal, 3);

    printf("Digite o elemento a ser definido: ");
    scanf("%d", element);
}

void menuBateryLevel(char level[]) {
    char _string[40] = {0};
    if(!strcmp(level, "0")){
        sprintf(_string,"Nivel Critico de Bateria");
    }else if(!strcmp(level, "1")){
        sprintf(_string,"Nivel Baixo de Bateria");
    }else if(!strcmp(level, "2")){
        sprintf(_string,"Nivel Medio de Bateria");
    }else if(!strcmp(level, "3")){
        sprintf(_string,"Nivel Alto de Bateria");
    }

    char bufferStringTerminal[1][100] = {0};
    sprintf(bufferStringTerminal[0], "%s" , _string);
    printMenuWithFrame(bufferStringTerminal, 1);

    // printMenuWithFrame(bufferStringTerminal, 4);
}

void menuCountDisplayMessages(char qtd[]) {
    // char bufferStringTerminal[][100] = {
    //     {"Quantidade de vezes a mensagem passou no display: "}
    // };
    char bufferStringTerminal[1][100] = {0};
    // char _string[] = "Quantidade de vezes a mensagem passou no display: ";
    sprintf(bufferStringTerminal[0], "Quantidade de vezes a mensagem passou no display: %s" , qtd);
    printMenuWithFrame(bufferStringTerminal, 1);
}

void menuGetTemperature(char temp[]) {

    char bufferStringTerminal[1][100] = {0};
    // char _string[] = "Setar Temperatura em C";

    sprintf(bufferStringTerminal[0], "Setar Temperatura em C: %sfc" , temp);
    printMenuWithFrame(bufferStringTerminal, 1);
}

void menuSetWordInDisplay() {
    char bufferStringTerminal[][100] = {
        {"Digite a mensagem a ser exibida"}
    };
    printMenuWithFrame(bufferStringTerminal, 1);
}
