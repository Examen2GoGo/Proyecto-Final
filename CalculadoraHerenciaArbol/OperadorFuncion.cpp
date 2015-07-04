#include "stdafx.h"
#include "OperadorFuncion.h"

OperadorFuncion::OperadorFuncion() {
}

OperadorFuncion::~OperadorFuncion() {
}

void OperadorFuncion::imprimir(ostream & out) {
	out << "FUNC" << endl;
}

Elemento * OperadorFuncion::operar(Elemento * a, Elemento * b,Elemento *c) {
	Operando * izq = dynamic_cast<Operando *>(a);
	Operando * der = dynamic_cast<Operando *>(b);
	Operando * otrofunc = dynamic_cast<Operando *>(c);
	return new Operando(izq->getValor() + der->getValor()* otrofunc->getValor());
}

Elemento * OperadorFuncion::clonar() {
	return new OperadorFuncion();
}
