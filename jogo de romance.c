#include <stdio.h>
#include <string.h>

int main() {
    int amor, amor2, amor3;
    char nome[30];

    printf("Esse e um mini jogo para a pessoa que eu mais amo no mundo!\n");
    printf("Para comecar, digite seu nome:\n");
    fgets(nome, sizeof(nome), stdin);  
    nome[strcspn(nome, "\n")] = 0; // Remove o '\n' no final  
     
    printf("Prazer, %s!\n", nome);
    printf("Meu nome e Pedro, mas vc ja sabe disso bakaaa\n");
    printf("Vc gostaria de sair comigo?\n");
    printf("1 - Sim seu lindo\n2 - Sim\n3 - Nao\n");
    scanf("%d", &amor);

    switch (amor) {
        case 1:
            printf("Vc esta se achando muito, qm vc acha q e pra falar assim cmg?\n");
            printf("1 - O amor da sua vida\n2 - A Bea\n");
            scanf("%d", &amor2);

            switch (amor2) {
                case 1:
                    printf("Nao gostei de vc (Pedro pega uma AK-47 e mata vc)\n");
                    printf("Fim brutal.\n");
                    break;
                case 2:
                    printf("Me prova que vc e a Bea (ele fala bravo)\n");
                    printf("Me fale o nome do gatinho dela\n");
                    printf("1 - Lucas\n2 - Fofo\n");
                    scanf("%d", &amor3);

                    switch (amor3) {
                        case 1:
                            printf("Vc esta certo, porem n gostei da resposta (ele pega uma bazuca de gatinhos e mata vc)\n");
                            printf("Fim tonto.\n");
                            break;
                        case 2:
                            printf("Nossa vc esta certa, vc e a Bea mesmo! Te amooooo (ele te da varios bjos)\n");
                            printf("(Vcs ficam juntos para sempre)\n");
                            printf("(Vcs tem 2 filhos, 2 gatos, 1 cachorro e uma cacatua)\n");
                            printf("Final feliz\n");
                            break;
                        default:
                            printf("Final secreto: sou burro\n");
                            break;
                    }
                    break;
            }
            break;

        case 2:
            printf("Nossa que sem empolgacao (Pedro pega uma espada samurai e mata vc)\n");
            printf("Final sem graca\n");
            break;

        case 3:
            printf("Vai tomar no cu (ele vira as costas e vai embora)\n");
            printf("Final pacifista\n");
            break;

        default:
            printf("Final secreto: sou burro\n");
            break;
    }

    return 0;
}


























