#pragma once
#include "DoublyLinkedList.h"
template <typename T, template <class> class U>
class NodoArbol {

	template <class T>
	friend class ArbolBinario;

	template <class T>
	friend class IteradorArbol;

private:
	DoublyLinkedList <T> actual;
	T elementoActual;
	NodoArbol <T,DoublyLinkedList>*padre, *hijos;

public:
	NodoArbol( T lista){
		this->actual = lista;
		this->elementoActual = elemento;
		padre = NULL;
		hijos = NULL;
	}

	~NodoArbol() {
	}

	DoublyLinkedList<T> * NodoArbol::getNodoArbol(){
		return actual;
	}

};

