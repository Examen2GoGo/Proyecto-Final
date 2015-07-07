
#include "stdafx.h"
#include "Elemento.h"

ostream& operator<<(ostream & out, Elemento & elemento) {
	elemento.imprimir(out);
	return out;
}
