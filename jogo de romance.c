#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

// Códigos de cor ANSI para deixar o texto colorido no terminal
#define RESET     "\033[0m"
#define VERMELHO  "\033[1;31m"
#define VERDE     "\033[1;32m"
#define AZUL      "\033[1;34m"
#define ROSA      "\033[1;95m"

int main() {
    setlocale(LC_ALL, ".UTF-8");

    // Variáveis do jogo
    int amor, amor2, amor3;
    char nome[30];
    char nome_lower[30];
    int finais = 0; // contador de finais únicos
    char jogar_novamente;
    int finais_vistos[8] = {0}; // vetor que marca os finais vistos

    do {
        // Introdução
        printf("Esse é um mini jogo para a pessoa que eu mais");
        printf(VERMELHO " AMO NO MUNDO 🥰\n" RESET);
        printf("Para começar, digite seu nome:\n");

        // Lê nome e remove \n
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;

        // Converte para minúsculo
        strcpy(nome_lower, nome);
        for (int i = 0; nome_lower[i]; i++) {
            nome_lower[i] = tolower(nome_lower[i]);
        }

        // Final verdadeiro
        if (
            strcmp(nome_lower, "bea") == 0 ||
            strcmp(nome_lower, "beatriz") == 0 ||
            strcmp(nome_lower, "beatriz esmy") == 0
        ) {
            printf(ROSA "\n╔════════════════════════════════════╗\n");
            printf("    💖 VOCÊ DESBLOQUEOU O FINAL 💖    \n");
            printf("         🌸🌸 VERDADEIRO 🌸🌸          \n");
            printf("╚════════════════════════════════════╝\n\n" RESET);

            printf(ROSA "Pedro te dá um abraço apertado e diz: 'Eu sabia que era você!'\n");
            printf("Vocês vivem felizes para sempre numa cabana com Wi-Fi 📶,\n");
            printf("muitos gatinhos 🐱 (inclusive o Lucas ),\n");
            printf("filmes da Disney 🍿 e comédias bobinhas 💕.\n");
            printf("✨👩‍❤️‍👨💍 Final verdadeiro 💍👩‍❤️‍👨✨\n" RESET);

            if (!finais_vistos[7]) {
                finais_vistos[7] = 1;
                finais++;
            }
        } else {
            // Caminho comum
            printf(AZUL "Prazer, %s!\n" RESET, nome);
            printf("Meu nome é Pedro, mas você já sabe disso, bakaaa 🚒\n");
            printf("Você gostaria de sair comigo?\n");

            printf(VERDE "1 - Sim seu lindo 💅\n" RESET);
            printf(VERDE "2 - Sim 😳\n" RESET);
            printf(VERMELHO "3 - Não 🙄\n" RESET);

            char entrada[10];
            fgets(entrada, sizeof(entrada), stdin);
            if (sscanf(entrada, "%d", &amor) != 1) amor = -1;

            switch (amor) {
                case 1:
                    printf("Você está se achando muito! Quem você acha que é pra falar assim comigo?\n");
                    printf(ROSA "1 - O amor da sua vida 💘\n" RESET);
                    printf(ROSA "2 - A Bea 😇\n" RESET);
                    fgets(entrada, sizeof(entrada), stdin);
                    if (sscanf(entrada, "%d", &amor2) != 1) amor2 = -1;

                    switch (amor2) {
                        case 1:
                            printf(VERMELHO "Não gostei de você 😤 (Pedro pega uma AK-47 e 💥)\nFim brutal 💀\n" RESET);
                            if (!finais_vistos[0]) { finais_vistos[0] = 1; finais++; }
                            break;
                        case 2:
                            printf("Me prova que você é a Bea 😠\n");
                            printf("Me diga o nome do gatinho dela 🐱\n");
                            printf(AZUL "1 - Lucas 🐾\n" RESET);
                            printf(AZUL "2 - Fofo 🦺\n" RESET);
                            fgets(entrada, sizeof(entrada), stdin);
                            if (sscanf(entrada, "%d", &amor3) != 1) amor3 = -1;

                            if (amor3 == 1) {
                                printf(VERMELHO "Você está certo, mas não gostei da resposta 😾 (bazuca de gatinhos 💥)\nFim tonto 🤪\n" RESET);
                                if (!finais_vistos[1]) { finais_vistos[1] = 1; finais++; }
                            } else if (amor3 == 2) {
                                printf(VERDE "Nossa! Você está certa! É você mesmo!! 😍\n");
                                printf("Pedro te enche de beijos 😘\n");
                                printf("Vocês ficam juntos pra sempre com 2 filhos, 2 gatos, 1 cachorro e uma cacatua 🐦\n");
                                printf("Final feliz 🌈\n" RESET);
                                if (!finais_vistos[2]) { finais_vistos[2] = 1; finais++; }
                            } else {
                                printf(VERMELHO "Final secreto: resposta estranha 🔀\n" RESET);
                                if (!finais_vistos[3]) { finais_vistos[3] = 1; finais++; }
                            }
                            break;
                        default:
                            printf(VERMELHO "Final secreto: sou burro 🙈\n" RESET);
                            if (!finais_vistos[3]) { finais_vistos[3] = 1; finais++; }
                            break;
                    }
                    break;
                case 2:
                    printf(VERMELHO "Nossa que sem empolgação... 😑 (Pedro pega uma espada samurai e... 💥)\nFinal sem graça 💤\n" RESET);
                    if (!finais_vistos[4]) { finais_vistos[4] = 1; finais++; }
                    break;
                case 3:
                    printf(AZUL "Vai tomar no cu 😤 (Pedro vira as costas e vai embora...)\nFinal pacifista ☮️\n" RESET);
                    if (!finais_vistos[5]) { finais_vistos[5] = 1; finais++; }
                    break;
                default:
                    printf(VERMELHO "Final secreto: sou burro 🤔\n" RESET);
                    if (!finais_vistos[6]) { finais_vistos[6] = 1; finais++; }
                    break;
            }
        }

        // Mostra progresso
        printf(AZUL "\nVocê concluiu %d/8 finais únicos! 🏆\n" RESET, finais);
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);
        getchar();
        printf("\n\n");

    } while (jogar_novamente == 's' || jogar_novamente == 'S');

    if (finais == 8) {
        // Final secreto desbloqueado
        printf(ROSA "\nSe você desbloqueou TODOS os finais, você com certeza é a BEAAAA! 😍\n");
        printf("Final secreto desbloqueado... 💖\n\n");

        // Coração bonitinho
        printf(ROSA "      *****       *****\n");
        printf("   *********** ***********\n");
        printf("  ***************************\n");
        printf(" *****************************\n");
        printf(" *****************************\n");
        printf("  ***************************\n");
        printf("   *************************\n");
        printf("     *********************\n");
        printf("       *****************\n");
        printf("         *************\n");
        printf("           *********\n");
        printf("             *****\n");
        printf("              ***\n");
        printf("               *\n" RESET);
    } else {
        //pessoa saiu do jogo
        printf(VERMELHO "%s, VOCÊ NÃO É A BEAAAA 😭\n" RESET, nome);
    }

    return 0;
}






















