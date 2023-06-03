#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLUSH_INPUT() fflush(stdin) /* macro definida com #. serve para criar codigo expansivel. limpa os vestigios de memoria do buffer de leitura */
#define WAIT_ENTER_KEY() while(getchar() != '\n')  /*e uma macro criada para quando o utilizador inserir o enter*/
#define RED(string) "\x1b[31m" string "\x1b[0m" /* macro criada para escrever texto com a cor vermelha */
#define GREEN(string) "\x1b[32m" string "\x1b[0m" /* macro criada para escrever texto com a cor verde */

void parque_estacionamento(char*** parque, int andar, int linha, int coluna);

void tam_parque();
