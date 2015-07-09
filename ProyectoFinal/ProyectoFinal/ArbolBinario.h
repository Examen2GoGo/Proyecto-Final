
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

private:
	NodoArbol<T, DoublyLinkedList> * raiz;

	

public:
	ArbolBinario(NodoArbol<T, DoublyLinkedList> elemento) {
		this->raiz = elemento;

	}

	virtual ~ArbolBinario() {
		if (raiz != NULL) {
			destruirRec(raiz);
		}
	}

	void ArbolBinario::descomponer() {
		descomponerRec(raiz);
	}
	
	NodoArbol<T, DoublyLinkedList> * ArbolBinario::solucionar() {
		solucionarRec(raiz);
		return raiz;
	}
	void insertar(T elemento) {
		DoublyLinkedList<T> nuevoElemento = new DoublyLinkedList<T>();
		nuevoElemento.addLast(elemento);
		NodoArbol <T, DoublyLinkedList> * nodo = new <DoublyLinkedList<T>>(nuevoElemento);
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

	void ArbolBinario::descomponerRec(NodoArbol <T, DoublyLinkedList> * actual) {
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


	void ArbolBinario::solucionarRec(NodoArbol <T, DoublyLinkedList> * actual) {
				if (actual != NULL) {
					if(actual->hijos != NULL){
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
	
	void insertarRec(NodoArbol<T, DoublyLinkedList> * nodoActual, NodoArbol<T, DoublyLinkedList> * elemento) {
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
	}

	void destruirRec(NodoArbol<T, DoublyLinkedList> * nodo) {
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
