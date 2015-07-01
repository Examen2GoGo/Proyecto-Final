
#pragma once

#include "Operador.h"
#include "Operando.h"

class OperadorDivision :
	public Operador {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorDivision();
	~OperadorDivision();

	virtual Elemento * operar(Elemento *, Elemento *);

	virtual Elemento * clonar();
};

