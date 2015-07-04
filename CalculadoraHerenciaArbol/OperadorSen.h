#pragma once

#include "OperadorUnario.h"
#include "Operando.h"

class OperadorSen : public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorSen();
	~OperadorSen();

	virtual Elemento * operar(Lista *);

	virtual Elemento * clonar();
};

