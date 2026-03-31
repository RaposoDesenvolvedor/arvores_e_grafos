#include <stdio.h>
#include <stdbool.h>

int main() {
    int vendas[] = {1, 2, 3, 2, 4, 2};
    int tamanho = sizeof(vendas) / sizeof(vendas[0]);
    int alvo = 2;
    
    int contador = 0;
    int encontrado = false;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (vendas[i] == alvo) {
            encontrado = true;
            contador++;
        }
    }

    if (encontrado) {
        printf("O ID %d acessou o sistema %d vezes.\n", alvo, contador);
    }

    return 0;
}