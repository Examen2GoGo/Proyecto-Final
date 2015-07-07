#pragma once

#include "OperadorTernario.h"
#include "Operando.h"

class OperadorFuncion : public OperadorTernario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorFuncion();
	~OperadorFuncion();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&);

	virtual Elemento * clonar();
};


