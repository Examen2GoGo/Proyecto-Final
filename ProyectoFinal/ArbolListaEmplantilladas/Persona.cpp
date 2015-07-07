#include "stdafx.h"
#include "Persona.h"

Persona::Persona() {
}

Persona::Persona(string nombre, int id){
	this->nombre = nombre;
	this->id = id;
}

Persona::~Persona(){
}

ostream & operator<<(ostream & out, Persona & p) {
	return out << p.nombre;
}

bool Persona::operator<(Persona & otra) {
	return this->nombre.compare(otra.nombre) < 0;
}

bool Persona::operator>(Persona & otra) {
	return this->nombre.compare(otra.nombre) > 0;
}

