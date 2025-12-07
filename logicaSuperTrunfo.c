#include <stdio.h>
#include <unistd.h>
#include <string.h>

char país1[50], país2[50]; // Nome dos países
char atriname1[20], atriname2[20];

float area1, area2; // Área em km²
float densidade1 = 0;
float densidade2 = 0; // Densidade populacional em float

unsigned long int populacao1, populacao2; // Número de habitantes
int escolhajogador, atributo1, atributo2;
int turistico1, turistico2;
int pontuação1 = 0, pontuação2 = 0;

double capita1, capita2;             // Pib per capita usando o double
double pib_digitado1, pib_digitado2; // O valor digitado pelo usuário
double pib_real1, pib_real2;         // Valor em reais facilitando a divisão

// Entradas para a primeira carta
int main() {

    printf("\n==============================================\n");
    printf("\n*** BEM VINDO AO SUPER TRUNFO: PAÍSES ***\n");
    printf("\n==============================================\n");
    printf("======== MENU ======== \n");
    printf("1. Começar o Jogo\n");
    printf("2. Regras\n");
    printf("3. Créditos\n");
    printf("Escolha: ");
    scanf("%d", &escolhajogador);

    //Switch para a Escolha do Jogador no menu

    switch (escolhajogador)
    {
    case 1:
        break;
    case 2:

        //Regras, caso o jogador escolha vê-las e depois iniciar o jogo
            printf("\n*** REGRAS ***\n");
            printf("Mecânica: As cartas são distribuídas igualmente. Um jogador escolhe uma(s) categoria(s) e lê seu valor.\n");
            printf("Vencedor da Rodada: O jogador com maior soma dos atributos escolhidos vence a rodada.\n");
            printf("Dica: Densidade demográfica (atributo 4) vence quando for MENOR.\n");
        return 0;
    case 3:

        //Créditos do Ultimo Programador ter editado 05-12-25

        printf("Super Trunfo - Países\n");
        printf("Versão 1.0 — Desenvolvido por Jorge Fuly\n");
        return 0;
    default:

        //Opção inválida caso o valor inserido não seja o correto

        printf("Opção Inválida!\n");
        return 0;

    }

    //Inicio do Cadastro das Cartas

    printf("\nVamos começar pelo Cadastro das CARTAS...\n");

    //Estou usando o sleep() para dar uma boa exibição do jogo

    sleep(1);
    printf("==========================\n");
    printf("   Cadastro da Carta 1 \n"); //Inicio das Informações
    printf("==========================\n");

    // Abre margem para usar espaços entre palavras como "Costa do Marfim"

    printf("\nNome do País: ");
    scanf(" %[^\n]", país1);         

    //População

    printf("Populacao: ");             
    scanf("%lu", &populacao1);

    //Area sem a obrigação de colocar 'km²'

    printf("Area (km²): ");            
    scanf("%f", &area1);

    //Esse comando serve para prioorizar o que o usuario digitou

    printf("PIB (em bilhões): ");
    scanf("%lf", &pib_digitado1);      

    //Pontos turísticos

    printf("Numero de Pontos Turisticos: ");  
    scanf("%d", &turistico1);

    //Equação para os calculos de Densidade e Per Capita

    pib_real1 = pib_digitado1 * 1e9;
    densidade1 = (float)populacao1 / area1;
    capita1 = (float)pib_real1 / populacao1;

    sleep(2);

    //  Entrada para Segunda carta

    printf("\n==========================\n");
    printf("\n Cadastro da Carta 2 \n");
    printf("\n==========================\n");
    
    sleep(2);

    //Segue os mesmos Moldes de Informações

    printf("\nNome do País: ");
    scanf(" %[^\n]", país2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%lf", &pib_digitado2);

    printf("Numero de Pontos Turisticos: "); 
    scanf("%d", &turistico2);

    //Calculos de densidade e conversão do valor digitado em bilhão

    pib_real2 = pib_digitado2 * 1e9;
    densidade2 = (float)populacao2 / area2;
    capita2 = (float)pib_real2 / populacao2;

    //Todas as informações passadas

    printf("\nCadastro concluido com sucesso!\n"); 

    //Atributos para serem selecionados
    printf("\n========================================\n");
    printf("\nEscolha um Atributo de Comparação: \n");
    printf("\n========================================\n");
    printf("1. População: \n");
    sleep(1);
    printf("2. Área: \n");
    sleep(1);
    printf("3. PIB: \n");
    sleep(1);
    printf("4. Densidade: \n");
    sleep(1);
    printf("5. Pontos Turísticos: \n");
    sleep(1);
    printf("Escolha: ");
    scanf("%d", &atributo1);

    sleep(1);
    printf("\n========================================\n");
    printf("\nEscolha +1 Atributo para Comparação Diferente do Anterior: \n");
    printf("\n========================================\n");
    sleep(1);
    if (atributo1 != 1) printf("1. População: \n");
    sleep(1);
    if (atributo1 != 2) printf("2. Área: \n");
    sleep(1);
    if (atributo1 != 3) printf("3. PIB: \n");
    sleep(1);
    if (atributo1 != 4) printf("4. Densidade: \n");
    sleep(1);
    if (atributo1 != 5) printf("5. Pontos Turísticos: \n");
    sleep(1);

    printf("Escolha: ");
    scanf("%d", &atributo2);
    
    while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
        printf("Erro: escolha outro atributo entre 1 e 5: ");
        scanf("%d", &atributo2);
    }
    
    printf("\n========COMPARAÇÃO DE CARTAS =========\n");
    printf("\n======== %s : %s ========\n", país1, país2);
    printf("\n========================================\n");


    //Utilização do Switch para os atributos selecionados

    switch (atributo1)
    {
    case 1:
        (populacao1 > populacao2) 
        ? (printf("Carta %s ganhou contendo mais Habitantes!\n", país1), pontuação1++)
        : (printf("Carta %s ganhou contendo mais Habitantes!\n", país2), pontuação2++);
        strcpy(atriname1, "População");
        break;
    case 2:
        (area1 > area2)
        ? (printf("Carta %s ganhou contendo mais Expansão Territorial!\n",país1),pontuação1++)
        : (printf("Carta %s ganhou contendo mais Expansão Territorial\n", país2),pontuação2++);
        strcpy(atriname1, "Área");
        break;
    case 3:
        (pib_real1 > pib_real2)
        ? (printf("Carta %s ganhou tendo o maior PIB!\n",país1),pontuação1++)
        : (printf("Carta %s ganhou tendo o maior PIB!\n", país2),pontuação2++);
        strcpy(atriname1, "PIB");
        break;
    case 4:
        (densidade1 < densidade2)
        ? (printf("Carta %s ganhou pois teve a menor Densidade Populacional!\n", país1),pontuação1++)
        : (printf("Carta %s ganhou pois teve a menor Densidade Populacional!\n", país2),pontuação2++);
        strcpy(atriname1, "Densidade");
        break;

    case 5:
        (turistico1 > turistico2)
        ? (printf("Carta %s ganhou, pois teve o mais Pontos Turísticos!\n", país1),pontuação1++)
        : (printf("Carta %s ganhou, pois teve o mais Pontos Turísticos!\n", país2),pontuação2++);
        strcpy(atriname1, "Pontos Turísticos");
        break;
    default:
        printf("Opção Inválida!");
        return 0;
    }

    switch (atributo2)
    {
    case 1:
        (populacao1 > populacao2) 
        ? (printf("Carta %s ganhou contendo mais Habitantes!\n", país1), pontuação1++)
        : (printf("Carta %s ganhou contendo mais Habitantes!\n", país2), pontuação2++);
        strcpy(atriname2, "População");
        break;
    case 2:
        (area1 > area2)
        ? (printf("Carta %s ganhou contendo mais Expansão Territorial!\n",país1),pontuação1++)
        : (printf("Carta %s ganhou contendo mais Expansão Territorial\n", país2),pontuação2++);
        strcpy(atriname2, "Área");
        break;
    case 3:
        (pib_real1 > pib_real2)
        ? (printf("Carta %s ganhou tendo o maior PIB!\n",país1),pontuação1++)
        : (printf("Carta %s ganhou tendo o maior PIB!\n", país2),pontuação2++);
        strcpy(atriname2, "PIB");
        break;
    case 4:
        (densidade1 < densidade2)
        ? (printf("Carta %s ganhou pois teve a menor Densidade Populacional!\n", país1),pontuação1++)
        : (printf("Carta %s ganhou pois teve a menor Densidade Populacional!\n", país2),pontuação2++);
        strcpy(atriname2, "Densidade");
        break;

    case 5:
        (turistico1 > turistico2)
        ? (printf("Carta %s ganhou! Pois teve o mais Pontos Turísticos!\n", país1),pontuação1++)
        : (printf("Carta %s ganhou! Pois teve o mais Pontos Turísticos!\n", país2),pontuação2++);
        strcpy(atriname2, "Pontos Turísticos");
        break;
    default:
        printf("Opção Inválida!");
        return 0;
    }
        
    //Exibição da Primeira Carta Trunfo

    sleep(3);
    printf("\n CARTA nº1 \n");
    sleep(1);
    printf("Nome do País: %s \n", país1);
    sleep(1);
    printf("População: %lu Habitantes\n", populacao1);
    sleep(1);
    printf("Área: %.2f km²\n", area1);
    sleep(1);
    printf("PIB: %.2lf bilhões de reais\n", pib_digitado1);
    sleep(1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    sleep(1);
    printf("PIB per Capita: R$%.2lf\n", capita1);
    sleep(2);

    //Exibição da Segunda Carta Trunfo

    printf("\n CARTA nº2 \n");
    sleep(1);
    printf("Nome do País: %s\n", país2);
    sleep(1);
    printf("População: %lu Habitantes\n", populacao2);
    sleep(1);
    printf("Área: %.2f km²\n", area2);
    sleep(1);
    printf("PIB: %.2lf bilhões de reais\n", pib_digitado2);
    sleep(1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    sleep(1);
    printf("PIB per Capita: R$%.2lf\n", capita2);

    //Baseado nos Critérios Selecionado pelo usuário e pontuações em que cada País ganhou

    printf("\n====================================\n");
    printf("\nBASEADO NOS CRITERIOS DE COMPARAÇÃO\n");
    printf("\n1º Atributo: %s\n",atriname1);
    printf("\n2º Atributo: %s \n", atriname2);
    printf("\n====================================\n");



    (pontuação1 > pontuação2)
    ? printf("\nO País %s Ganhou com mais Pontuações\n", país1)
    : (pontuação1 < pontuação2
        ? printf("\nO País %s Ganhou com mais Pontuações\n", país2)
        : printf("\nOs Países %s e %s Empataram em Pontuações\n", país1, país2));
    
    sleep(2);
    printf("\nSuper Trunfo - Países\n");
    printf("\nVersão 1.0 — Desenvolvido por Jorge Fuly\n");

    
    //Fim do Código
    
    return 0;
}
