#pragma once
#include "stdafx.h"
//#include "OperadorUnario.h"
//#include "Operando.h"

class OperadorCos : public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorCos();
	~OperadorCos();

	virtual Elemento * operar(Lista*);

	virtual Elemento * clonar();
};

