#ifndef DONANTE_H
#define DONANTE_H

#include <iostream>
#include <cstring>
#include <string>
using namespace ::std;

struct Paciente {
	char edad [3] = "";
	char codigo [9] = "";
	char prioridad [2] = "";
	char sexo [10] = "";
	char nombre [41] = "";
	char tipoSangre [4] = "";
};

/*                            Declaracion
---------------------------------------------------------------------*/
Paciente generar_paciente(string codigo, string nombre, string edad, string sexo, string tipoSangre, string prioridad);

void imprimir_paciente(Paciente paciente);

#endif // DONANTE_H
