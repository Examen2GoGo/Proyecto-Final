#pragma once

template<class T, template<class L> class DoublyLinkedList>
class NodoArbol {

	template <class T>
	friend class ArbolBinario;

	template <class T>
	friend class IteradorArbol;

private:
	DoublyLinkedList <T> actual;
	NodoArbol<DoublyLinkedList<T>> *padre, *hijos;

public:
	NodoArbol(DoublyLinkedList<T> lista){
		this->actual = lista;
		padre = NULL;
		hijos = NULL;
	}

	~NodoArbol() {
	}

	DoublyLinkedList<T> * NodoArbol::getNodoArbol(){
		return actual;
	}

};

