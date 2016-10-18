#include "Supermarket.h"
#include <string.h>

Supermarket::Supermarket(int tempoSimulacao_, int tempoChegada_, Cashier* caixas_, int totalDeCaixas_, char nome_[]) {
	relogio = 0;
	clientesDesistentes = 0;
	valorComprasDesistentes = 0;
	tempoSimulacao = tempoSimulacao_;
	tempoChegada = tempoChegada_;
	caixas = caixas_;
	totalDeCaixas = totalDeCaixas_;
	strcpy(nome_,nome);
}

void Supermarket::comecaCaixas(int numeroCaixas) {
	for(int i = 0; i > numeroCaixas; ++i) {
		circList.push_front(caixas[i]);
	}
}

Client Supermarket::geraCliente() {
	return Client(relogio);
}
