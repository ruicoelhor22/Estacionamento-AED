#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estacionamento.h"
#include "Viatura.h"

#define FLUSH_INPUT() fflush(stdin) /* macro definida com #. serve para criar codigo expansivel. limpa os vestigios de memoria do buffer de leitura */
#define WAIT_ENTER_KEY() while(getchar() != '\n')  /* e uma macro criada para quando o utilizador inserir o enter */
#define RED(string) "\x1b[31m" string "\x1b[0m" /* macro criada para escrever texto com a cor vermelha */
#define GREEN(string) "\x1b[32m" string "\x1b[0m" /* macro criada para escrever texto com a cor verde */



/*imprimir cada lugar do parque de estacionamento*/
void parque_estacionamento(char*** parque, int andar, int linha, int coluna)
{
	int ca, cl, cc; /*contadores para andar e setor*/

	for (ca = 0; ca < andar; ca++) 
	{
		printf("PISO %d\n\n", ca + 1);
		
		for (cl = 0; cl < linha; cl++) 
		{
			for (cc = 0; cc < coluna; cc++) 
			{
				printf(" %c ", parque[ca][cl][cc]);
			}
			printf("\n");
		}
		
	printf("\n\n\n");
	}

	printf("\n\n");
	printf(GREEN("PRIMA ENTER PARA CONTINUAR"));
	WAIT_ENTER_KEY();
	system("cls");
}			


/*o primeiro processo que cria o parque*/	
void tam_parque()
{	

	int nr_carros = 0; /*o nr_carros é para pecorrer o array de carros*/
	int andar, linha, coluna, total; 
	unsigned int ca, cl, cc; /* unsigned é uma garantia que as vars são sempre positivas contadores para andar e setor*/
	char term; /*var usada para a validação de input*/
	char*** parque;  /* pointer tri-dimensional*/
	carro* carros; /*pointer uni-dimensional*/

	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENU DO SISTEMA PARQUE DE ESTACIONAMENTO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\nDEFINIR O TAMANHO DO PARQUE");
	
	/*-----------------------------------------------------------*/

	piso:
	FLUSH_INPUT();
	printf("\nIntroduza o numero de andares que o parque tem: ");

	/*garantir que é só inserido um numero e o o enter '\n'*/
	if(scanf("%i%c", &andar, &term) != 2 || term != '\n' ){
		system("cls");
		printf(RED("POR FAVOR INSIRA VALORES VALIDOS \n\n"));
		goto piso;	
	}
	
	/*verificar se o valor inserido é positivo*/
	if(andar < 1){
		system("cls");
		printf(RED("INSIRA UM VALOR VALIDO"));
		goto piso;
	}

	/*-----------------------------------------------------------*/
	
	linha:
	FLUSH_INPUT();
	printf("\nIntroduza o numero de linhas que cada andar tem: ");
	
	/*garantir que é só inserido um numero e o o enter '\n'*/
	if(scanf("%i%c", &linha, &term) != 2 || term != '\n'){
		system("cls");
		printf(RED("POR FAVOR INSIRA VALORES VALIDOS \n\n"));
		goto linha;
	}

	/*verificar se o valor inserido é positivo*/
	if(linha < 1){
		system("cls");
		printf(RED("INSIRA UM VALOR VALIDO"));
		goto linha;
	}

	/*-----------------------------------------------------------*/
	
	coluna:
	FLUSH_INPUT();
	printf("\nIntroduza o numero de colunas que cada andar tem: ");
	
	/*garantir que é só inserido um numero e o o enter '\n'*/
	if(scanf("%i%c", &coluna, &term) != 2 || term != '\n'){
		system("cls");
		printf(RED("POR FAVOR INSIRA VALORES VALIDOS \n\n"));
		goto coluna;
	}
	
	/*verificar se o valor inserido é positivo*/
	if(coluna < 1){
		system("cls");
		printf(RED("INSIRA UM VALOR VALIDO"));
		goto coluna;
	}
	
	/*-----------------------------------------------------------*/
	
	total = andar * linha * coluna; /*var criada para a lotação do parque de estacionamento*/
	
	carros = (carro *) calloc(total, sizeof(carro));  /*define que a partir do primeiro endereço de mem, existem total endereços de mem que guardam vars do tipo carro*/
	
	parque = malloc(sizeof parque * andar); /* define que a partir do primeiro endereço da primeira camada de mem, neste é um pointer tri-dimensional, existem andar endereços com vars do tipo parque  */
	
	
	for(ca = 0; ca < andar; ca++){
		parque[ca] = malloc(sizeof parque * linha ); /*o mesmo raciocinio da linha 123 mas para a segunda camada do pointer que se refere as linhas*/
		for(cl = 0; cl < linha; cl++){
			parque[ca][cl] = malloc(sizeof parque * coluna ); /*o mesmo raciocinio da linha 123 mas para a terceira camada do pointer que se refere as colunas*/
		}
	}
	
	FLUSH_INPUT();

	/*esta a preencher o pointer tri-dimensional com a letra 'L' em todas as posições*/
	for (ca=0; ca < andar; ca++) 
	{	
		for (cl=0; cl < linha; cl++) 
		{
			for (cc=0; cc < coluna; cc++) 
			{
				parque[ca][cl][cc] = 'L';
			}
		}	
	}

	printf("\n\n");
	printf("PRIMA ENTER PARA CONTINUAR");
	WAIT_ENTER_KEY();
		
	system("cls");
	
	menu(parque, andar, linha, coluna, carros, nr_carros);
}
