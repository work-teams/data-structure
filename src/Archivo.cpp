#include "Archivo.h"

/*                            Definicion
---------------------------------------------------------------------*/
void destruir_archivo(fstream & archivo) {
	remove("Expedientes.txt");
}

/*---------------------------------------------*/
void guardar_datos(fstream & archivo, Lista lista) {
	if ( lista_vacia(lista) ) {
		destruir_archivo(archivo);
		return;
	}
	
	archivo.open("Expedientes.txt", ios::out);
	while (lista.cabecera != nullptr) {
		archivo.write( (char*) &lista.cabecera->paciente, sizeof(lista.cabecera->paciente) );
		lista.cabecera = lista.cabecera->sgt;
	}
	archivo.close();
}
