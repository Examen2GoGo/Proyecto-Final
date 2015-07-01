
#pragma once

#include "Elemento.h"

using namespace std;

class Operando : public Elemento {
private:
	double valor;

	virtual void imprimir(ostream&);

public:
	Operando(double);
	virtual ~Operando();

	double getValor();

	virtual Elemento * clonar();
};