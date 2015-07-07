#include "stdafx.h"
#include "OperadorCos.h"


OperadorCos::OperadorCos() {
}

OperadorCos::~OperadorCos() {
}

void OperadorCos::imprimir(ostream & out) {
	out << "c" << endl;
}

Elemento * OperadorCos::operar(DoublyLinkedList<Elemento>& valores) {
	//Elemento * a = valores.primerElemento()->obtenerDatos();
	//Operando * izq = dynamic_cast<Operando *>(a);
	//Operando * der = dynamic_cast<Operando *>(b);
	//return new Operando(cos(izq->getValor()));
	return new Operando(0);
}


Elemento * OperadorCos::clonar() {
	return new OperadorCos();
}