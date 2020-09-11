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