#include "../include/Donante.h"

using namespace ::std;

/*                            Definicion
---------------------------------------------------------------------*/
Paciente generar_paciente(string codigo, string nombre, string edad, string sexo, string tipoSangre, string prioridad) {
	Paciente nuevo;

	strcpy(nuevo.codigo, codigo.c_str());
	strcpy(nuevo.edad, edad.c_str());
	strcpy(nuevo.prioridad, prioridad.c_str());
	strcpy(nuevo.nombre, nombre.c_str());
	strcpy(nuevo.sexo, sexo.c_str());
	strcpy(nuevo.tipoSangre, tipoSangre.c_str());

	return nuevo;
}

/*---------------------------------------------*/
void imprimir_paciente(Paciente paciente) {
	fflush(stdin);
	printf("%s\t%s\t%s\t%s\t      %s\n", paciente.codigo, paciente.sexo, paciente.edad, paciente.tipoSangre, paciente.nombre);
}
