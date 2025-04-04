#include <stdio.h>

int main() {
    float nota1, nota2, media;

    // Pede a primeira nota e verifica se está entre 0 e 10.
    printf("Digite a primeira nota do aluno (entre 0 e 10):\n");
    if (scanf("%f", &nota1) != 1) {
        printf("Erro: Entrada invalida!\n");
        return 1;
    }
    if (nota1 < 0 || nota1 > 10) {  // ?? Corrigido: Agora aceita 10
        printf("Nota invalida! A nota deve estar entre 0 e 10.\n");
        return 1;
    }

    // Pede a segunda nota e faz a mesma verificação.
    printf("Digite a segunda nota do aluno (entre 0 e 10):\n");
    if (scanf("%f", &nota2) != 1) {
        printf("Erro: Entrada invalida!\n");
        return 1;
    }
    if (nota2 < 0 || nota2 > 10) {  // ?? Corrigido: Agora aceita 10
        printf("Nota invalida! A nota deve estar entre 0 e 10.\n");
        return 1;
    }

    // Calcula a média e mostra.
    media = (nota1 + nota2) / 2;
    printf("Sua media: %.2f\n", media);

    // Verifica se passou ou nao.
    if (media >= 6.0) {
        printf("Parabens, voce passou!\n");
    } else {
        printf("Infelizmente, voce nao passou.\n");
    }

    return 0;
}
		

	
	

