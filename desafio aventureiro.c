#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura da carta de país
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

// Função para exibir o menu de escolha de atributo
int exibir_menu() {
    int escolha;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("0 - Sair\n");
    printf("Digite o número da sua escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

// Função para comparar duas cartas com base no atributo escolhido
void comparar_cartas(Carta carta1, Carta carta2, int atributo) {
    printf("\n--- Comparando: %s vs %s ---\n", carta1.nome, carta2.nome);
    char atributo_nome[50];
    float valor1, valor2;

    switch (atributo) {
        case 1:
            strcpy(atributo_nome, "População");
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2:
            strcpy(atributo_nome, "Área");
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3:
            strcpy(atributo_nome, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4:
            strcpy(atributo_nome, "Número de Pontos Turísticos");
            valor1 = carta1.pontos_turisticos;
            valor2 = carta2.pontos_turisticos;
            break;
        case 5:
            strcpy(atributo_nome, "Densidade Demográfica");
            valor1 = carta1.densidade_demografica;
            valor2 = carta2.densidade_demografica;
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    printf("Atributo escolhido: %s\n", atributo_nome);
    printf("%s: %.2f\n", carta1.nome, valor1);
    printf("%s: %.2f\n", carta2.nome, valor2);

    printf("Resultado: ");
    if (atributo == 5) { // Regra especial para Densidade Demográfica
        if (valor1 < valor2) {
            printf("%s venceu!\n", carta1.nome);
        } else if (valor2 < valor1) {
            printf("%s venceu!\n", carta2.nome);
        } else {
            printf("Empate!\n");
        }
    } else { // Regra geral: maior valor vence
        if (valor1 > valor2) {
            printf("%s venceu!\n", carta1.nome);
        } else if (valor2 > valor1) {
            printf("%s venceu!\n", carta2.nome);
        } else {
            printf("Empate!\n");
        }
    }
}

int main() {
    // Exemplo de duas cartas (você pode carregar as suas do desafio anterior)
    Carta brasil = {"Brasil", 213000000, 8516000.0, 1.44, 100, 25.0};
    Carta argentina = {"Argentina", 45000000, 2780000.0, 0.49, 50, 16.2};

    int escolha;

    do {
        escolha = exibir_menu();
        if (escolha >= 1 && escolha <= 5) {
            comparar_cartas(brasil, argentina, escolha);
        } else if (escolha != 0) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    printf("\nSaindo do Super Trunfo...\n");

    return 0;
}