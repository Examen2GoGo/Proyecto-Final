#pragma once
#include"stdafx.h"
#include "Operador.h"
#include "Operando.h"

class OperadorBinario :public Operador {

protected:
	virtual void imprimir(ostream&) = 0;

public:

	virtual ~OperadorBinario() {};

	virtual Elemento * operar(DoublyLinkedList<Elemento *>&) = 0;

};
