#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char convidados[][20] = {"Ana", "Bruno", "Carlos", "Diana"};
    int tamanho = sizeof(convidados) / sizeof(convidados[0]);
    char alvo[] = "Diana";
    
    int posicao = -1;
    int encontrado = false;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(convidados[i], alvo) == 0) {
            encontrado = true;
            posicao = i + 1;
            break;
        }
    }
    if (encontrado) {
        printf("Convidado %s encontrado na lista na posição %d.\n", alvo, posicao);
    } else {
        printf("Convidado %s não encontrado na lista.\n", alvo);
    }

    return 0;
}