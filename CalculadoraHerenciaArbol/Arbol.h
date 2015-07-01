
#pragma once

#include "Elemento.h"
#include "Operador.h"
#include "Operacion.h"

class Arbol {
private:
	Elemento * raiz;
	
	void destruirRec(Elemento *);
	void solucionarRec(Elemento *&);
	void descomponerRec(Elemento *&);

public:
	Arbol(Elemento *);
	~Arbol();

	void descomponer();
	Elemento * solucionar();
};