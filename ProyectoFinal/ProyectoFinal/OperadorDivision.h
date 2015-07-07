
#pragma once
#include "stdafx.h"
//#include "OperadorBinario.h"
//#include "Operando.h"

class OperadorDivision : public OperadorBinario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorDivision();
	~OperadorDivision();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&);

	virtual Elemento * clonar();
};

