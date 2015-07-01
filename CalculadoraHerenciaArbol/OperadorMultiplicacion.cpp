
#include "stdafx.h"
#include "OperadorMultiplicacion.h"

OperadorMultiplicacion::OperadorMultiplicacion() {
}

OperadorMultiplicacion::~OperadorMultiplicacion() {
}

void OperadorMultiplicacion::imprimir(ostream & out) {
	out << '*' << endl;
}

Elemento * OperadorMultiplicacion::operar(Elemento * a, Elemento * b) {
	Operando * izq = dynamic_cast<Operando *>(a);
	Operando * der = dynamic_cast<Operando *>(b);
	return new Operando(izq->getValor() * der->getValor());
}

Elemento * OperadorMultiplicacion::clonar() {
	return new OperadorMultiplicacion();
}
