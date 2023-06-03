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

typedef struct
{
	char matricula[10];
	char marca[40];
	int ocupado;  /*flag usado para garantir que o carro tenho um lugar de estacionamento na função registar_veiculo*/
	int andar, linha, coluna;
	time_t tempo_entrada;
	time_t tempo_saida;	 

}carro;


void fatura(char*** parque, carro historico_carro);

int registar_veiculo(char*** parque, carro* carros, int nr_carros, int andar, int linha, int coluna);

bool verificarExistencia(char mat[10], carro* carros, int nr_carros);

int remover_veiculo(char*** parque, carro* carros, int nr_carros);

void lista_carros (carro* carros, int nr_carros);
