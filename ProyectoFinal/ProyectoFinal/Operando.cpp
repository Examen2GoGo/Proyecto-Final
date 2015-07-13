
#include "stdafx.h"

#include "Operando.h"

Operando::Operando(double valor) {
	this->valor = valor;
}

Operando::~Operando() {
}

double Operando::getValor() {
	return valor;
}

void Operando::imprimir(ostream & out) {
	out << valor;
}
