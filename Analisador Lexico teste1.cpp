#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void lerArquivo(char url[])
{
	FILE *arquivo;
	arquivo = fopen(url,"r");

	if(arquivo == NULL)
		printf("\nerro, nao foi possivel abrir o arquivo");
	
	else
	{		
		while(feof(arquivo)==false)
		{
			char c = fgetc(arquivo);
			printf("%c",c);
		}
	}
	fclose(arquivo);	
}

main()
{
	printf("analisador lexico\n");
	char url[]="Trab1_Compiladores.txt";
	lerArquivo(url);
}
