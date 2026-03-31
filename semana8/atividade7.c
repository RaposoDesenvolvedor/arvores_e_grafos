#include <stdio.h>
#include <stdbool.h>

int main() {
    int numeros[] = {9991, 9992, 9993, 9994};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int alvo = 9993;
    
    int encontrado = false;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] == alvo) {
            encontrado = true;
            break;
        }
    }
    
    if (encontrado) {
        printf("Número %d encontrado na lista.\n", alvo);
    } else {
        printf("Número %d não encontrado na lista.\n", alvo);
    }

    return 0;
}