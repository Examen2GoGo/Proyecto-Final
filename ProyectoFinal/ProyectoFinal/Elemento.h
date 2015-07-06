
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

	Elemento * getProximo();
	Elemento *& getHijoIzquierdo();
	Elemento *& getHijoDerecho();
	Elemento *& getHijo1();
	Elemento *& getHijo2();

	void setProximo(Elemento *);
	void setHijoIzquierdo(Elemento *);
	void setHijoDerecho(Elemento *);
	void setHijo1(Elemento *);
	void setHijo2(Elemento *);


	virtual Elemento * clonar() = 0;
};

ostream& operator<<(ostream &, Elemento &);
