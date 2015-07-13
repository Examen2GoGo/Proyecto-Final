#include "stdafx.h"
#include "OperadorTan.h"

OperadorTan::OperadorTan() {
}

OperadorTan ::~OperadorTan() {
}

void OperadorTan::imprimir(ostream & out) {
	out << "t" << endl;
}

Elemento * OperadorTan::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	return new Operando(tan(a->getValor()));
}

