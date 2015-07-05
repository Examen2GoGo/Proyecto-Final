
#pragma once
#include "stdafx.h"
//#include "OperadorBinario.h"
//#include "Operando.h"

class OperadorResta : public OperadorBinario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorResta();
	~OperadorResta();

	virtual Elemento * operar(Lista*);

	virtual Elemento * clonar();
};

