
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
		for (iterator it = elementos.begin(); it != elementos.end(); ++it){
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
		DoublyLinkedList<T> * hijo = actual->getNodoArbol();
		for (iterator it = hijo.begin(); it != hijo.end(); ++it){
			if (*it != NULL){
				T * nuevoOp =*it->getNodoLista
				Operador * op = dynamic_cast<Operador*>(nuevoOp);
				if (nuevoOp != NULL) {
					if(hijo != NULL){
						solucionarRec(actual->hijos);
					}
					Elemento * solucion = op->operar(hijos);
					delete actual;
					actual = new NodoArbol(DoublyLinkedList(solucion));
				}
			}

		}
		/*Elemento * der = actual->getHijoDerecho();
		//Operador * op = dynamic_cast<Operador*>(actual);
		if (op != NULL) {
			if (izq != NULL) {
				solucionarRec(actual->hijos);
			}
			if (der != NULL) {
				solucionarRec(actual->getHijoDerecho());
			}
			Elemento * solucion = op->operar(actual->getHijoIzquierdo(), actual->getHijoDerecho());
			delete actual;
			actual = solucion;
		}*/
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
