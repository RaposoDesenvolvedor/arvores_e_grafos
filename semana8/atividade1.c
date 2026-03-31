#include <stdio.h>
#include <stdbool.h>

int main() {
    int matriculas[] = {101, 102, 103, 104, 105};
    int tamanho = 5;
    int alvo = 103;
    
    int encontrado = false;
    int posicao = -1;
    int comparacoes = 0;

    for (int i = 0; i < tamanho; i++) {
        comparacoes++;
        
        if (matriculas[i] == alvo) {
            encontrado = true;
            posicao = i;
            break;
        }
    }
    if (encontrado) {
        printf("Aluno de matricula %d está presente.\n", alvo);
        printf("Posição no vetor: %d\n", posicao);
    } else {
        printf("Aluno %d não está presente.\n", alvo);
    }
    printf("Total de comparações realizadas: %d\n", comparacoes);

    return 0;
}