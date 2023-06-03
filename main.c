#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estacionamento.h"
#include "Viatura.h"

#define FLUSH_INPUT() fflush(stdin) /* macro definida com #. serve para criar codigo expansivel. limpa os vestigios de memoria do buffer de leitura */
#define WAIT_ENTER_KEY() while(getchar() != '\n')  /*e uma macro criada para quando o utilizador inserir o enter*/
#define RED(string) "\x1b[31m" string "\x1b[0m" /* macro criada para escrever texto com a cor vermelho */
#define GREEN(string) "\x1b[32m" string "\x1b[0m" /* macro criada para escrever texto com a cor verde */

void menu(char*** parque, int andar, int linha, int coluna, carro* carros, int nr_carros)
{
	
	int opcao;
	char term;
	
	do {
		printf("\n1.LISTAR O PARQUE DE ESTACIONAMENTO");
        printf("\n2.ESTACIONAR O CARRO");
        printf("\n3.LISTA DE CARROS");
        printf("\n4.REMOVER O CARRO");
        printf(RED("\n0.EXIT"));

        printf("\nESCOLHA O QUE PRETENDE FAZER\n");
        
		FLUSH_INPUT();

		/*garantir que é só inserido um numero e o o enter '\n'*/
		if((scanf("%i%c", &opcao, &term) != 2) || term != '\n'){
			system("cls");
			printf(RED("POR FAVOR INSIRE UM VALOR VALIDO \n\n"));
			menu(parque, andar, linha, coluna, carros, nr_carros);
		}
		
		FLUSH_INPUT();
		
        switch(opcao){
            case 1: 
            
            system("cls");
			parque_estacionamento(parque, andar, linha, coluna);
			menu(parque, andar, linha, coluna, carros, nr_carros);
			
			break;
        	
            case 2:
			
			system("cls");
			nr_carros = registar_veiculo(parque, carros, nr_carros, andar, linha, coluna);  /*para atualizar o valor da var do nmr de carros*/
			menu(parque, andar, linha, coluna, carros, nr_carros);
			
		    break;
			            
            case 3: 
						
			system("cls");			
			lista_carros(carros, nr_carros);	
			menu(parque, andar, linha, coluna, carros, nr_carros);		
        	
			break;
			
            case 4: 
            
			system("cls");
			nr_carros = remover_veiculo(parque, carros, nr_carros);  /*para atualizar o valor da var do nmr de carros*/	
			menu(parque, andar, linha, coluna, carros, nr_carros);	
			
			break;

			case 0: 
			
			exit(0);	
			
			break;
			
            default: 
				printf(RED("\n. ! VALOR INVALIDO !"));   
        }

    } while(opcao!=0);
	
}


int main(int argc, char *argv[]) 
{
	tam_parque();
}
