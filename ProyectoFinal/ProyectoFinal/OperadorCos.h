#pragma once

#include "OperadorUnario.h"
#include "Operando.h"

class OperadorCos : public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorCos();
	~OperadorCos();

	virtual Elemento * operar(DoublyLinkedList<Elemento *>&);

};

