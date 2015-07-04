#pragma once

#include "Operador.h"
#include "Operando.h"

class OperadorTernario :public Operador {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorTernario();
	~OperadorTernario();

	virtual Elemento * operar(Elemento *, Elemento *);

	virtual Elemento * clonar();
};
