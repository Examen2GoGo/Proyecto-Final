#pragma once
#include "stdafx.h"
//#include "Operador.h"
//#include "Operando.h"

class OperadorUnario :public Operador {

protected:
	virtual void imprimir(ostream&)= 0;

public:
	OperadorUnario();
	~OperadorUnario();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&) = 0;

	virtual Elemento * clonar() = 0;
};