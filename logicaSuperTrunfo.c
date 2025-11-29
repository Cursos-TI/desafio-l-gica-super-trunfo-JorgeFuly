#include <stdio.h>

    char estado1, estado2;              // Letra de A a H
    char codigo1[4], codigo2[4];        // Código Ex: A03
    char Cidade1[50],Cidade2[50];       // Nome das cidades

    float area1, area2;                 // Área em km²
    float densidade1 = 0;
    float densidade2 = 0;       // Densidade populacional em float

    unsigned long int populacao1, populacao2; // Número de habitantes
    int pontos1, pontos2;               // Quantidade de pontos turísticos
    int resultado1, resultado2;

    double capita1, capita2;            // Pib per capita usando o double
    double pib_digitado1,pib_digitado2; // O valor digitado pelo usuário 
    double pib_real1,pib_real2;         // Valor em reais facilitando a divisão
    
       // Entradas para a primeira carta
int main() {
    printf(" Cadastro da Carta 1 \n"); //Inicio das Informações

    printf("Estado (A-H): ");          //Estado com apenas um caractere entre A e H
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");  //Código da carta com Um caracter e 2 Numerais
    scanf("%s", &codigo1);

    printf("Nome da Cidade: ");          //Nome da cidade
    scanf(" %[^\n]", Cidade1);         // Abre margem para usar espaços entre palavras como "Rio de Janeiro"

    printf("Populacao: ");             //População
    scanf("%lu", &populacao1);

    printf("Area (km²): ");            //Area sem a obrigação de colocar 'km²'
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%lf", &pib_digitado1);      //Esse comando serve para prioorizar o que o usuario digitou

    printf("Numero de Pontos Turisticos: "); //Pontos turísticos 
    scanf("%d", &pontos1);

    pib_real1 = pib_digitado1 * 1000000000.0;
    densidade1 = (float)populacao1 / area1;
    capita1 = (float)pib_real1 / populacao1;

    //  Entrada para Segunda carta
    printf("\n Cadastro da Carta 2 \n");    //Todo o procedimento repetido código por código

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", &codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", Cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%lf", &pib_digitado2);

    printf("Número de Pontos Turisticos: ");
    scanf("%d", &pontos2);
    
    //Calculos de densidade e conversão do valor digitado em bilhão

    pib_real2 = pib_digitado2 * 1000000000.0;
    densidade2 = (float)populacao2 / area2;
    capita2 = (float)pib_real2 / populacao2;

    printf("\nCadastro concluido com sucesso!\n"); //Todas as informações passadas

    //Exibição da Primeira Carta Trunfo

    printf("\n CARTA nº1 \n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s \n", Cidade1);
    printf("População: %lu Habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib_digitado1);
    printf("Número de Pontos Turísticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$%.2f\n", capita1);

    //Exibição da Segunda Carta Trunfo

    printf("\n CARTA nº2 \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", Cidade2);
    printf("População: %lu Habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib_digitado2);
    printf("Número de Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$%.2f\n", capita2);

    printf("\n========COMPARAÇÃO DE CARTAS: %s / %s =========\n", Cidade1, Cidade2);
    if (populacao1 > populacao2){
        printf("Carta %s ganhou em População!\n", Cidade1);
    } else {
        printf("Carta %s ganhou em População!\n",Cidade2);
    }
    if (area1 > area2){
        printf("Carta %s ganhou contendo mais Expansão Territorial!\n",Cidade1);
    } else {
        printf("Carta %s ganhou contendo mais Expansão Territorial\n", Cidade2);
    }
    if (pib_real1 > pib_real2){
        printf("Carta %s ganhou tendo o maior PIB!\n",Cidade1);
    } else {
        printf("Carta %s ganhou tendo o maior PIB!\n", Cidade2);
    }
    if (pontos1 > pontos2){
        printf("Carta %s ganhou contendo mais Pontos Turísticos!\n", Cidade1);
    } else {
        printf("Carta %s ganhou contendo mais Pontos Turísticos!\n", Cidade2);
    }
    if (densidade1 < densidade2){
        printf("Carta %s ganhou pois teve a menor Densidade Populacional!\n", Cidade1);
    } else {
        printf("Carta %s ganhou pois teve a menor Densidade Populacional!\n", Cidade2);
    }
    if (capita1 > capita2){
        printf("Carta %s ganhou! Pois teve o maior PIB per capita!\n", Cidade1);
    } else {
        printf("Carta %s ganhou! Pois teve o maior PIB per capita!\n", Cidade2);
    }
    

    
    //Fim do Código

    return 0;
}
