
#pragma once

#include "Operador.h"
#include "Operando.h"

class OperadorMultiplicacion :
	public Operador {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorMultiplicacion();
	~OperadorMultiplicacion();

	virtual Elemento * operar(Elemento *, Elemento *);

	virtual Elemento * clonar();
};

