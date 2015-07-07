#include "stdafx.h"
#include "OperadorSuma.h"

OperadorSuma::OperadorSuma() {
}

OperadorSuma::~OperadorSuma() {
}

void OperadorSuma::imprimir(ostream & out) {
	out << '+' << endl;
}

Elemento * OperadorSuma::operar(DoublyLinkedList<Elemento>& valores) {
	//Elemento * a = valores.primerElemento()->obtenerDatos();
	//Elemento * b = valores.primerElemento()->siguienteElemento()->obtenerDatos();
	//Operando * izq = dynamic_cast<Operando *>(a);
	//Operando * der = dynamic_cast<Operando *>(b);
	//return new Operando(izq->getValor() + der->getValor());
	return new Operando(0);
}

Elemento * OperadorSuma::clonar() {
	return new OperadorSuma();
}
