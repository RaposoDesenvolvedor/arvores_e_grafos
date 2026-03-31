#include <stdio.h>
#include <stdbool.h>

int main() {
    int ids[] = {2001, 2002, 2003, 2004};
    int tamanho = sizeof(ids) / sizeof(ids[0]);
    int alvo = 2005;

    int encontrado = false;

    // Busca sequencial
    for (int i = 0; i < tamanho; i++) {
        if (ids[i] == alvo) {
            encontrado = true;
        }
    }

    if (!encontrado) {
        printf("ID %d não está cadastrado na lista.\n", alvo);
    }

    return 0;
}