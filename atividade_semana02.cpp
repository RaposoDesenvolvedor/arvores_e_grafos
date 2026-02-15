#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// João Lucas Raposo Martins - 2412905

void preencherVetorDecrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void preencherVetorAleatorio(int *vetor, int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {

        vetor[i] = rand() % 100;
    }
}

void bubbleSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                (*comparacoes)++;
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*movimentacoes)++;
            }
        }
    }
}

void selectionSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
    for (int i = 0; i < tamanho; i++) {
        int menor_indice = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] <  vetor[menor_indice]) {
                (*comparacoes)++;
                menor_indice = j;
            }
        }

        int temp = vetor[menor_indice];
        vetor[menor_indice] = vetor[i];
        vetor[i] = temp;
        (*movimentacoes)++;
    }

}

void executarTeste(const char *algoritmo, void (*sortFunction)(int *, int, int *, int *), int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    int comparacoes = 0, movimentacoes = 0;
    clock_t inicio, fim;
    double tempo;

    preencherVetorDecrescente(vetor, tamanho);
    inicio = clock();
    sortFunction(vetor, tamanho, &comparacoes, &movimentacoes);
    fim = clock();
    tempo = ((double)(fim - inicio)) / (CLOCKS_PER_SEC / 1000);

    printf("| %-13s | %-7d | %-10.3f | %-12d | %-12d |\n", algoritmo, tamanho, tempo, comparacoes, movimentacoes);
    free(vetor);
}

int main() {
    printf("| Algoritmo     | Tamanho | Tempo (ms) | Comparacoes  | Movimentacoes  |\n");
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 100);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 100);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 1000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 1000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 10000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 10000);
    printf("|---------------|---------|------------|--------------|----------------|\n");

    printf("Pergunta: Qual dos algoritmos apresentou o melhor desempenho?\n\n");
    printf("Neste caso, o Selection Sort apresenta desempenho superior, uma vez que o vetor não está ordenado.\n");
    printf("O Selection Sort é mais criterioso ao realizar as movimentações, diferentemente do Bubble Sort, que realiza a movimentação em todos as posições.\n");
    printf("Com o método do Selection Sort, ele consome menos tempo movimentando os números.\n");
    printf("Também é possível verificar uma maior variação com o gerador de vetor aleatório.\n");
    printf("Para utilizar, basta trocar a função 'preencherVetorDecrescente' por 'preencherVetorAleatorio' na função 'executarTeste'.\n");


    return 0;
}
