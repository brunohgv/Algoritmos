#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<math.h>

typedef struct{
	int x;
	int y;
}Ponto;

//Lê arquivo
int lerArquivo(int* x, int* y, int retorno)
{
	FILE *arq;
	
	arq = fopen("trembala.dat", "r");
	int i, n;
	
	//Lê o número de coordenadas
	fscanf(arq, "%i", &n);
		
	//Realoca os vetores x e y para o número de espaços iguais a n
	y = (int*) malloc(n * sizeof(int));
	x = (int*) malloc(n * sizeof(int));
	
	//Lê coordenadas x
	for(i = 0 ; i < n ; i++)
	{
		fscanf(arq, "%i", &x[i]);	
	}
	//Lê coordenadas y
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

void heap(Ponto* ponto, int n, int i){
	int indiceMaiorValor = i;
	int esquerda = 2*i + 1;
	int direita = 2*i + 2;
	
	//verifica se o índice está dentro do limite do vetor e o substitui se o valor da esquerda for maior
	if (esquerda < n && ponto[esquerda].x > ponto[indiceMaiorValor].x){
		indiceMaiorValor = esquerda;
	}
	
	//verifica se o índice está dentro do limite do vetor e o substitui se o valor da direita for maior
	if (direita < n && ponto[direita].x > ponto[indiceMaiorValor].x){
		indiceMaiorValor = direita;
	}
	
	//trocar posição x[i] com x[indiceMaiorValor] se ele já não for
	if (indiceMaiorValor != i){
		int auxiliarX = ponto[i].x;
		int auxiliarY = ponto[i].y;
		ponto[i].x = ponto[indiceMaiorValor].x;
		ponto[i].y = ponto[indiceMaiorValor].y;
		ponto[indiceMaiorValor].x = auxiliarX;
		ponto[indiceMaiorValor].y = auxiliarY;
		heap(ponto, n, indiceMaiorValor);
	}
}

void heapsort(Ponto* ponto, int n){
	//reorganiza
	int i;
	for(i = (n/2 - 1); i >= 0 ; i--){
		heap(ponto, n, i);
	}	
	
	//extrai os elementos do heap a cada reorganização;
	int auxiliarX, auxiliarY;
	for(i = n - 1 ; i >= 0; i--){
		//move a raiz do heap para o fim do segmento atual do vetor 
		auxiliarX = ponto[i].x;
		auxiliarY = ponto[i].y;
		ponto[i].x = ponto[0].x;
		ponto[i].y = ponto[0].y;
		ponto[0].x = auxiliarX;
		ponto[0].y = auxiliarY;
		
		//chama a função novamente no segmento reduzido
		heap(ponto, i, 0);	
	}
}

void imprimirVetor(int* vet, int n){
	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf("%i ", vet[i]);
	}
}

void imprimirStruct(Ponto* ponto, int n){
	int i;
	for(i = 0 ; i < n ; i++){
		printf("%i ", ponto[i].x);
	}
	printf("\n");
	for(i = 0 ; i < n ; i++){
		printf("%i ", ponto[i].y);
	}
	
}

void criarStruct(int* x, int* y, Ponto* ponto, int n){
	int i;
	for(i = 0 ; i < n ; i++){
		ponto[i].x = x[i];
		ponto[i].y = y[i];
	}
}

float calcularDistancia(Ponto p1, Ponto p2){
	int x = p1.x - p2.x;
	int y = p1.y - p2.y;
	
	// (x^2 + y^2)^(1/2)
	float total = sqrt(pow(x, 2) + pow(y, 2));
	
	return total;
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
	
	Ponto ponto[n];
	
	criarStruct(x, y, ponto, n);
	
	imprimirStruct(ponto, n);
	
	heapsort(ponto, n);
	printf("\n\n");
	imprimirStruct(ponto , n);
		
	
	
	
	system("pause");
}


