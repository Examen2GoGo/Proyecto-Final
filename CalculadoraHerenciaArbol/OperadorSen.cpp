#include "stdafx.h"
#include "OperadorSen.h"


OperadorSen ::OperadorSen () {
}

OperadorSen ::~OperadorSen () {
}

void OperadorSen ::imprimir(ostream & out) {
	out << "s" << endl;
}

/*Elemento * OperadorSen ::operar(Lista* valores) {
	Operando * izq = dynamic_cast<Operando *>(a);
	Operando * der = dynamic_cast<Operando *>(b);
	return new Operando(sin(izq->getValor()));
}*/


Elemento * OperadorSen ::clonar() {
	return new OperadorSen ();
}
