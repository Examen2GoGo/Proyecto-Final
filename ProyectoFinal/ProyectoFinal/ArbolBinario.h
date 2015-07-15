
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


	Elemento * solucionar() {
		raiz = descomponerRec(raiz);
		raiz = solucionarRec(raiz);
		return raiz->actual;
	}

	IteradorArbol<T> begin() {
		return IteradorArbol<T>(raiz);
	}

	IteradorArbol<T> end() {
		return IteradorArbol<T>(NULL);
	}

private:

	NodoArbol<Elemento *> *  descomponerRec(NodoArbol<Elemento *> * actual) {
		NodoArbol<Elemento *> * resultado = actual;
		Operacion * operacion = dynamic_cast<Operacion *>(actual->getActual());
		if (operacion != NULL) {

			NodoArbol<Elemento *> * temp = actual;
			resultado = operacion->descomponer();
			delete temp;

			DoublyLinkedList<Elemento *> listaTemporal;
			DoublyLinkedList<Elemento *> elementos = resultado->getHijos();

			if (elementos.sizeLinkedList() != 0){
				IteradorLista<Elemento *> it = elementos.begin();
				while (it != elementos.end()) {
					NodoArbol<Elemento *> * temp2 = new NodoArbol<Elemento *>(*it++);
					listaTemporal.addLast(descomponerRec(temp2)->actual);
					//delete temp2;
				}
			}
			resultado->setHijos(listaTemporal);
		}
		return resultado;
	}


	NodoArbol<Elemento *> * solucionarRec(NodoArbol<Elemento *> * actual) {
		NodoArbol<Elemento *> * resultado = actual;
		Operador * operacion = dynamic_cast<Operador *>(actual->getActual());
		if (operacion != NULL) {

			DoublyLinkedList<Elemento *> listaTemporal;
			DoublyLinkedList<Elemento *> elementos = resultado->getHijos();
			if (elementos.sizeLinkedList() != 0){
				IteradorLista<Elemento *> it = elementos.begin();
				while (it != elementos.end()) {
					NodoArbol<Elemento *> * temp2 = new NodoArbol<Elemento *>(*it++);
					listaTemporal.addLast(solucionarRec(temp2)->getActual());
					//*****
					delete temp2; // revisar en descomponerRec
					//****
				}
				DoublyLinkedList<Elemento *> operandos = actual->getHijos();
				Operador * op = dynamic_cast<Operador*>(actual->getActual());
				Elemento * solucion = op->operar(operandos);
				delete actual;
				resultado = new NodoArbol<Elemento *>(solucion);
			}
			resultado->setHijos(listaTemporal);
		}
		return resultado;
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

};


template<class T>
ostream & operator<<(ostream & out, ArbolBinario<T> & a) {
	a.imprimir(a.raiz, out, 0);
	return out;
}
