#include "stdafx.h"
#include "OperadorLn.h"

OperadorLn::OperadorLn() {
}

OperadorLn::~OperadorLn() {
}

void OperadorLn::imprimir(ostream & out) {
	out << "L" << endl;
}

Elemento * OperadorLn::operar(Elemento * a, Elemento * b) {
	Operando * izq = dynamic_cast<Operando *>(a);
	Operando * der = dynamic_cast<Operando *>(b);
	return new Operando(log(izq->getValor()));
}


Elemento * OperadorLn::clonar() {
	return new OperadorLn();
}