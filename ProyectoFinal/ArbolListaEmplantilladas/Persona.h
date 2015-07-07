#pragma once

using namespace std;

class Persona {

	friend ostream & operator<<(ostream &, Persona &);

	template <class T>
	friend class NodoLista;

private:
	string nombre;
	int id;
	

public:
	Persona();
	Persona(string, int);
	~Persona();

	bool operator<(Persona &);
	bool operator>(Persona &);

};

ostream & operator<<(ostream &, Persona &);

