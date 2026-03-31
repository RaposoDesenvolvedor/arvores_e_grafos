#include <stdio.h>
#include <stdbool.h>

int main() {
    int notas[] = {7, 8, 5, 9, 6};
    int tamanho = sizeof(notas) / sizeof(notas[0]);
    int alvo = 10;
    
    int encontrado = false;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (notas[i] == alvo) {
            encontrado = true;
            break;
        }
    }
    
    if (encontrado) {
        printf("Nota %d encontrado na lista.\n", alvo);
    } else {
        printf("Nota %d não encontrado na lista.\n", alvo);
    }

    return 0;
}