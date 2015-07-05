
#pragma once

#include "stdafx.h"
//#include "Operacion.h"
#include "Nodo.h"

using namespace std;

class Lista {

	friend ostream& operator<<(ostream&, Lista&);

private:
	Nodo *cabeza, *cola;
	int cantidadElementos;
	Nodo * obtenerNuevoNodo(Elemento *);

public:
	Lista();
	Lista(istream &);
	~Lista();

	void insertar(Elemento *);
	Nodo * primerElemento();
	int getCantidadElementos();
	Elemento * getCopy(int);
};

ostream& operator<<(ostream&, Lista&);

