/*                           Comentario
---------------------------------------------------------------------
	University: Universidad Nacional Mayor de San Marcos
	Faculty: Ingenieria de Sistemas e Informatica
	School: Ingenieria de Software

	Subject: Estructura de Datos
	Project: Sistema Banco de Sangre

	Name: Grupo 05
	Date: 2020/09/11
	User: krypt97
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
	cout << "EstructuraDatos-ProyectoFinal-SistemaBancoSangre" << endl << endl;

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

	// Recupera datos del archivo e inserta en la lista enlazada.
	recuperar_datos(archivo, lista, paciente);

	do {
		menuPrincipal();
		cin >> op;

		switch (op) {
		    // Insertar paciente en la lista enlazada.
			case 1:
				menuInsertar();
				codigo = validar_codigo(codigo);
				nombre = validar_nombre();
				edad = validar_edad(edad);
				sexo = validar_sexo(sexo);
				tipoSangre = validar_tipoSangre(tipoSangre);
				prioridad = define_prioridad(tipoSangre);
				paciente = generar_paciente(codigo, nombre, edad, sexo, tipoSangre, prioridad);
				insertar_aLista(lista, paciente);
				cout << "insertado\n";
				break;

            // Imprime en pantalla los datos almacenado en la lista enlazada.
            case 2:
				menuMostrar();
				mostrar_lista(lista); break;

            case 3: ordenar_prioridad(lista); break;

            // Buscar paciente por código.
            case 4:
                codigo = validar_codigo(codigo);
				buscado = buscar_codigo(lista, codigo);
				if (buscado != nullptr) {
                    menuMostrar();
					imprimir_paciente(buscado->paciente);
				}
				break;

            // Eliminar paciente por código.
            case 5:
                codigo = validar_codigo(codigo);
				buscado = buscar_codigo(lista, codigo);
				if (buscado != nullptr) {
					eliminar_nodo(lista, buscado);
					cout << "eliminado\n";
				}
				break;

            // Guardar datos de la lista enlazada en el archivo.
			case 6: guardar_datos(archivo, lista); break;

            // Borra la lista enlazada de memoria y elimina el archivo.
            case 7:	destruir_lista(lista); break;
		}
		system("pause");
		system("cls");

	} while (op != 8);

	return 0;
}
