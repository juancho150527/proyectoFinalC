#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <regex>
using namespace std;

struct datos {
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

// Declaraciones reorganizadas según el orden de definición
void colorTexto(int color);
const int anchuraConsola = 160;
void cargarArreglo(datos dato[]);
void guardarArreglo(datos dato[]);
void subrayar();
void menuPrincipal(datos dato[]);
int recibirTipoDatoEntero(int& num);
long long recibirTipoDatoLong(long long& num);
bool verificarTipoDatoString(string pal);
string recibirTipoDatoString(string& pal);
void teclaPresionada();
string recibirEmail();
void crearViaje(datos dato[]);
void guardarDatos(datos dato[]);
bool validacionAsiento(int nAsiento, int nVuelo, datos dato[]);
bool buscarCedula(long cedula, datos dato[], int cantidadDatos);
void pantallaCentrada(const string& texto, int anchura);
void validarNombre(string& nombre);
int guardar(datos dato[], datos nuevoUsuario);
bool validarCapacidadVuelo(int nVuelo, datos dato[], int maxAsientos);
int vueloExiste(datos dato[]);
vector<int> asientosDisponibles(int nVuelo, datos dato[]);
vector<int> asientosOcupados(int nVuelo, datos dato[]);
void cancelarViaje(datos dato[]);
void consutas_reportes(datos dato[], int nVuelo);
void cantAsientosDisponibles(int nVuelo, datos dato[]);
void cantAsientosDisponiblesvariosVuelos(datos dato[]);
void cantAsientosOcupados(int nVuelo, datos dato[]);
void cantAsientosOcupadosvariosVuelos(datos dato[]);
void asientosDispEspecificos(datos dato[]);
void asientosOcpEspecificos(datos dato[]);
void consultarDatosAsiento(datos dato[], int nVuelo);


void colorTexto(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}// Funci�n para cambiar el color del texto

void cargarArreglo (datos dato[]) {
	ifstream archivo;
	int lineas=0;
	int contador=0;
	archivo.open("dato.txt", ios::in);
	if (!archivo) {
		cout<<"Archivo no encontrado"<<endl;
	}//if
	else {
		while(!archivo.eof() && contador<1500) {
		archivo >> dato[contador].nombre;
		archivo >> dato[contador].edad;
		archivo >> dato[contador].sexo;
		archivo >> dato[contador].cedula;
		archivo >> dato[contador].email;
		archivo >> dato[contador].telefono;
		archivo >> dato[contador].nVuelo;
		archivo >> dato[contador].nAsiento;
		archivo >> dato[contador].libre;
		contador+=1;
		}//while
			if (archivo.fail()){ break;
			contador+=1;
		}//while
	}//else
	archivo.close();
}//Carga en el arreglo lo que haya en el archivo dato.txt

void guardarArreglo(datos dato[]){
	ofstream archivo("dato.txt");
	for (int i=0; i<1500; i++) {
		if (dato[i].cedula != 0) { 
			archivo<<dato[i].nombre<<" ";
			archivo<<dato[i].edad<<" ";
			archivo<<dato[i].sexo<<" ";
			archivo<<dato[i].cedula<<" ";
			archivo<<dato[i].email<<" ";
			archivo<<dato[i].telefono<<" "; 
			archivo<<dato[i].nVuelo<<" ";
			archivo<<dato[i].nAsiento<<" ";
			archivo<<dato[i].libre<<"\n";
		}
	}//for
	archivo.close();
}//Guardar el arreglo datos en el archivo dato.txt

void subrayar() {
	cout<<"-------------------------------------------\n";
}

int main() {
	datos dato[1500];
	int nVuelo;
	colorTexto(11); // Azul claro
    pantallaCentrada("=== Bienvenido a la aerolinea UCP ===", anchuraConsola);
	colorTexto(7); // Restaurar color predeterminado
	for (int i=0; i<10; i++) {
		int v[10];
		v[i]=1000+i+1;
		for (int j=0; j<150; j++) {
			dato[i*150+j].nombre="";
			dato[i*150+j].edad=0;
			dato[i*150+j].sexo="";
			dato[i*150+j].cedula=0;
			dato[i*150+j].email="";
			dato[i*150+j].telefono=0;
			dato[i*150+j].nVuelo=v[i];
			dato[i*150+j].nAsiento=j+1;
			dato[i*150+j].libre=true;
		}
	}
	cargarArreglo(dato);
	nVuelo = vueloExiste(dato);
	while (nVuelo == 0) {
		system("cls");
		cout << "Vuelo no encontrado. Intente de nuevo.\n";
		system("pause");
		nVuelo = vueloExiste(dato);
	}
	menuPrincipal(dato);
	guardarArreglo(dato);
	return 0;
}

void menuPrincipal(datos dato[], int nVuelo) {
	int opcion;
	do {
		system("cls");
		subrayar();
		cout<<"        MENU PRINCIPAL        \n";
		subrayar();
		cout<<"1. Reservar vuelo\n";
		cout<<"2. Cancelar reserva\n";
		cout<<"3. consultas y reportes\n";
		cout<<"4. busqueda avanzada\n";
		cout<<"5. salir\n";
		subrayar();
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		teclaPresionada();
		
		switch(opcion) {
			case 1:
				crearViaje(dato);
				break;
			case 2:
				cancelarViaje(dato);
				break;
			case 3:
				consutas_reportes(dato, nVuelo);
				break;
			case 4:
				busquedaAvanzada(dato);
				break;
			case 5:
				cout<<"Saliendo del programa...\n";
				break;
			default:
				cout<<"Opcion invalida. Intente de nuevo.\n";
				getch();
		}
	} while(opcion != 5);
	
}

int recibirTipoDatoEntero(int& num) {
	 while (true) {
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un dato valido (entero no negativo): ";
            teclaPresionada();
            continue;
        }
        if (num < 0) {
            cout << "El numero no puede ser negativo. Intente de nuevo: ";
            teclaPresionada();
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        teclaPresionada();
        return num;
    }
}//Funcion validar datos tipo enteros

long long recibirTipoDatoLong(long long& num) {
	 while (true) {
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un dato valido (numero no negativo): ";
            teclaPresionada();
            continue;
        }
        if (num < 0) {
            cout << "El numero no puede ser negativo. Intente de nuevo: ";
            teclaPresionada();
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        teclaPresionada();
        return num;
    }
}//Funcion validar datos tipo long long

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

string recibirEmail() {
	static const std::regex patronEmail(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
	string email;
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

void crearViaje(int nVuelo, datos dato[]) {
	datos nuevoUsuario;
	nuevoUsuario.nVuelo = nVuelo;
	vector<int> asientosDisponiblesVec = asientosDisponibles(nVuelo, dato);
	for (int i = 0; i < asientosDisponiblesVec.size(); ++i) {
		if (asientosDisponiblesVec[i] > 0 && asientosDisponiblesVec[i] <= 150) {
			cout << "Asiento disponible: " << asientosDisponiblesVec[i] << endl;
		}
	}
	cout << "Ingrese el numero de asiento que desea reservar: ";
	recibirTipoDatoEntero(nuevoUsuario.nAsiento);
	while (!validacionAsiento(nuevoUsuario.nAsiento, nVuelo, dato)) {
		system("cls");
		cout << "Asiento no disponible. Ingrese otro numero de asiento: ";
		recibirTipoDatoEntero(nuevoUsuario.nAsiento);
	}
	guardarDatos(nuevoUsuario, dato);

}

void guardarDatos(datos nuevoUsuario, datos dato[]) {
	
	//nombre
	fflush(stdin);
	cout<<"Ingrese su nombre completo--> ";
	recibirTipoDatoString(nuevoUsuario.nombre);
	validarNombre(nuevoUsuario.nombre);

	//cedula
	cout<<"Ingrese su numero de cedula--> ";
	recibirTipoDatoLong(nuevoUsuario.cedula);
	while (buscarCedula(nuevoUsuario.cedula, dato)==0) {
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
	nuevoUsuario.email = recibirEmail();
	
	//telefono
	cout<<"Ingrese su numero de telefono--> ";
	recibirTipoDatoLong(nuevoUsuario.telefono);

	if (guardar(dato, nuevoUsuario) != -1) {
		fstream archivo;
        archivo.open("dato.txt", ios::app);
		if (!archivo) {
            pantallaCentrada("ERROR: No se pudo acceder al archivo.", anchuraConsola);
        } else {
			cout << "Registro exitoso.\n";
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

int buscarCedula(long cedula, datos dato[], int cantidadDatos=1500) {
	for (int i=0; i<cantidadDatos; i++) {
		if (dato[i].cedula==cedula) {
			return i;
		}//if
	}//for
	return 0;
}//busca la cedula en el arreglo datos y retorna su indice o 0 si no la encuentra

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

bool validarCapacidadVuelo(int nVuelo, datos dato[], int maxAsientos = 150) {
    int contador = 0;
    for (int i = 0; i < 10000; ++i) {
        // Considera registro válido/ocupado cuando existe una cédula distinta de 0
        if (dato[i].nVuelo == nVuelo && dato[i].cedula != 0) {
            contador++;
            if (contador >= maxAsientos) return false; // ya alcanzó el máximo
        }
    }
    return true; // todavía hay espacio (< maxAsientos)
}

int vueloExiste(datos dato[]) {
	int nVuelo = 0, vuelos[10];
	cout << "			Vuelos disponibles:				\n";
	for (int i = 0; i < 10; i++) {
		vuelos[i] = 1000 + i + 1;
		if(validarCapacidadVuelo(vuelos[i], dato)) {
			cout << "Vuelo disponible: " << vuelos[i] << endl;
		}
	}
	cout << "Ingrese el numero de vuelo: ";
	cin >> nVuelo;
	teclaPresionada();
	for (int i = 0; i < 10; i++) {
		if (nVuelo == vuelos[i]) {
			return nVuelo; // El vuelo existe 
		}
	}
	return 0; // No se encontró ningún registro para ese vuelo
}

vector<int> asientosDisponibles(int nVuelo, datos dato[]) {
	vector<int> asientos;
	for (int i = 0; i < 150; ++i) {
		asientos.push_back(i + 1); // Inicializa con números de asiento del 1 al 150
	}
	for (int i = 0; i < 10000; ++i) {
		if (dato[i].nVuelo == nVuelo && dato[i].libre) {
			asientos[i] = i; // libres
		}
	}
	return asientos;
}

vector<int> asientosOcupados(int nVuelo, datos dato[]) {
	vector<int> asientos;
	for (int i = 0; i < 150; ++i) {
		asientos.push_back(0); // Inicializa con 0 indicando no ocupado
	}
	for (int i = 0; i < 10000; ++i) {
		if (dato[i].nVuelo == nVuelo && !dato[i].libre) {
			asientos[i] = i + 1; // ocupados
		}
	}
	return asientos;
}

void cancelarViaje(datos dato[]) {
	long cedula;
	pantallaCentrada("Eliminar Cuenta", 160);
	cout << "Ingrese su numero de cedula para cancelar la reserva: ";
	recibirTipoDatoLong(cedula);
	int indice = buscarCedula(cedula, dato);
	if (indice == 0) {
		cout << "Cedula no encontrada. No se puede cancelar la reserva.\n";
		return;
	} else {
		dato[indice].nombre = "";
		dato[indice].edad = 0;
		dato[indice].sexo = "";
		dato[indice].cedula = 0;
		dato[indice].email = "";
		dato[indice].telefono = 0;
		dato[indice].nVuelo = 0; // Limpiar el vuelo
		dato[indice].nAsiento = 0; // Limpiar el asiento
		dato[indice].libre = true; // Marcar como libre
		pantallaCentrada("Reserva eliminada correctamente!", 160);
	}
}

void consutas_reportes(datos dato[], int nVuelo) {
	int opcion;
	do {
		system("cls");
		subrayar();
		cout<<"        CONSULTAS Y REPORTES        \n";
		subrayar();
		cout<<"1. ver la cantidad de asientos disponibles por vuelo\n";
		cout<<"2. ver la cantidad de asientos ocupados por vuelo\n";
		cout<<"3. ver los asientos disponibles de un vuelo especifico\n";
		cout<<"4. ver los asientos ocupados de un vuelo especifico\n";
		cout<<"5. consultar datos de un asiento\n";
		cout<<"6. listar pasajeros de un vuelo\n";
		cout<<"7. volver al menu principal\n";
		subrayar();
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		teclaPresionada();
		
		switch(opcion) {
			case 1:
				cantAsientosDisponiblesvariosVuelos(dato);
				break;
			case 2:
				cantAsientosOcupadosvariosVuelos(dato);
				break;
			case 3:
				asientosDispEspecificos(dato);
				break;
			case 4:
				asientosOcpEspecificos(dato);
				break;
			case 5:
				consultarDatosAsiento(dato, nVuelo);
				break;
			case 6:
				listarPasajeros(dato);
				break;
			case 7:
				cout<<"Volviendo al menu principal...\n";
				break;
			default:
				cout<<"Opcion invalida. Intente de nuevo.\n";
				getch();
		}
	} while(opcion != 7);
}

void cantAsientosDisponibles(int nVuelo, datos dato[]) {
	int contador = 0;
	for (int i=0; i<10000; i++) {
		if (dato[i].nVuelo==nVuelo && dato[i].libre) {
			contador+=1;
		}//if
	}//for
	cout<<"Cantidad de asientos disponibles en el vuelo "<<nVuelo<<": "<<contador<<"\n";
}

void cantAsientosDisponiblesvariosVuelos(datos dato[]) {
	for (int i=0; i<10; i++) {
		int nVuelo = 1000+i+1;
		cantAsientosDisponibles(nVuelo, dato);
	}//for
}

void cantAsientosOcupados(int nVuelo, datos dato[]) {
	int contador = 0;
	for (int i=0; i<10000; i++) {
		if (dato[i].nVuelo==nVuelo && !dato[i].libre) {
			contador+=1;
		}//if
	}//for
	cout<<"Cantidad de asientos ocupados en el vuelo "<<nVuelo<<": "<<contador<<"\n";
}

void cantAsientosOcupadosvariosVuelos(datos dato[]) {
	for (int i=0; i<10; i++) {
		int nVuelo = 1000+i+1;
		cantAsientosOcupados(nVuelo, dato);
	}//for
}

void asientosDispEspecificos(datos dato[]) {
	cout<<"Ingrese el numero de vuelo para ver los asientos disponibles: ";
	int nVuelo;
	recibirTipoDatoEntero(nVuelo);
	system("cls");
	vector<int> asientosDisponiblesVec = asientosDisponibles(nVuelo, dato);
	for (int i = 0; i < asientosDisponiblesVec.size(); ++i) {
		if (asientosDisponiblesVec[i] > 0 && asientosDisponiblesVec[i] <= 150) {
			cout << "Asiento disponible: " << asientosDisponiblesVec[i] << endl;
		}
	}
}

void asientosOcpEspecificos(datos dato[]) {
	cout<<"Ingrese el numero de vuelo para ver los asientos ocupados: ";
	int nVuelo;
	recibirTipoDatoEntero(nVuelo);
	system("cls");
	vector<int> asientosOcupadosVec = asientosOcupados(nVuelo, dato);
	for (int i = 0; i < asientosOcupadosVec.size(); ++i) {
		if (asientosOcupadosVec[i] > 0 && asientosOcupadosVec[i] <= 150) {
			cout << "Asiento ocupado: " << asientosOcupadosVec[i] << endl;
		}
	}
}

void consultarDatosAsiento(datos dato[], int nVuelo) {
	int nAsiento;
	pantallaCentrada("Consultar Datos de Asiento", 160);
	cout << "Ingrese el numero de asiento: ";
	recibirTipoDatoEntero(nAsiento);
	int indice = nVuelo * 150 + (nAsiento - 1); // Calcular el índice basado en nVuelo y nAsiento
	if (indice == 0) {
		cout << "Cedula no encontrada. No se puede consultar los datos del asiento.\n";
		return;
	} else {
		cout << "Datos del Asiento:\n";
		cout << "Nombre: " << dato[indice].nombre << endl;
		cout << "Edad: " << dato[indice].edad << endl;
		cout << "Sexo: " << dato[indice].sexo << endl;
		cout << "Cedula: " << dato[indice].cedula << endl;
		cout << "Email: " << dato[indice].email << endl;
		cout << "Telefono: " << dato[indice].telefono << endl;
		cout << "Numero de Vuelo: " << dato[indice].nVuelo << endl;
		cout << "Numero de Asiento: " << dato[indice].nAsiento << endl;
	}
}

void listarPasajeros(datos dato[]) {
	pantallaCentrada("Lista de Pasajeros", 160);
	int nVuelo;
	cout << "Ingrese el numero de vuelo para listar los pasajeros: ";
	recibirTipoDatoEntero(nVuelo);
	system("cls");
	cout << "Pasajeros en el vuelo " << nVuelo << ":\n";
	subrayar();
	cout << "Nombre\tEdad\tSexo\tCedula\tEmail\tTelefono\tAsiento\n";
	subrayar();
	for (int i = 0; i < 10000; ++i) {
		if (dato[i].nVuelo == nVuelo && !dato[i].libre) {
			cout << dato[i].nombre << "\t"
				 << dato[i].edad << "\t"
				 << dato[i].sexo << "\t"
				 << dato[i].cedula << "\t"
				 << dato[i].email << "\t"
				 << dato[i].telefono << "\t"
				 << dato[i].nAsiento << "\n";
		}
	}
}

void busquedaAvanzada(datos dato[]) {
	int opcion;
	do {
		system("cls");
		subrayar();
		cout<<"        busqueda avanzada        \n";
		subrayar();
		cout<<"1. buscar por cedula\n";
		cout<<"2. buscar por nombre\n";
		cout<<"3. volver al menu principal\n";
		subrayar();
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		teclaPresionada();
		
		switch(opcion) {
			case 1:
				busquedaPorCedula(dato);
				break;
			case 2:
				busquedaPorNombre(dato);
				break;
			case 3:
				cout<<"Volviendo al menu principal...\n";
				break;
			default:
				cout<<"Opcion invalida. Intente de nuevo.\n";
				getch();
		}
	} while(opcion != 3);
}

void busquedaPorCedula(datos dato[]) {
	long cedula;
	pantallaCentrada("Busqueda por Cedula", 160);
	cout << "Ingrese la cedula a buscar: ";
	recibirTipoDatoLong(cedula);
	int indice = buscarCedula(cedula, dato);
	if (indice == 0) {
		cout << "Cedula no encontrada.\n";
		return;
	} else {
		cout << "Datos del Pasajero:\n";
		cout << "Nombre: " << dato[indice].nombre << endl;
		cout << "Edad: " << dato[indice].edad << endl;
		cout << "Sexo: " << dato[indice].sexo << endl;
		cout << "Cedula: " << dato[indice].cedula << endl;
		cout << "Email: " << dato[indice].email << endl;
		cout << "Telefono: " << dato[indice].telefono << endl;
		cout << "Numero de Vuelo: " << dato[indice].nVuelo << endl;
		cout << "Numero de Asiento: " << dato[indice].nAsiento << endl;
	}
}

void busquedaPorNombre(datos dato[]) {
	string nombre;
	pantallaCentrada("Busqueda por Nombre", 160);
	cout << "Ingrese el nombre a buscar: ";
	recibirTipoDatoString(nombre);
	bool encontrado = false;
	cout << "Nombre\tEdad\tSexo\tCedula\tEmail\tTelefono\tAsiento\n";
	for (int i = 0; i < 10000; ++i) {
		if (dato[i].nombre.find(nombre) != string::npos) { // Cambiado a find
			encontrado = true;
			cout << "Datos del Pasajero:\n";
			cout << dato[i].nombre << "\t"
				 << dato[i].edad << "\t"
				 << dato[i].sexo << "\t"
				 << dato[i].cedula << "\t"
				 << dato[i].email << "\t"
				 << dato[i].telefono << "\t"
				 << dato[i].nAsiento << "\n";
		}
	}
	if (!encontrado) {
		cout << "Nombre no encontrado.\n";
	}
}