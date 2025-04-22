#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;


void mostrarCarta(Carta c) {
    printf("Carta: %s\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligência: %d\n", c.inteligencia);
}


Carta gerarCartaAleatoria() {
    Carta cartas[] = {
        {"Dragão", 90, 60, 40},
        {"Mago", 30, 50, 95},
        {"Guerreiro", 80, 70, 50},
        {"Elfo", 50, 90, 70},
        {"Orc", 75, 55, 30}
    };
    int total = sizeof(cartas) / sizeof(Carta);
    return cartas[rand() % total];
}


void comparar(Carta jogador, Carta computador, int atributo) {
    int valJogador, valComputador;

    switch (atributo) {
        case 1:
            valJogador = jogador.forca;
            valComputador = computador.forca;
            break;
        case 2:
            valJogador = jogador.velocidade;
            valComputador = computador.velocidade;
            break;
        case 3:
            valJogador = jogador.inteligencia;
            valComputador = computador.inteligencia;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("\n--- Resultado ---\n");
    printf("Sua carta: %d vs Carta do computador: %d\n", valJogador, valComputador);

    if (valJogador > valComputador)
        printf(" Você venceu!\n");
    else if (valJogador < valComputador)
        printf(" Você perdeu!\n");
    else
        printf(" Empate!\n");
}

int main() {
    srand(time(NULL));

    Carta suaCarta = gerarCartaAleatoria();
    Carta cartaComputador = gerarCartaAleatoria();

    printf("=== Sua carta ===\n");
    mostrarCarta(suaCarta);

    int escolha;
    printf("\nEscolha um atributo para competir:\n");
    printf("1 - Força\n2 - Velocidade\n3 - Inteligência\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &escolha);

    printf("\n=== Carta do Computador ===\n");
    mostrarCarta(cartaComputador);

    comparar(suaCarta, cartaComputador, escolha);

    return 0;
}
