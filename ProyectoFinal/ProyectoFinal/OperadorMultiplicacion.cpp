#include "stdafx.h"
#include "OperadorMultiplicacion.h"

OperadorMultiplicacion::OperadorMultiplicacion() {
}

OperadorMultiplicacion::~OperadorMultiplicacion() {
}

void OperadorMultiplicacion::imprimir(ostream & out) {
	out << '*' << endl;
}

Elemento * OperadorMultiplicacion::operar(DoublyLinkedList<Elemento>& valores) {
	//Elemento * a = valores.primerElemento()->obtenerDatos();
	//Elemento * b = valores.primerElemento()->siguienteElemento()->obtenerDatos();
	//Operando * izq = dynamic_cast<Operando *>(a);
	//Operando * der = dynamic_cast<Operando *>(b);
	//return new Operando(izq->getValor() * der->getValor());
	return new Operando(0);
}

Elemento * OperadorMultiplicacion::clonar() {
	return new OperadorMultiplicacion();
}
