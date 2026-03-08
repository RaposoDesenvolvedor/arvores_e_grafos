#include <stdio.h>
#include <stdlib.h>

typedef void (*AlgoritmoOrdenacao)(int*, int, int*, int*);

// Funções gerais
void imprimir_vetor(int *vetor, int tamanho, int trocas, int comparacoes) {
    printf("Lista atual: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
    printf("Trocas: %d | Comparações: %d\n", trocas, comparacoes);
}

void ler_elemento(int *novo_elemento, int *tamanho_vetor) {
    printf("Número: ");
    scanf("%d", novo_elemento);

    if (*novo_elemento < 0 || *novo_elemento == -1) return;

    (*tamanho_vetor)++;
}

void realocar_memoria_vetor(int **vetor, int tamanho, int novo_elemento) {
    int *temp = (int *)realloc(*vetor, tamanho * sizeof(int));

    if (temp == NULL) {
        printf("Erro de alocação de memória!\n");
        free(*vetor);
        return;
    }

    *vetor = temp;

    int ultimo_indice = tamanho - 1;
    (*vetor)[ultimo_indice] = novo_elemento;
}

// Algoritmos de ordenação
void bubble_sort(int *vetor, int tamanho, int *trocas, int *comparacoes) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            (*comparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

void selection_sort(int *vetor, int tamanho, int *trocas, int *comparacoes) {
    for (int i = 0; i < tamanho; i++) {
        int menor_indice = i;
        for (int j = i + 1; j < tamanho; j++) {
            (*comparacoes)++;
            if (vetor[j] <  vetor[menor_indice]) {
                menor_indice = j;
            }
        }

        int temp = vetor[menor_indice];
        vetor[menor_indice] = vetor[i];
        vetor[i] = temp;
        (*trocas)++;
    }
}

// Função Quick Sort
int particao(int *vetor, int indice_menor, int indice_maior, int *trocas, int *comparacoes) {
    int pivo = vetor[indice_maior];
    int i = indice_menor - 1;

    for (int j = indice_menor; j < indice_maior; j++) {
        
        (*comparacoes)++;
        if (vetor[j] < pivo) {
            i++;

            if (i != j) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                (*trocas)++;
            }
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[indice_maior];
    vetor[indice_maior] = temp;

    return (i + 1);
}

void quick_sort(int *vetor, int indice_menor, int indice_maior, int *trocas, int *comparacoes) {
    if (indice_menor < indice_maior) {
        int part = particao(vetor, indice_menor, indice_maior, trocas, comparacoes);

        quick_sort(vetor, indice_menor, part - 1, trocas, comparacoes);
        quick_sort(vetor, part + 1, indice_maior, trocas, comparacoes);
    }
}

// Função do Merge Sort
void mesclar(int *vetor, int inicio, int meio, int fim, int *trocas, int *comparacoes) {
    int tamanho_esquerdo = meio - inicio + 1;
    int tamanho_direito = fim - meio;

    int balde_esquerdo[tamanho_esquerdo];
    int balde_direito[tamanho_direito];

    for (int i = 0; i < tamanho_esquerdo; i++) {
        balde_esquerdo[i] = vetor[inicio + i];
    }
    for (int j = 0; j < tamanho_direito; j++) {
        balde_direito[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < tamanho_esquerdo && j < tamanho_direito) {
        (*comparacoes)++;
        if (balde_esquerdo[i] <= balde_direito[j]) {

            vetor[k] = balde_esquerdo[i];
            (*trocas)++;
            i++;
        } else {
            vetor[k] = balde_direito[j];
            (*trocas)++;
            j++;
        }
        k++;
    }

    // Adicionar restante dos números ao vetor
    while (i < tamanho_esquerdo) {
        vetor[k] = balde_esquerdo[i];
        i++;
        k++;
    }

    while (j < tamanho_direito) {
        vetor[k] = balde_direito[j];
        j++;
        k++;
    }

}

void merge_sort(int *vetor, int inicio, int fim, int* trocas, int* comparacoes) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(vetor, inicio, meio, trocas, comparacoes);
        merge_sort(vetor, meio + 1, fim, trocas, comparacoes);

        mesclar(vetor, inicio, meio, fim, trocas, comparacoes);
    }
}

// Conversor para a adequação do algoritmo ao typedef
void conversor_quick_sort(int *vetor, int tamanho, int* trocas, int* comparacoes) {
    quick_sort(vetor, 0, tamanho - 1, trocas, comparacoes);
}

void conversor_merge_sort(int *vetor, int tamanho, int* trocas, int* comparacoes) {
    merge_sort(vetor, 0, tamanho - 1, trocas, comparacoes);
}

void insertion_sort(int *vetor, int tamanho, int *trocas, int *comparacoes) {
    int i, indice_elemento, chave;

    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        indice_elemento = i - 1;

        while (indice_elemento >= 0 && vetor[indice_elemento] > chave) {
            (*comparacoes)++;                
            vetor[indice_elemento + 1] = vetor[indice_elemento];
            indice_elemento--;
            (*trocas)++;
        }

        vetor[indice_elemento + 1] = chave;
        (*trocas)++;
    }
}



void executar_algoritmo(void *algoritmo, int **vetor, const char nome_algoritmo[], int *tamanho) {
    int novo_elemento;
    int trocas = 0, comparacoes = 0;
    AlgoritmoOrdenacao algoritmo_escolhido = (AlgoritmoOrdenacao)algoritmo;

    printf("\n--- ALGORITMO SELECIONADO: %s ---\n", nome_algoritmo);
    printf("Os números serão ordenados automaticamente após serem inseridos.\n");
    printf("Insira qualquer valor para ordenar. Insira -1 para sair do algoritmo.\n");
    while (1)
    {
        ler_elemento(&novo_elemento, tamanho);

        if (novo_elemento < 0 || novo_elemento == -1) break;

        realocar_memoria_vetor(vetor, *tamanho, novo_elemento);
        algoritmo_escolhido(*vetor, *tamanho, &trocas, &comparacoes);
        imprimir_vetor(*vetor, *tamanho, trocas, comparacoes);
    }

    printf("\nVetor final com o algoritmo %s: \n", nome_algoritmo);
    imprimir_vetor(*vetor, *tamanho, trocas, comparacoes);
    printf("\n");

    trocas = 0, comparacoes = 0, *tamanho = 0;
    free(*vetor);
    *vetor = NULL;
    return;
}

int main() {
    int *vetor = NULL;
    int tamanho = 0;
    int opcao;

    do {
        printf("--- ALGORITMOS DINÂMICOS ---\n");
        printf("1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n");
        printf("4 - Quick Sort\n5 - Merge Sort\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: executar_algoritmo(bubble_sort, &vetor, "Bubble Sort", &tamanho); break;
            case 2: executar_algoritmo(selection_sort, &vetor, "Selection Sort", &tamanho); break;
            case 3: executar_algoritmo(insertion_sort, &vetor, "Insertion Sort", &tamanho); break;
            case 4: executar_algoritmo(conversor_quick_sort, &vetor, "Quick Sort", &tamanho); break;
            case 5: executar_algoritmo(conversor_merge_sort, &vetor, "Merge Sort", &tamanho); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n"); continue;
        }

    } while (opcao != 0);

    if (vetor != NULL) {
        free(vetor);
    }

    return 0;
}