
#pragma once
#include "stdafx.h"

using namespace std;

class Elemento {

	friend ostream& operator<<(ostream &, Elemento &);

protected:
	Elemento * proximo, *hijoIzquierdo, *hijoDerecho, *hijo1, *hijo2; //*hijo3;
	

	virtual void imprimir(ostream&) = 0;

public:

	Elemento();
	virtual ~Elemento();
	Lista * hijos;

	Elemento * getProximo();
	Elemento *& getHijoIzquierdo();
	Elemento *& getHijoDerecho();

	void setProximo(Elemento *);
	void setHijoIzquierdo(Elemento *);
	void setHijoDerecho(Elemento *);
	void setHijo1(Elemento *);
	void setHijo2(Elemento *);


	virtual Elemento * clonar() = 0;
};

ostream& operator<<(ostream &, Elemento &);
