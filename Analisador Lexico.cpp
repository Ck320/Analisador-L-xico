#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "BilbliotecaAnalisadorLexico.h"
//#include "testeBiblio.h"

FILE *arquivo;

void abrirArquivo(char url[])
{
	arquivo = fopen(url,"r");

	if(arquivo == NULL)
		printf("\nerro, nao foi possivel abrir o arquivo");	
}

void ler()
{
	while(feof(arquivo)==false)
	{
		
	}
}

main()
{
	printf("analisador lexico\n\n");
	char url[]="Trab1_Compiladores.txt";
	abrirArquivo(url);
	proximo(arquivo);
	fclose(arquivo);
	
	getch();
}
