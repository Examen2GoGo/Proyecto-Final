
#pragma once

#include "stdafx.h"
#include "NodoArbol.h"
#include "IteradorArbol.h"
#include "IteradorLista.h"

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
	NodoArbol<Elemento *> * raiz;

public:

	ArbolBinario(T operacion) {
		raiz = new NodoArbol<Elemento *>(operacion);
	}

	virtual ~ArbolBinario() {
		if (raiz != NULL) {
			//destruirRec(raiz);
		}
	}

	NodoArbol<Elemento *> * getRaiz(){
		return this->raiz;
	}


	void destruirRec(NodoArbol<Elemento *> * nodo) {
		/*
		if (nodo->actual != NULL) {
		destruirRec(nodo->hIzq);
		delete nodo;
		}
		*/
	}


	NodoArbol<Elemento *> solucionar() {
		descomponerRec(raiz);
		solucionarRec(raiz);
		return NULL;  raiz;
	}

private:

	void descomponerRec(NodoArbol<Elemento *> * actual) {
		Operacion * operacion = dynamic_cast<Operacion *>(actual->getActual());
		if (operacion != NULL) {
			// Este llamado modifica la lista
			//NodoArbol<Elemento *> * temp = actual;
			actual = operacion->descomponer();
			//delete temp;

			DoublyLinkedList<Elemento *> elementos = actual->getHijos();
			if (elementos.sizeLinkedList() != 0){
				IteradorLista<Elemento *> it = elementos.begin();
				while (it != elementos.end()) {
					descomponerRec(new NodoArbol<Elemento *>(*it++));
				}
			}
		}
	}
	/*
	; // agarro la lista de los hijos
	NodoArbol<T> * raizNodo;
	IteradorLista<T> it = elementos.begin(); //recorro la lista de forma fácil
	while (it != elementos.end()) {
	Operacion * operacion = dynamic_cast<Operacion *>(*it++);
	if (operacion != NULL) {
	// Este llamado modifica la lista
	//NodoArbol<Elemento*>(*it) = operacion->descomponer();



	}
	}*/



	void solucionarRec(NodoArbol<Elemento *> *& actual) {
		/*
		DoublyLinkedList<T> elementos = actual->getHijos();
		NodoArbol<T> * raizNodo;

		if (actual->getActual() != NULL) {
		if (elementos.sizeLinkedList() != NULL){
		IteradorLista<T> it = elementos.begin();
		while (it != elementos.end()) {
		Operacion * operacion = dynamic_cast<Operacion *>(*it++);
		raizNodo = new NodoArbol<T>(operacion);
		solucionarRec(raizNodo);
		}
		DoublyLinkedList<T> operandos = actual->getHijos();
		Operador * op = dynamic_cast<Operador*>(actual->getActual());
		//Elemento * solucion = op->operar(operandos);
		DoublyLinkedList<T> listaSolucion;
		//listasolucion.addLast(solucion);
		delete actual;
		//actual = new NodoArbol(solucion);
		}
		}
		}*/

	}


	void imprimir(NodoArbol<Elemento *>* nodo, ostream& out, int profundidad) {
		/*
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
		*/
	}


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
