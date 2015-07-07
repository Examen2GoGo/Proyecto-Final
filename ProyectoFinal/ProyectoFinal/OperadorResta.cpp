#include "stdafx.h"
#include "OperadorResta.h"

OperadorResta::OperadorResta() {
}

OperadorResta::~OperadorResta() {
}

void OperadorResta::imprimir(ostream & out) {
	out << '-' << endl;
}

Elemento * OperadorResta::operar(DoublyLinkedList<Elemento>& valores) {
	//Elemento * a = valores.primerElemento()->obtenerDatos();
	//Elemento * b = valores.primerElemento()->siguienteElemento()->obtenerDatos();
	//Operando * izq = dynamic_cast<Operando *>(a);
	//Operando * der = dynamic_cast<Operando *>(b);
	//return new Operando(izq->getValor() - der->getValor());
	return new Operando(0);
}

Elemento * OperadorResta::clonar() {
	return new OperadorResta();
}