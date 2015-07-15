#include "stdafx.h"
#include "OperadorElevacion.h"


OperadorElevacion::OperadorElevacion() {
}

OperadorElevacion::~OperadorElevacion() {
}

void OperadorElevacion::imprimir(ostream & out) {
	out << '^' << endl;
}

Elemento * OperadorElevacion::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	Operando * b = dynamic_cast<Operando *>(*++it);
	return new Operando(pow((a->getValor()), (b->getValor())));
}
