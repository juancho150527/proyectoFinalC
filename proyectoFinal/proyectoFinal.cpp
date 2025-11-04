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

void cargarArreglo();
void cargarArregloAsiento ();
void guardarArreglo();
void guardarArregloAsiento();







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

