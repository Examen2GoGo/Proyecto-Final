
#pragma once

using namespace std;

class Elemento {

	friend ostream& operator<<(ostream &, Elemento &);

protected:
	Elemento * proximo, *hijoIzquierdo, *hijoDerecho;

	virtual void imprimir(ostream&) = 0;

public:

	Elemento();
	virtual ~Elemento();

	Elemento * getProximo();
	Elemento *& getHijoIzquierdo();
	Elemento *& getHijoDerecho();

	void setProximo(Elemento *);
	void setHijoIzquierdo(Elemento *);
	void setHijoDerecho(Elemento *);

	virtual Elemento * clonar() = 0;
};

ostream& operator<<(ostream &, Elemento &);
