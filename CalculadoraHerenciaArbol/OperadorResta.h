
#pragma once

#include "OperadorBinario.h"
#include "Operando.h"

class OperadorResta : public OperadorBinario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorResta();
	~OperadorResta();

	virtual Elemento * operar(Elemento *, Elemento *);

	virtual Elemento * clonar();
};

