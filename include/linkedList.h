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

void mostrar_lista(Lista lista);

void destruir_lista(Lista & lista);

void eliminar_nodo(Lista & lista, Nodo* aEliminar);

void ordenar_prioridad(Lista lista);

#endif // LINKEDLIST_H
