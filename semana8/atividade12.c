#include <stdio.h>
#include <stdbool.h>

int buscaBinaria(int arr[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == alvo) {
            return meio;
        }

        if (arr[meio] < alvo) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

void bubbleSort(int arr[], int tamanho, int *comparacoes) {
    int temp;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            (*comparacoes)++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int vetor[] = {500, 200, 800, 300, 100};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int alvo = 300;

    int comparacoes = 0;
    bubbleSort(vetor, tamanho, &comparacoes);

    int posicao = buscaBinaria(vetor, tamanho, alvo);


    if (posicao != -1) {
        printf("ID %d encontrado na lista ordenada na posição %d.\n", alvo, posicao);
    } else {
        printf("ID %d não encontrado.\n", alvo);
    }

    printf("Comparações totais: %d.\n", comparacoes);

    return 0;
}