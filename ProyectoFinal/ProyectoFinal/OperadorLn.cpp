#include "stdafx.h"
#include "OperadorLn.h"

OperadorLn::OperadorLn() {
}

OperadorLn::~OperadorLn() {
}

void OperadorLn::imprimir(ostream & out) {
	out << "L" << endl;
}

Elemento * OperadorLn::operar(DoublyLinkedList<Elemento *>& valores) {
	IteradorLista<Elemento *> it = valores.begin();
	Operando * a = dynamic_cast<Operando *>(*it);
	return new Operando(log(a->getValor()));

}
