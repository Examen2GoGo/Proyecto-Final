#include "stdafx.h"
#include "OperadorResta.h"

OperadorResta::OperadorResta() {
}

OperadorResta::~OperadorResta() {
}

void OperadorResta::imprimir(ostream & out) {
	out << '-' << endl;
}

Elemento * OperadorResta::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	Operando * b = dynamic_cast<Operando *>(*++it);
	return new Operando(a->getValor() - b->getValor());
}
