
#pragma once

#include "stdafx.h"
#include "NodoArbol.h"
#include "IteradorArbol.h"

using namespace std;

template<class T>
class ArbolBinario {

	template <class T>
	friend class ArbolBinario;

	template <class T>
	friend class IteradorArbol;

	template<class T>
	friend ostream & operator<<(ostream &, ArbolBinario<T> &);

public:
	NodoArbol<T> * raiz;

	ArbolBinario() {
		raiz = NULL;
	}

	virtual ~ArbolBinario() {
		if (raiz != NULL) {
			//destruirRec(raiz);
		}
	}
	/*
	void destruirRec(NodoArbol<T, DoublyLinkedList> * nodo) {
		if (nodo->actual != NULL) {
			destruirRec(nodo->hIzq);
			delete nodo;
		}
	}
	*/

	NodoArbol<T> * solucionar(Operacion * op) {
		op = raiz;
		descomponerRec(raiz);
		solucionarRec(raiz);
		return raiz;
	}

private:

	void descomponerRec(NodoArbol <T, DoublyLinkedList> * actual) {
		DoublyLinkedList<T> elementos = actual->getNodoArbol;
		for (IteratorLista<T> it = elementos.begin(); it != elementos.end(); ++it){
			if (*it != NULL){
				Operacion * operacion = dynamic_cast<Operacion *>(*it);
				if (operacion != NULL) {
					Elemento * tmp = elemento;
					actual = operacion->descomponer();
					delete tmp;

					if (actual->hijos != NULL){
						descomponerRec(hijos);
					}

				}
			}
		}
	}


	void solucionarRec(Elemento * actual) {
		if (actual != NULL) {
			if (actual->hijos != NULL){
				solucionarRec(actual->hijos);
			}
			DoublyLinkedList<T> operandos = actual->hijos->getNodoArbolHijos();
			Operador * op = dynamic_cast<Operador*>(actual->getNodoArbol()->getFirstElement());
			Elemento * solucion = op->operar(operandos);
			DoublyLinkedList<T> listaSolucion;
			listasolucion.addLast(solucion);
			delete actual;
			actual = new NodoArbol(listaSolucion);
		}
	}

	/*
	void imprimir(NodoArbol<T, DoublyLinkedList>* nodo, ostream& out, int profundidad) {
	if (nodo->hIzq != NULL) {
	imprimir(nodo->hIzq, out, profundidad + 1);
	}
	for (int i = 0; i < profundidad; ++i) {
	cout << "\t";
	}
	out << nodo->actual << endl;
	if (nodo->hDer != NULL) {
	imprimir(nodo->hDer, out, profundidad + 1);
	}
	}*/


	IteradorArbol<T> begin() {
		return IteradorArbol<T>(raiz);
	}

	IteradorArbol<T> end() {
		return IteradorArbol<T>(NULL);
	}
};

template<class T>
ostream & operator<<(ostream & out, ArbolBinario<T> & a) {
	a.imprimir(a.raiz, out, 0);
	return out;
}
