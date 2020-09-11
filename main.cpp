/*                           Comentario
---------------------------------------------------------------------
	University: Universidad Nacional Mayor de San Marcos
	Faculty: Ingenieria de Sistemas e Informatica
	School: Ingenieria de Software
	
	Subject: Estructura de Datos
	Project: Sistema Banco de Sangre
	
	Name: Marin Evangelista Jorge Luis
	Date: 2020/09/11
	User: jm-dev7
---------------------------------------------------------------------
*/

#include <iostream>

#include "include/Archivo.h"
#include "include/Donante.h"
#include "include/linkedList.h"
#include "include/Validar.h"
#include "include/Consola.h"

using namespace ::std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*                        Funcion Principal
---------------------------------------------------------------------*/
int main(int argc, char** argv) {
	cout << "EstructuraDatos_ProyectoFinal_SistemaBancoSangre" << endl << endl;
	
	/*---------------------------------------------*/
	Lista lista;
	Paciente paciente;
	fstream archivo;
	
	string codigo;
	string tipoSangre;
	string edad;
	string prioridad;
	string sexo;
	string nombre;

	Nodo* buscado;
	
	int op;
	
	/*---------------------------------------------*/
	recuperar_datos(archivo, lista, paciente); //recupera datos del archivo

	do {
		menuPrincipal();
		cin >> op;

		switch (op) {
			case 1:
				menuInsertar();

				codigo = validar_codigo(codigo);
				nombre = validar_nombre();
				edad = validar_edad(edad);
				sexo = validar_sexo(sexo);
				tipoSangre = validar_tipoSangre(tipoSangre);
				prioridad = define_prioridad(tipoSangre);

				paciente = generar_paciente(codigo, nombre, edad, sexo, tipoSangre, prioridad);
				
				insertar_aLista(lista, paciente); //inserta en lista enlazada
				cout << "insertado\n";
				break;
			case 2:
				guardar_datos(archivo, lista); //guarda datos en archivo
				break;
			case 3:
				menuMostrar();

				mostrar_lista(lista); break; //imprime la lista enlazada
			case 5:
				destruir_lista(lista); break;
			case 6:
				buscado = buscar_codigo(lista, codigo);
				if (buscado != nullptr) {
					eliminar_nodo(lista, buscado);
					cout << "eliminado\n";
				}
				break;
			case 7:
				ordenar_prioridad(lista);
				break;
			case 8:
				buscado = buscar_codigo(lista, codigo);
				if (buscado != nullptr) {
					imprimir_paciente(buscado->paciente);
				}
				break;
		}

		system("pause");
		system("cls");

	} while (op != 4);
	
	return 0;
}