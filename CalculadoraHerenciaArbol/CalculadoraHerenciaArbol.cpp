// CalculadoraHerenciaArbol.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"
#include "Arbol.h"
#include "Operando.h"

int _tmain(int argc, _TCHAR* argv[]) {

	ifstream archivoOperaciones("operaciones.txt");
	ofstream archivoResultados("resultados.txt");

	Lista operaciones(archivoOperaciones);

	cout << "Operaciones:\n" << operaciones << endl;

	cout << "Operaciones Resueltas: " << endl;
	for (int i = 0; i < operaciones.getCantidadElementos(); i++) {

		Elemento * operacionActual = operaciones.getCopy(i);

		Arbol arbol(operacionActual->clonar());
		arbol.descomponer();
		Operando * resultado = dynamic_cast<Operando *>(arbol.solucionar());
		archivoResultados << *resultado << endl;

		cout << i + 1 << ". " << *operacionActual << " = " << *resultado << endl;

		delete operacionActual;
	}

	archivoOperaciones.close();
	archivoResultados.close();

	system("pause");
	return 0;
}

