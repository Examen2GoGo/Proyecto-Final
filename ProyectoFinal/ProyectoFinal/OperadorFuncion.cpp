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
	//Elemento * a = valores.primerElemento()->obtenerDatos();
	//Elemento * b = valores.primerElemento()->siguienteElemento()->obtenerDatos();
	//Operando * izq = dynamic_cast<Operando *>(a);
	//Operando * der = dynamic_cast<Operando *>(b);
	//return new Operando(izq->getValor() / der->getValor());
	return new Operando(0);
}
