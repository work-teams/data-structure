#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Donante.h"

struct Nodo {
	Paciente paciente;
	Nodo* sgt;
	Nodo* ant;
};

struct Lista {
	Nodo* cabecera = nullptr;
	Nodo* cola = nullptr;
};

/*                            Declaracion
---------------------------------------------------------------------*/
Nodo* generar_nodo(Paciente paciente);

Nodo* buscar_codigo(Lista lista, string codigo);

bool lista_vacia(Lista lista);

void insertar_aLista(Lista & lista, Paciente paciente);

#endif // LINKEDLIST_H
