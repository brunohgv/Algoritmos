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
		v[i] = rand()%201 - 100;
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

// Função para imprimir no console o vetor de inteiros
void teste(int* vet, int n){
	int i;
	for(i=0;i<n;i++){
		printf("pos %i : %i\n", i, vet[i]);
	}
}

// Algoritmo recursivo
// Método: Divisão e conquista
// Retorna: Valor máximo do vetor
int max_rec(int* A, int p, int r)
{
	if(p == r)
	{
		return A[p];
	}
	else
	{
		int result, x, y;
		int q = (p + r) / 2;
		
		x =  max_rec(A, p, q);
		y = max_rec(A, q+1 , r);
		
		result = max( x , y );
		
		return result;		
	}
}

// Algoritmo recursivo mergesort
// Método: Divisão e conquista
// Retorna: Vetor ordenado de forma crescente
// Créditos: geeksforgeeks.org
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

// Algoritmo iterativo
// Retorna: Vetor ordenado de forma crescente
void cresc_it(int* A, int p, int n)
{
	int i, j, aux;
	for(j = 0 ; j <= n ; j++)
	{
		for(i = 1 ; i <= n ; i++)
		{	
			if(A[i] < A[i-1])
			{
				aux = A[i];
				A[i] = A[i-1];
				A[i-1] = aux;
			}
		}	
	}
}


// Algoritmo recursivo
// Método: Divisão e conquista
// Retorna: Posição do número buscado 'x' ou primeiro menor que ele
// Créditos: Paulo Feofiloff (Analise de busca binária)
int buscabinaria(int* a, int p, int r, int x)
{
	if(p == r-1) //se o índice de início do intervalo for igual ao índice do final retorne esse índice
	{
		return r;
	}
	else
	{
		int q = (p + r) / 2; //divisão do intervalo em duas pertes
		if(a[q] < x)
		{
			return buscabinaria(a, q, r, x); //Se 'a' for menor que o valor desejado, procure valores maiores
		}
		else
		{
			return buscabinaria(a, p, q, x); //Se 'a' for maior que o valor desejado, procure valores menores
		}
	}
}	

//Função principal da busca binária
int loc_rec(int* a, int n, int x)
{
	return buscabinaria(a, 0, n+1, x);
}



// Algoritmo iterativo
// Retorna: Posição do número buscado 'x' ou primeiro maior que ele
// Créditos: Paulo Feofiloff (Analise de busca binária)
int loc_it(int* a, int n, int x)
{
	int p = 0;
	int r = n - 1;
	while(p < r - 1)
	{
		int q = (p + r) / 2;
		if(a[q] < x)
		{
			p = q;
		}
		else
		{
			r = q;
		}
	}
	return r;
}

//Algoritmo iterativo
//Retorna: A maior soma sequencial do vetor informado no intervalo [p , r]
//Créditos: Paulo Feofiloff (SOLIDEZI)
int seg_it(int* a, int p, int r)
{
	int x = a[r];	//x recebe última posição do vetor 'a'
	int q;
	int s;
	int j;
	for(q = r - 1 ; q >= p ; q--)	//enquanto 'q' for maior que 'p' (início do segmento)
	{
		s = 0;
		for(j = q ; j <= r ; j++)	//percorre o vetor somando os segmentos
		{
			s = s + a[j];
			if(s > x)				//se a soma desse segmento for maior que a soma anterior
			{
				x = s;				//a variável 'x' recebe o valor da soma
			}
		}
	}
	return x;
}

//Algoritmo recursivo
//Método: Divisão e conquista
//Retorna: A maior soma sequencial do vetor informado no intervalo [p , r]
//Créditos: Paulo Feofiloff (SOLIDEZII)
seg_rec(int* a, int p, int r)
{
	if(p == r)
	{
		return a[p];
	}
	else
	{
		int x1, x2;
		int q = (p + r) / 2;
		x1 = seg_rec(a, p, q);
		x2 = seg_rec(a, q+1, r);
		int s = a[q];
		int y1 = s;
		int i;
		for(i = q - 1 ; i > p ; i--)
		{
			s += a[i];
			if(s > y1)
			{
				y1 = s;
			}
		}
		s = a[q+1];
		int y2 = s;
		int j;
		for(j = q + 2 ; j < r ; j++)
		{
			s += a[j];
			if(s > y2)
			{
				y2 = s;
			}
		}
		int x = max(max(x1 , y1 + y2), x2);
		return x;
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
	
	//printf("Maximo valor rec: %i\n", maximo);
	//printf("Maximo valor it: %i\n", max);
	//printf("Count: %i", COUNT);	
	
	//cresc_it(vet, 0, n-1);
	//mergeSort(vet, 0, n-1);
	
	//teste(vet, n);
	
	//printf("Maior segmento recursivo: %i\n", seg_rec(vet, 0, n));
	
	//printf("Maior segmento iterativo: %i\n", seg_it(vet, 0, n - 1));
	
	//printf("Resultado: %i", loc_it(vet, n, 50));
}


