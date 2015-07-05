#pragma once
#include "stdafx.h"
//#include "OperadorTernario.h"
//#include "Operando.h"

class OperadorFuncion : public OperadorTernario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorFuncion();
	~OperadorFuncion();

	virtual Elemento * operar(Lista*);

	virtual Elemento * clonar();
};


