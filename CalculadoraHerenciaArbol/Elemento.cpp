
#include "stdafx.h"
#include "Elemento.h"

Elemento::Elemento() {
	this->proximo = NULL;
	this->hijoIzquierdo = NULL;
	this->hijoDerecho = NULL;
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
