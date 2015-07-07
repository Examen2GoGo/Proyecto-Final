
#pragma once

#include "stdafx.h"
#include "operador.h"
#include "Operando.h"

class OperadorUnario :public Operador {

protected:
	virtual void imprimir(ostream&)= 0;

public:

	virtual ~OperadorUnario() {};
	virtual Elemento * operar(DoublyLinkedList<Elemento>&) = 0;

	virtual Elemento * clonar() = 0;
};