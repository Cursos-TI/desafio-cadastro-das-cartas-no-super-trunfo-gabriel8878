#include <stdio.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para armazenar informações da cidade
struct Cidade {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

void cadastrarCidades(struct Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            // Gerar código da cidade
            sprintf(cidades[i][j].codigo, "%c%02d", estados[i], j + 1);
            
            printf("Cadastro da cidade %s\n", cidades[i][j].codigo);
            printf("Populacao: ");
            scanf("%d", &cidades[i][j].populacao);
            printf("Area (km2): ");
            scanf("%f", &cidades[i][j].area);
            printf("PIB (em bilhoes): ");
            scanf("%f", &cidades[i][j].pib);
            printf("Numero de pontos turisticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);
            printf("--------------------------------\n");
        }
    }
}

void compararCartas(struct Cidade c1, struct Cidade c2) {
    int pontos_c1 = 0, pontos_c2 = 0;

    printf("\nComparacao de Cartas:\n\n");
    printf("Populacao: Carta %d venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao);
    pontos_c1 += c1.populacao > c2.populacao;
    pontos_c2 += c2.populacao > c1.populacao;

    printf("Area: Carta %d venceu (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area);
    pontos_c1 += c1.area > c2.area;
    pontos_c2 += c2.area > c1.area;

    printf("PIB: Carta %d venceu (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib);
    pontos_c1 += c1.pib > c2.pib;
    pontos_c2 += c2.pib > c1.pib;

    printf("Pontos Turisticos: Carta %d venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 2, c1.pontos_turisticos > c2.pontos_turisticos);
    pontos_c1 += c1.pontos_turisticos > c2.pontos_turisticos;
    pontos_c2 += c2.pontos_turisticos > c1.pontos_turisticos;

    float densidade_c1 = c1.area > 0 ? c1.populacao / c1.area : 0;
    float densidade_c2 = c2.area > 0 ? c2.populacao / c2.area : 0;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", densidade_c1 > densidade_c2 ? 1 : 2, densidade_c1 > densidade_c2);
    pontos_c1 += densidade_c1 > densidade_c2;
    pontos_c2 += densidade_c2 > densidade_c1;

    float pib_per_capita_c1 = c1.populacao > 0 ? c1.pib / c1.populacao : 0;
    float pib_per_capita_c2 = c2.populacao > 0 ? c2.pib / c2.populacao : 0;
    printf("PIB per Capita: Carta %d venceu (%d)\n", pib_per_capita_c1 > pib_per_capita_c2 ? 1 : 2, pib_per_capita_c1 > pib_per_capita_c2);
    pontos_c1 += pib_per_capita_c1 > pib_per_capita_c2;
    pontos_c2 += pib_per_capita_c2 > pib_per_capita_c1;

    printf("Super Poder: Carta %d venceu (%d)\n", pontos_c1 > pontos_c2 ? 1 : 2, pontos_c1 > pontos_c2);
}

int main() {
    struct Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO];
    
    printf("=== Cadastro de Cidades para o Super Trunfo ===\n");
    cadastrarCidades(cidades);
    
    int estado1, cidade1, estado2, cidade2;
    printf("Digite o estado e a cidade da primeira carta (0-%d 0-%d): ", NUM_ESTADOS-1, CIDADES_POR_ESTADO-1);
    scanf("%d %d", &estado1, &cidade1);
    printf("Digite o estado e a cidade da segunda carta (0-%d 0-%d): ", NUM_ESTADOS-1, CIDADES_POR_ESTADO-1);
    scanf("%d %d", &estado2, &cidade2);

    compararCartas(cidades[estado1][cidade1], cidades[estado2][cidade2]);
    
    return 0;
}
