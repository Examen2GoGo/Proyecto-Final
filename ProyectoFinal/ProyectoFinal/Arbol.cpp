#include "stdafx.h"
#include "Arbol.h"


Arbol::Arbol(Nodo * nodo) {
	this->raiz = nodo;
}

Arbol::~Arbol() {
	destruirRec(raiz);
}

void Arbol::destruirRec(Nodo * actual) {
	if (actual->getHijo0() != NULL) {
		destruirRec(actual->getHijo0());
	}
	if (actual->getHijo1() != NULL) {
		destruirRec(actual->getHijo1());
	}
	actual = NULL;
	delete actual;
	
}

void Arbol::descomponer() {
	descomponerRec(raiz);
}

void Arbol::descomponerRec(Nodo * actual) {
	Operacion * operacion = dynamic_cast<Operacion *>(actual->obtenerDatos());
	if (operacion != NULL) {
		Nodo * tmp = actual;
		actual = operacion->descomponer();
		delete tmp;
		Elemento * izq = actual->getHijo0()->obtenerDatos();
		Elemento * der = actual->getHijo1()->obtenerDatos();
		hijos.insertar(izq);
		hijos.insertar(der);
		if (izq != NULL) {
			descomponerRec(actual->getHijo0());
		}
		if (der != NULL) {
			descomponerRec(actual->getHijo1());
		}
	}
}

Elemento * Arbol::solucionar() {
	solucionarRec(raiz);
	return raiz->obtenerDatos();
}

void Arbol::solucionarRec(Nodo * actual) {
	Operador * op = dynamic_cast<Operador*>(actual->obtenerDatos());
	if (op != NULL) {

		// Recorrer hijos con for


		if (h0 != NULL) {
			solucionarRec(actual->getHijo0());
		}
		if (h1 != NULL) {
			solucionarRec(actual->getHijo1());
		}
		if (h2 != NULL) {
			solucionarRec(actual->getHijo2());
		}
		Elemento * solucion = op->operar(hijos);
		delete actual;
		actual = new Nodo(solucion);
		//Aqui no se está pasando bien la solucion a la raiz
	}
}

Nodo *Arbol::getRaiz(){
	return raiz;
}

