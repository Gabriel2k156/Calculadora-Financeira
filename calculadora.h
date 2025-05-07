#ifndef CALCULADORA_H
#define CALCULADORA_H

double calcular_juros_simples (double capital, double taxa_de_juros, int tempo);
double calcular_juros_compostos (double capital, double taxa_de_juros, int tempo);
double calcular_amortizacao (double capital, double taxa_de_juros, int tempo);
double calcular_valor_presente (double valor_futuro, double taxa_de_juros, int tempo);
double calcular_valor_futuro (double valor_presente, double taxa_de_juros, int tempo);


#endif