#include <stdio.h>

int particao(int v[], int ini, int fim){
	int pivo, topo;
	pivo = v[ini]; //Pivô é o primeiro elemento do array
	topo = ini;
	for(int i = ini+1; i<=fim; i++){
		if(v[i] < v[pivo]){
			v[topo] = v[i];
			v[i] = v[topo+1];
			topo++;
		}
	}
	v[topo] = pivo;
	return topo;
}

void merge(int v[], int ini, int meio, int fim){
	int a = fim-ini;
	int aux[fim];
	//Copia as 2 partes no array auxiliar
	for(int i=ini; i<=fim; i++){
		aux[i] = v[i];
	}

	int i=ini;
	int j=meio+1;
	int k=ini;
	//Copia os menores valores (esquerda e direita) de volta no vetor original
	while(i<=meio && j<=fim){
		if(aux[i] <= aux[j]){
			v[k] = aux[i];
			i++;
		}else{
			v[k] = aux[j];
			j++;
		}
	k++;
	}
	//Copia o resto do lado esquerdo do array no vetor original
	while(i<=meio){
		v[k] = aux[i];
		k++;
		i++;
	}
	//Copia o resto do lado direito do array no vetor original
	while(j<=fim){
		v[k] = aux[j];
		k++;
		j++;
	}
}

void mergeSort(int v[], int ini, int fim){
	int meio;
	//Analisa se o vetor já está ordenado
	if(ini<fim){
		meio = ini + ((fim-ini)/2); //Obtém o índice do elemento central
		mergeSort(v, ini, meio); //Ordena o lado esquerdo do array
		mergeSort(v, meio+1, fim); //Ordena o lado direito do arrray
		merge(v, ini, meio, fim); //Combina os lados
	}
}

void quickSort(int v[], int ini, int fim){
	int meio;
	if(ini<fim){
		meio = particao(v, ini, fim); //Obtém o índice do pivô
		quickSort(v, ini, meio); //Ordena o lado esquerdo do pivô
		quickSort(v, meio+1, fim); //Ordena o lado direito do pivô
	}
}


int main(){
	
	return 0;
}

