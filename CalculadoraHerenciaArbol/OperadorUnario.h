#pragma once

#include "Operador.h"
#include "Operando.h"

class OperadorUnario :public Operador {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorUnario();
	~OperadorUnario();

	virtual Elemento * operar(Elemento *, Elemento *);

	virtual Elemento * clonar();
};