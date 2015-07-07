
#pragma once

#include "stdafx.h"
#include "NodoArbol.h"
#include "IteradorArbol.h"

using namespace std;

template<class T>
class ArbolBinario {

	template<class T>
	friend ostream & operator<<(ostream &, ArbolBinario<T> &);

private:
	NodoArbol<DoublyLinkedList<T>> * raiz;

	

public:
	ArbolBinario(DoublyLinkedList<T> elemento) {
		this->raiz = new NodoArbol<DoublyLinkedList<T>>(elemento);
	}

	virtual ~ArbolBinario() {
		if (raiz != NULL) {
			destruirRec(raiz);
		}
	}

	void ArbolBinario::descomponer() {
		descomponerRec(raiz);
	}
	
	NodoArbol<DoublyLinkedList<T>> * ArbolBinario::solucionar() {
		solucionarRec(raiz);
		return raiz;
	}
	void insertar(T elemento) {
		DoublyLinkedList<T> nuevoElemento = new DoublyLinkedList<T>();
		nuevoElemento.addLast(elemento);
		NodoArbol <DoublyLinkedList<T>> * nodo = new <DoublyLinkedList<T>>(nuevoElemento);
		if (raiz == NULL) {
			raiz = nodo;
		} else {
			insertarRec(raiz, nodo);
		}
	}

	IteradorArbol<T> begin() {
		return IteradorArbol<T>(raiz);
	}

	IteradorArbol<T> end() {
		return IteradorArbol<T>(NULL);
	}

private:

	void ArbolBinario::descomponerRec(NodoArbol <DoublyLinkedList<T>> * actual) {
		DoublyLinkedList<T> * actualLista = actual->getNodoArbol();
		T * elemento = actualLista->getFirstElement();
		Operacion * operacion = dynamic_cast<Operacion *>(elemento);
		if (operacion != NULL) {

			Elemento * tmp = elemento;
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

	void Arbol::solucionarRec(NodoArbol <T> * actual) {
		T * hijo = actual->getNodoArbol();
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

	
	void insertarRec(NodoArbol<T> * nodoActual, NodoArbol<T> * elemento) {
		/*
		if (nodoActual->actual < elemento->actual) {
			if (nodoActual->hIzq != NULL) {
				insertarRec(nodoActual->hIzq, elemento);
			} else {
				nodoActual->hIzq = elemento;
				elemento->padre = nodoActual;
			}
		} else {
			if (nodoActual->hDer != NULL) {
				insertarRec(nodoActual->hDer, elemento);
			} else {
				nodoActual->hDer = elemento;
				elemento->padre = nodoActual;
			}
		}*/
	}

	void imprimir(NodoArbol<T>* nodo, ostream& out, int profundidad) {
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
	}

	void destruirRec(NodoArbol<T> * nodo) {
		if (nodo->hIzq != NULL) {
			destruirRec(nodo->hIzq);
		}
		if (nodo->hDer != NULL) {
			destruirRec(nodo->hDer);
		}
		delete nodo;
	}
};

template<class T>
ostream & operator<<(ostream & out, ArbolBinario<T> & a) {
	a.imprimir(a.raiz, out, 0);
	return out;
}
