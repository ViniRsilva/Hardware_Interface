#include "../include/registers.h"
#include "../include/interfaceControl.h"

void actionsR0(int action) {
  unsigned int actionValue;

  printf("Digite sua opcao : ");
  scanf("%d", & actionValue);

  switch (action) {
  case 1:
    onOffDisplay(actionValue);
    break;
  case 2:
    setDisplayMode(actionValue);
  case 3:
    setDisplaySpeed(actionValue);
    break;
  case 4:
    setOperationLed(actionValue);
    break;
  case 5:
    setLedStatus(actionValue);
    break;
  case 6:
    reset(actionValue);
    break;
  }

}

void actionsR1(int action) {
  unsigned int colorValue;

  char colors[][9] = { {"Vermelho"},{"Verde"}, {"Azul"} };

  printf("Digite um valor para a %s do display : ", colors[action - 1]);
  scanf("%d", & colorValue);

  switch (action) {
  case 1:
    setRedDisplay(colorValue);
    break;
  case 2:
    setGreenDisplay(colorValue);
    break;
  }
}

void actionsR2(int action) {
  unsigned int colorValue;

  char colors[][9] = { {"Vermelho"},{"Verde"}, {"Azul"} };

  printf("Digite um valor para a %s do display : ", colors[action - 1]);
  scanf("%d", & colorValue);

  switch (action) {
  case 3:
    setBlueDisplay(colorValue);
    break;
  }
}

void actionsR3(int action, char *result) {
    unsigned int actionValue = action;
    int _result;

    switch(action) {
        case 1:
            _result = getBateryLevel(actionValue);
            sprintf(result, "%d", _result);
            break;
        case 2: 
            _result = getCountSlidingDisplayMessages(actionValue);
            sprintf(result, "%d", _result);
            break;
        case 3:
            float _resultf = getTemperature(actionValue);
            sprintf(result, "%.2f", _resultf);
            break;
        default:
            sprintf(result, "Invalid action");
            break;
    }
}

void setWordInDisplay() {
    char word[100];
    printf("Digite uma palavra: ");
    fgets(word, sizeof(word), stdin); //  Limita a leitura para no máximo 99 caracteres
    int tam = strlen(word);
    // printf("tamnho = %d", i);
    // Garante que a string esteja terminada com '\0' após o último caractere válido
    // word[strlen(word)] = '\0'
    // if (word[strlen(word) - 1] == '\n') {
    //     word[strlen(word) - 1] = '\0';
    // }
    if(tam > 24){
      setDisplayBigWord(word);
    }else{
      setDisplayWord(word);
    }
}