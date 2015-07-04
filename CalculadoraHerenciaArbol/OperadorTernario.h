#pragma once

#include "Operador.h"
#include "Operando.h"

class OperadorTernario :public Operador {

protected:
	virtual void imprimir(ostream&) = 0;

public:
	OperadorTernario();
	~OperadorTernario();

	virtual Elemento * operar(Lista*) = 0;

	virtual Elemento * clonar() = 0;
};
