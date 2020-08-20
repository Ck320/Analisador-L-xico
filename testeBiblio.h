#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char lethers[30]="abcdefghijklmnopqrstuvwxyz";
char numbers[15][2]={"0","1","2","3","4","5","6","7","8","9"};
char num[11]="0123456789";
char specialSim[15]=".,;():=<>+-*";
char specialSimC[5][3]={":=","(*","*)"};
char CompoundSim[20][20]={" program "," label "," var "," procedure "," function "," begin "," end "," if "," then "," else "," while "," do "," or "," and "," div "," not ","integer"};
char auxCompoundSim[20][20]={"program","label","var","procedure","function","begin","end","if","then","else","while","do","or","and","div","not","integer"};

typedef struct
{
	char lexema[100];
	char tipo[10];
	int linha;
}Simbolo;

Simbolo *sim;
int quant=0;

void inicia()
{
	sim = (Simbolo*)malloc(sizeof(Simbolo));
}

void limpa()
{
	free(sim);
}

void adiciona(char lexema[],char tipo[],int linha)
{
	strcpy(sim[quant].lexema,lexema);
	//strcpy(sim[quant].tipo,tipo);
	sim[quant].linha=linha;
	quant++;
}

void scanner(char lex[],int line)
{
	int i;
	
	for(i=0;i<16;i++)
		if(strstr(lex,CompoundSim[i])!=NULL)
		{
			char tipo[]="comp_Sim";
			adiciona(CompoundSim[i],tipo,line);	
		}
			
	for(i=0;i<15;i++)
	{
		int j;
		for(j=0;j<strlen(lex);j++)
		{
			if(lex[j]==specialSim[i])
			{
				char tipo[]="special_Sim";
				char result[2]="";
				result[0]=specialSim[i];
				adiciona(result,tipo,line);
			}
					
		}		
	}				
}

void scannerVal(char lex[],int line) //busca valores
{
	char num[]="";		
	int i,j;
	bool start=false;
	bool stop=false;
	for(i=1;i<strlen(lex);i++)
	{
		for(j=0;j<16;j++)
		{
									
					
			
		}
	}
}


bool scannerSim(char x)
{
	int i;
	for(i=0;i<strlen(specialSim);i++)
	{
		if(x == specialSim[i])
		{
			return true;
		}
	}
	return false;
}

bool scannerLether(char x)
{
	int i;
	for(i=0;i<strlen(lethers);i++)
	{
		if(x == lethers[i])
		{
			return true;
		}
	}
	return false;
}

bool scannerNum(char x)
{
	int i;
	for(i=0;i<strlen(num);i++)
	{
		if(x == num[i])
		{
			return true;
		}
	}
	return false;
}

void scannerVar(char lex[],int line) //busca variaveis (id)
{
	bool achou=false;
	int i,j,tamanho=0;
	char letra[100]="";	
	for(i=1;i<strlen(lex);i++)
	{
		if((scannerLether(lex[i])==true))
		{
			letra[tamanho]=lex[i];
			tamanho++;
		}
		if((scannerNum(lex[i])==true))
		{
			letra[tamanho]=lex[i];
			tamanho++;
		}
		
		//if((lex[i]==' ') || (scannerSim(lex[i])==true))
		if((lex[i]==' ')|| (scannerSim(lex[i])==true))
		{
			for(j=0;j<17;j++)
			{
				if(strcmp(letra,auxCompoundSim[j])==0)
				{
					achou=true;
					memset(letra,'\0',100);
					tamanho=0;	
				}						
			}
			if(achou==false)
			{
				if(strcmp(letra,"")==0);
				else
				{
					char tipo[]="variable";
					//printf("\n--%s--",letra);
					adiciona(letra,tipo,line);
					memset(letra,'\0',100);
					tamanho=0;
				}								
			}
			achou=false;					
		}		
	}	
}

void mostrar()
{
	int i;
	for(i=0;i<quant;i++)
	{		
		printf("\n line == %d -> %s",sim[i].linha,sim[i].lexema);
	}
	free(sim);
}

