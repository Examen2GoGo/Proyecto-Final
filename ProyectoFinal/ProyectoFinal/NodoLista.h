#pragma once

template<class T>
class NodoLista {

	template <class T>
	friend class DoublyLinkedList;
	
	template <class T>
	friend class IteradorLista;
	
	template <class T>
	friend class IteradorInverso;
	
private:
	T actual;
	NodoLista<T> *next, *prev;

public:
	NodoLista(T elemento) {
		this->actual = elemento;
		next = NULL;
		prev = NULL;
	}

	~NodoLista() {
	}

	T * NodoLista::getNodoLista(){
		return actual;
	}
};
