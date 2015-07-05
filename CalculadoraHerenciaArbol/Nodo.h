#pragma once
#include "Elemento.h"

class Nodo {
	friend class Arbol;
	//friend class Iterador;

private:
	Elemento * actual;

	

public:
	Nodo * siguiente;
	Nodo(Elemento * elemento) {
		this->actual = elemento;
		siguiente = 0;
	}

	~Nodo() {
	}

	Elemento * obtenerDatos()
	{
		return actual;
	}
};

