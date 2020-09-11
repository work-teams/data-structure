#include "Validar.h"

/*                            Definicion
---------------------------------------------------------------------*/
bool es_numero(string str) {
	for (int i = 0; i < str.length(); i++) {
		if ( !isdigit(str[i]) ) {
			return false;
		}
	}

	return true;
}

/*---------------------------------------------*/
void a_mayuscula(string & str) {
	char cad [str.length()];
	strcpy(cad, str.c_str());
	strupr(cad);
	str = cad;
}
