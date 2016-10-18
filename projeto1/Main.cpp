#include "Supermarket.h"
#include "Cashier.h"
#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

vector<Cashier> vetor(100);

void verificaSeCriaCliente(Supermarket superMarket){
	if(superMarket.relogio == superMarket.tempoChegada){
		Client novo = superMarket.geraCliente();
		//verifica se não há fila com menos de 10
		int aux;
		for(int i = 0; i < superMarket.circList.size(); ++i){
			if(superMarket.circList.at(i).calculaPessoas() > 9){
				++aux;
			}
		}
		if(aux == superMarket.circList.size()){
			superMarket.valorComprasDesistentes = novo.valorTotalDeCompras * 3;
			++superMarket.clientesDesistentes;
			return;
		}
		//verifica qual caixa deve ir
		int caixa;
		if(novo.tipoDoCliente == 0) {
			int compras = 500;
			for(int i = 0; i < superMarket.circList.size(); ++i){
				if(superMarket.circList.at(i).calculaCompras() < compras){
					compras = superMarket.circList.at(i).calculaCompras();
					caixa = i;
				}
			}
		}
		else {
			int pessoas = 500;
			for(int i = 0; i < superMarket.circList.size(); ++i){
				if(superMarket.circList.at(i).calculaPessoas() < pessoas) {
					pessoas = superMarket.circList.at(i).calculaPessoas();
					caixa = i;
				}
			}
	}
	//calcula tempo de saida
	int tempoAnterior = 0;
	for(int i = 0; i < superMarket.circList.at(caixa).queue.size(); ++i){
		tempoAnterior += superMarket.circList.at(caixa).queue.at(i).tempoDeSaida;
	}
	novo.calculaTempoSaida(superMarket.circList.at(caixa).eficiencia, tempoAnterior);
	superMarket.circList.at(caixa).queue.enqueue(novo);
	superMarket.tempoChegada=+superMarket.tempoChegada;
	}
}


int main(int argc, char **argv) {
	char linha[100], nomeMercado[50], *sub, nomeCaixa[80];
	int tempoSimulacao, tempoChegada, numeroCaixas, eficiencia, salario;
	ifstream arquivo("market.dat");
	
	arquivo.getline(linha, 100);
	
	strncpy(nomeMercado, linha, 50);
	arquivo >> tempoSimulacao;
	arquivo >> tempoChegada;
	arquivo >> numeroCaixas;

	cout << "Nome do Supermercado: " << nomeMercado << endl;
	cout << "Tempo de Simulacao: " << tempoSimulacao << endl;
	cout << "Tempo medio de chegada de clientes: " << tempoChegada << " segundos."<< endl;
	cout << "Numero de caixas: " << numeroCaixas << endl;

	arquivo.getline(linha,200);

	Cashier* array;
	array = new Cashier[numeroCaixas];
	for (int i = 0; i < numeroCaixas; i++) {
		arquivo.getline(linha,200);	  
		sub = strtok(linha, "-");
		strncpy(nomeCaixa,sub,80);
		sub = strtok(NULL, "-");
		eficiencia = atoi(sub);
		sub = strtok(NULL, "-");
		salario = atoi(sub);
		printf("%d\n", eficiencia);
		Cashier c(eficiencia, salario, nomeCaixa);
		array[i] = c;
	}

	/*Cashier c1(1, 800, nomeMercado);
	array[0] = c1;
	array[1] = c1;
	array[2] = c1;*/
	Supermarket sp(tempoSimulacao, tempoChegada, array, numeroCaixas, nomeMercado);

	sp.comecaCaixas(numeroCaixas);
	while(sp.relogio < sp.tempoSimulacao) {
		for(int i = 0; i < sp.circList.size(); ++i){
			sp.circList.at(i).verificaSeSai(sp.relogio);
		}
		verificaSeCriaCliente(sp);
		++sp.relogio;
	}
	printf("%d\n", sp.circList.at(1).clientesAtendidos);
	return 0;
}
