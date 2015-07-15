#include "stdafx.h"
#include "OperadorCos.h"


OperadorCos::OperadorCos() {
}

OperadorCos::~OperadorCos() {
}

void OperadorCos::imprimir(ostream & out) {
	out << "c" << endl;
}

Elemento * OperadorCos::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	return new Operando(tan(a->getValor()));
}

