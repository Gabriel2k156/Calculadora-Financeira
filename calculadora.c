#include "calculadora.h"
#include <math.h>

double calcular_juros_simples (double capital, double taxa_de_juros, int tempo){
	return capital * (taxa_de_juros / 100) * tempo;
}

double calcular_juros_compostos (double capital, double taxa_de_juros, int tempo){
	return capital * (pow(1 + taxa_de_juros / 100, tempo));
};

double calcular_amortizacao (double capital, double taxa_de_juros, int tempo){
    calculo2 = pow(1 + taxa_de_juros, tempo) - 1;
    calculo1 = taxa_de_juros * pow(1 + taxa_de_juros, tempo);
    return capital * (calculo1 / calculo2);
}
    
double calcular_valor_presente (double valor_futuro, double taxa_de_juros, int tempo){
    return valor_futuro / pow(1 + taxa_de_juros, tempo);
  }
    	
double calcular_valor_futuro (double valor_presente, double taxa_de_juros, int tempo){
	return valor_presente * pow(1 + taxa_de_juros, tempo);		
}
