#pragma once

using namespace std;

class Elemento {

	friend ostream& operator<<(ostream &, Elemento &);

protected:
	virtual void imprimir(ostream&) = 0;

public:
	virtual ~Elemento() {};
};

ostream& operator<<(ostream &, Elemento &);
