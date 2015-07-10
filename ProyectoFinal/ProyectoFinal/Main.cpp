
#include "stdafx.h"

#include "Elemento.h"
#include "Operacion.h"
#include "DoublyLinkedList.h"
#include "ArbolBinario.h"

int _tmain(int argc, _TCHAR* argv[]) {

	ifstream file("Operaciones.txt");

	DoublyLinkedList<Operacion *> operaciones;
	DoublyLinkedList<Operando *> resultados;

	string str;
	while (getline(file, str)){
		operaciones.addLast(new Operacion(str));
	}

	IteradorLista<Operacion *> itA = operaciones.begin();
	while (itA != operaciones.end()) {

		Operacion * op = *(itA++);
		ArbolBinario<Operacion *> arbol(op);

		cout << *op << "-> ";
		arbol.solucionar();

	}
	cout << endl;

	system("pause");
	return 0;
}

