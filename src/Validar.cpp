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

/*---------------------------------------------*/
string validar_codigo(string str) {
	bool esValido = false;
	
	while (!esValido) {
		try {
			fflush(stdin);
			cout << "Codigo: ";
			getline(cin, str);
			
			if (str.length() != 8) {
				throw esValido;
			}
			
			esValido = es_numero(str);
			if (!esValido) {
				throw esValido;
			}
		} catch (bool e) {}
	}
	
	return str;
}