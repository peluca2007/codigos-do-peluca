#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    // Define a localização para português (pra aceitar acentos e ç)
    setlocale(LC_ALL,"Portuguese");

    // Variáveis principais
    int alunos, i;
    float nota1, nota2, media;
    char nomes[50][50];     // Armazena o nome de até 50 alunos
    float medias[50];       // Armazena a média de cada aluno

    // Entrada da quantidade de alunos
    printf("Primeiro insira a quantidade de alunos (no máximo 50 alunos):\n");

    // Validação da quantidade de alunos (entre 1 e 50)
    while (scanf("%d", &alunos) != 1 || alunos < 1 || alunos > 50) {
        printf("\033[1;31mErro: Entrada inválida! Insira um número entre 1 e 50.\033[0m\n");
        while (getchar() != '\n'); // Limpa o buffer
        printf("Digite novamente: ");
    }

    // Limpa o buffer após ler o número
    while (getchar() != '\n');

    // Loop para ler dados de cada aluno
    for (i = 0; i < alunos; i++) {
        printf("\nDigite o nome do aluno:\n");
        fgets(nomes[i], sizeof(nomes[i]), stdin);

        // Validação da primeira nota
        do {
            printf("Digite a primeira nota do(a) %s (entre 0 e 10):\n", nomes[i]);
            if (scanf("%f", &nota1) != 1 || nota1 < 0 || nota1 > 10) {
                printf("\033[1;31mErro: Nota inválida! A nota deve estar entre 0 e 10.\033[0m\n");
                while (getchar() != '\n'); // Limpa o buffer para evitar loop infinito
            } else {
                break; // Sai do loop se a nota for válida
            }
        } while (1);

        // Validação da segunda nota
        do {
            printf("Digite a segunda nota do(a) %s (entre 0 e 10):\n", nomes[i]);
            if (scanf("%f", &nota2) != 1 || nota2 < 0 || nota2 > 10) {
                printf("\033[1;31mErro: Nota inválida! A nota deve estar entre 0 e 10.\033[0m\n");
                while (getchar() != '\n'); // Limpa o buffer para evitar loop infinito
            } else {
                break; // Sai do loop se a nota for válida
            }
        } while (1);

        // Limpa o buffer para a próxima leitura de nome
        while (getchar() != '\n');

        // Calcula e salva a média
        media = (nota1 + nota2) / 2;
        medias[i] = media;
    }

    // Exibição dos resultados com cores para "passou" ou "não passou"
    printf("\n\033[1;34m=== Resultados ===\033[0m\n");
    for (i = 0; i < alunos; i++) {
        printf("\nAluno: %s", nomes[i]);  // nomes[i] já inclui \n
        printf("Média: %.2f\n", medias[i]);
        if (medias[i] >= 6.0)
            printf("Situação: \033[0;32mPassou\033[0m\n");
        else
            printf("Situação: \033[1;31mNão passou\033[0m\n");
    }

    return 0;
}

		

	
	


	
	

