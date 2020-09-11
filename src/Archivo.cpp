#include "Archivo.h"

/*---------------------------------------------*/
void destruir_archivo(fstream & archivo) {
	remove("Expedientes.txt");
}
