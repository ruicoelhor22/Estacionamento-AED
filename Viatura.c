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
#define RED(string) "\x1b[31m" string "\x1b[0m" /* macro criada para escrever texto com a cor vermelha */
#define GREEN(string) "\x1b[32m" string "\x1b[0m" /* macro criada para escrever texto com a cor verde */

/*escreve a fatura do respetivo carro removido*/
void fatura(char*** parque, carro historico_carro)
{
	double segundos;
	double horas;
	double preco;	
	
	segundos = difftime(historico_carro.tempo_saida, historico_carro.tempo_entrada);/*diferença de tempo*/
	
	horas = segundos/3600; /* transformo o resultado do diff que é em segundos para horas */
	
	preco = horas * 2.5; /* o preço é 2,5 por hora */
	
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FATURA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	
	printf("\n\n");
		
	printf("\nMatricula: ");
	puts(historico_carro.matricula);
		
	printf("\n");
		
	printf("Marca: ");
	puts(historico_carro.marca);
	
	printf("\n");
	
	printf("__________________________");
	printf("\n");
	printf("| Andar | Linha | Coluna |");
	printf("\n");
	printf("|  %d   |  %d   |   %d   |", historico_carro.andar, historico_carro.linha, historico_carro.coluna);
	printf("\n\n");
	
	printf("O carro este estacionado durante : %f horas", horas);
	
	printf("\n\n");
	
	printf("O preco a pagar e de : %f euros", preco);	
	
	printf("\n\n");
	
	printf("----------------------------");	
	
	printf("\n\n");
	
}

/*esta função serve para criar o veiculo e estaciona-lo*/
int registar_veiculo(char*** parque, carro* carros, int nr_carros, int andar, int linha, int coluna)
{
	nr_carros++;
	int insere_carro = nr_carros - 1;
	char term;
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 REGISTO DE CARRO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

	validacao:
		
	printf("Matricula do carro (xx-xx-xx): ");
	FLUSH_INPUT();
	gets(carros[insere_carro].matricula);
	
	if(carros[insere_carro].matricula[2] != '-' && carros[insere_carro].matricula[5] != '-'){ /*validação do formato da matricula*/
	
		printf(RED("POR FAVOR INSIRA NO FORMATO PEDIDO \n\n"));
		goto validacao;
	}
		
	printf("Marca do carro: ");
	FLUSH_INPUT();
	gets(carros[insere_carro].marca);	
	
	estacionar_novamente: 
	FLUSH_INPUT();  
	 
	while(carros[insere_carro].ocupado != 1)
	{
			carros[insere_carro].ocupado = 0;
			printf("\nESCOLHER O LUGAR DO CARRO");
			
			/*----------------------------------------------------------------------*/
			
			escolher_andar_novamente:
			FLUSH_INPUT();
			
			printf("\nIntroduza o numero do andar que o carro se encontra : ");
			if( scanf("%i%c", &carros[insere_carro].andar, &term) != 2 || term != '\n'){
					system("cls");
					printf(RED("POR FAVOR INSIRA VALORES VALIDOS \n\n"));
					goto estacionar_novamente;
			}
			
			if((carros[insere_carro].andar < 1) || (carros[insere_carro].andar > andar)){ /*validação do lugar para que nao seja negativo nem que nao exista*/
				system("cls");
				printf(RED("POR FAVOR INSIRA O VALOR NOVAMENTE \n\n"));
				goto escolher_andar_novamente;
			}
			
			/*----------------------------------------------------------------------*/
			
			escolher_linha_novamente:
			FLUSH_INPUT();
			
			printf("\nIntroduza o numero da linha em que o carro se encontra : ");
			if( scanf("%i%c", &carros[insere_carro].linha, &term) != 2 || term != '\n'){
				system("cls");
				printf(RED("POR FAVOR INSIRA VALORES VALIDOS \n\n"));
				goto estacionar_novamente;
			}
			
			if((carros[insere_carro].linha < 1) || (carros[insere_carro].linha > linha)){ /*validação do lugar para que nao seja negativo nem que nao exista*/
				system("cls");
				printf(RED("POR FAVOR INSIRA O VALOR NOVAMENTE \n\n"));
				goto escolher_linha_novamente;
			}
	
			/*----------------------------------------------------------------------*/
			
			escolher_coluna_novamente:
			FLUSH_INPUT();
				
			printf("\nIntroduza o numero da coluna em que o carro se encontra : ");
			if( scanf("%i%c", &carros[insere_carro].coluna, &term) != 2 || term != '\n'){
				system("cls");
				printf(RED("POR FAVOR INSIRA VALORES VALIDOS \n\n"));
				goto estacionar_novamente;
				
			}
						
			if((carros[insere_carro].coluna < 1) || (carros[insere_carro].coluna > coluna)){ /*validação do lugar para que nao seja negativo nem que nao exista*/
				system("cls");
				printf(RED("POR FAVOR INSIRA O VALOR NOVAMENTE \n\n"));
				goto escolher_coluna_novamente;
			}

			/*----------------------------------------------------------------------*/
	
			if (parque[carros[insere_carro].andar - 1][carros[insere_carro].linha - 1][carros[insere_carro].coluna - 1] != 'O') /*verificação se o lugar em causa esta ocupado*/
			{
				printf(GREEN("O carro foi estacionado com sucesso! \n"));
				parque[carros[insere_carro].andar - 1][carros[insere_carro].linha - 1][carros[insere_carro].coluna - 1] = 'O'; /*muda o lugar antes livre para ocupado*/
				carros[insere_carro].ocupado = 1;
		
			} else {
		
				printf(RED("O lugar esta ocupado, escolha outro"));
				printf("\n");
				carros[insere_carro].ocupado = 0;
				goto estacionar_novamente;
			}

		time(&carros[insere_carro].tempo_entrada); /*esta a guarda no endereço do carro em causa, o seu tempo de entrada*/
		printf("%s", ctime(&carros[insere_carro].tempo_entrada)); /*escreve o tempo no formato: dia da semana / mês / nmr do dia do mês / horas / minuto / segundo / ano*/
	}
	
	printf("\n\n");
	
	FLUSH_INPUT();
	printf(GREEN("PRIMA ENTER PARA CONTINUAR"));
	WAIT_ENTER_KEY();
	system("cls");
	return nr_carros;
}

/*função do tipo booleano para verficiar a existencia do carro*/
bool verificarExistencia(char mat[10], carro* carros, int nr_carros)
{
    int i;
    for(i=0; i<nr_carros; i++){
        if(strcmp(carros[i].matricula, mat)==0){
            return true;
        }
    }
    return false;
}

/*esta função tem como objetivo remover o veiculo*/
int remover_veiculo(char*** parque, carro* carros, int nr_carros)
{
	char remove_matri[10];
	int j, z;
	carro historico_carro; /*esta var serve para guardar o carro que vai ser removido, para depois ser utilizado na função fatura*/
		
	printf("Insira a matricula do carro que deseja remover : ");
	FLUSH_INPUT();
	gets(remove_matri);
	
	if(verificarExistencia(remove_matri, carros, nr_carros)){
	
		for(j = 0; j < nr_carros; j++) {

			if (strcmp(carros[j].matricula, remove_matri) == 0) {	/*compara as strings e verifica se são iguais*/
				parque[carros[j].andar - 1][carros[j].linha - 1][carros[j].coluna - 1] = 'L';
	
				time(&carros[j].tempo_saida);
				printf("%s", ctime(&carros[j].tempo_saida));
			
				memcpy(&historico_carro, &carros[j], sizeof(carro)); /*copia a celula toda do pointer em questao*/
			
				for(z = j; z < nr_carros - 1; z++) {
					memcpy(&carros[j], &carros[j + 1], sizeof(carro));	/*copia a celula toda do pointer em questao*/
				}
				
			memset(&carros[nr_carros-1],0,sizeof(carros)); /*mete o ultimo carro com todos os valores null*/

			printf("O carro foi removido com sucesso !\n\n");
			
			printf("PRIMA ENTER PARA VER FATURA");
			WAIT_ENTER_KEY();
			system("cls");
			fatura(parque, historico_carro);
			}		
		}

		--nr_carros;
	
		printf(GREEN("PRIMA ENTER PARA CONTINUAR"));
		FLUSH_INPUT();
		WAIT_ENTER_KEY();
		system("cls");
	
	} else {
		
		printf("O CARRO NAO EXISTE\n\n");
		
		printf("PRIMA ENTER PARA CONTINUAR");
		WAIT_ENTER_KEY();
		system("cls");
		
	}
	
	return nr_carros;
}

/*esta função lista todos os carros existentes*/
void lista_carros (carro* carros, int nr_carros) 
{
	int i;
	for (i=0; i <= nr_carros - 1; i++) {
		printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CARRO NUMERO %d \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n", i+1);
		printf("\nMatricula: ");
		puts(carros[i].matricula);
		printf("\nMarca: ");
		puts(carros[i].marca);
		printf("\nEstacionado no andar %i, linha %i, coluna %i. \n\n", carros[i].andar, carros[i].linha, carros[i].coluna);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");
			
	}
	printf(GREEN("PRIMA ENTER PARA CONTINUAR"));
	WAIT_ENTER_KEY();
	system("cls");
}
