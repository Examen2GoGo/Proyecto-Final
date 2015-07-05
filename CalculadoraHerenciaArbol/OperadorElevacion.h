#pragma once

#include "OperadorBinario.h"
#include "Operando.h"

class OperadorElevacion : public OperadorBinario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorElevacion();
	~OperadorElevacion();

	//virtual Elemento * operar(Lista*);

	virtual Elemento * clonar();
};