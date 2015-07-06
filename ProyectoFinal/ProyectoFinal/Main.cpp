// CalculadoraHerenciaArbol.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[]) {

	ifstream archivoOperaciones("operaciones.txt");
	ofstream archivoResultados("resultados.txt");

	Lista operaciones(archivoOperaciones);
	Lista resultados;
	cout << "Operaciones:\n" << operaciones << endl;

	cout << "Operaciones Resueltas: " << endl;
	for (int i = 0; i < operaciones.getCantidadElementos(); i++) {

		Elemento * operacion = operaciones.getCopy(i);

		Arbol arbol(new Nodo(operacion->clonar()));
		arbol.descomponer();
		Operando * resultado = dynamic_cast<Operando *>(arbol.solucionar());
		archivoResultados << *resultado << endl;

		cout << i + 1 << ". " << *operacion << " = " << *resultado << endl;

		resultados.insertar(resultado);

		delete operacion;
	}
	cout << "Meter en archivo: \n" << resultados << endl;

	archivoOperaciones.close();
	archivoResultados.close();

	system("pause");
	return 0;
}

