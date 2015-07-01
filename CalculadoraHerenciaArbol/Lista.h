
#pragma once

#include "Elemento.h"
#include "Operacion.h"

using namespace std;

class Lista {

	friend ostream& operator<<(ostream&, Lista&);

private:
	Elemento *cabeza, *cola;
	int cantidadElementos;

public:
	Lista();
	Lista(istream &);
	~Lista();

	void insertar(Elemento *);
	int getCantidadElementos();
	Elemento * getCopy(int);
};

ostream& operator<<(ostream&, Lista&);

