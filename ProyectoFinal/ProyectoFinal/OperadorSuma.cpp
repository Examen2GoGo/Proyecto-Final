#include "stdafx.h"
#include "OperadorSuma.h"

OperadorSuma::OperadorSuma() {
}

OperadorSuma::~OperadorSuma() {
}

void OperadorSuma::imprimir(ostream & out) {
	out << '+' << endl;
}

Elemento * OperadorSuma::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	Operando * b = dynamic_cast<Operando *>(*++it);
	return new Operando(a->getValor() + b->getValor());
}
