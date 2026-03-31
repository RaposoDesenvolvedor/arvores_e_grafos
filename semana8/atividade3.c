#include <stdio.h>
#include <stdbool.h>

int main() {
    int produtos[] = {5, 10, 15, 20};
    int tamanho = sizeof(produtos) / sizeof(produtos[0]);
    int alvo = 8;
    
    int encontrado = false;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (produtos[i] == alvo) {
            encontrado = true;
            break;
        }
    }
    
    if (encontrado) {
        printf("Produto %d encontrado na lista.\n", alvo);
    } else {
        printf("Produto %d não encontrado na lista.\n", alvo);
    }

    return 0;
}