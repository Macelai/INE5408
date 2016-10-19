#include "Supermarket.h"
#include <string.h>

Supermarket::Supermarket(int tempoSimulacao_, int tempoChegada_, Cashier* caixas_, int totalDeCaixas_, char nome_[]) {
	relogio = 0;
	clientesDesistentes = 0;
	valorComprasDesistentes = 0;
	tempoSimulacao = tempoSimulacao_*60*60;
	tempoChegada = 0;
	tempoChegadaNovo = tempoChegada_;
	caixas = caixas_;
	totalDeCaixas = totalDeCaixas_;
	strcpy(nome_,nome);
}

Supermarket::Supermarket(){
	relogio = 0;
}

Client Supermarket::geraCliente() {
	return Client(relogio);
}
