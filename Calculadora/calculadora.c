/*
 * Autores: Gabriel Marques, Fernando Araujo, Vinicius Matos, Allan Gabriel, Atila Santana
 * Data: maio de 2025
 * Descricao: Descrição: Implementação das funções da calculadora financeira.
 * Inclui funções para calcular: juros simples, juros compostos, amortização (Price),
 * valor presente e valor futuro.00
 */
#include "calculadora.h"
#include <math.h>

double calcular_juros_simples (double capital, double taxa_de_juros, int tempo){
	return capital * (taxa_de_juros / 100) * tempo;// JurosSimples = Capital * taxa * tempo
}

double calcular_juros_compostos (double capital, double taxa_de_juros, int tempo){
	return capital * (pow(1 + taxa_de_juros / 100, tempo));// JurosCompostos = Capital * (1 * taxa)^tempo
};

double calcular_amortizacao (double capital, double taxa_de_juros, int tempo){
	double calculo1, calculo2;
	calculo1 = taxa_de_juros * pow (1 + taxa_de_juros, tempo);// Parte 1 do calculo: Taxa * (1 + taxa)^tempo
    calculo2 = pow(1 + taxa_de_juros, tempo) - 1;// Parte 2 do calculo: (1 + taxa)^tempo - 1
    return capital * (calculo1 / calculo2);// Amortizacao = (taxa * (1 + taxa)^tempo) / ((1 + taxa)^tempo - 1)
}
    
double calcular_valor_presente (double valor_futuro, double taxa_de_juros, int tempo){
    return valor_futuro / pow(1 + taxa_de_juros, tempo);// ValorPresente = ValorFuturo / ((1 + taxa)^tempo)
  }
    	
double calcular_valor_futuro (double valor_presente, double taxa_de_juros, int tempo){
	return valor_presente * pow(1 + taxa_de_juros, tempo);// ValorFuturo = ValorPresente * ((1 + tempo)^tempo)		
}
