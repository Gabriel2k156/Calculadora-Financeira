#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "calculadora.h"
 
 double J, M; // J = Juros simples // M = Juros compostos
 double capital, parcela, calculo1, calculo2;
 double taxa_de_juros, valor_presente, valor_futuro;
 int opcao, tipo_de_juros, tempo;
 int main() {
     do{
     printf("\n          CALCULADORA FINANCEIRA\n\n");
     printf("Qual operacao financeira deseja calcular?\n\n");
     printf("1 = Juros Simples\n2 = Juros Compostos\n");
     printf("3 = Amortizacao\n4 = Valor Presente\n");
     printf("5 = Valor Futuro\n6 = Sair\n");
     scanf("%d", &opcao);
     while (getchar() != '\n'); // Limpa o buffer para que o getchar() funcione no final do programa
    
     switch(opcao){
     
     
     case 1:
     
        printf("Qual o valor da capital?\n");
        scanf("%lf", &capital);
        
        printf("Qual a taxa de juros?\n");
        scanf("%lf", &taxa_de_juros);
        
        printf("Os juros sao mensais ou anuais\n1 = Mensais\n2 = Anuais\n");
        scanf("%d", &tipo_de_juros);
        
        if(tipo_de_juros == 1){
        printf("Digite o periodo em MESES\n");// Nao e necessario nenhum tipo de conversao, o calculo ja e feito usando meses como base
        scanf("%d", &tempo);
        }
         
        else if(tipo_de_juros == 2){
        printf("Digite o periodo em ANOS\n");
        scanf("%d", &tempo);

        tempo = tempo * 12; // Converte a entrada de ANOS para MESES para realizar o calculo, proporcionalmente
        taxa_de_juros = taxa_de_juros / 12; // Mesma coisa dita acima
        }
         
        printf ("Valor com juros = R$%.2lf\n", calcular_juros_simples (capital, taxa_de_juros, tempo) + capital);// Juros_Simples = Capital * tx de juros * tempo
        break; // Impede que o resto dos "case" sejam executados
        
         
     case 2:
         
        printf("Qual o valor da capital?\n");
        scanf("%lf", &capital);
         
        printf("Qual a taxa de juros?\n");
        scanf("%lf", &taxa_de_juros);
         
        printf("Os juros sao mensais ou anuais?\n1 = Mensais\n2 = Anuais\n");
        scanf("%d", &tipo_de_juros);
         
        if(tipo_de_juros == 1){
        printf("Digite o periodo em MESES\n");
        scanf("%d", &tempo);
        }
         
        else if(tipo_de_juros == 2){
        printf("Digite o periodo em ANOS\n");
        scanf("%d", &tempo);

        tempo = tempo * 12; // Converte a entrada de ANOS para MESES para realizar o calculo, proporcionalmente
        taxa_de_juros = taxa_de_juros / 12; // Mesma coisa dita acima
        }
   
        printf("Valor com juros = R$%.2lf\n", calcular_juros_compostos ( capital, taxa_de_juros, tempo));
        break;// Impede que o resto dos "case" sejam executados
         
        case 3:
         
        printf("Qual o valor financiado?\n");
        scanf("%lf", &capital);
         
        printf("Os juros sao mensais ou anuais?\n1 = Mensais\n2 = Anuais\n");
        scanf("%d", &tipo_de_juros);
         
        if(tipo_de_juros == 1){
        printf("Qual a taxa de juros MENSAL?\n");
        scanf("%lf", &taxa_de_juros);
        if(taxa_de_juros <= 0){
        printf("A taxa de juros nao pode ser zero\n");
        break;
        }
         
        printf("Digite o periodo em MESES\n");
        scanf("%d", &tempo);
        }
         
        else if(tipo_de_juros == 2){
        printf("Qual a taxa de juros ANUAL?");
        scanf("%lf", &taxa_de_juros);
             
        printf("Digite o periodo em ANOS\n");
        scanf("%d", &tempo);
        tempo = tempo * 12; // Converte a entrada de ANOS para MESES para realizar o calculo, proporcionalmente
        taxa_de_juros = taxa_de_juros / 12; // Mesma coisa dita acima
        }
         
         
        printf("Parcela = %.2lf\n", calcular_amortizacao (capital, taxa_de_juros, tempo));
        break;// Impede que o resto dos "case" sejam executados
         
        case 4:
        printf("Digite o valor futuro\n");
        scanf("%lf", &valor_futuro);

        printf("Os juros sao mensais ou anuais?\n1 = Mensais\n2 = Anuais\n");
        scanf("%d", &tipo_de_juros);
         
        if(tipo_de_juros == 1){
        printf("Qual a taxa de juros MENSAL?\n");
        scanf("%lf", &taxa_de_juros);
            
        printf("Digite o periodo em MESES\n");
        scanf("%d", &tempo); 
        
        taxa_de_juros = taxa_de_juros / 100;// Converte a entrada de numero inteiro (taxa de juros) em decimal

        }
         
        else if(tipo_de_juros == 2){
        printf("Digite o periodo em ANOS\n");
        scanf("%d", &tempo);

        printf("Digite a taxa de juros ANUAL\n");
        scanf("%lf", &taxa_de_juros);

        tempo = tempo * 12; // Converte a entrada de ANOS para MESES para realizar o calculo, proporcionalmente
        taxa_de_juros = (taxa_de_juros / 100) / 12; // Mesma coisa dita acima
        }


        printf("O valor presente liquido e de R$%.2lf\n", calcular_valor_presente (valor_futuro, taxa_de_juros, tempo));
        break;// Impede que o resto dos "case" sejam executados

        case 5:
        printf("Digite o valor presente\n");
        scanf("%lf", &valor_presente);
        
        printf("Os juros sao mensais ou anuais?\n1 = Mensais\n2 = Anuais\n");
         scanf("%d", &tipo_de_juros);
         
        if(tipo_de_juros == 1){
        printf("Qual a taxa de juros MENSAL?\n");
        scanf("%lf", &taxa_de_juros);
            
        printf("Digite o periodo em MESES\n");
        scanf("%d", &tempo);

        taxa_de_juros = taxa_de_juros / 100;
        }  

        else if(tipo_de_juros == 2){
        printf("Qual a taxa de juros ANOS?\n");
        scanf("%lf", &taxa_de_juros);
                
        printf("Digite o periodo em ANOS\n");
        scanf("%d", &tempo);

        tempo = tempo * 12;
        taxa_de_juros = (taxa_de_juros / 100) / 12;// Converte a entrada de numero inteiro (taxa de juros) em decimal
        }
        valor_futuro = valor_presente * pow(1 + taxa_de_juros, tempo);// VF = VP * (1 + juros)^tempo

        printf("O valor futuro do seu investimento e de R$%.2lf\n", calcular_valor_futuro ( valor_presente, taxa_de_juros, tempo));
        break;// Impede que o resto dos "case" sejam executados

        case 6:

        printf("Saindo da calculadora...\n");
        getchar(); // Pede uma entrada antes do programa fechar
         break;// Impede que o resto dos "case" sejam executados

        default:
        printf("Digite uma opcao valida\n");// Impede que seja utilizada outra opcao alem das listadas no menu
        }  
       }   
     
     
     while(opcao != 6);
    
     return 0;
    }