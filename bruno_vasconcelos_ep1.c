#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defini��es para m�nimo e m�ximo
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Bruno Henrique Gusm�o Vasconcelos
//Primeiro EP
//11/10/2017
//Algoritmos e estruturas de dados


//contador global
int COUNT = 0;


//Fun��o para preencher o vetor com n�meros aleat�rios de 1 � 100
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


// Algoritmo iterativo
// Retorna: maior valor do vetor A
int max_it(int* A, int tamA){
	int i;
	int max = A[0];
	for(i = 0 ; i < tamA ; i++)
	{
		if(A[i] > max)
		{
			max = A[i];
		}
	}
	return max;
}

// Fun��o para imprimir no console o vetor de inteiros
void teste(int* vet, int n){
	int i;
	for(i=0;i<n;i++){
		printf("pos %i : %i\n", i, vet[i]);
	}
}

// Algoritmo recursivo
// M�todo: Divis�o e conquista
// Retorna: Valor m�ximo do vetor
int max_rec(int* A, int p, int r)
{
	int result, x, y;
	if(p == r)
	{
		return A[p];
	}
	else
	{
		int q = (p + r) / 2;
		x =  max_rec(A, p, q);
		y = max_rec(A, q+1 , r);
		
		result = max( x , y );
		
		return result;		
	}
}


main()
{
	srand(time(NULL));
	
	int i;
	int* vet;
	
	
	//tamanho do vetor
	int n = 10;
	
	
	vet = vetor(n);
	
	int max = max_it(vet, n);
	
	int maximo;
	
	maximo = max_rec(vet, 0, n-1);
	
	teste(vet, n);
	
	printf("Maximo valor rec: %i\n", maximo);
	printf("Maximo valor it: %i\n", max);
	printf("Count: %i", COUNT);	
}


