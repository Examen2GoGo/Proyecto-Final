#include "stdafx.h"
#include "OperadorTan.h"

OperadorTan::OperadorTan() {
}

OperadorTan ::~OperadorTan() {
}

void OperadorTan::imprimir(ostream & out) {
	out << "t" << endl;
}

Elemento * OperadorTan::operar(DoublyLinkedList<Elemento>& valores) {
	//Elemento * a = valores.primerElemento()->obtenerDatos();
	//Operando * izq = dynamic_cast<Operando *>(a);
	//Operando * der = dynamic_cast<Operando *>(b);
	//return new Operando(tan(izq->getValor()));
	return new Operando(0);
}


Elemento * OperadorTan::clonar() {
	return new OperadorTan();
}
