
#pragma once

#include "Elemento.h"
#include "Operador.h"
#include "Operacion.h"
#include "Nodo.h"
#include "Lista.h"

class Arbol {
private:
	Nodo * raiz;
	
	void destruirRec(Elemento *);
	void solucionarRec(Elemento *);
	void descomponerRec(Elemento *);
	

public:
	Arbol(Elemento *);
	~Arbol();
	Lista * hijos;

	void descomponer();
	Elemento * solucionar();
};