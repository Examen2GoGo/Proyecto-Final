#include "stdafx.h"
#include "OperadorFuncion.h"

OperadorFuncion::OperadorFuncion() {
}

OperadorFuncion::~OperadorFuncion() {
}

void OperadorFuncion::imprimir(ostream & out) {
	out << "F" << endl;
}

Elemento * OperadorFuncion::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	Operando * b = dynamic_cast<Operando *>(*++it);
	Operando * c = dynamic_cast<Operando *>(*++it);
	return new Operando(a->getValor() + b->getValor() + c->getValor());
}
