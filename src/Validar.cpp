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

/*---------------------------------------------*/
string define_prioridad(string tipoSangre) {
	string val [] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
	string str;
	int i;

	try {
		fflush(stdin);
		for (i = 0; i < 8; i++) {
			if (tipoSangre == val[i]) {
				throw i;
			}
		}
	} catch (int e) {
		switch (e) {
			case 0: str = "0"; break;
			case 1: str = "1"; break;
			case 2: str = "2"; break;
			case 3: str = "3"; break;
			case 4: str = "4"; break;
			case 5: str = "5"; break;
			case 6: str = "6"; break;
			case 7: str = "7"; break;
		}

		return str;
	}
}

/*---------------------------------------------*/
string validar_edad(string str) {
	bool esValido = false;
	while (!esValido) {
		try {
			fflush(stdin);
			cout << "Edad: ";
			getline(cin, str);

			if (str.length() > 3) {
				throw esValido;
			}

			esValido = es_numero(str);
		} catch (bool e) {}
	}

	return str;
}

/*---------------------------------------------*/
string validar_sexo(string str) {
	string val [] = {"MASCULINO", "FEMENINO"};
	bool esValido = false;

	while (!esValido) {
		fflush(stdin);
		cout << "Sexo: ";
		getline(cin, str);
		a_mayuscula(str);

		for (int i = 0; i < 2; i++) {
			if (str == val[i]) {
				esValido = true;
			}
		}
	}

	return str;
}