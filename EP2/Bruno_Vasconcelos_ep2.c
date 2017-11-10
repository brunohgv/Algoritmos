#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

//arquiva resultados max_it
int lerArquivo(int* x, int* y, int retorno)
{
	FILE *arq;
	
	arq = fopen("trembala.dat", "r");
	int i, n;
	
	//L� o n�mero de coordenadas
	fscanf(arq, "%i", &n);
		
	//Realoca os vetores x e y para o n�mero de espa�os iguais a n
	y = (int*) malloc(n * sizeof(int));
	x = (int*) malloc(n * sizeof(int));
	
	//L� coordenadas x
	for(i = 0 ; i < n ; i++)
	{
		fscanf(arq, "%i", &x[i]);	
	}
	//L� coordenadas y
	for(i = 0 ; i < n ; i++)
	{
		fscanf(arq, "%i", &y[i]);
	}
	
	//fecha arquivo
	fclose(arq);
	
	if(retorno == 1){
		return x;		
	}
	else if(retorno == 2){
		return y;
	}
	else if(retorno == 3){
		return n;
	}
}

void heap(int* x, int n, int i){
	int indiceMaiorValor = i;
	int esquerda = 2*i + 1;
	int direita = 2*i + 2;
	
	//verifica se o �ndice est� dentro do limite do vetor e o substitui se o valor da esquerda for maior
	if (esquerda < n && x[esquerda] > x[i]){
		indiceMaiorValor = esquerda;
	}
	
	//verifica se o �ndice est� dentro do limite do vetor e o substitui se o valor da direita for maior
	if (direita < n && x[direita] > x[i]){
		indiceMaiorValor = direita;
	}
	
	//trocar posi��o x[i] com x[indiceMaiorValor] se ele j� n�o for
	if (indiceMaiorValor != i){
		int auxiliar = x[i];
		x[i] = x[indiceMaiorValor];
		x[indiceMaiorValor] = auxiliar;
		heap(x, n, indiceMaiorValor);
	}
}

void heapsort(int* x, int n){
	//reorganiza
	int i;
	for(i = (n/2 - 1); i >= 0 ; i--){
		heap(x, n, i);
	}	
	
	//extrai os elementos do heap a cada reorganiza��o;
	int auxiliar;
	for(i = n - 1 ; i >= 0; i--){
		//move a raiz do heap para o fim do segmento atual do vetor 
		auxiliar = x[i];
		x[i] = x[0];
		x[0] = auxiliar;
		
		//chama a fun��o novamente no segmento reduzido
		heap(x, i, 0);	
	}
}

void imprimirVetor(int* vet, int n){
	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf("%i ", vet[i]);
	}
}


main()
{
	setlocale(LC_ALL, "portuguese");
	
	int* x;
	int* y;
	int n;
	
	n = lerArquivo(x, y, 3);
	x = lerArquivo(x, y, 1);
	y = lerArquivo(x, y, 2);
	
	
	imprimirVetor(x, n);
	
	system("pause");
}


