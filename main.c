///////////////////////////////////////////////////////////////////////////////////////////////
// Projeto: Sistema de Aprovação de Empréstimo                                              //
// Local: NetBeans - v18                                                                    //
// Data: 23/03/2025                                                                         //
// Autor: Diogo Moreira - 2023.1.08.003                                                     //
// Disciplina: Algoritmos e Estruturas de Dados I - Prática                                 //
// Objetivo: Desenvolver um algoritmo para avaliar a solicitação de um empréstimo bancário  //
// e classificar de acordo com critérios como renda, idade e histórico de crédito.          //
//////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>

int main(){
    // igualado a zero para evitar o lixo de memoria     
    int idade = 0, Historico_Credito = 0, Num_Parcelas_Atraso = 0, Num_Parcelas_Atraso_2anos = 0;
    float Renda_Mensal = 0;

    // o uso de varios while para caso a informaçao nao corresponda a pergunta
    printf("\nInforme sua idade: ");
    scanf("%d", &idade);
    while (idade < 0 || idade > 100) {
        printf("\n\tIdade inválida!!");
        printf("\nInforme sua idade: ");
        scanf("%d", &idade);
    }

    printf("\nInforme sua renda mensal: ");
    scanf("%f", &Renda_Mensal);
    while (Renda_Mensal < 0) {
        printf("\n\tInforme um valor positivo!!");
        printf("\nInforme sua renda mensal: ");
        scanf("%f", &Renda_Mensal);
    }

    printf("\nInforme se seu histórico de crédito está negativo(1) ou não(0): ");
    scanf("%d", &Historico_Credito);
    while (Historico_Credito != 0 && Historico_Credito != 1) {
        printf("\n\tEntrada inválida! Insira 1 para negativo ou 0 para não negativo.");
        printf("\nInforme se seu histórico de crédito está negativo(1) ou não(0): ");
        scanf("%d", &Historico_Credito);
    }

    printf("\nInforme o número de parcelas em atraso atualmente: ");
    scanf("%d", &Num_Parcelas_Atraso);
    while (Num_Parcelas_Atraso < 0) {
        printf("\n\tO número de parcelas não pode ser negativo.");
        printf("\nInforme o número de parcelas em atraso atualmente: ");
        scanf("%d", &Num_Parcelas_Atraso);
    }

    printf("\nInforme o número de parcelas em atraso nos últimos 2 anos: ");
    scanf("%d", &Num_Parcelas_Atraso_2anos);
    while (Num_Parcelas_Atraso_2anos < 0) {
        printf("\n\tO número de parcelas não pode ser negativo.");
        printf("\nInforme o número de parcelas em atraso nos últimos 2 anos: ");
        scanf("%d", &Num_Parcelas_Atraso_2anos);
    }

    // Empréstimo Negado
    if (Renda_Mensal < 2000 || Historico_Credito == 1 || idade < 18 || idade > 70) {
        printf("\n\tEmpréstimo Negado!!\n");
    }
    // Empréstimo de Baixo Valor 
    else if (Renda_Mensal >= 2000 && Renda_Mensal < 5000 && Num_Parcelas_Atraso <= 2) {
        printf("\n\tEmpréstimo de Baixo Valor (até R$ 5.000,00)\n");
    }
    // Empréstimo de Médio Valor
    else if (Renda_Mensal >= 5000 && Renda_Mensal < 10000 && Num_Parcelas_Atraso == 0 && Num_Parcelas_Atraso_2anos <= 4) {
        printf("\n\tEmpréstimo de Médio Valor (até R$ 20.000,00)\n");
    }
    // Empréstimo de Alto Valor
    else if (Renda_Mensal >= 10000 && Num_Parcelas_Atraso_2anos == 0) {
        printf("\n\t Empréstimo de Alto Valor (acima de R$ 20.000,00)\n");
    }

    return 0;
}
