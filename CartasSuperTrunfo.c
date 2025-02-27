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

float calcularSuperPoder(struct Cidade c) {
    float densidade = c.area > 0 ? c.populacao / c.area : 0;
    float pib_per_capita = c.populacao > 0 ? c.pib / c.populacao : 0;
    return c.populacao + c.pib + pib_per_capita + (1 / (densidade + 1)) + c.pontos_turisticos;
}

void compararCartas(struct Cidade c1, struct Cidade c2) {
    float poder_c1 = calcularSuperPoder(c1);
    float poder_c2 = calcularSuperPoder(c2);

    printf("\nComparacao de Cartas:\n\n");
    printf("Super Poder Total - Carta 1: %.2f\n", poder_c1);
    printf("Super Poder Total - Carta 2: %.2f\n", poder_c2);

    if (poder_c1 > poder_c2) {
        printf("Carta 1 venceu!\n");
    } else if (poder_c2 > poder_c1) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
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

