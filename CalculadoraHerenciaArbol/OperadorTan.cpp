#include "stdafx.h"
#include "OperadorTan.h"

OperadorTan::OperadorTan() {
}

OperadorTan ::~OperadorTan() {
}

void OperadorTan::imprimir(ostream & out) {
	out << "tan" << endl;
}

Elemento * OperadorTan::operar(Elemento * a, Elemento * b) {
	Operando * izq = dynamic_cast<Operando *>(a);
	Operando * der = dynamic_cast<Operando *>(b);
	return new Operando(tan(izq->getValor()));
}


Elemento * OperadorTan::clonar() {
	return new OperadorTan();
}
