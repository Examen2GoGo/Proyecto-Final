#pragma once

#include "Operador.h"
#include "Operando.h"

class OperadorUnario :public Operador {

protected:
	virtual void imprimir(ostream&)= 0;

public:
	OperadorUnario();
	~OperadorUnario();

	virtual Elemento * operar(Lista*) = 0;

	virtual Elemento * clonar() = 0;
};