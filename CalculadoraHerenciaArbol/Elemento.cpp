
#include "stdafx.h"
#include "Elemento.h"

Elemento::Elemento() {
	this->proximo = NULL;
	this->hijoIzquierdo = NULL;
	this->hijoDerecho = NULL;
	this->hijos = NULL;
	this->hijo1 = NULL;
	this->hijo2 = NULL;
}

Elemento::~Elemento() {
}

Elemento * Elemento::getProximo() {
	return proximo;
}

Elemento *& Elemento::getHijoIzquierdo() {
	return hijoIzquierdo;
}

Elemento *& Elemento::getHijoDerecho() {
	return hijoDerecho;
}

void Elemento::setProximo(Elemento * proximo) {
	this->proximo = proximo;
}

void Elemento::setHijo1(Elemento * hijo) {
	this->hijo1 = hijo;
	hijos->insertar(hijo);
}

void Elemento::setHijo2(Elemento * hijo) {
	this->hijo2 = hijo;
	hijos->insertar(hijo);
}

void Elemento::setHijoIzquierdo(Elemento * hijoIzquierdo) {
	this->hijoIzquierdo = hijoIzquierdo;
}

void Elemento::setHijoDerecho(Elemento * hijoDerecho) {
	this->hijoDerecho = hijoDerecho;
}


ostream& operator<<(ostream & out, Elemento & elemento) {
	elemento.imprimir(out);
	return out;
}
