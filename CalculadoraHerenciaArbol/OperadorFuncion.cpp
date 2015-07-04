#include "stdafx.h"
#include "OperadorFuncion.h"

OperadorFuncion::OperadorFuncion() {
}

OperadorFuncion::~OperadorFuncion() {
}

void OperadorFuncion::imprimir(ostream & out) {
	out << "F" << endl;
}

Elemento * OperadorFuncion::operar(Lista *) {
	Operando * izq = dynamic_cast<Operando *>(a);
	Operando * der = dynamic_cast<Operando *>(b);
	return new Operando(izq->getValor() / der->getValor());
}

Elemento * OperadorFuncion::clonar() {
	return new OperadorFuncion();
}
