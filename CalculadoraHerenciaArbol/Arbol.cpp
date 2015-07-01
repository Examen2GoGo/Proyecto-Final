
#include "stdafx.h"
#include "Arbol.h"

Arbol::Arbol(Elemento * nodo) {
	this->raiz = nodo;
}

Arbol::~Arbol() {
	destruirRec(raiz);
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
	descomponerRec(raiz);
}

void Arbol::descomponerRec(Elemento *& actual) {
	Operacion * operacion = dynamic_cast<Operacion *>(actual);
	if (operacion != NULL) {

		Elemento * tmp = actual;
		actual = operacion->descomponer();
		delete tmp;

		Elemento * izq = actual->getHijoIzquierdo();
		Elemento * der = actual->getHijoDerecho();
		if (izq != NULL) {
			descomponerRec(actual->getHijoIzquierdo());
		}
		if (der != NULL) {
			descomponerRec(actual->getHijoDerecho());
		}
	}
}

Elemento * Arbol::solucionar() {
	solucionarRec(raiz);
	return raiz;
}

void Arbol::solucionarRec(Elemento *& actual) {
	Elemento * izq = actual->getHijoIzquierdo();
	Elemento * der = actual->getHijoDerecho();
	Operador * op = dynamic_cast<Operador*>(actual);
	if (op != NULL) {
		if (izq != NULL) {
			solucionarRec(actual->getHijoIzquierdo());
		}
		if (der != NULL) {
			solucionarRec(actual->getHijoDerecho());
		}
		Elemento * solucion = op->operar(actual->getHijoIzquierdo(), actual->getHijoDerecho());
		delete actual;
		actual = solucion;
	}
}
