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
	int decision;
	/*---------------------------------------------*/

	// Recupera datos del archivo e inserta en la lista enlazada (memoria HEAP).
	recuperar_datos(archivo, lista, paciente);

	do {
		menuPrincipal();
		cin >> op;

		switch (op) {
		    // Insertar nuevo paciente en la lista enlazada.
			case 1:
			    system("cls");
				menuInsertar();

				codigo = validar_codigo(codigo);
				nombre = validar_nombre();
				edad = validar_edad(edad);
				sexo = validar_sexo(sexo);
				tipoSangre = validar_tipoSangre(tipoSangre);
				prioridad = define_prioridad(tipoSangre);
				paciente = generar_paciente(codigo, nombre, edad, sexo, tipoSangre, prioridad);
				insertar_aLista(lista, paciente);

				cout << "\n\tPACIENTE INSERTADO\n";
				system("pause");
				break;

            // Imprime en pantalla los datos almacenado en la lista enlazada (memoria HEAP).
            case 2:
                system("cls");
				menuMostrar();
				mostrar_lista(lista);
				system("pause");
				break;

            case 3:
                ordenar_prioridad(lista);
                system("cls");
				menuMostrar();
				mostrar_lista(lista);
				system("pause");
                break;

            // Buscar paciente por código.
            case 4:
                system("cls");
                codigo = validar_codigo(codigo);
				buscado = buscar_codigo(lista, codigo);
				if (buscado != nullptr) {
                    menuMostrar();
					imprimir_paciente(buscado->paciente);
				}
				system("pause");
				break;

            // Eliminar paciente por código.
            case 5:
                system("cls");
                codigo = validar_codigo(codigo);
				buscado = buscar_codigo(lista, codigo);
				if (buscado != nullptr) {
					eliminar_nodo(lista, buscado);
					cout << "\n\tPACIENTE ELIMINADO\n";
				}
				system("pause");
				break;

            // Borra la lista enlazada de memoria y elimina el archivo.
            case 6:	destruir_lista(lista); break;

            // Guardar datos de la lista enlazada en el archivo (PERSISTENCIA).
			case 7:
			    cout << "\n\tDESEA GUARDAR LOS CAMBIOS?" << endl;
			    cout << "\t1.No\n\t2.Si\n" << endl;
			    cout << " INGRESE OPCION: ";
			    cin >> decision;
			    if (decision == 2) {
                    guardar_datos(archivo, lista);
			    }
			    op = 8;
			    break;
		}
		system("cls");

	} while (op != 8);

	return 0;
}
