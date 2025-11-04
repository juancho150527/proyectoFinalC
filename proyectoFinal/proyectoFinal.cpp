#include <bits/stdc++.h>//libreria general
#include <conio.h>//sonido 
#include<windows.h>//visuales 
using namespace std;

struct datos {//estrutura de datos 
	string nombre;
	string apellido; 
	int edad;
	char sexo;
	long cedula;
	string email;
	long long telefono;
	int nVuelo;
};

struct asiento {//estrutura de asiento 
	int nVuelo;
	int nAsiento;
	bool libre;
	long cedula;
};

void cargarArreglo(datos usuario[]);
void cargarArregloAsiento (asiento asiento[]);
void guardarArreglo(datos usuario[]);
void guardarArregloAsiento(asiento asiento[]);
void subrayar();
void menuPrincipal(datos usuario[], asiento asiento[]);
int recibirTipoDatoEntero(int& num);





void cargarArreglo (datos usuario[]) {
	ifstream archivo;
	int lineas=0;
	int contador=0;
	archivo.open("usuario.txt", ios::in);
	if (!archivo) {
		cout<<"Archivo no encontrado"<<endl;
	}//if
	else {
		while(!archivo.eof() && contador<10000) {
		archivo >> usuario[contador].nombre;
		archivo >> usuario[contador].apellido;
		archivo >> usuario[contador].edad;
		archivo >> usuario[contador].sexo;
		archivo >> usuario[contador].cedula;
		archivo >> usuario[contador].email;
		archivo >> usuario[contador].telefono;
		archivo >> usuario[contador].nVuelo;
		contador+=1;
		}//while
	}//else
	archivo.close();
}//Carga en el arreglo lo que haya en el archivo ususario.txt

void cargarArregloAsiento (asiento asiento[]) {
	ifstream archivo;
	int lineas=0;
	int contador=0;
	archivo.open("asiento.txt", ios::in);
	if (!archivo) {
		cout<<"Archivo no encontrado"<<endl;
	}//if
	else {
		while(!archivo.eof() && contador<10000) {
		archivo >> asiento[contador].nVuelo;
		archivo >> asiento[contador].nAsiento;
		archivo >> asiento[contador].libre;
		archivo >> asiento[contador].cedula;
		contador+=1;
		}//while
	}//else
	archivo.close();
}//Carga en el arreglo lo que haya en el archivo asiento.txt

void guardarArreglo(datos usuario[]){
	ofstream archivo("usuario.txt");
	for (int i=0; i<10000; i++) {
		archivo<<usuario[i].nombre<<" ";
		archivo<<usuario[i].apellido<<" ";
		archivo<<usuario[i].edad<<" ";
		archivo<<usuario[i].sexo<<" ";
		archivo<<usuario[i].cedula<<" ";
		archivo<<usuario[i].email<<" ";
		archivo<<usuario[i].telefono<<" "; 
		archivo<<usuario[i].nVuelo<<"\n";
	}//for
	archivo.close();
}//Guardar el arreglo usuario

void guardarArregloAsiento(asiento asiento[]){
	ofstream archivo("usuario.txt");
	for (int i=0; i<10000; i++) {
		archivo<<asiento[i].nVuelo<<" ";
		archivo<<asiento[i].nAsiento<<" ";
		archivo<<asiento[i].libre<<" "; 
		archivo<<asiento[i].cedula<<"\n";
	}//for
	archivo.close();
}//Guardar el arreglo asiento

void subrayar() {
	cout<<"-------------------------------------------\n";
}//subrayar

main() {
	datos usuario[10000];
	asiento asiento[10000];
	cargarArreglo(usuario);
	cargarArregloAsiento(asiento);
	
	//Aquí va el código del programa
	
	guardarArreglo(usuario);
	guardarArregloAsiento(asiento);
	return 0;
}

void menuPrincipal(datos usuario[], asiento asiento[]) {
	int opcion;
	do {
		system("cls");
		subrayar();
		cout<<"        MENU PRINCIPAL        \n";
		subrayar();
		cout<<"1. Registrar usuario\n";
		cout<<"2. Reservar asiento\n";
		cout<<"3. Cancelar reserva\n";
		cout<<"4. Ver usuarios registrados\n";
		cout<<"5. Ver asientos disponibles\n";
		cout<<"6. Salir\n";
		subrayar();
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		
		switch(opcion) {
			case 1:
				//Registrar usuario
				break;
			case 2:
				//Reservar asiento
				break;
			case 3:
				//Cancelar reserva
				break;
			case 4:
				//Ver usuarios registrados
				break;
			case 5:
				//Ver asientos disponibles
				break;
			case 6:
				cout<<"Saliendo del programa...\n";
				break;
			default:
				cout<<"Opcion invalida. Intente de nuevo.\n";
				getch();
		}
	} while(opcion != 6);
	
}

int recibirTipoDatoEntero(int& num) {
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Ingrese un dato valido"<<endl;
		cin>>num;
		teclaPresionada();
	}//while
	return num;
}//Funcion validar datos tipo enteros