#pragma once

#include "Operador.h"
#include "Operando.h"

class OperadorBinario :public Operador {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorBinario();
	~OperadorBinario();

	virtual Elemento * operar(Elemento *, Elemento *);

	virtual Elemento * clonar();
};
