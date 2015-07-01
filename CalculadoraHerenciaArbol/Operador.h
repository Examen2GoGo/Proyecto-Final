
#pragma once

#include "stdafx.h"
#include "Elemento.h"

using namespace std;

class Operador : public Elemento {

protected:
	virtual void imprimir(ostream&) = 0;

public:
	virtual Elemento * operar(Elemento *, Elemento *) = 0;

	virtual Elemento * clonar() = 0;
};