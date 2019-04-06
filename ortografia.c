	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>

	unsigned char **dicionario;
	unsigned char palavra[100];
	int linha = 0;


	int comparador(const void *a, const void *b)
		//Retorna o valor de comparação para busca e para ordenacao
		{
			return (strcmp(*(const char **) a, *(const char **) b));
		}


	void ledicionario()
	{
		FILE *arq;
		int tampalav;
		arq = fopen ("/usr/share/dict/brazilian", "r");
		if(!arq)
		{
			printf("Dicionario nao encontrado\n");
			exit(1);
		}
		//Contando o numero de linhas
		do
		{
			fscanf(arq, "%s", palavra);
			linha++;
		} while (! feof(arq));
		
		//Alocando memória para vetor dicionario
		dicionario = (unsigned char **) malloc (linha*sizeof(unsigned char *));
		//Volta para o inicio do arquivo
		rewind(arq);
		//Le e salva o dicionario
		for (int i = 0; i < linha - 1; ++i)
		 {
		 	fscanf(arq, "%s", palavra);
		 	tampalav = strlen((const char *) palavra);
		 	dicionario[i] = (unsigned char *) malloc (tampalav*sizeof(unsigned char));
		 	
		 	//Converte tudo para minuscula	 	
		 	for(int j = 0; j < tampalav; j++)
		 	{
				if((palavra[j] >= 65 && palavra[j] <= 90) || (palavra[j] >= 192 && palavra[j] <= 196) || 
				(palavra[j] >= 199 && palavra[j] <= 207) || (palavra[j] >= 210 && palavra[j] <= 214) || (palavra[j] >= 217 && palavra[j] <= 220))
					{
					palavra[j]+=32;					
					}
					dicionario[i][j] = palavra[j];
			}
		}
		
		//Ordena o dicionario
		qsort(dicionario, linha-1, sizeof(unsigned char *), comparador);
	}

	int ehletra(unsigned char palavra)
	{
		if( (palavra >= 65 && palavra <= 90) || (palavra >= 97 && palavra <= 122) || (palavra >= 192 && palavra <= 196) || (palavra >= 199 && palavra <= 207) || 
			(palavra >= 210 && palavra <= 214) || (palavra >= 217 && palavra <= 220) || (palavra >= 224 && palavra <= 228) || (palavra >= 231 && palavra <= 239) || 
			(palavra >= 242 && palavra <= 246) || (palavra >= 249 && palavra <= 252))
			{
			return(1);
			}
		return(0);
	}


	int main(){
		int count = 0;
		unsigned char letra, *busca;

		ledicionario();
		letra = fgetc(stdin);
		do
			{
			 while (!ehletra(letra) && !feof(stdin))
				//escreve ate encontrar uma letra
				{
					printf("%c", letra);
					letra = fgetc(stdin);
				}

			 while (ehletra(letra) && !feof(stdin))
				//salva todas as letras da palavra
				{
					palavra[count] = letra;		
					count++;
					letra = fgetc(stdin);
				}
				// coloca o \0 (final) na string
			palavra[count] = '\0';
			
			busca = (unsigned char *) malloc (strlen((const char*) palavra)*sizeof(unsigned char));
			for(int j = 0; j < count; j++)
		 		{
				//converte tudo para minuscula
				if((palavra[j] >= 65 && palavra[j] <= 90) || (palavra[j] >= 192 && palavra[j] <= 196) || 
				(palavra[j] >= 199 && palavra[j] <= 207) || (palavra[j] >= 210 && palavra[j] <= 214) || (palavra[j] >= 217 && palavra[j] <= 220))
					{
					busca[j] = palavra[j]+32;
					} else {
						busca[j] = palavra[j];
					}
				}

			if(count)
				//Se uma palavra foi lida, faz a busca binaria
				{
					count=0;
				if(bsearch(&busca, dicionario, linha-1, sizeof(unsigned char *), comparador))
					{
					printf("%s", palavra);
					}
				else 
					{
					printf("[%s]", palavra);
					}

				}
		//Le tudo ate o final do arquivo
		} while (!feof(stdin));


		return 0;
	}