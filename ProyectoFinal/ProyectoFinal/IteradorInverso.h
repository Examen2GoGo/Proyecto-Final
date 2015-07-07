#pragma once
#include "NodoLista.h"

template<class T>
class IteradorInverso{
private:
	NodoLista<T> * actual;

public:

	IteradorInverso(NodoLista<T> * actual){
		this->actual = actual;
	}

	~IteradorInverso(){
	}

	// Predecremento
	IteradorInverso<T>& operator--() {
		this->actual = this->actual->prev;
		return *this;
	}

	// Posdecremento
	IteradorInverso<T> operator--(int) {
		IteradorInverso<T> tmp(this->actual);
		--(*this);
		return tmp;
	}

	T operator*() {
		return actual->actual;
	}

	bool operator!=(IteradorInverso<T> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(IteradorInverso<T> & otro) {
		return this->actual == otro.actual;
	}

};