
#include "stdafx.h"
#include "Lista.h"

Lista::Lista() {
	this->cabeza = NULL;
	this->cola = NULL;
}

Lista::Lista(istream & in) : Lista() {
	while (!in.eof()) {
		string buffer;
		getline(in, buffer);
		Operacion * operacion = new Operacion(buffer);
		if (operacion->getValor() != "") {
			insertar(operacion);
		} else {
			delete operacion;
		}
	}
}

Lista::~Lista() {
	Nodo * actual = cabeza;
	while (actual != NULL) {
		Nodo * tmp = actual;
		actual = actual->siguiente;
		delete tmp;
	}
}

void Lista::insertar(Elemento * nuevoElemento) {
	Nodo *nuevoPtr = obtenerNuevoNodo(nuevoElemento);
	if (cabeza == NULL) {
		cabeza = cola = nuevoPtr;
	} else {
		cola->siguiente = nuevoPtr; 
		cola = nuevoPtr; 
	}
	cantidadElementos++;
}

int Lista::getCantidadElementos() {
	return cantidadElementos;
}

Elemento * Lista::getCopy(int i) {
	Nodo * actual = cabeza;
	while (actual != NULL && i != 0) {
		actual = actual->siguiente;
		i--;
	}
	return actual->obtenerDatos()->clonar();
}

Nodo* Lista::obtenerNuevoNodo(Elemento * nuevoElemento)
{
	return new Nodo(nuevoElemento);
}

ostream& operator<<(ostream & out, Lista & lista) {
	Nodo * actual = lista.cabeza;
	int c = 0;
	while (actual != NULL) {
		out << ++c << ". " << *actual->obtenerDatos() << endl;
		actual = actual->siguiente;
	}
	return out << endl;
}
