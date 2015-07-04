
#include "stdafx.h"
#include "Operacion.h"

const char Operacion::OPERADORES[Operacion::NUM_OPERADORES] = { '+', '-', '/', '*', '^', 'F', 's', 'c', 't', 'l' };

Operacion::Operacion(string operacion) {
	this->operacion = operacion;
	reemplazarOperadores();
	eliminarEspaciosEnBlanco();
	eliminarParentesisInnecesarios(this->operacion);
}

Operacion::~Operacion() {
}

Elemento * Operacion::descomponer() {

	Elemento * resultado;
	int indice = indiceMenorPrecedencia(operacion);

	if (indice == -1) {
		resultado = new Operando(stod(operacion));
	} else {
	    //Agregar los nuevos operadores
		string izq = operacion.substr(0, indice);
		string cen = operacion.substr(indice, 1);
		string der = operacion.substr(indice + 1, operacion.length() - indice - 1);

		switch (cen[0]) {
		case 's':
			resultado = new OperadorSen();
			break;
		case 'c':
			resultado = new OperadorCos();
			break;
		case 't':
			resultado = new OperadorTan();
			break;
		case 'l':
			resultado = new OperadorLn();
			break;
		case '+':
			resultado = new OperadorSuma();
			break;
		case '-':
			resultado = new OperadorResta();
			break;
		case '/':
			resultado = new OperadorDivision();
			break;
		case'*':
			resultado = new OperadorMultiplicacion();
			break;
		case '^':
			resultado = new OperadorElevacion();
			break;
		case 'F':
			resultado = new OperadorFuncion();
			break;
		default:
			resultado = NULL;
			break;
		}

		resultado->setHijo1(procesarStringHijo(izq));
		resultado->setHijo2(procesarStringHijo(der));
	}
	return resultado;
}

void Operacion::eliminarEspaciosEnBlanco() {
	for (unsigned int i = 0; i < operacion.length(); ++i) {
		switch (operacion[i]) {
		case ' ':
		case '\t':
		case '\n':
			operacion.erase(i, 1);
			--i;
		default:
			break;
		}
	}
}

void Operacion::eliminarParentesisInnecesarios(string & string) {
	bool continuar = true;
	while (continuar) {
		continuar = false;
		if (string[0] == LEFT_PARENTHESIS && string[string.length() - 1] == RIGHT_PARENTHESIS) {
			int parentesis = 1;
			bool quitarParentesis = true;
			for (unsigned int i = 1; i < string.length() - 1 && quitarParentesis; ++i) {
				char c = string[i];
				if (c == LEFT_PARENTHESIS) {
					parentesis++;
				} else if (c == RIGHT_PARENTHESIS) {
					parentesis--;
				}
				if (parentesis < 1) {
					quitarParentesis = false;
				}
			}
			if (quitarParentesis) {
				string = string.substr(1, string.length() - 2);
				continuar = true;
			}
		}
	}
}


int Operacion::indiceMenorPrecedencia(string string) {
	int index = -1;
	int parentesis = 0;
	for (int k = 0; k < NUM_OPERADORES && index == -1; k++) {
		for (unsigned int i = 0; i < string.length() && index == -1; ++i) {
			char c = string[i];
			if (c == LEFT_PARENTHESIS) {
				parentesis++;
			} else if (c == RIGHT_PARENTHESIS) {
				parentesis--;
			} else if (parentesis == 0 && c == OPERADORES[k]) {
				index = i;
			}
		}
	}
	return index;
}

Elemento * Operacion::procesarStringHijo(string string) {
	Elemento * resultado;
	eliminarParentesisInnecesarios(string);
	if (indiceMenorPrecedencia(string) == -1) {
		resultado = new Operando(stod(string));
	} else {
		resultado = new Operacion(string);
	}
	return resultado;
}

string Operacion::getValor() {
	return operacion;
}

void Operacion::imprimir(ostream & out) {
	out << operacion;
}

Elemento * Operacion::clonar() {
	return new Operacion(this->operacion);
}


void Operacion::reemplazar(string inicial, string cambio){
		if (inicial.empty())
			return;
		size_t start_pos = 0;
		while ((start_pos = operacion.find(inicial, start_pos)) != std::string::npos) {
			operacion.replace(start_pos, inicial.length(), cambio);
			//start_pos += cambio.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
		}
	}

void Operacion::reemplazarOperadores(){
	reemplazar( "sen", "s");
	reemplazar("cos", "c");
	reemplazar("tan", "t");
	reemplazar("log", "l");
	reemplazar("FUNC", "F");
	

}