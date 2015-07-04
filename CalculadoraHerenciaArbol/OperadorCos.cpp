#include "stdafx.h"
#include "OperadorCos.h"


OperadorCos::OperadorCos() {
}

OperadorCos::~OperadorCos() {
}

void OperadorCos::imprimir(ostream & out) {
	out << "c" << endl;
}

Elemento * OperadorCos::operar(Elemento * a, Elemento * b) {
	Operando * izq = dynamic_cast<Operando *>(a);
	Operando * der = dynamic_cast<Operando *>(b);
	return new Operando(cos(izq->getValor()));
}


Elemento * OperadorCos::clonar() {
	return new OperadorCos();
}