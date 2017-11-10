#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

//Bruno Henrique Gusm�o Vasconcelos
//Segundo EP
//09/11/2017
//Algoritmos e estruturas de dados


//Fun��o para preencher o vetor com n�meros aleat�rios de 0 � 99
int* vetor(int n)
{
	int *v;
	v = (int*) malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n ; i++)
	{
		v[i] = rand()%100;
	}
 	
	return v;	
}

//arquiva resultados max_it
void arquivaDistancia(int *x, int *y, int n)
{
	FILE *arq;
	
	arq = fopen("trembala.dat", "w");
	int i;
	fprintf(arq, "%i\n", n);
	//salva coordenadas x
	for(i = 0 ; i < n ; i++)
	{
		fprintf(arq, "%i ", x[i]);
	}
	fprintf(arq, "\n");
	//salva coordenadas y
	for(i = 0 ; i < n ; i++)
	{
		fprintf(arq, "%i ", y[i]);
	}
	

	fclose(arq);	
}




main()
{
	setlocale(LC_ALL, "portuguese");
	
	srand(time(NULL));
	
	int* x;
	int* y;
	int n = 50;
	
	x = vetor(n);
	y = vetor(n);
	
	arquivaDistancia(x, y, n);
	
	
	system("pause");
}


