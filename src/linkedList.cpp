#include "linkedList.h"

using namespace ::std;

/*                            Definicion
---------------------------------------------------------------------*/
Nodo* generar_nodo(Paciente paciente) {
	Nodo* nuevo = new Nodo();
	nuevo->paciente = paciente;
	nuevo->ant = nullptr;
	nuevo->sgt = nullptr;
	
	return nuevo;
}

/*---------------------------------------------*/
Nodo* buscar_codigo(Lista lista, string codigo) {
	while (lista.cabecera != nullptr and codigo != lista.cabecera->paciente.codigo) {
		lista.cabecera = lista.cabecera->sgt;
	}
	return lista.cabecera;
}

/*---------------------------------------------*/
bool lista_vacia(Lista lista) {
	if (lista.cabecera == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

/*---------------------------------------------*/
void insertar_aLista(Lista & lista, Paciente paciente) {
	Nodo* nuevo = generar_nodo(paciente);
	
	if ( lista_vacia(lista) ) {
		lista.cabecera = nuevo;
		lista.cola = nuevo;
	}
	else {
		lista.cola->sgt = nuevo;
		nuevo->ant = lista.cola;
		lista.cola = nuevo;
	}
}