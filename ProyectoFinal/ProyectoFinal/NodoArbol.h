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
	NodoArbol <T,DoublyLinkedList>*padre, *hijos;

public:
	NodoArbol(DoublyLinkedList<T> elementos){
		this->actual = elementos;
		padre = NULL;
		hijos = NULL;
	}

	~NodoArbol() {
	}

	DoublyLinkedList<T> * NodoArbol::getNodoArbol(){
		return actual;
	}

	DoublyLinkedList<T> * NodoArbol::getNodoArbolHijos(){
		return hijos;
	}

	void NodoArbol::setHijos(DoublyLinkedList<T> * elementos){
		hijos = new NodoArbol(elementos);
	}

};

