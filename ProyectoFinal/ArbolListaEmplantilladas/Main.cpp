#include "stdafx.h"
#include "ArbolBinario.h"
#include "DoublyLinkedList.h"
#include "Persona.h"

using namespace std;

template<class T>
void imprimir(DoublyLinkedList<T> lista);

int _tmain(int argc, _TCHAR* argv[]){

	DoublyLinkedList<Persona> lista;
	lista.addLast(Persona("Mati", 100)); //árbol contiene una operación 
	lista.addLast(Persona("Faby", 300)); //completa en un objeto Operacion
	lista.addLast(Persona("Guly", 500)); 

	IteradorLista<Persona> itA = lista.begin();
	while (itA != lista.end()) {
		ArbolBinario<Persona> arbol;		
		arbol.insertar(*itA);
		++itA;
	}
	
	



	system("pause");
	return 0;
}

/*
	
	Persona p1("Mati", 100);
	Persona p2("Hoja", 200);
	Persona p3("Zeta", 300);
	Persona p4("Faby", 400);
	Persona p10("Mati", 100);
	Persona p20("Hoja", 200);
	Persona p30("Zeta", 300);
	Persona p40("Faby", 400);

	DoublyLinkedList<Persona> a;
	a.addLast(p1);
	a.addLast(p2);
	a.addLast(p3);
	a.addLast(p4);

	cout << a << endl;

	//Iteradores
	imprimir(a);


	//arbol 
	cout << "\n\nARBOL" << endl;
	ArbolBinario<Persona> c;
	c.insertar(p10);
	c.insertar(p20);
	c.insertar(p30);
	c.insertar(p40);

	cout << c << endl;

	cout << "Preincremento" << endl;
	// Probar Iteradores preincremento
	IteradorArbol<Persona> itA = c.begin();
	while (itA != c.end()) {
		cout << *itA << endl;
		++itA;
	}
	cout << endl;

	cout << "Posincremento" << endl;
	// Probar Iteradores posincremento
	IteradorArbol<Persona> itB = c.begin();
	while (itB != c.end()) {
		cout << *(itB++) << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}

template<class T>
void imprimir(DoublyLinkedList<T> lista) {

	cout << "\n\nPreincremento" << endl;
	// Probar Iteradores preincremento
	IteradorLista<T> itA = lista.begin();
	while (itA != lista.end()) {
		cout << *itA << "->";
		++itA;
	}
	cout << endl;

	cout << "Posincremento" << endl;
	// Probar Iteradores posincremento
	IteradorLista<T> itB = lista.begin();
	while (itB != lista.end()) {
		cout << *(itB++) << "->";
	}
	cout << endl;

	cout << "Predecremento" << endl;
	// Probar Iteradores predecremento
	IteradorInverso<T> itC = lista.rBegin();
	while (itC != lista.rEnd()) {
		cout << *itC << "->";
		--itC;
	}
	cout << endl;

	cout << "Posdecremento" << endl;
	// Probar Iteradores posdecremento
	IteradorInverso<T> itD = lista.rBegin();
	while (itD != lista.rEnd()) {
		cout << *(itD--) << "->";
	}
	cout << endl;
}
*/