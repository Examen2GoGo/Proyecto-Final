#pragma once
#include "stdafx.h"

#include "Elemento.h"
#include "NodoArbol.h"
#include "DoublyLinkedList.h"
#include "Operando.h"
#include "Operador.h"
#include "OperadorSuma.h"
#include "OperadorResta.h"
#include "OperadorDivision.h"
#include "OperadorMultiplicacion.h"
#include "OperadorSen.h"
#include "OperadorCos.h"
#include "OperadorTan.h"
#include "OperadorLn.h"
#include "OperadorElevacion.h"
#include "OperadorFuncion.h"

using namespace std;

class Operacion : public Elemento {
private:

	static const int NUM_OPERADORES = 10;
	static const char OPERADORES[NUM_OPERADORES];
	static const char LEFT_PARENTHESIS = '(';
	static const char RIGHT_PARENTHESIS = ')';
	static const char RIGHT_BRACKET = ']';
	static const char LEFT_BRACKET = '[';
	string operacion;

	
	DoublyLinkedList<int> * hijosArbol;

	virtual void imprimir(ostream&);
	void eliminarEspaciosEnBlanco();
	void eliminarParentesisInnecesarios(string &);
	void reemplazar(string, string);
	void reemplazarOperadores();
	int indiceMenorPrecedencia(string);
	Elemento * procesarStringHijo(string);

public:
	Operacion(string);
	virtual ~Operacion();

	NodoArbol<Elemento *> * descomponer();

	string getValor();

	virtual Elemento * clonar();
};

