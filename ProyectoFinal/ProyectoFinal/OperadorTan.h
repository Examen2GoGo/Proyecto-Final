#pragma once

#include "OperadorUnario.h"
#include "Operando.h"

class OperadorTan : public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorTan();
	~OperadorTan();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&);

	virtual Elemento * clonar();
};
