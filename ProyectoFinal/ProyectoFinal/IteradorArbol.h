#pragma once

#include "NodoArbol.h"

template<class T>
class IteradorArbol {
private:
	NodoArbol<T,DoublyLinkedList> * anterior;
	NodoArbol<T, DoublyLinkedList> * actual;

public:

	IteradorArbol(NodoArbol<T, DoublyLinkedList> * actual) {
		this->anterior = actual;
		this->actual = actual;
	}

	~IteradorArbol() {
	}

	// Preincremento
	IteradorArbol<T>& operator++() {
		bool continuar = true;
		while (continuar && actual != 0) {
			continuar = false;
			NodoArbol<T> * tmp = actual;
			if (actual != NULL && anterior == actual->hIzq) {
				if (actual->hDer != NULL) {
					actual = actual->hDer;
				} else {
					actual = actual->padre;
					continuar = true;
				}
			} else if (actual != NULL && anterior == actual->hDer) {
				actual = actual->padre;
				continuar = true;
			} else if (actual->hIzq != NULL) {
				actual = actual->hIzq;
			} else if (actual->hDer != NULL) {
				actual = actual->hDer;
			} else {
				actual = actual->padre;
				continuar = true;
			}
			anterior = tmp;
		}
		return *this;
	}

	// Posincremento
	IteradorArbol<T> operator++(int) {
		IteradorArbol<T> tmp(this->actual);
		++(*this);
		return tmp;
	}

	T operator*() {
		return actual->actual;
	}

	bool operator!=(IteradorArbol<T> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(IteradorArbol<T> & otro) {
		return this->actual == otro.actual;
	}

};

