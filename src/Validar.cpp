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

/*---------------------------------------------*/
string validar_tipoSangre(string str) {
	string val [] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
	bool esValido = false;
	
	while (!esValido) {
		try {
			fflush(stdin);
			cout << "Tipo de sangre: ";
			getline(cin, str);
			
			if (str.length() >= 2 and str.length() <= 3) {
				a_mayuscula(str);
			}
			else {
				throw esValido;
			}
			
			for (int i = 0; i < 8; i++) {
				if (str == val[i]) {
					throw esValido = true;
				}
			}
		} catch (bool e) {}
	}
	
	return str;
}