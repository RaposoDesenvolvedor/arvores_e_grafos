#include <stdio.h>
#include <stdbool.h>

int main() {
    int produtos[] = {12, 25, 30, 48, 50};
    int tamanho = 5;
    int alvo = 30;
    
    int encontrado = false;
    int posicao = -1;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (produtos[i] == alvo) {
            encontrado = true;
            posicao = i;
            break;
        }
    }
    if (encontrado) {
        printf("Produto %d encontrado na lista.\n", alvo);
        printf("Posição no vetor: %d\n", posicao);
    } else {
        printf("Produto %d não encontrado na lista.\n", alvo);
    }

    return 0;
}