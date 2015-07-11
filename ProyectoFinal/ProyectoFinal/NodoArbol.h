#pragma once
#include "DoublyLinkedList.h"


template <class T>
class NodoArbol {

	template <class T>
	friend class ArbolBinario;

	template <class T>
	friend class IteradorArbol;

private:
	T actual;
	DoublyLinkedList<T> hijos;

public:
	NodoArbol(T actual){
		this->actual = actual;
	}

	~NodoArbol() {
	}

	T getActual(){
		return actual;
	}

	void agregarHijo(T hijo) {
		hijos.addLast(hijo);
	}

	T get(int index){
		IteradorLista<T> it = hijos.begin();
		while (index-- > 0) {
			it++;
		}
		return *it;
	}

	DoublyLinkedList<T> & getHijos(){
		return this->hijos;
	}

};

