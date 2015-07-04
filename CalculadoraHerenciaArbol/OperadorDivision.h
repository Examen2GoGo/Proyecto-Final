
#pragma once

#include "OperadorBinario.h"
#include "Operando.h"

class OperadorDivision : public OperadorBinario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorDivision();
	~OperadorDivision();

	virtual Elemento * operar(Elemento *, Elemento *);

	virtual Elemento * clonar();
};

