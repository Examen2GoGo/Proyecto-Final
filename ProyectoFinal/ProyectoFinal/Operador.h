#pragma once

#include "stdafx.h"

#include "Elemento.h"
#include "DoublyLinkedList.h"

using namespace std;

class Operador : public Elemento {

protected:
	virtual void imprimir(ostream&) = 0;

public:
	virtual ~Operador() {};

	virtual Elemento * operar(DoublyLinkedList<Elemento>&) = 0;

	virtual Elemento * clonar() = 0;
};