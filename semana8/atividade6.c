#include <stdio.h>
#include <stdbool.h>

int main() {
    int vendas[] = {100, 200, 150, 300, 200};
    int tamanho = sizeof(vendas) / sizeof(vendas[0]);
    int alvo = 200;
    
    int posicao = -1;
    int encontrado = false;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (vendas[i] == alvo) {
            encontrado = true;
            posicao = i;

            if (encontrado) {
                printf("Venda de R$%d encontrado na lista na posição %d.\n", alvo, posicao);
            }
        }
    }
 
    return 0;
}