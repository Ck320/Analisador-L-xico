#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void proximo(FILE *arquivo)
{
	int lines=1;
	int tamanhoLexema=0;
	char lexema[100];
	
			
	while(feof(arquivo)==false)
	{
		char proximo = fgetc(arquivo);		
		
		if(proximo =='\n')
		{
			int i;
			printf("linha :: %d\t",lines);	
			for(i=0;i<tamanhoLexema;i++)
			{
				printf("%c",lexema[i]);
			}
						
			printf("\n");			
			for(i=0;i<tamanhoLexema;i++)
			{
				lexema[i]=NULL;
			}		
			tamanhoLexema=0;		
			lines++;				
		}
				
		else
		{	
			if(proximo=='\t');			
			else
			{
				lexema[tamanhoLexema]=proximo;			
				tamanhoLexema++;
			}									
		}									
	}	
	free(lexema);	
}

void codigo()
{
	
}

void erro()
{
	printf("\nerro");
}
