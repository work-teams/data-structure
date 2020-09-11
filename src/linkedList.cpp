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

/*---------------------------------------------*/
void mostrar_lista(Lista lista) {
	while (lista.cabecera != nullptr) {
		imprimir_paciente(lista.cabecera->paciente);
		lista.cabecera = lista.cabecera->sgt;
	}
}

/*---------------------------------------------*/
void destruir_lista(Lista & lista) {
	if ( !lista_vacia(lista) ) {
		Nodo* aEliminar;
		
		while (lista.cabecera != nullptr) {
			aEliminar = lista.cabecera;
			lista.cabecera = lista.cabecera->sgt;
			delete aEliminar;
		}
		lista.cola = nullptr;
	}
}

/*---------------------------------------------*/
void eliminar_nodo(Lista & lista, Nodo* aEliminar) {
	if (lista.cabecera == lista.cola) {
		lista.cabecera = nullptr;
		lista.cola  = nullptr;
	}
	else if (lista.cabecera == aEliminar) {
		lista.cabecera = lista.cabecera->sgt;
		lista.cabecera->ant = nullptr;
	}
	else if (lista.cola == aEliminar) {
		lista.cola = lista.cola->ant;
		lista.cola->sgt = nullptr;
	}
	else {
		aEliminar->sgt->ant = aEliminar->ant;
		aEliminar->ant->sgt = aEliminar->sgt;
	}
	delete aEliminar;
}