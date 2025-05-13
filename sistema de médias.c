#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    // Configura o programa para aceitar acentuação em português
    setlocale(LC_ALL,"Portuguese");

    // Declaração de variáveis
    int alunos, i;
    float nota1, nota2, media;
    char nomes[50][50];     // Vetor para armazenar até 50 nomes de alunos
    float medias[50];       // Vetor para armazenar as médias dos alunos

    // Solicita a quantidade de alunos e valida a entrada
    printf("Primeiro insira a quantidade de alunos (no máximo 50 alunos):\n");
    while (scanf("%d", &alunos) != 1 || alunos < 1 || alunos > 50) {
        printf("\033[1;31mErro: Entrada inválida! Insira um número entre 1 e 50.\033[0m\n");
        while (getchar() != '\n'); // Limpa o buffer do teclado
        printf("Digite novamente: ");
    }
    while (getchar() != '\n'); // Limpa o buffer após o número

    // Coleta os dados de cada aluno
    for (i = 0; i < alunos; i++) {
        // Lê o nome do aluno
        printf("\nDigite o nome do aluno:\n");
        fgets(nomes[i], sizeof(nomes[i]), stdin);

        // Lê e valida a primeira nota
        do {
            printf("Digite a primeira nota do(a) %s (entre 0 e 10):\n", nomes[i]);
            if (scanf("%f", &nota1) != 1 || nota1 < 0 || nota1 > 10) {
                printf("\033[1;31mErro: Nota inválida! A nota deve estar entre 0 e 10.\033[0m\n");
                while (getchar() != '\n'); // Limpa o buffer
            } else {
                break;
            }
        } while (1);

        // Lê e valida a segunda nota
        do {
            printf("Digite a segunda nota do(a) %s (entre 0 e 10):\n", nomes[i]);
            if (scanf("%f", &nota2) != 1 || nota2 < 0 || nota2 > 10) {
                printf("\033[1;31mErro: Nota inválida! A nota deve estar entre 0 e 10.\033[0m\n");
                while (getchar() != '\n'); // Limpa o buffer
            } else {
                break;
            }
        } while (1);

        while (getchar() != '\n'); // Limpa o buffer para próxima leitura

        // Calcula e armazena a média do aluno
        media = (nota1 + nota2) / 2;
        medias[i] = media;
    }

    // Exibe os resultados de cada aluno
    printf("\n\033[1;34m=== Resultados ===\033[0m\n");
    for (i = 0; i < alunos; i++) {
        printf("\nAluno: %s", nomes[i]);  // nomes[i] já inclui o \n
        printf("Média: %.2f\n", medias[i]);
        if (medias[i] >= 6.0)
            printf("Situação: \033[0;32mPassou\033[0m\n");  // Verde para aprovado
        else
            printf("Situação: \033[1;31mNão passou\033[0m\n"); // Vermelho para reprovado
    }

    // Calcula a média geral da sala
    float soma = 0.0, mediaSala;
    for (i = 0; i < alunos; i++) {
        soma += medias[i];
    }
    mediaSala = soma / alunos;
    printf("\n\033[1;36mMédia geral da sala: %.2f\033[0m\n", mediaSala);

    // Determina a maior e a menor média
    float menor = medias[0], maior = medias[0];
    for (i = 1; i < alunos; i++) {
        if (medias[i] < menor)
            menor = medias[i];
        if (medias[i] > maior)
            maior = medias[i];
    }

    // Exibe a menor e maior média da sala
    printf("\033[1;35mMenor média da sala: %.2f\033[0m\n", menor);  // Roxo
    printf("\033[1;33mMaior média da sala: %.2f\033[0m\n", maior);  // Amarelo

    return 0;
}


	
	

