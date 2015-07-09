#pragma once

using namespace std;

class Elemento {

	friend ostream& operator<<(ostream &, Elemento &);

protected:
	virtual void imprimir(ostream&) = 0;

public:
	virtual ~Elemento() {};
	virtual Elemento * clonar() = 0;
};

ostream& operator<<(ostream &, Elemento &);
