#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "testeBiblio.h"

void proximo(FILE *arquivo)
{
	int lines=1,i;
	int tamanhoLexema=1;
	char lexema[100]="";
	
	inicia();
	
	while(feof(arquivo)==false)
	{
		char proximo = fgetc(arquivo);		
		lexema[0]=' ';
		if(proximo =='\n')
		{
			lexema[tamanhoLexema]=' ';
			scanner(lexema,lines);
			scannerVar(lexema,lines);
			memset(lexema,'\0',100);
			
			lexema[0]=' ';				
			tamanhoLexema=1;		
			lines++;				
		}
								
		if((proximo>31)&&(proximo<127))
		{
			lexema[tamanhoLexema]=proximo;			
			tamanhoLexema++;
		}									
	}
	mostrar();
}

void codigo()
{
	
}

void erro()
{
	printf("\nerro");
}
