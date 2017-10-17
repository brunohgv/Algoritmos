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


//Algorítmo adaptado do Minicurso de Análise de algoritmos de Feofiloff
//cap 5.3 SOLIDEZII
//Objetivo do algoritmo: Encontrar o maior valor em um vetor de inteiros
int max_rec(int* A, int p, int r){
	if(p==r){
		return A[p];
		COUNT++;
	}else{
		int q = (p+r)/2;
		int x1 = max_rec(A, p, q);
		COUNT++;
		int x2 = max_rec(A, q+1, r);
		COUNT++;
		int y1;
		int s;
		int y2;
		s = A[q];
		y1 = s;;
		int i,j;
		for(i = q - 1 ; i > p ; q--){
			s += A[i];
			if(s>y1){
				y1 = s;	
			} 	
		}
		s = A[q+1];
		y2 = s;
		for(j = q + 2 ; j < r ; j++){
			s += A[j];
			if(s > y2){
				y2 = s;
			}
		}
		return max(max(x1, y1+y2), x2);
	}
}

// algoritmo iterativo para receber maior valor do vetor A
// Criado por Bruno Henrique Gusmão Vasconcelos
int max_it(int A[], int tamA){
	int i;
	int max;
	if(tamA == 1){
		return A[tamA];
	} else {
		for(i = 1 ; i < tamA ; i++){
		if(A[i] > A[i - 1]){
			max = A[i];
		}
	}
	return max;
	}
}

//Preencher vetor de inteiros
int preencher(int A[], int r){

}


main()
{
	srand(time(NULL));
	
	int i;
	int *vet;
	
	
	//tamanho do vetor
	int n = 20;
	
	
	vet = vetor(n);
	
	max_rec(vet, 0, n);
	
	
	/*
	for(i=0;i<n;i++){
		printf("pos %i : %i\n", i, vet[i]);
	}
	*/
	
	printf("Count: %i", COUNT);
	
	
}


