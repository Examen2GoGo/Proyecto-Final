#pragma once

template<class T>
class NodoArbol {

	template <class T>
	friend class ArbolBinario;

	template <class T>
	friend class IteradorArbol;

private:
	T actual;
	NodoArbol<T> *padre, *hIzq, *hDer;

public:
	NodoArbol(T elemento) {
		this->actual = elemento;
		padre = NULL;
		hIzq = NULL;
		hDer = NULL;
	}

	~NodoArbol() {
	}

};

