
#pragma once

#include "OperadorBinario.h"
#include "Operando.h"

class OperadorSuma : public OperadorBinario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorSuma();
	~OperadorSuma();

	virtual Elemento * operar(Lista*);

	virtual Elemento * clonar();
};

