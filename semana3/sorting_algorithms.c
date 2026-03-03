#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar_vetor(int vetor[], int inicio, int fim) {
    printf("[ ");
    for (int i = inicio; i <= fim; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

void preencher_vetor_decrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

// Bubble Sort
void bubble_sort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int menor_indice = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] <  vetor[menor_indice]) {
                menor_indice = j;
            }
        }

        int temp = vetor[menor_indice];
        vetor[menor_indice] = vetor[i];
        vetor[i] = temp;
    }
}


// Insertion Sort
void insertion_sort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];

            j--;
        }

        vetor[j + 1] = chave;
    }
}

// Quick Sort
int quick_sort_particao(int vetor[], int indice_menor, int indice_maior) {
    int pivo = vetor[indice_maior];

    int i = indice_menor - 1;

    for (int j = indice_menor; j < indice_maior; j++) {
        
        if (vetor[j] < pivo) {
            i++;
            if (i != j) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[indice_maior];
    vetor[indice_maior] = temp;

    return (i + 1);
}


void quick_sort(int vetor[], int indice_menor, int indice_maior) {
    if (indice_menor < indice_maior) {

        int part = quick_sort_particao(vetor, indice_menor, indice_maior);

        quick_sort(vetor, indice_menor, part - 1);
        quick_sort(vetor, part + 1, indice_maior);
    }
}

// Merge Sort
void merge(int vetor[], int inicio, int meio, int fim) {
    int tamanho_esquerdo = meio - inicio + 1;
    int tamanho_direito = fim - meio;

    int balde_esquerdo[tamanho_esquerdo];
    int balde_direito[tamanho_direito];

    // Copiar vetores
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
        if (balde_esquerdo[i] <= balde_direito[j]) {
            vetor[k] = balde_esquerdo[i];
            i++;
        } else {
            vetor[k] = balde_direito[j];
            j++;
        }
        k++;
    }

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

void merge_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

void executar_teste(const char *nome_algoritmo, void *algoritmo, int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    clock_t inicio, fim;
    double tempo;

    preencher_vetor_decrescente(vetor, tamanho);
    inicio = clock();

    // Compara os endereços de memória
    if (algoritmo == bubble_sort || algoritmo == selection_sort || algoritmo == insertion_sort) {
        ((void (*)(int *, int))algoritmo)(vetor, tamanho);
    } 

    if (algoritmo == quick_sort || algoritmo == merge_sort) {
        ((void (*)(int *, int, int))algoritmo)(vetor, 0, tamanho - 1);
    }

    fim = clock();
    tempo = ((double)(fim - inicio) * 1000.0) / CLOCKS_PER_SEC;

    printf("| %-18s | %-7d | %-10.3f |\n", nome_algoritmo, tamanho, tempo);
    free(vetor);
}

void titulo_tabela() {
    printf("\n");
    printf("|--------------------|---------|------------|\n");
    printf("| Algoritmo          | Tamanho | Tempo (ms) |\n");
    printf("|--------------------|---------|------------|\n");
}

void rodape_tabela() {
    printf("|--------------------|---------|------------|\n");
    printf("\n");
    printf("Observação: Os vetores utilizados são vetores decrescentes de 0 à 10, 0 à 100, 0 à 1000 ou de 0 ao valor escolhido.\n\n");
}

void comparacao() {
    titulo_tabela();
    executar_teste("Bubble Sort", bubble_sort, 10);
    executar_teste("Bubble Sort", bubble_sort, 100);
    executar_teste("Bubble Sort", bubble_sort, 1000);
    printf("|--------------------|---------|------------|\n");
    executar_teste("Selection Sort", selection_sort, 10);
    executar_teste("Selection Sort", selection_sort, 100);
    executar_teste("Selection Sort", selection_sort, 1000);
    printf("|--------------------|---------|------------|\n");
    executar_teste("Insertion Sort", insertion_sort, 10);
    executar_teste("Insertion Sort", insertion_sort, 100);
    executar_teste("Insertion Sort", insertion_sort, 1000);
    printf("|--------------------|---------|------------|\n");
    executar_teste("Quick Sort", quick_sort, 10);
    executar_teste("Quick Sort", quick_sort, 100);
    executar_teste("Quick Sort", quick_sort, 1000);
    printf("|--------------------|---------|------------|\n");
    executar_teste("Merge Sort", merge_sort, 10);
    executar_teste("Merge Sort", merge_sort, 100);
    executar_teste("Merge Sort", merge_sort, 1000);
    rodape_tabela();
}

void menu() {
    int opcao, tamanho;
    
    do {
        printf("--- MENU DE ALGORITMOS DE ORDENAÇÃO ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Ver Tabela de Comparacao Completa\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 5) {
            printf("Digite o tamanho do vetor: ");
            scanf("%d", &tamanho);
        }

        switch (opcao) {
            case 1:
                titulo_tabela();
                executar_teste("Bubble Sort", bubble_sort, tamanho);
                rodape_tabela();
                break;
            case 2:
                titulo_tabela();
                executar_teste("Insertion Sort", insertion_sort, tamanho);
                rodape_tabela();
                break;
            case 3:
                titulo_tabela();
                executar_teste("Selection Sort", selection_sort, tamanho);
                rodape_tabela();
                break;
            case 4:
                titulo_tabela();
                executar_teste("Quick Sort", quick_sort, tamanho);
                rodape_tabela();
                break;
            case 5:
                titulo_tabela();
                executar_teste("Merge Sort", merge_sort, tamanho);
                rodape_tabela();
                break;
            case 6:
                comparacao();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}