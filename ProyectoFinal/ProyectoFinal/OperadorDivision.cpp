#include "stdafx.h"
#include "OperadorDivision.h"

OperadorDivision::OperadorDivision() {
}

OperadorDivision::~OperadorDivision() {
}

void OperadorDivision::imprimir(ostream & out) {
	out << '/' << endl;
}

Elemento * OperadorDivision::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	Operando * b = dynamic_cast<Operando *>(*++it);
	return new Operando(a->getValor() / b->getValor());
}
