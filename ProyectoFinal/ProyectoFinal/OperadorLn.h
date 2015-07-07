#pragma once

#include "OperadorUnario.h"
#include "Operando.h"

class OperadorLn : public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorLn();
	~OperadorLn();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&);

	virtual Elemento * clonar();
};
