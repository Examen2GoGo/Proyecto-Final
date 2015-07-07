#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[]) {

	ifstream file("Operaciones.txt");
	string str;

	DoublyLinkedList<Operacion> operaciones;
	DoublyLinkedList<Operando> resultados;
	ArbolBinario<Operacion> arbol;

	while (getline(file, str)){
		operaciones.addLast(Operacion(str));
	}
	cout << "Operaciones:\n" << operaciones << endl;

	IteradorLista<Operacion> itA = operaciones.begin();
	while (itA != operaciones.end()) {
		cout << *(itA++) << "->";
		arbol.insertar(*(itA++));
		//arbol.resolver();
	}
	cout << endl;


	system("pause");
	return 0;
}

