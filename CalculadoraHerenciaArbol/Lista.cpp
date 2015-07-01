
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
	Elemento * actual = cabeza;
	while (actual != NULL) {
		Elemento * tmp = actual;
		actual = actual->getProximo();
		delete tmp;
	}
}

void Lista::insertar(Elemento * nuevoElemento) {
	if (cabeza == NULL) {
		this->cabeza = nuevoElemento;
		this->cola = nuevoElemento;
	} else {
		this->cola->setProximo(nuevoElemento);
		this->cola = nuevoElemento;
	}
	cantidadElementos++;
}

int Lista::getCantidadElementos() {
	return cantidadElementos;
}

Elemento * Lista::getCopy(int i) {
	Elemento * actual = cabeza;
	while (actual != NULL && i != 0) {
		actual = actual->getProximo();
		i--;
	}
	return actual->clonar();
}

ostream& operator<<(ostream & out, Lista & lista) {
	Elemento * actual = lista.cabeza;
	int c = 0;
	while (actual != NULL) {
		out << ++c << ". " << *actual << endl;
		actual = actual->getProximo();
	}
	return out << endl;
}
