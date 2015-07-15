
#include "stdafx.h"

#include "Elemento.h"
#include "Operacion.h"
#include "DoublyLinkedList.h"
#include "ArbolBinario.h"

int _tmain(int argc, _TCHAR* argv[]) {

	ifstream file("Operaciones.txt");

	DoublyLinkedList<Operacion *> operaciones;
	DoublyLinkedList<Elemento *> resultados;

	string str, strResultados = "";
	while (getline(file, str)){
		operaciones.addLast(new Operacion(str));
	}

	IteradorLista<Operacion *> itA = operaciones.begin();
	while (itA != operaciones.end()) {
		Operacion * op = *(itA++);
		strResultados += op->getValor() + "= ";
		ArbolBinario<Operacion *> arbol(op);
		arbol.solucionar();
		resultados.addLast(arbol.getRaiz()->getActual());
		stringstream sStr;
		Operando * a = dynamic_cast<Operando *>(arbol.getRaiz()->getActual());
		sStr << a->getValor();
		strResultados += sStr.str() + "\n";
		cout << *op << " = " << sStr.str() << endl;
		
	}

	ofstream out("resultados.txt");
	out << strResultados;
	out.close();
	
	system("pause");
	return 0;
}

