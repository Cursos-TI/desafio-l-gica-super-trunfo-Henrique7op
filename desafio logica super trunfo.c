#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define NUM_CARTAS 10
#define NUM_ATRIBUTOS 5

typedef struct {
    char nome[50];
    int populacao;          // em milhões
    float area;             // em milhões de km²
    float pib;              // em trilhões de USD
    float idh;              // índice de 0 a 1
    int densidade;          // hab/km²
} Carta;

void inicializarCartas(Carta cartas[]) {
    strcpy(cartas[0].nome, "Brasil");
    cartas[0].populacao = 213;
    cartas[0].area = 8.5;
    cartas[0].pib = 1.4;
    cartas[0].idh = 0.765;
    cartas[0].densidade = 25;
    
    strcpy(cartas[1].nome, "Estados Unidos");
    cartas[1].populacao = 331;
    cartas[1].area = 9.8;
    cartas[1].pib = 21.4;
    cartas[1].idh = 0.926;
    cartas[1].densidade = 36;
    
    strcpy(cartas[2].nome, "China");
    cartas[2].populacao = 1402;
    cartas[2].area = 9.6;
    cartas[2].pib = 14.7;
    cartas[2].idh = 0.761;
    cartas[2].densidade = 146;
    
    strcpy(cartas[3].nome, "Japão");
    cartas[3].populacao = 126;
    cartas[3].area = 0.38;
    cartas[3].pib = 5.0;
    cartas[3].idh = 0.919;
    cartas[3].densidade = 334;
    
    strcpy(cartas[4].nome, "Alemanha");
    cartas[4].populacao = 83;
    cartas[4].area = 0.36;
    cartas[4].pib = 3.8;
    cartas[4].idh = 0.947;
    cartas[4].densidade = 232;
    
    strcpy(cartas[5].nome, "Índia");
    cartas[5].populacao = 1380;
    cartas[5].area = 3.3;
    cartas[5].pib = 2.9;
    cartas[5].idh = 0.645;
    cartas[5].densidade = 424;
    
    strcpy(cartas[6].nome, "Rússia");
    cartas[6].populacao = 146;
    cartas[6].area = 17.1;
    cartas[6].pib = 1.5;
    cartas[6].idh = 0.824;
    cartas[6].densidade = 9;
    
    strcpy(cartas[7].nome, "Austrália");
    cartas[7].populacao = 25;
    cartas[7].area = 7.7;
    cartas[7].pib = 1.4;
    cartas[7].idh = 0.944;
    cartas[7].densidade = 3;
    
    strcpy(cartas[8].nome, "Canadá");
    cartas[8].populacao = 38;
    cartas[8].area = 10.0;
    cartas[8].pib = 1.6;
    cartas[8].idh = 0.929;
    cartas[8].densidade = 4;
    
    strcpy(cartas[9].nome, "França");
    cartas[9].populacao = 67;
    cartas[9].area = 0.64;
    cartas[9].pib = 2.7;
    cartas[9].idh = 0.901;
    cartas[9].densidade = 119;
}

void exibirCarta(Carta carta) {
    printf("\n=== %s ===\n", carta.nome);
    printf("1. População: %d milhões\n", carta.populacao);
    printf("2. Área: %.2f milhões de km²\n", carta.area);
    printf("3. PIB: %.2f trilhões de USD\n", carta.pib);
    printf("4. IDH: %.3f\n", carta.idh);
    printf("5. Densidade Demográfica: %d hab/km²\n", carta.densidade);
}

int escolherAtributo(int primeiroAtributo) {
    int opcao;
    
    printf("\nEscolha um atributo:\n");
    
    for (int i = 1; i <= NUM_ATRIBUTOS; i++) {
        if (i != primeiroAtributo) {
            switch(i) {
                case 1: printf("%d. População\n", i); break;
                case 2: printf("%d. Área\n", i); break;
                case 3: printf("%d. PIB\n", i); break;
                case 4: printf("%d. IDH\n", i); break;
                case 5: printf("%d. Densidade Demográfica\n", i); break;
            }
        }
    }
    
    do {
        printf("Opção: ");
        scanf("%d", &opcao);
        
        if (opcao < 1 || opcao > NUM_ATRIBUTOS || opcao == primeiroAtributo) {
            printf("Opção inválida! Escolha um atributo diferente do primeiro.\n");
        }
    } while (opcao < 1 || opcao > NUM_ATRIBUTOS || opcao == primeiroAtributo);
    
    return opcao;
}

float obterValorAtributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.idh;
        case 5: return carta.densidade;
        default: return 0;
    }
}

int compararAtributos(float valor1, float valor2, int atributo) {
    // Para densidade demográfica, o menor valor vence
    if (atributo == 5) {
        if (valor1 < valor2) return 1;
        if (valor1 > valor2) return -1;
        return 0;
    }
    
    // Para outros atributos, o maior valor vence
    if (valor1 > valor2) return 1;
    if (valor1 < valor2) return -1;
    return 0;
}

void exibirResultadoAtributo(Carta carta1, Carta carta2, int atributo, int resultado) {
    char nomeAtributo[30];
    char unidade[20] = "";
    
    switch(atributo) {
        case 1: 
            strcpy(nomeAtributo, "População");
            strcpy(unidade, " milhões");
            break;
        case 2: 
            strcpy(nomeAtributo, "Área");
            strcpy(unidade, " milhões de km²");
            break;
        case 3: 
            strcpy(nomeAtributo, "PIB");
            strcpy(unidade, " trilhões de USD");
            break;
        case 4: 
            strcpy(nomeAtributo, "IDH");
            break;
        case 5: 
            strcpy(nomeAtributo, "Densidade Demográfica");
            strcpy(unidade, " hab/km²");
            break;
    }
    
    printf("\n%s: %s %.2f%s vs %s %.2f%s -> ",
           nomeAtributo,
           carta1.nome, obterValorAtributo(carta1, atributo), unidade,
           carta2.nome, obterValorAtributo(carta2, atributo), unidade);
    
    if (resultado == 1) {
        printf("%s vence!\n", carta1.nome);
    } else if (resultado == -1) {
        printf("%s vence!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Carta cartas[NUM_CARTAS];
    Carta cartaJogador, cartaComputador;
    int primeiroAtributo, segundoAtributo;
    int indiceJogador, indiceComputador;
    float somaJogador = 0, somaComputador = 0;
    int resultado1, resultado2;
    
    srand(time(NULL));
    inicializarCartas(cartas);
    
    // Escolha aleatória das cartas
    indiceJogador = rand() % NUM_CARTAS;
    indiceComputador = rand() % NUM_CARTAS;
    cartaJogador = cartas[indiceJogador];
    cartaComputador = cartas[indiceComputador];
    
    printf("=== Jogo de Comparação de Países ===\n");
    printf("Sua carta:\n");
    exibirCarta(cartaJogador);
    
    printf("\nCarta do computador:\n");
    exibirCarta(cartaComputador);
    
    // Escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. IDH\n");
    printf("5. Densidade Demográfica\n");
    
    do {
        printf("Opção: ");
        scanf("%d", &primeiroAtributo);
        
        if (primeiroAtributo < 1 || primeiroAtributo > NUM_ATRIBUTOS) {
            printf("Opção inválida! Escolha entre 1 e 5.\n");
        }
    } while (primeiroAtributo < 1 || primeiroAtributo > NUM_ATRIBUTOS);
    
    // Escolha do segundo atributo (dinâmico)
    segundoAtributo = escolherAtributo(primeiroAtributo);
    
    // Comparação dos atributos
    resultado1 = compararAtributos(
        obterValorAtributo(cartaJogador, primeiroAtributo),
        obterValorAtributo(cartaComputador, primeiroAtributo),
        primeiroAtributo
    );
    
    resultado2 = compararAtributos(
        obterValorAtributo(cartaJogador, segundoAtributo),
        obterValorAtributo(cartaComputador, segundoAtributo),
        segundoAtributo
    );
    
    // Exibir resultados individuais
    printf("\n=== Resultados ===\n");
    exibirResultadoAtributo(cartaJogador, cartaComputador, primeiroAtributo, resultado1);
    exibirResultadoAtributo(cartaJogador, cartaComputador, segundoAtributo, resultado2);
    
    // Soma dos atributos
    somaJogador = obterValorAtributo(cartaJogador, primeiroAtributo) + 
                  obterValorAtributo(cartaJogador, segundoAtributo);
                  
    somaComputador = obterValorAtributo(cartaComputador, primeiroAtributo) + 
                     obterValorAtributo(cartaComputador, segundoAtributo);
    
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", cartaJogador.nome, somaJogador);
    printf("%s: %.2f\n", cartaComputador.nome, somaComputador);
    
    // Resultado final
    printf("\n=== Resultado Final ===\n");
    if (somaJogador > somaComputador) {
        printf("%s vence com a maior soma de atributos!\n", cartaJogador.nome);
    } else if (somaComputador > somaJogador) {
        printf("%s vence com a maior soma de atributos!\n", cartaComputador.nome);
    } else {
        printf("Empate! As somas dos atributos são iguais.\n");
    }
    
    return 0;
}