
#include "stdafx.h"
#include "Arbol.h"


Arbol::Arbol(Elemento * nodo) {
	this->raiz = new Nodo(nodo);
	hijos = NULL;
}

Arbol::~Arbol() {
	destruirRec(raiz->obtenerDatos());
}

void Arbol::destruirRec(Elemento * actual) {
	if (actual->getHijoIzquierdo() != NULL) {
		destruirRec(actual->getHijoIzquierdo());
	}
	if (actual->getHijoDerecho() != NULL) {
		destruirRec(actual->getHijoDerecho());
	}
	delete actual;
}

void Arbol::descomponer() {
	descomponerRec(raiz->obtenerDatos());
}

void Arbol::descomponerRec(Elemento * actual) {
	Operacion * operacion = dynamic_cast<Operacion *>(actual);
	if (operacion != NULL) {

		Elemento * tmp = actual;
		actual = operacion->descomponer();
		delete tmp;
		Elemento * izq = actual->getHijo1();
		Elemento * der = actual->getHijo2();
		hijos->insertar(izq);
		hijos->insertar(der);
		if (izq != NULL) {
			descomponerRec(actual->getHijo1());
		}
		if (der != NULL) {
			descomponerRec(actual->getHijo2());
		}
	}
}

Elemento * Arbol::solucionar() {
	solucionarRec(raiz->obtenerDatos());
	return raiz->obtenerDatos();
}

void Arbol::solucionarRec(Elemento * actual) {
	Elemento * izq = actual->getHijo1();
	Elemento * der = actual->getHijo2();
	Operador * op = dynamic_cast<Operador*>(actual);
	if (op != NULL) {
		if (izq != NULL) {
			solucionarRec(actual->getHijo1());
		}
		if (der != NULL) {
			solucionarRec(actual->getHijo2());
		}
		Elemento * solucion = op->operar(hijos);
		delete actual;
		actual = solucion;
	}
}
