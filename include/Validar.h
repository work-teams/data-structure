#ifndef VALIDAR_H
#define VALIDAR_H

#include <iostream>
#include <string>
#include <cstring>
using namespace ::std;

/*                            Declaracion
---------------------------------------------------------------------*/
bool es_numero(string str);

void a_mayuscula(string & str);

string validar_codigo(string str);

string validar_tipoSangre(string str);

string define_prioridad(string tipoSangre);

string validar_edad(string str);

string validar_sexo(string str);

#endif // VALIDAR_H
