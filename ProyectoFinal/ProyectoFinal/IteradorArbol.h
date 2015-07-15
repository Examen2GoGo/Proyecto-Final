#pragma once

#include "NodoArbol.h"

template<class T>
class IteradorArbol {
private:
	NodoArbol<T> * anterior;
	NodoArbol<T> * actual;

public:

	IteradorArbol(NodoArbol<T> * actual) {
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
			if (actual != NULL && anterior == actual->hijos) {
				if (actual->hijos != NULL) {
					actual = actual->hijos;
				}
				else {
					actual = actual->padre;
					continuar = true;
				}
			}
			else if (actual != NULL && anterior == actual->hijos) {
				actual = actual->padre;
				continuar = true;
			}
			else if (actual->hijos != NULL) {
				actual = actual->hijos;
			}
			else {
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

