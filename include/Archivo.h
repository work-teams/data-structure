#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "linkedList.h"
#include <fstream>
using namespace ::std;

/*                            Declaracion
---------------------------------------------------------------------*/
void destruir_archivo(fstream & archivo);

void guardar_datos(fstream & archivo, Lista lista);

#endif // ARCHIVO_H
