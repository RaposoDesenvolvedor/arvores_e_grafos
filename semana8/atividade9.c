#include <stdio.h>
#include <stdbool.h>

int main() {
    int temperaturas[] = {30, 32, 28, 27, 35};
    int tamanho = sizeof(temperaturas) / sizeof(temperaturas[0]);
    int alvo = 27;

    int encontrado = false;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (temperaturas[i] == alvo) {
            encontrado = true;
        }
    }

    if (encontrado) {
        printf("Temperatura %d° encontrada na lista.\n", alvo);
    }

    return 0;
}