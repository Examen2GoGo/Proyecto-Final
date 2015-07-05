
#pragma once

#include "Elemento.h"
#include "Operador.h"
#include "Operacion.h"
#include "Nodo.h"
#include "Lista.h"

class Arbol {
	
private:
	Nodo * raiz;
	
	void destruirRec(Nodo *);
	void solucionarRec(Nodo *);
	void descomponerRec(Nodo *);
	

public:
	Arbol(Nodo *);
	~Arbol();
	Lista * hijos;

	void descomponer();
	Elemento * solucionar();
};