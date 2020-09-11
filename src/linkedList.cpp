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