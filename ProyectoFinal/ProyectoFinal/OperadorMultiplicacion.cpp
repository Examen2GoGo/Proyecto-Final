#include "stdafx.h"
#include "OperadorMultiplicacion.h"

OperadorMultiplicacion::OperadorMultiplicacion() {
}

OperadorMultiplicacion::~OperadorMultiplicacion() {
}

void OperadorMultiplicacion::imprimir(ostream & out) {
	out << '*' << endl;
}

Elemento * OperadorMultiplicacion::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	Operando * b = dynamic_cast<Operando *>(*++it);
	return new Operando(a->getValor() * b->getValor());
}

