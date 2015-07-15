#include "stdafx.h"
#include "OperadorSen.h"


OperadorSen::OperadorSen() {
}

OperadorSen ::~OperadorSen() {
}

void OperadorSen::imprimir(ostream & out) {
	out << "s" << endl;
}

Elemento * OperadorSen::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	return new Operando(sin(a->getValor()));
}
