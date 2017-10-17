#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Definições para mínimo e máximo
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Bruno Henrique Gusmão Vasconcelos
//Primeiro EP
//11/10/2017
//Algoritmos e estruturas de dados


//contador global
int COUNT = 0;


//Função para preencher o vetor com números aleatórios de 1 à 100
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


//Algoritmo recursivo para encontrar o maior valor em um vetor de inteiros
int max_rec(int* A, int p, int r)
{
	int result, x, y, x1, x2, y1, y2;
	x = 0;
	y = 0;
	if(p == r)
	{
		return A[p];
	}
	else
	{
		int q = (p + r) / 2;
		x1 =  max_rec(A, p, q);
		x2 = max_rec(A, q + 1 , r);
		int i, j;
		for(i = q - 1 ; i > p ; i--)
		{
			if(A[i] > x)
			{
				x = A[i];
			}
		}
		for(j = q ; j < r ; j ++)
		{
			if(A[j] > y)
			{
				y = A[j];
			}
		}
		result = max( x , y );
		
		return result;		
	}
}

// algoritmo iterativo para receber maior valor do vetor A
// Criado por Bruno Henrique Gusmão Vasconcelos
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

//Função para 
void teste(int* vet, int n){
	int i;
	for(i=0;i<n;i++){
		printf("pos %i : %i\n", i, vet[i]);
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
	
	maximo = max_rec(vet, 0, n);
	
	teste(vet, n);
	
	printf("Maximo valor: %i\n", maximo);
	printf("Maximo valor it: %i\n", max);
	printf("Count: %i", COUNT);	
}


