#include "../include/Consola.h"

/*                            Definicion
---------------------------------------------------------------------*/
void menuPrincipal() {
	cout<<"**********************************************";
	cout<<"\n\t\t MENU PRINCIPAL \n";
	cout<<"**********************************************\n";
	cout<<" 	1. Insertar paciente                      "<<endl;
	cout<<" 	2. Mostrar lista                          "<<endl;
	cout<<" 	3. Ordenar lista por tipo de sangre       "<<endl;
	cout<<" 	4. Buscar por codigo                      "<<endl;
    cout<<" 	5. Eliminar por codigo                    "<<endl;
	cout<<" 	6. Destruir lista enlazada                "<<endl;
	cout<<" 	7. Salir		                          "<<endl;
	cout<<"**********************************************\n";

	cout<<"\n INGRESE OPCION: ";
}

/*---------------------------------------------*/
void menuMostrar() {
	cout<<"\n_____________________________________________________________________________________\n";
	cout<<"CODIGO          SEXO            EDAD    TIPO-SANGRE   NOMBRE";
	cout<<"\n_____________________________________________________________________________________\n";

}

/*---------------------------------------------*/
void menuInsertar() {
	cout<<"****************************************************";
	cout<<"\n\tDIGITE DATOS DEL PACIENTE A INSERTAR \n";
	cout<<"****************************************************\n";

}
