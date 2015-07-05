#include "stdafx.h"
#include "OperadorElevacion.h"


OperadorElevacion::OperadorElevacion() {
}

OperadorElevacion::~OperadorElevacion() {
}

void OperadorElevacion::imprimir(ostream & out) {
	out << '^' << endl;
}

Elemento * OperadorElevacion::operar(Lista * valores) {
	Elemento * a = valores->primerElemento()->obtenerDatos();
	Elemento * b = valores->primerElemento()->siguienteElemento()->obtenerDatos();
	Operando * izq = dynamic_cast<Operando *>(a);
	Operando * der = dynamic_cast<Operando *>(b);
	return new Operando(pow((izq->getValor()),(der->getValor())));
}


Elemento * OperadorElevacion::clonar() {
	return new OperadorElevacion();
}