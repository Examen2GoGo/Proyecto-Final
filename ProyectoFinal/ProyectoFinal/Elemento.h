
#pragma once
#include "stdafx.h"

using namespace std;

class Elemento {

	friend ostream& operator<<(ostream &, Elemento &);

protected:
	virtual void imprimir(ostream&) = 0;

public:
	//Elemento();
	//virtual ~Elemento();
	virtual Elemento * clonar() = 0;
};

ostream& operator<<(ostream & out, Elemento & elemento) {
	elemento.imprimir(out);
	return out;
}
