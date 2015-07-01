
#pragma once

#include "Operador.h"
#include "Operando.h"

class OperadorSuma :
	public Operador {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorSuma();
	~OperadorSuma();

	virtual Elemento * operar(Elemento *, Elemento *);

	virtual Elemento * clonar();
};

