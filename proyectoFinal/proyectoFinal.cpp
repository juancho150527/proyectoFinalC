#include <bits/stdc++.h>//libreria general
#include <conio.h>//sonido 
#include<windows.h>//visuales 
#include <regex> // para usar regex
using namespace std;

struct datos {//estrutura de datos 
	string nombre;
	int edad;
	string sexo;
	long cedula;
	string email;
	long long telefono;
	int nVuelo;
	int nAsiento;
	bool libre;
};

void cargarArreglo(datos dato[]);
void guardarArreglo(datos dato[]);
void subrayar();
void menuPrincipal(datos dato[]);
int recibirTipoDatoEntero(int& num);
long recibirTipoDatoLong(long& num);
bool verificarTipoDatoString(string pal);
string recibirTipoDatoString(string& pal);
void teclaPresionada();
string recibirEmail(string& email);
bool validacionAsiento(int nAsiento, int nVuelo, datos dato[]);
bool buscarCedula(long cedula, datos dato[]);
void crearViaje(datos dato[]);
void pantallaCentrada(const string& texto, int anchura);
void validarNombre(string& nombre);



void cargarArreglo (datos dato[]) {
	ifstream archivo;
	int lineas=0;
	int contador=0;
	archivo.open("dato.txt", ios::in);
	if (!archivo) {
		cout<<"Archivo no encontrado"<<endl;
	}//if
	else {
		while(!archivo.eof() && contador<10000) {
		archivo >> dato[contador].nombre;
		archivo >> dato[contador].edad;
		archivo >> dato[contador].sexo;
		archivo >> dato[contador].cedula;
		archivo >> dato[contador].email;
		archivo >> dato[contador].telefono;
		archivo >> dato[contador].nVuelo;
		contador+=1;
		}//while
	}//else
	archivo.close();
}//Carga en el arreglo lo que haya en el archivo dato.txt

void guardarArreglo(datos dato[]){
	ofstream archivo("dato.txt");
	for (int i=0; i<10000; i++) {
		archivo<<dato[i].nombre<<" ";
		archivo<<dato[i].edad<<" ";
		archivo<<dato[i].sexo<<" ";
		archivo<<dato[i].cedula<<" ";
		archivo<<dato[i].email<<" ";
		archivo<<dato[i].telefono<<" "; 
		archivo<<dato[i].nVuelo<<" ";
		archivo<<dato[i].nAsiento<<"";
		archivo<<dato[i].libre<<"\n";
	}//for
	archivo.close();
}//Guardar el arreglo datos en el archivo dato.txt

void subrayar() {
	cout<<"-------------------------------------------\n";
}//subrayar

main() {
	datos dato[10000];
	asiento asiento[10000];
	cargarArreglo(dato);
	
	//Aquí va el código del programa
	
	guardarArreglo(dato);
	menuPrincipal(dato);
	return 0;
}

void menuPrincipal(datos dato[]) {
	int opcion;
	do {
		system("cls");
		subrayar();
		cout<<"        MENU PRINCIPAL        \n";
		subrayar();
		cout<<"1. Registrar vuelo\n";
		cout<<"2. Reservar asiento\n";
		cout<<"3. Cancelar reserva\n";
		cout<<"4. Ver datos registrados\n";
		cout<<"5. Ver asientos disponibles\n";
		cout<<"6. Salir\n";
		subrayar();
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		
		switch(opcion) {
			case 1:
				//Registrar dato
				break;
			case 2:
				//Reservar asiento
				break;
			case 3:
				//Cancelar reserva
				break;
			case 4:
				//Ver datos registrados
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

long recibirTipoDatoLong(long& num) {
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Ingrese un dato valido"<<endl;
		cin>>num;
		teclaPresionada();
	}//while
	return num;
}//Funcion validar datos tipo longs

bool verificarTipoDatoString(string pal) {
	if (pal.empty()) { //.empty devuelve true o false si la variable esta vacia
		cout << "El campo no puede estar vac�o.\n";
		return false;
	}//if
	for (int i=0; i< pal.size(); i++) {
		if (!isalpha(pal[i]) && pal[i] != ' ') { // isalpha verifica que solo contenga letras
			cout << "Solo puede contener letras y espacios.\n";
			return false;
		}//if
	}//for
	return true;
}//Funcion verificar que sea valido el string

string recibirTipoDatoString(string& pal) {
	do {
		fflush(stdin);
		getline(cin, pal);
		teclaPresionada();
	} while (!verificarTipoDatoString(pal));
	return pal;
}//Funcion leer el string hasta que sea valido

void teclaPresionada() {
    Beep(750, 100); // Sonido de 750 Hz, 100ms
}

string recibirEmail(string& email) {
	while (true) {
		getline(cin, email);
		teclaPresionada();
		if (regex_match(email, patronEmail)) {
			return email;
		} else {
			cout << "Correo electrónico no válido. Intente de nuevo: ";
		}
	}
	
}//Funcion para recibir y validar email usando regex

void crearViaje(datos dato[]) {
	// Mensaje inicial centrado
    colorTexto(13); // Amarillo
    pantallaCentrada("=== Creacion de cuenta===", anchuraConsola);
}

void guardarDatos(datos dato[]) {
	datos nuevoUsuario;

	//nombre
	fflush(stdin);
	cout<<"Ingrese su nombre completo--> ";
	recibirTipoDatoString(nuevoUsuario.nombre);
	validarNombre(nuevoUsuario.nombre);

	//cedula
	cout<<"Ingrese su numero de cedula--> ";
	recibirTipoDatoLong(nuevoUsuario.cedula);
	while (buscarCedula(nuevoUsuario.cedula, dato)) {
		cout<<"La cedula ya esta registrada, ingrese otra cedula--> ";
		recibirTipoDatoLong(nuevoUsuario.cedula);
	}//while

	//sexo
	fflush(stdin);
	cout<<"Ingrese su sexo--> ";
	recibirTipoDatoString(nuevoUsuario.sexo);

	//edad
	cout<<"Ingrese su edad--> ";
	recibirTipoDatoEntero(nuevoUsuario.edad);

	//email
	fflush(stdin);
	cout<<"Ingrese su email--> ";
	recibirEmail(nuevoUsuario.email);

	//telefono
	cout<<"Ingrese su numero de telefono--> ";
	recibirTipoDatoLong(nuevoUsuario.telefono);

	if (guardar(dato, nuevoUsuario) != -1) {
		fstream archivo;
        archivo.open("dato.txt", ios::app);
		cout << "Registro exitoso.\n";
		if (!archivo) {
            pantallaCentrada("ERROR: No se pudo acceder al archivo.", anchuraConsola);
        } else {
			archivo << nuevoUsuario.nombre << " "
					<< nuevoUsuario.edad << " "
					<< nuevoUsuario.sexo << " "
					<< nuevoUsuario.cedula << " "
					<< nuevoUsuario.email << " "
					<< nuevoUsuario.telefono << " "
					<< nuevoUsuario.nVuelo << " "
					<< nuevoUsuario.nAsiento << ""
					<< nuevoUsuario.libre << "\n";
			archivo.close();
		}
	} else {
		cout << "No hay espacio disponible para nuevos registros.\n";
	}

}

bool validacionAsiento(int nAsiento, int nVuelo, datos dato[]) {
	for (int i=0; i<10000; i++) {
		if (dato[i].nAsiento==nAsiento && dato[i].nVuelo==nVuelo) {
			return true;
			break;
		}//if
	}//for
	return false;
}//Funcion para validar si el asiento ya esta reservado

bool buscarCedula(long cedula, datos dato[], int cantidadDatos) {
	for (int i=0; i<cantidadDatos; i++) {
		if (dato[i].cedula==cedula) {
			return true;
		}//if
	}//for
	return false;
}//busca la cedula en el arreglo datos y devuelve true si la encuentra o false si no la encuentra

void pantallaCentrada(const string& texto, int anchura = 160) {
    int relleno = (anchura - texto.size()) / 2; // Calcula espacios para centrar
    if (relleno > 0) {
        cout << string(relleno, ' ') << texto << endl;
    } else {
        cout << texto << endl; // Si la l�nea es m�s larga, solo imprime
    }
}// Funci�n para centrar texto en consola

void validarNombre(string& nombre){
	for (int i=0; i<nombre.size();i++){
		if(nombre[i]==' '){
			nombre[i] ='_';
		}//if
	}//for
}//Guarda en nombre con espacios reemplazados por guiones bajos

int guardar(datos dato[], datos nuevoUsuario) {
	for (int i=0; i<10000; i++) {
		if (dato[i].cedula == 0) { // Asumiendo que cedula 0 indica espacio libre
			dato[i].libre = false;
			dato[i] = nuevoUsuario;
			cout<<"Datos guardados exitosamente.\n";
			teclaPresionada();
			return i; // Retorna el �ndice donde se guardaron los datos
		}//if
	}//for
	return -1; // Indica que no hubo espacio disponible
}

