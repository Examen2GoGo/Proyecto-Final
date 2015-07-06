#pragma once
#include"stdafx.h"
#include "Elemento.h"

class Nodo {
	friend class Arbol;
	friend class Lista;
	//friend class Iterador;

private:
	Elemento * actual;
	Nodo  *hijo0, *hijo1,*hijo2;

public:
	Nodo * siguiente;
	Nodo(Elemento * elemento) {
		this->actual = elemento;
		siguiente = 0;
		hijo0 = 0;
		hijo1 = 0;
		hijo2 = 0;
	}

	~Nodo() {
	}

	Elemento * obtenerDatos(){
		return actual;
	}

	void Nodo::setHijo0(Elemento * hijo){
		this->hijo0 = new Nodo(hijo);
	}

	void Nodo::setHijo1(Elemento * hijo){
		this->hijo1 = new Nodo (hijo);
	}

	void Nodo::setHijo2(Elemento * hijo){
		this->hijo2 = new Nodo(hijo);
	}

	Nodo * Nodo::getHijo0(){
		return hijo0;
	}

	Nodo * Nodo::getHijo1(){
		return hijo1;
	}

	Nodo * Nodo::getHijo2(){
		return hijo2;
	}
	Nodo * Nodo::siguienteElemento(){
		return siguiente;

	}

};

