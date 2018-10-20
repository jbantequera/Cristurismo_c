/* 
 * File:   VistaPrograma.cpp
 * Author: Javier
 *
 * Created on 24 de mayo de 2018, 18:14
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <typeinfo>

#include "Pieza.h"
#include "Vehiculo.h"
#include "Jugador.h"
#include "VistaPrograma.h"

using namespace std;

/*******************
*	CONSTRUCTORES  *
*******************/
VistaPrograma::VistaPrograma(){
	this->listaPlayers = new Jugador* [1];
	this->setTotalPlayers(0);

	this->setJugadorActivo(0);

	this->catalogoVehiculos = new Vehiculo* [1];
	this->setTotalModelos(0);

	this->catalogoPiezas = new Pieza* [1];
	this->setTotalPiezas(0);

	this->setPrecioGasolina(0);
	this->setPrecioDiesel(0);

	this->setLogin("admin");
	this->setPasswd("admin");

	this->setPartidaCargada(false);
	this->resultadoBusqueda = 0;
	this->resultadoBusquedaJ = 0;
}

/*********************
*	  DESTRUCTOR	 *
*********************/
VistaPrograma::~VistaPrograma(){
	//Borramos los jugadores
	for (int i=0; i < this->getTotalPlayers(); i++)
		delete this->listaPlayers[i];

	this->setTotalPlayers(0);
	delete [] this->listaPlayers;
	this->listaPlayers = 0;

	//Quitamos al jugador activo
	this->setJugadorActivo(0);

	//Borramos los vehiculos
	for (int i=0; i < this->getTotalModelos(); i++)
		delete this->catalogoVehiculos[i];

	this->setTotalModelos(0);
	delete [] this->catalogoVehiculos;
	this->catalogoVehiculos = 0;

	//Borramos las piezas
	for (int i=0; i < this->getTotalPiezas(); i++)
		delete this->catalogoPiezas[i];

	this->setTotalPiezas(0);
	delete [] this->catalogoPiezas;
	this->catalogoPiezas = 0;

	//Reiniciamos el precio de los combustibles
	this->setPrecioGasolina(0);
	this->setPrecioDiesel(0);

	this->setLogin("");
	this->setPasswd("");

	this->setPartidaCargada(false);
}

/**********************
*	MÉTODOS PRIVADOS  *
**********************/
void VistaPrograma::resizeListaPlayers(int nuevotam){
	int tope = this->getTotalPlayers();
	Jugador** auxiliar = new Jugador* [nuevotam];

	//Comprobamos si el nuevo vector va a ser menor
	if (nuevotam < tope)
		tope = nuevotam;

	//Copiamos los punteros a jugador al nuevo vector
	for (int i=0; i < tope; i++){
		auxiliar[i] = this->listaPlayers[i];
	}

	//Borramos los jugadores sobrantes si reducimos el tamaño del vector
	for (int i=tope; i < this->getTotalPlayers(); i++){
		if (this->listaPlayers[i] != 0)
			delete listaPlayers[i];
	}

	//Asignamos el nuevo vector de vehiculos (No borramos porque llamaría al destructor de todos los Jugadores)
	this->listaPlayers = auxiliar;

	//Actualizamos las útiles
	this->setTotalPlayers(tope);
}

void VistaPrograma::resizeCatalogoVehiculos(int nuevotam){
	int tope = this->getTotalModelos();
	Vehiculo** auxiliar = new Vehiculo* [nuevotam];

	//Copiamos los vehículos al nuevo vector
	for (int i=0; i < tope; i++){
		auxiliar[i] = this->catalogoVehiculos[i];
	}

	//Asignamos el nuevo vector de vehiculos
	this->catalogoVehiculos = auxiliar;
}

void VistaPrograma::resizeCatalogoPiezas(int nuevotam){
	int tope = this->getTotalPiezas();
	Pieza** auxiliar = new Pieza* [nuevotam];

	//Copiamos los vehículos al nuevo vector
	for (int i=0; i < tope; i++){
		auxiliar[i] = this->catalogoPiezas[i];
	}

	//Asignamos el nuevo vector de vehiculos
	this->catalogoPiezas = auxiliar;
}

void VistaPrograma::resizeResultadoBusqueda(int nuevotam){
	int tope = this->getTotalModelos();
	Vehiculo** auxiliar = new Vehiculo* [nuevotam];

	//Copiamos los vehículos al nuevo vector
	for (int i=0; i < tope; i++){
		auxiliar[i] = this->catalogoVehiculos[i];
	}

	//Asignamos el nuevo vector de vehiculos
	this->catalogoVehiculos = auxiliar;
}
/*********************
*	MÉTODOS SET/GET  *
*********************/
void VistaPrograma::setJugadorActivo(Jugador* jugadorActivo){
	this->jugadorActivo = jugadorActivo;
}

void VistaPrograma::setTotalPlayers(int totalPlayers){
	this->totalPlayers = totalPlayers;
}

void VistaPrograma::setTotalModelos(int totalModelos){
	this->totalModelos = totalModelos;
}

void VistaPrograma::setTotalPiezas(int totalPiezas){
	this->totalPiezas = totalPiezas;
}

void VistaPrograma::setPrecioGasolina(double precioGasolina){
	this->precioGasolina = precioGasolina;
}

void VistaPrograma::setPrecioDiesel(double precioDiesel){
	this->precioDiesel = precioDiesel;
}

void VistaPrograma::setLogin(string login){
	this->login = login;
}

void VistaPrograma::setPasswd(string passwd){
	this->passwd = passwd;
}

void VistaPrograma::setPartidaCargada(bool partidaCargada){
	this->partidaCargada = partidaCargada;
}

//Gets
Jugador* VistaPrograma::getJugadorActivo() const{
	return(this->jugadorActivo);
}

int VistaPrograma::getTotalPlayers() const{
	return(this->totalPlayers);
}

int VistaPrograma::getTotalModelos() const{
	return(this->totalModelos);
}

int VistaPrograma::getTotalPiezas() const{
	return(this->totalPiezas);
}

double VistaPrograma::getPrecioGasolina() const{
	return(this->precioGasolina);
}

double VistaPrograma::getPrecioDiesel() const{
	return(this->precioDiesel);
}

string VistaPrograma::getLogin() const{
	return(this->login);
}

string VistaPrograma::getPasswd() const{
	return(this->passwd);
}

bool VistaPrograma::getPartidaCargada() const{
	return(this->partidaCargada);
}

/*********************
*	 OTROS MÉTODOS	 *
*********************/
void VistaPrograma::tituloASCII() const{
	cout << endl << endl;
	cout << "************************************************************************************************************************************************************************" << endl;
	cout << "  ,ad8888ba,               88                                               88                                                                ,ad8888ba,  888888888888  " << endl;
	cout << " d8 '    ` 8b                               ,d                                                                                               d8 '    ` 8b      88       " << endl;
	cout << "d8'                                         88                                                                                              d8'                88       " << endl;
	cout << "88             8b,dPPYba,  88  ,adPPYba,  MM88MMM  88       88  8b,dPPYba,  88  ,adPPYba,  88,dPYba,,adPYba,    ,adPPYba,                   88                 88       " << endl;
	cout << "88             88P'    Y8  88  I8[          88     88       88  88P'    Y8  88  I8[        88P'    88      8a  a8       8a     aaaaaaaa     88      88888      88       " << endl;
	cout << "Y8,            88          88   ` Y8ba,     88     88       88  88          88   ` Y8ba,   88      88      88  8b       d8                  Y8,        88      88       " << endl;
	cout << " Y8a.    .a8P  88          88  aa    ]8I    88,     8a,   ,a88  88          88  aa    ]8I  88      88      88   8a,   ,a8                    Y8a.    .a88      88       " << endl;
	cout << "  ` Y8888Y '   88          88  ` YbbdP '     Y888   ` YbbdP'Y8  88          88  ` YbbdP '  88      88      88   ` YbbdP '                     ` Y88888P        88 		 " << endl;
	cout << "************************************************************************************************************************************************************************" << endl;
	cout << endl << endl;
}

void VistaPrograma::autentificacionAdmin(){
	string login = "";
	string passwd = "";

	cout << "Por favor, introduzca sus credenciales: " << endl;
	
	do{
		do{
			cout << "Login: ";
			cin >> login;
		
			if (login != this->getLogin())
				cout << "¡Login incorrecto!" << endl;
		}while (login != this->getLogin());
		
		cout << "Contraseña: ";
		cin >> passwd;

		if (passwd != this->getPasswd())
			cout << "¡Credenciales incorrectos!" << endl;
	}while(passwd != this->getPasswd());

	cout << "¡Credenciales correctos!" << endl;
	cout << "Has entrado al sistema como administrador" << endl;

	this->imprimirMenu();
}

void VistaPrograma::Bienvenida(){
	this->tituloASCII();

	cout << "¡Bienvenido al GOTY de 2018!" << endl;

	this->autentificacionAdmin();
}

void VistaPrograma::importarDatos(){
	//cout << "debug: Vamos a importar vehiculos" << endl;
	this->importarCatalogo();
	//cout << "debug: Vamos a importar piezas" << endl;
	this->importarPiezas();
	//cout << "debug: Vamos a importar jugadores" << endl;
	this->importarJugadores();

	this->setPartidaCargada(true);
}

void VistaPrograma::importarCatalogo(){
    string cadena;
    ifstream fichero("data/Catalogo.xml");

	int id = 0;
	string marca = "";
	string modelo = "";

	//Depósito
	string tipoCombustible = "";
	int cilindrada = 0;
	double combustibleActual = 0;
	double capacidadDepositoMax = 0;

	//Estadísticas
	int caballos = 0;
	int aerodinamica = 0;
	int aceleracion = 0;
	int manejo = 0;
	int velocidadMax = 0;
	int frenada = 0;

	//Personalización
	int totalPiezas = 0;

	//Precios
	int precioBase = 0;
	bool disponible = false;
	
	//Exclusivo de camion
	int capacidadCarga = 0;

	//Primero vamos a leer el catálogo
	//cout << "debug: Importando datos de catálogo" << endl;
	
	//Mientras que no alcancemos el final del archivo
		while (!fichero.eof()){
			fichero >> cadena; //Leo cadena a cadena
			//cout << "debug: Cadena introducida --> " << cadena << endl;

			if (cadena == "<coche>"){ //Si la cadena coincide con la etiqueta hombre, pasamos a mapear un Coche
				//cout << "debug: Coche encontrado" << endl;
				while (cadena != "</coche>"){
					fichero >> cadena; //leo cadena a cadena hasta llegar al final de coche
					//cout << "debug: Cadena introducida --> " << cadena << endl;

					if (cadena == "<id>"){ //leemos la etiqueta <nombre>
						fichero >> id; //leemos el valor de nombre
						fichero >> cadena; //leemos la etiqueta </nombre> == salimos de <nombre>
					}

					else if (cadena == "<marca>"){ //leemos la etiqueta <apellido1>
						fichero >> marca; //leemos el valor de apellido1
						fichero >> cadena; // leemos la etiqueta </apellido1>
					}

					else if (cadena == "<modelo>"){ 
						fichero >> modelo;
						fichero >> cadena;
					}

					else if (cadena == "<tipoCombustible>"){
						fichero >> tipoCombustible;
						fichero >> cadena;
					}

					else if (cadena == "<cilindrada>"){
						fichero >> cilindrada;
						fichero >> cadena;
					}
					else if (cadena == "<capacidadDepositoMax>"){
						fichero >> capacidadDepositoMax;
						fichero >> cadena;
					}
					else if (cadena == "<caballos>"){
						fichero >> caballos;
						fichero >> cadena;
					}
					else if (cadena == "<aerodinamica>"){
						fichero >> aerodinamica;
						fichero >> cadena;
					}
					else if (cadena == "<aceleracion>"){
						fichero >> aceleracion;
						fichero >> cadena;
					}
					else if (cadena == "<manejo>"){
						fichero >> manejo;
						fichero >> cadena;
					}
					else if (cadena == "<velocidadMax>"){
						fichero >> velocidadMax;
						fichero >> cadena;
					}
					else if (cadena == "<frenada>"){
						fichero >> frenada;
						fichero >> cadena;
					}
					else if (cadena == "<combustibleActual>"){
						fichero >> combustibleActual;
						fichero >> cadena;
					}
					else if (cadena == "<totalPiezas>"){
						fichero >> totalPiezas;
						fichero >> cadena;
					}
					else if (cadena == "<precioBase>"){
						fichero >> precioBase;
						fichero >> cadena;
					}
					else if (cadena == "<catalogado>"){
						fichero >> cadena;

						if (cadena == "true")
							disponible = true;
						else if (cadena == "false")
							disponible = false;

						fichero >> cadena;
					}
				}

				//Creamos el nuevo coche en el vector catálogo
				this->agregarNuevoVehiculoAlSistema(new Coche(id, marca, modelo, tipoCombustible, cilindrada, combustibleActual, capacidadDepositoMax, caballos, aerodinamica, aceleracion, manejo, velocidadMax, frenada, precioBase, disponible));
				//cout << "debug: Coche añadido a catálogo" << endl;

				//Reiniciamos los datos
				id = 0;
				marca = "";
				modelo = "";
				tipoCombustible = "";
				cilindrada = 0;
				combustibleActual = 0;
				capacidadDepositoMax = 0;
				caballos = 0;
				aerodinamica = 0;
				aceleracion = 0;
				manejo = 0;
				velocidadMax = 0;
				frenada = 0;
				totalPiezas = 0;
				precioBase = 0;
				disponible = false;
			}
			
			if (cadena == "<moto>"){
				//cout << "debug: Coche encontrado" << endl;
				while (cadena != "</moto>"){
					fichero >> cadena;
					//cout << "debug: Cadena introducida --> " << cadena << endl;

					if (cadena == "<id>"){ 
						fichero >> id;
						fichero >> cadena;
					}

					else if (cadena == "<marca>"){
						fichero >> marca;
						fichero >> cadena;
					}

					else if (cadena == "<modelo>"){ 
						fichero >> modelo;
						fichero >> cadena;
					}

					else if (cadena == "<tipoCombustible>"){
						fichero >> tipoCombustible;
						fichero >> cadena;
					}

					else if (cadena == "<cilindrada>"){
						fichero >> cilindrada;
						fichero >> cadena;
					}
					else if (cadena == "<capacidadDepositoMax>"){
						fichero >> capacidadDepositoMax;
						fichero >> cadena;
					}
					else if (cadena == "<caballos>"){
						fichero >> caballos;
						fichero >> cadena;
					}
					else if (cadena == "<aerodinamica>"){
						fichero >> aerodinamica;
						fichero >> cadena;
					}
					else if (cadena == "<aceleracion>"){
						fichero >> aceleracion;
						fichero >> cadena;
					}
					else if (cadena == "<manejo>"){
						fichero >> manejo;
						fichero >> cadena;
					}
					else if (cadena == "<velocidadMax>"){
						fichero >> velocidadMax;
						fichero >> cadena;
					}
					else if (cadena == "<frenada>"){
						fichero >> frenada;
						fichero >> cadena;
					}
					else if (cadena == "<combustibleActual>"){
						fichero >> combustibleActual;
						fichero >> cadena;
					}
					else if (cadena == "<totalPiezas>"){
						fichero >> totalPiezas;
						fichero >> cadena;
					}
					else if (cadena == "<precioBase>"){
						fichero >> precioBase;
						fichero >> cadena;
					}
					else if (cadena == "<catalogado>"){
						fichero >> cadena;

						if (cadena == "true")
							disponible = true;
						else if (cadena == "false")
							disponible = false;

						fichero >> cadena;
					}
				}

				//Creamos la nueva moto en el vector catálogo
				this->agregarNuevoVehiculoAlSistema(new Motocicleta(id, marca, modelo, tipoCombustible, cilindrada, combustibleActual, capacidadDepositoMax, caballos, aerodinamica, aceleracion, manejo, velocidadMax, frenada, precioBase, disponible));
				//cout << "debug: Moto añadida a catálogo" << endl;

				//Reiniciamos los datos
				id = 0;
				marca = "";
				modelo = "";
				tipoCombustible = "";
				cilindrada = 0;
				combustibleActual = 0;
				capacidadDepositoMax = 0;
				caballos = 0;
				aerodinamica = 0;
				aceleracion = 0;
				manejo = 0;
				velocidadMax = 0;
				frenada = 0;
				totalPiezas = 0;
				precioBase = 0;
				disponible = false;
			}

			if (cadena == "<camion>"){
				//cout << "debug: Camion encontrado" << endl;
				while (cadena != "</camion>"){
					fichero >> cadena;
					//cout << "debug: Cadena introducida --> " << cadena << endl;

					if (cadena == "<id>"){ 
						fichero >> id;
						fichero >> cadena;
					}

					else if (cadena == "<marca>"){
						fichero >> marca;
						fichero >> cadena;
					}

					else if (cadena == "<modelo>"){ 
						fichero >> modelo;
						fichero >> cadena;
					}

					else if (cadena == "<tipoCombustible>"){
						fichero >> tipoCombustible;
						fichero >> cadena;
					}

					else if (cadena == "<cilindrada>"){
						fichero >> cilindrada;
						fichero >> cadena;
					}
					else if (cadena == "<capacidadDepositoMax>"){
						fichero >> capacidadDepositoMax;
						fichero >> cadena;
					}
					else if (cadena == "<caballos>"){
						fichero >> caballos;
						fichero >> cadena;
					}
					else if (cadena == "<aerodinamica>"){
						fichero >> aerodinamica;
						fichero >> cadena;
					}
					else if (cadena == "<aceleracion>"){
						fichero >> aceleracion;
						fichero >> cadena;
					}
					else if (cadena == "<manejo>"){
						fichero >> manejo;
						fichero >> cadena;
					}
					else if (cadena == "<velocidadMax>"){
						fichero >> velocidadMax;
						fichero >> cadena;
					}
					else if (cadena == "<frenada>"){
						fichero >> frenada;
						fichero >> cadena;
					}
					else if (cadena == "<combustibleActual>"){
						fichero >> combustibleActual;
						fichero >> cadena;
					}
					else if (cadena == "<totalPiezas>"){
						fichero >> totalPiezas;
						fichero >> cadena;
					}
					else if (cadena == "<precioBase>"){
						fichero >> precioBase;
						fichero >> cadena;
					}
					else if (cadena == "<capacidadCarga>"){
						fichero >> capacidadCarga;
						fichero >> cadena;
					}
					else if (cadena == "<catalogado>"){
						fichero >> cadena;

						if (cadena == "true")
							disponible = true;
						else if (cadena == "false")
							disponible = false;

						fichero >> cadena;
					}
				}

				//Creamos el nuevo camion en el vector catálogo
				this->agregarNuevoVehiculoAlSistema(new Camion(id, marca, modelo, tipoCombustible, cilindrada, combustibleActual, capacidadDepositoMax, caballos, aerodinamica, aceleracion, manejo, velocidadMax, frenada, precioBase, capacidadCarga, disponible));
				//cout << "debug: Camion añadido a catálogo" << endl;

				//Reiniciamos los datos
				id = 0;
				marca = "";
				modelo = "";
				tipoCombustible = "";
				cilindrada = 0;
				combustibleActual = 0;
				capacidadDepositoMax = 0;
				caballos = 0;
				aerodinamica = 0;
				aceleracion = 0;
				manejo = 0;
				velocidadMax = 0;
				frenada = 0;
				totalPiezas = 0;
				precioBase = 0;
				capacidadCarga = 0;
				disponible = false;
			}
		}

		fichero.close();
}

void VistaPrograma::importarPiezas(){
    string cadena;
    ifstream fichero("data/Piezas.xml");

	int id = 0;
	string nombre = "";

	int aerodinamica = 0;
	int frenada = 0;
	int velocidadMax = 0;
	int manejo = 0;
	int aceleracion = 0;

	int precio = 0;

	//Primero vamos a leer el catálogo
	//cout << "debug: Importando datos de catálogo de PIEZAS" << endl;
	
	//Mientras que no alcancemos el final del archivo
		while (!fichero.eof()){
			fichero >> cadena; //Leo cadena a cadena
			//cout << "debug: Cadena introducida --> " << cadena << endl;

			if (cadena == "<pieza>"){ //Si la cadena coincide con la etiqueta hombre, pasamos a mapear un Coche
				//cout << "debug: Pieza encontrado" << endl;
				while (cadena != "</pieza>"){
					fichero >> cadena; //leo cadena a cadena hasta llegar al final de coche
					//cout << "debug: Cadena introducida --> " << cadena << endl;

					if (cadena == "<id>"){
						fichero >> id;
						fichero >> cadena;
					}

					else if (cadena == "<nombre>"){
						fichero >> nombre;
						fichero >> cadena;
					}

					else if (cadena == "<aerodinamica>"){
						fichero >> aerodinamica;
						fichero >> cadena;
					}

					else if (cadena == "<frenada>"){
						fichero >> frenada;
						fichero >> cadena;
					}

					else if (cadena == "<velocidadMax>"){
						fichero >> velocidadMax;
						fichero >> cadena;
					}

					else if (cadena == "<manejo>"){
						fichero >> manejo;
						fichero >> cadena;
					}

					else if (cadena == "<aceleracion>"){
						fichero >> aceleracion;
						fichero >> cadena;
					}

					else if (cadena == "<precio>"){
						fichero >> precio;
						fichero >> cadena;
					}
				}

				//Añadimos la pieza al catálogo
				this->agregarNuevaPiezaAlSistema(new Pieza(id, nombre, aerodinamica, frenada, velocidadMax, manejo, aceleracion, precio));
				
				//Reiniciamos los datos
				id = 0;
				nombre = "";
				aerodinamica = 0;
				frenada = 0;
				velocidadMax = 0;
				manejo = 0;
				aceleracion = 0;
				precio = 0;
			}
		}

	fichero.close();
}

void VistaPrograma::importarJugadores(){
	string cadena;
	ifstream fichero("data/Jugadores.xml");

	//cout << "debug: Jugadores.xml abierto" << endl;

	int id = 0;
	string login = "";
	string passwd = "";
	double creditos = 0;
	int numeroVictorias = 0;
	int totalVehiculosGaraje = 0;
	bool carnetActual = false;

	//Variables para garaje
	Jugador* playerActual = 0;
	Vehiculo* vehiculoActual = 0;
	int idvehiculo = 0;
	int idpieza = 0;

	while(!fichero.eof()){
		fichero >> cadena;
		//cout << "debug: Cadena introducida --> " << cadena << endl;

		if (cadena == "<jugador>"){
			while (cadena != "</jugador>"){
				fichero >> cadena;
				//cout << "debug: Cadena introducida --> " << cadena << endl;
				
				if (cadena == "<id>"){
					fichero >> id;
					fichero >> cadena;
				}

				else if (cadena == "<login>"){
					fichero >> login;
					fichero >> cadena;
				}

				else if (cadena == "<passwd>"){
					fichero >> passwd;
					fichero >> cadena;
				}

				else if (cadena == "<creditos>"){
					fichero >> creditos;
					fichero >> cadena;
				}

				else if (cadena == "<numeroVictorias>"){
					fichero >> numeroVictorias;
					fichero >> cadena;

					//Creamos el usuario ahora que tenemos los datos necesarios
					playerActual = new Jugador(id, login, passwd, creditos, numeroVictorias);
					this->agregarNuevoJugadorAlSistema(playerActual);
				}

				else if (cadena == "<tipoCarnet>"){
					while (cadena != "</tipoCarnet>"){					
						fichero >> cadena;
						
						if (cadena == "<carnetA>"){
							fichero >> cadena;

							if (cadena == "true")
								carnetActual = true;
							else
								carnetActual = false;

							playerActual->setTipoCarnet(0, carnetActual);
							fichero >> cadena;
						}

						if (cadena == "<carnetB>"){
							fichero >> cadena;

							if (cadena == "true")
								carnetActual = true;
							else
								carnetActual = false;

							playerActual->setTipoCarnet(1, carnetActual);
							fichero >> cadena;
						}
						
						if (cadena == "<carnetC>"){
							fichero >> cadena;

							if (cadena == "true")
								carnetActual = true;
							else
								carnetActual = false;

							playerActual->setTipoCarnet(2, carnetActual);
							fichero >> cadena;
						}
					}
				}

				else if (cadena == "<garaje>"){
					while (cadena != "</garaje>"){
						fichero >> cadena;
						
						if (cadena == "<coche>"){
							while(cadena != "</coche>"){
								fichero >> cadena;
								
								if (cadena == "<id>"){
									fichero >> idvehiculo;
									vehiculoActual = new Coche(*(dynamic_cast<Coche*>(this->buscarCatalogoVehiculosID(idvehiculo))));
									playerActual->agregarVehiculo(vehiculoActual);
									fichero >> cadena;
								}
								
								else if (cadena == "<piezas>"){
									while (cadena != "</piezas>"){
										fichero >> cadena;
										if (cadena != "</piezas>"){
											idpieza = atoi(cadena.c_str());										

											playerActual->asignarPiezaVehiculo(vehiculoActual, this->buscarPieza(idpieza));
										}
									}
								}							
							}

							//Reiniciamos los datos de vehículo
							vehiculoActual = 0;
							idvehiculo = 0;
							idpieza = 0;
						}

						if (cadena == "<camion>"){
							while(cadena != "</camion>"){
								fichero >> cadena;
								
								if (cadena == "<id>"){
									fichero >> idvehiculo;
									vehiculoActual = new Camion(*(dynamic_cast<Camion*>(this->buscarCatalogoVehiculosID(idvehiculo))));
									playerActual->agregarVehiculo(vehiculoActual);
									fichero >> cadena;
								}
								
								else if (cadena == "<piezas>"){
									while (cadena != "</piezas>"){
										fichero >> cadena;
										if (cadena != "</piezas>"){
											idpieza = atoi(cadena.c_str());										

											playerActual->asignarPiezaVehiculo(vehiculoActual, this->buscarPieza(idpieza));
										}
									}
								}							
							}




							//Reiniciamos los datos de vehículo
							vehiculoActual = 0;
							idvehiculo = 0;
							idpieza = 0;
						}

						if (cadena == "<moto>"){
							while(cadena != "</moto>"){
								fichero >> cadena;
								
								if (cadena == "<id>"){
									fichero >> idvehiculo;
									vehiculoActual = new Motocicleta(*(dynamic_cast<Motocicleta*>(this->buscarCatalogoVehiculosID(idvehiculo))));
									playerActual->agregarVehiculo(vehiculoActual);
									fichero >> cadena;
								}
								
								else if (cadena == "<piezas>"){
									while (cadena != "</piezas>"){
										fichero >> cadena;
										if (cadena != "</piezas>"){
											idpieza = atoi(cadena.c_str());										

											playerActual->asignarPiezaVehiculo(vehiculoActual, this->buscarPieza(idpieza));
										}
									}
								}							
							}

							//Reiniciamos los datos de vehículo
							vehiculoActual = 0;
							idvehiculo = 0;
							idpieza = 0;
						}
					}				
				}			
			}

			//Reiniciamos los datos del jugador
			id = 0;
			login = "";
			passwd = "";
			creditos = 0;
			numeroVictorias = 0;
			totalVehiculosGaraje = 0;
			carnetActual = false;
			playerActual = 0;
		}
	}
}

void VistaPrograma::exportarDatos(){
	this->exportarCatalogo();
	//No vamos a modificar las piezas en ningún momento
	this->exportarJugadores();
}

void VistaPrograma::exportarCatalogo(){
	ofstream fichero("data/pruebacatalogo.xml");

	Vehiculo *v = 0;

	fichero << "<catalogo>" << endl;

	//Recorremos el vector de catálogo
	for(int i = 0; i < this->getTotalModelos(); i++){
		v = this->catalogoVehiculos[i];

		//Comprobamos el tipo de vehiculo
		if (Coche* c = dynamic_cast<Coche*>(v)){
			fichero << "\t<coche>" << endl;
			fichero << "\t\t<id> " << c->getID() << " </id>" << endl;
			fichero << "\t\t<marca> " << c->getMarca() << " </marca>" << endl;
			fichero << "\t\t<modelo> " << c->getModelo() << " </modelo>" << endl;
			fichero << "\t\t<tipoCombustible> " << c->getTipoCombustible() << " </tipoCombustible>" << endl;
			fichero << "\t\t<cilindrada> " << c->getCilindrada() << " </cilindrada>" << endl;
			fichero << "\t\t<capacidadDepositoMax> " << c->getCapacidadDepositoMax() << " </capacidadDepositoMax>" << endl;
			fichero << "\t\t<caballos> " << c->getCaballos() << " </caballos>" << endl;
			fichero << "\t\t<aerodinamica> " << c->getAerodinamica() << " </aerodinamica>" << endl;
			fichero << "\t\t<aceleracion> " << c->getAceleracion() << " </aceleracion>" << endl;
			fichero << "\t\t<manejo> " << c->getManejo() << " </manejo>" << endl;
			fichero << "\t\t<velocidadMax> " << c->getVelocidadMax() << " </velocidadMax>" << endl;
			fichero << "\t\t<frenada> " << c->getFrenada() << " </frenada>" << endl;
			fichero << "\t\t<combustibleActual> " << c->getCombustibleActual() << " </combustibleActual>" << endl;
			fichero << "\t\t<totalPiezas> " << c->getTotalPiezas() << " </totalPiezas>" << endl;
			fichero << "\t\t<precioBase> " << c->getPrecioBase() << " </precioBase>" << endl;
			fichero << "\t\t<precioActual> " << c->getPrecioActual() << " </precioActual>" << endl;
			if (c->getDisponible())			
				fichero << "\t\t<catalogado> " << "true" << " </catalogado>" << endl;
			else
				fichero << "\t\t<catalogado> " << "false" << " </catalogado>" << endl;
			fichero << "\t</coche>" << endl;
		}
		else if (Motocicleta* m = dynamic_cast<Motocicleta*>(v)){
			fichero << "\t<moto>" << endl;
			fichero << "\t\t<id> " << m->getID() << " </id>" << endl;
			fichero << "\t\t<marca> " << m->getMarca() << " </marca>" << endl;
			fichero << "\t\t<modelo> " << m->getModelo() << " </modelo>" << endl;
			fichero << "\t\t<tipoCombustible> " << m->getTipoCombustible() << " </tipoCombustible>" << endl;
			fichero << "\t\t<cilindrada> " << m->getCilindrada() << " </cilindrada>" << endl;
			fichero << "\t\t<capacidadDepositoMax> " << m->getCapacidadDepositoMax() << " </capacidadDepositoMax>" << endl;
			fichero << "\t\t<caballos> " << m->getCaballos() << " </caballos>" << endl;
			fichero << "\t\t<aerodinamica> " << m->getAerodinamica() << " </aerodinamica>" << endl;
			fichero << "\t\t<aceleracion> " << m->getAceleracion() << " </aceleracion>" << endl;
			fichero << "\t\t<manejo> " << m->getManejo() << " </manejo>" << endl;
			fichero << "\t\t<velocidadMax> " << m->getVelocidadMax() << " </velocidadMax>" << endl;
			fichero << "\t\t<frenada> " << m->getFrenada() << " </frenada>" << endl;
			fichero << "\t\t<combustibleActual> " << m->getCombustibleActual() << " </combustibleActual>" << endl;
			fichero << "\t\t<totalPiezas> " << m->getTotalPiezas() << " </totalPiezas>" << endl;
			fichero << "\t\t<precioBase> " << m->getPrecioBase() << " </precioBase>" << endl;
			fichero << "\t\t<precioActual> " << m->getPrecioActual() << " </precioActual>" << endl;
			if (m->getDisponible())			
				fichero << "\t\t<catalogado> " << "true" << " </catalogado>" << endl;
			else
				fichero << "\t\t<catalogado> " << "false" << " </catalogado>" << endl;
			fichero << "\t</moto>" << endl;
		}
		else if (Camion *c = dynamic_cast<Camion*>(v)){
			fichero << "\t<camion>" << endl;
			fichero << "\t\t<id> " << c->getID() << " </id>" << endl;
			fichero << "\t\t<marca> " << c->getMarca() << " </marca>" << endl;
			fichero << "\t\t<modelo> " << c->getModelo() << " </modelo>" << endl;
			fichero << "\t\t<tipoCombustible> " << c->getTipoCombustible() << " </tipoCombustible>" << endl;
			fichero << "\t\t<cilindrada> " << c->getCilindrada() << " </cilindrada>" << endl;
			fichero << "\t\t<capacidadDepositoMax> " << c->getCapacidadDepositoMax() << " </capacidadDepositoMax>" << endl;
			fichero << "\t\t<caballos> " << c->getCaballos() << " </caballos>" << endl;
			fichero << "\t\t<aerodinamica> " << c->getAerodinamica() << " </aerodinamica>" << endl;
			fichero << "\t\t<aceleracion> " << c->getAceleracion() << " </aceleracion>" << endl;
			fichero << "\t\t<manejo> " << c->getManejo() << " </manejo>" << endl;
			fichero << "\t\t<velocidadMax> " << c->getVelocidadMax() << " </velocidadMax>" << endl;
			fichero << "\t\t<frenada> " << c->getFrenada() << " </frenada>" << endl;
			fichero << "\t\t<combustibleActual> " << c->getCombustibleActual() << " </combustibleActual>" << endl;
			fichero << "\t\t<totalPiezas> " << c->getTotalPiezas() << " </totalPiezas>" << endl;
			fichero << "\t\t<precioBase> " << c->getPrecioBase() << " </precioBase>" << endl;
			fichero << "\t\t<precioActual> " << c->getPrecioActual() << " </precioActual>" << endl;
			fichero << "\t\t<capacidadCarga> " << c->getCapacidadCarga() << " </capacidadCarga>" << endl;
			if (c->getDisponible())			
				fichero << "\t\t<catalogado> " << "true" << " </catalogado>" << endl;
			else
				fichero << "\t\t<catalogado> " << "false" << " </catalogado>" << endl;
			fichero << "\t</camion>" << endl;
		}
	}

	fichero << "</catalogo>";
	fichero.close();
}

void VistaPrograma::exportarJugadores(){
	ofstream fichero("data/pruebajugadores.xml");
	Jugador* j = 0;
	Vehiculo* v = 0;

	fichero << "<jugadores>" << endl;

	//Recorremos la lista de jugadores
	for (int i=0; i < this->getTotalPlayers(); i++){
		j = this->listaPlayers[i];

		fichero << "\t<jugador>" << endl;
		fichero << "\t\t<id> " << j->getID() << " </id>" << endl;
		fichero << "\t\t<login> " << j->getLogin() << " </login>" << endl;
		fichero << "\t\t<passwd> " << j->getPasswd() << " </passwd>" << endl;
		fichero << "\t\t<creditos> " << j->getCreditos() << " </creditos>" << endl;
		fichero << "\t\t<numeroVictorias> " << j->getNumeroVictorias() << " </numeroVictorias>" << endl;
		fichero << "\t\t<tipoCarnet>" << endl;
			//Primer carnet
			if (j->getTipoCarnet(0))			
				fichero << "\t\t\t<carnetA> true </carnetA>" << endl;
			else
				fichero << "\t\t\t<carnetA> false </carnetA>" << endl;
			//Segundo carnet
			if (j->getTipoCarnet(1))			
				fichero << "\t\t\t<carnetB> true </carnetB>" << endl;
			else
				fichero << "\t\t\t<carnetB> false </carnetB>" << endl;
			//Tercer carnet
			if (j->getTipoCarnet(2))			
				fichero << "\t\t\t<carnetC> true </carnetC>" << endl;
			else
				fichero << "\t\t\t<carnetC> false </carnetC>" << endl;
		fichero << "\t\t</tipoCarnet>" << endl;
		fichero << "\t\t<totalVehiculosGaraje> " << j->getTotalVehiculosGaraje() << " </totalVehiculosGaraje>" << endl;
		fichero << "\t\t<garaje> " << endl;
			//Recorremos el garaje
			for (int t = 0; t < j->getTotalVehiculosGaraje(); t++){
				v = j->getVehiculo(t);

				if (Coche* c = dynamic_cast<Coche*>(v)){
					fichero << "\t\t\t<coche>" << endl;
					fichero << "\t\t\t\t<id> " << c->getID() << " </id>" << endl;
					fichero << "\t\t\t\t<piezas> ";
					for (int p = 0; p < c->getTotalPiezas(); p++){
						fichero << (c->getPieza(p))->getID() << " ";
					}					
					fichero << "</piezas>" << endl;
					fichero << "\t\t\t</coche>" << endl;
				}
				else if (Motocicleta* m = dynamic_cast<Motocicleta*>(v)){
					fichero << "\t\t\t<moto>" << endl;
					fichero << "\t\t\t\t<id> " << m->getID() << " </id>" << endl;
					fichero << "\t\t\t\t<piezas> ";
					for (int p = 0; p < m->getTotalPiezas(); p++){
						fichero << (m->getPieza(p))->getID() << " ";
					}					
					fichero << "</piezas>" << endl;
					fichero << "\t\t\t</moto>" << endl;
				}
				else if (Camion *c = dynamic_cast<Camion*>(v)){
					fichero << "\t\t\t<camion>" << endl;
					fichero << "\t\t\t\t<id> " << c->getID() << " </id>" << endl;
					fichero << "\t\t\t\t<piezas> ";
					for (int p = 0; p < c->getTotalPiezas(); p++){
						fichero << (c->getPieza(p))->getID() << " ";
					}					
					fichero << "</piezas>" << endl;
					fichero << "\t\t\t</camion>" << endl;
				}
			
			}
		fichero << "\t\t</garaje> " << endl;
		fichero << "\t</jugador>" << endl;
	}

	fichero << "</jugadores>";

	fichero.close();
}

void VistaPrograma::agregarNuevoVehiculoAlSistema(Vehiculo* v){
	//Si necesitamos ampliar el catálogo
	if (v->getID() >= this->getTotalModelos())
		this->resizeCatalogoVehiculos(this->getTotalModelos() + 1);

	this->catalogoVehiculos[this->getTotalModelos()] = v;
	this->setTotalModelos(this->getTotalModelos() + 1);
}

void VistaPrograma::agregarNuevaPiezaAlSistema(Pieza* p){
	//Si necesitamos ampliar el catálogo
	if (p->getID() >= this->getTotalPiezas())
		this->resizeCatalogoPiezas(this->getTotalPiezas() + 1);

	this->catalogoPiezas[this->getTotalPiezas()] = p;
	this->setTotalPiezas(this->getTotalPiezas() + 1);
}

void VistaPrograma::agregarNuevoJugadorAlSistema(Jugador *j){
	//Si necesitamos ampliar listaPlayers
	if (this->getTotalPlayers() != 0)
		this->resizeListaPlayers(this->getTotalPlayers() + 1);

	this->listaPlayers[this->getTotalPlayers()] = j;
	this->setTotalPlayers(this->getTotalPlayers() + 1);
	//cout << "debug: Jugador agregado al sistema" << endl;
}

void VistaPrograma::verCatalogoVehiculos() const{
	for (int i=0; i < this->getTotalModelos(); i++)
		this->catalogoVehiculos[i]->print();
}

void VistaPrograma::verCatalogoPiezas() const{
	for (int i=0; i < this->getTotalPiezas(); i++)
		this->catalogoPiezas[i]->print();
}

Vehiculo* VistaPrograma::buscarCatalogoVehiculosID(int idvehiculo){
	Vehiculo* resultado = 0;

	for (int i=0; i < this->getTotalModelos(); i++)
		if ((this->catalogoVehiculos[i])->getID() == idvehiculo)
			resultado = this->catalogoVehiculos[i];

	return(resultado);
}

Pieza* VistaPrograma::buscarPieza(int idpieza){
	Pieza* resultado = 0;

	for (int i=0; i < this->getTotalPiezas(); i++)
		if ((this->catalogoPiezas[i])->getID() == idpieza)
			resultado = this->catalogoPiezas[i];

	return(resultado);
}


void VistaPrograma::imprimirMenu(){
	int opcion = 0;

	do{
		cout << endl << "******************MENU******************" << endl;
		cout << "1. Administración del Sistema" << endl;
		cout << "2. Acciones del Usuario" << endl;
		cout << "0. Salir" << endl;
	
		cout << endl << "Opcion: ";
		cin >> opcion;

		switch(opcion){
			case 0:
				cout << "¡Hasta la próxima!" << endl;
				break;
			case 1:
				this->imprimirMenuAdmin();
				break;
			case 2:
				if (this->getPartidaCargada())
					this->loginUsuario();
				else
					cout << "Debes cargar la partida para loguearte" << endl;
				break;
			default:
				cout << "Escoge una opción válida" << endl;
		}
	}while(opcion != 0);
}

void VistaPrograma::imprimirMenuAdmin(){
	int opcion = 0;
	
	do{
		cout << endl << "******Administracion del Sistema*******" << endl;

		cout << "1. Importar Datos al Sistema desde Ficheros *.xml" << endl;
		cout << "2. Exportar Datos del Sistema a Ficheros *.xml" << endl;
		cout << "3. Rankings" << endl;
		cout << "4. Catálogo" << endl;
		cout << "5. Jugadores" << endl;
		cout << "0. Volver" << endl;

		cout << endl << "Opcion: ";
		cin >> opcion;
	
		switch(opcion){
			case 0:
				break;
			case 1:
				if(!(this->getPartidaCargada()))
					this->importarDatos();
				else
					cout << "¡Ya has cargado una partida!" << endl;
				break;
			case 2:
				if(this->getPartidaCargada())
					this->exportarDatos();
				else
					cout << "¡Necesitas cargar la partida!" << endl;
				break;
			case 3:
				if(this->getPartidaCargada())
					this->menuRankings();
				else
					cout << "¡Necesitas cargar la partida!" << endl;
				break;
			case 4:
				if(this->getPartidaCargada())
					this->imprimirMenuAdminCatalogo();
				else
					cout << "¡Necesitas cargar la partida!" << endl;
				break;
			case 5:
				if(this->getPartidaCargada())
					this->imprimirMenuAdminJugadores();
				else
					cout << "¡Necesitas cargar la partida!" << endl;
				break;
			default:
				cout << "Escoge una opción válida" << endl;
		}
	}while(opcion != 0);
}

void VistaPrograma::loginUsuario(){
	string login = "";
	string passwd = "";
	bool loginencontrado = false;

	cout << endl << "Por favor, introduzca sus credenciales: " << endl;
	
	do{
		do{
			loginencontrado = false;
			this->setJugadorActivo(0);

			cout << "Login: ";
			cin >> login;
		
			for (int i=0; i < this->getTotalPlayers(); i++)
				if (login == (this->listaPlayers[i])->getLogin()){
					loginencontrado = true;
					this->setJugadorActivo(this->listaPlayers[i]);
				}

			if (!loginencontrado)
				cout << "¡El usuario no existe en el sistema!" << endl;
		}while (!loginencontrado);
		
		cout << "Contraseña: ";
		cin >> passwd;

		if (passwd != (this->getJugadorActivo())->getPasswd())
			cout << "¡Credenciales incorrectos!" << endl;

	}while(passwd != (this->getJugadorActivo())->getPasswd());

	cout << "¡Credenciales correctos!" << endl;
	cout << "Bienvenido " << (this->getJugadorActivo())->getLogin() << endl;

	this->imprimirMenuUsuario();
}

void VistaPrograma::menuRankings(){
	int opcion = 0;

	do{
		cout << endl << "*******Ránkings*******" << endl;
		cout << "1. Top 3 Vehículos" << endl;
		cout << "2. Top 3 Coche / Moto / Camión" << endl;
		cout << "3. Hall de la Fama" << endl;
		cout << "0. Volver" << endl;

		cout << "Opción: ";
		cin >> opcion;

		switch(opcion){
			case 0:
				break;
			case 1:
				this->topVehiculos();
				break;
			case 2:
				this->topVehiculosEspecifico();
				break;
			case 3:
				this->topJugadores();
				break;
			default:
				cout << "Introduce una opción válida" << endl;
		}

	}while(opcion != 0);
}

void VistaPrograma::topVehiculos(){
	this->resultadoBusqueda = new Vehiculo* [5]; //Top 3 + FatBad + NitroIndomable
	this->resultadoBusquedaJ = new Jugador* [5];
	int util = 0;
	
	double valoracionMax = 0;
	double valoracionMin;
	int manejoMin;
	int aceleracionMax;
	bool vehiculoYaAsignado = false;

	Jugador* u = 0;

	//Top 3 por valoración media	
	for (int i = 0; i < 3; i++){
		valoracionMax = 0; //Reiniciamos la valoración máxima
		
		//Primero buscamos en el catálogo
		for (int j = 0; j < this->getTotalModelos(); j++){
			if ((this->catalogoVehiculos[j])->calcularMediaVehiculo() >= valoracionMax){ //Si damos con un vehículo que cumpla la condición
				vehiculoYaAsignado = false;

				for (int k = 0; k < util; k++){ //Comprobamos si ya hemos asignado ese vehículo al top comparando direcciones de memoria
					if (this->catalogoVehiculos[j] == this->resultadoBusqueda[k])
						vehiculoYaAsignado = true;
				}

				if (!vehiculoYaAsignado){
					this->resultadoBusqueda[i] = this->catalogoVehiculos[j];
					this->resultadoBusquedaJ[i] = 0;
					valoracionMax = (this->catalogoVehiculos[j])->calcularMediaVehiculo();
				}
			}
		}

		//Luego buscamos en los garajes de cada usuario
		for (int j = 0; j < this->getTotalPlayers(); j++){
			u = this->listaPlayers[j]; //Puntero auxiliar apuntando al jugador actual

			for (int k = 0; k < u->getTotalVehiculosGaraje(); k++){
				if ((u->getVehiculo(k))->calcularMediaVehiculo() >= valoracionMax){
					vehiculoYaAsignado = false;

					for (int l = 0; l < util; l++){
						if (u->getVehiculo(k) == this->resultadoBusqueda[l])
							vehiculoYaAsignado = true;
					}

					if (!vehiculoYaAsignado){
						this->resultadoBusqueda[i] = u->getVehiculo(k);
						this->resultadoBusquedaJ[i] = u;
						valoracionMax = (u->getVehiculo(k))->calcularMediaVehiculo();
					}
				}			
			}
		}

		util++;
	}

	//Vehículo FatBad (Peor nivel medio)
	//Primero asignamos el primer vehículo del catálogo (para tener un referente válido)
	this->resultadoBusqueda[3] = this->catalogoVehiculos[0];
	this->resultadoBusquedaJ[3] = 0;
	valoracionMin = (this->resultadoBusqueda[3])->calcularMediaVehiculo();

	//Buscamos en el resto del catálogo
	for (int i = 1; i < this->getTotalModelos(); i++){
		if ((this->catalogoVehiculos[i])->calcularMediaVehiculo() <= valoracionMin){
			this->resultadoBusqueda[3] = this->catalogoVehiculos[i];
			this->resultadoBusquedaJ[3] = 0;
			valoracionMin = (this->resultadoBusqueda[3])->calcularMediaVehiculo();
		}
	}

	//Buscamos en los garajes de los usuarios
	for (int i = 0; i < this->getTotalPlayers(); i++){
		u = this->listaPlayers[i];

		for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
			if ((u->getVehiculo(j))->calcularMediaVehiculo() <= valoracionMin){
				this->resultadoBusqueda[3] = u->getVehiculo(j);
				this->resultadoBusquedaJ[3] = u;
				valoracionMin = (u->getVehiculo(j))->calcularMediaVehiculo();
			}
		}
	}

	//Vehiculo Nitro-Indomable (Peor nivel de manejo + Mayor nivel de aceleración)
	//Primero asignamos el primer vehículo del catálogo (para tener un referente válido)
	this->resultadoBusqueda[4] = this->catalogoVehiculos[0];
	this->resultadoBusquedaJ[4] = 0;
	manejoMin = (this->resultadoBusqueda[4])->getManejo();
	aceleracionMax = (this->resultadoBusqueda[4])->getAceleracion();

	//Buscamos en el resto del catálogo
	for (int i = 1; i < this->getTotalModelos(); i++){
		if ((this->catalogoVehiculos[i])->getManejo() <= manejoMin){
			if ((this->catalogoVehiculos[i])->getAceleracion() >= aceleracionMax){
				this->resultadoBusqueda[4] = this->catalogoVehiculos[i];
				this->resultadoBusquedaJ[4] = 0;
				manejoMin = (this->resultadoBusqueda[4])->getManejo();
				aceleracionMax = (this->resultadoBusqueda[4])->getAceleracion();
			}
		}
	}

	//Buscamos en los garajes de los usuarios
	for (int i = 0; i < this->getTotalPlayers(); i++){
		u = this->listaPlayers[i];

		for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
			if ((u->getVehiculo(j))->getManejo() <= manejoMin){
				if ((u->getVehiculo(j))->getAceleracion() >= aceleracionMax){
					this->resultadoBusqueda[4] = u->getVehiculo(j);
					this->resultadoBusquedaJ[4] = u;
					manejoMin = (this->resultadoBusqueda[4])->getManejo();
					aceleracionMax = (this->resultadoBusqueda[4])->getAceleracion();
				}
			}
		}
	}

	//Imprimimos TOP 3
	cout << endl << "***Top 3 Vehículos***" << endl;
	for (int i=0; i<util; i++){
		cout << "[" << (i + 1) << "] - [Propietario: ";

		if (this->resultadoBusquedaJ[i] == 0)
			cout << "Catálogo";
		else
			cout << (this->resultadoBusquedaJ[i])->getLogin();

		cout << "] - ";	this->resultadoBusqueda[i]->printMinimo();
	}

	//Imprimimos FATBAD
	cout << endl << "***Vehículo FatBad***" << endl;
	cout << "Propietario: ";

	if (this->resultadoBusquedaJ[3] == 0)
		cout << "Catálogo" << endl;
	else
		cout << (this->resultadoBusquedaJ[3])->getLogin() << endl;

	this->resultadoBusqueda[3]->print();

	//Imprimimos NitroIndomable
	cout << endl << "***Vehículo Nitro-Indomable***" << endl;
	cout << "Propietario: ";

	if (this->resultadoBusquedaJ[3] == 0)
		cout << "Catálogo" << endl;
	else
		cout << (this->resultadoBusquedaJ[3])->getLogin() << endl;

	this->resultadoBusqueda[4]->print();

	//Borramos los resultados
	delete [] this->resultadoBusqueda;
	this->resultadoBusqueda = 0;

	delete [] this->resultadoBusquedaJ;
	this->resultadoBusquedaJ = 0;
}

void VistaPrograma::topVehiculosEspecifico(){
	this->resultadoBusqueda = new Vehiculo* [5]; //Top 3 + FatBad + NitroIndomable
	
	for (int i=0; i<5; i++){
		this->resultadoBusqueda[i] = 0;	
	}

	this->resultadoBusquedaJ = new Jugador* [5];

	int posAuxiliar = 0;	
	bool referenteAsignado = false;

	string tipoV = "";

	double valoracionMax = 0;
	double valoracionMin;
	int manejoMin;
	int aceleracionMax;
	bool vehiculoYaAsignado = false;

	Jugador* u = 0;

	do{
		cout << "¿De qué tipo de vehículo (moto/coche/camion) deseas hacer el ránking?: ";
		cin >> tipoV;
	}while((tipoV != "moto") && (tipoV != "coche") && (tipoV != "camion"));

	//Top 3 por valoración media	
	for (int i = 0; i < 3; i++){
		valoracionMax = 0; //Reiniciamos la valoración máxima
		
		//Primero buscamos en el catálogo
		for (int j = 0; j < this->getTotalModelos(); j++){
			if ((this->catalogoVehiculos[j])->calcularMediaVehiculo() >= valoracionMax){ //Si damos con un vehículo que cumpla la condición
				vehiculoYaAsignado = false;

				for (int k = 0; k < i; k++){ //Comprobamos si ya hemos asignado ese vehículo al top comparando direcciones de memoria
					if (this->catalogoVehiculos[j] == this->resultadoBusqueda[k])
						vehiculoYaAsignado = true;
				}

				if (!vehiculoYaAsignado){
					if (tipoV == "moto"){
						if (Motocicleta *m = dynamic_cast<Motocicleta*>(this->catalogoVehiculos[j])){
							this->resultadoBusqueda[i] = m;
							this->resultadoBusquedaJ[i] = 0;
							valoracionMax = m->calcularMediaVehiculo();
						}
					}
					else if (tipoV == "coche"){
						if (Coche *c = dynamic_cast<Coche*>(this->catalogoVehiculos[j])){
							this->resultadoBusqueda[i] = c;
							this->resultadoBusquedaJ[i] = 0;
							valoracionMax = c->calcularMediaVehiculo();
						}
					}
					else if (tipoV == "camion"){
						if (Camion *c = dynamic_cast<Camion*>(this->catalogoVehiculos[j])){
							this->resultadoBusqueda[i] = c;
							this->resultadoBusquedaJ[i] = 0;
							valoracionMax = c->calcularMediaVehiculo();
						}
					}
				}
			}
		}

		//Luego buscamos en los garajes de cada usuario
		for (int j = 0; j < this->getTotalPlayers(); j++){
			u = this->listaPlayers[j]; //Puntero auxiliar apuntando al jugador actual

			for (int k = 0; k < u->getTotalVehiculosGaraje(); k++){
				if ((u->getVehiculo(k))->calcularMediaVehiculo() >= valoracionMax){
					vehiculoYaAsignado = false;

					for (int l = 0; l < i; l++){
						if (u->getVehiculo(k) == this->resultadoBusqueda[l])
							vehiculoYaAsignado = true;
					}

					if (!vehiculoYaAsignado){
						if (tipoV == "moto"){
							if (Motocicleta *m = dynamic_cast<Motocicleta*>(u->getVehiculo(k))){
								this->resultadoBusqueda[i] = m;
								this->resultadoBusquedaJ[i] = u;
								valoracionMax = m->calcularMediaVehiculo();
							}
						}
						else if (tipoV == "coche"){
							if (Coche *c = dynamic_cast<Coche*>(u->getVehiculo(k))){
								this->resultadoBusqueda[i] = c;
								this->resultadoBusquedaJ[i] = u;
								valoracionMax = c->calcularMediaVehiculo();
							}
						}
						else if (tipoV == "camion"){
							if (Camion *c = dynamic_cast<Camion*>(u->getVehiculo(k))){
								this->resultadoBusqueda[i] = c;
								this->resultadoBusquedaJ[i] = u;
								valoracionMax = c->calcularMediaVehiculo();
							}
						}
					}
				}			
			}
		}
	}

	//Vehículo FatBad (Peor nivel medio)
	//Primero asignamos el primer vehículo del tipo del catálogo (para tener un referente válido)
	for (int i = 0; (i < this->getTotalModelos()) && (!referenteAsignado); i++){
		if (tipoV == "moto"){
			if (Motocicleta *m = dynamic_cast<Motocicleta*>(this->catalogoVehiculos[i])){
					this->resultadoBusqueda[3] = m;
					this->resultadoBusquedaJ[3] = 0;
					valoracionMin = m->calcularMediaVehiculo();
					referenteAsignado = true;
					posAuxiliar = i;
			}
		}
		else if (tipoV == "coche"){
			if (Coche *c = dynamic_cast<Coche*>(this->catalogoVehiculos[i])){
					this->resultadoBusqueda[3] = c;
					this->resultadoBusquedaJ[3] = 0;
					valoracionMin = c->calcularMediaVehiculo();
					referenteAsignado = true;
					posAuxiliar = i;
			}
		}
		else if (tipoV == "camion"){
			if (Camion *c = dynamic_cast<Camion*>(this->catalogoVehiculos[i])){
					this->resultadoBusqueda[3] = c;
					this->resultadoBusquedaJ[3] = 0;
					valoracionMin = c->calcularMediaVehiculo();
					referenteAsignado = true;
					posAuxiliar = i;
			}
		}
	}

	if (this->resultadoBusqueda[3] != 0){ //Si hemos encontrado al menos un referente
		//Buscamos en el resto del catálogo
		for (int i = posAuxiliar; i < this->getTotalModelos(); i++){
			if ((this->catalogoVehiculos[i])->calcularMediaVehiculo() <= valoracionMin){
				if (tipoV == "moto"){
					if (Motocicleta *m = dynamic_cast<Motocicleta*>(this->catalogoVehiculos[i])){
							this->resultadoBusqueda[3] = m;
							this->resultadoBusquedaJ[3] = 0;
							valoracionMin = m->calcularMediaVehiculo();
							referenteAsignado = true;
					}
				}
				else if (tipoV == "coche"){
					if (Coche *c = dynamic_cast<Coche*>(this->catalogoVehiculos[i])){
							this->resultadoBusqueda[3] = c;
							this->resultadoBusquedaJ[3] = 0;
							valoracionMin = c->calcularMediaVehiculo();
							referenteAsignado = true;
					}
				}
				else if (tipoV == "camion"){
					if (Camion *c = dynamic_cast<Camion*>(this->catalogoVehiculos[i])){
							this->resultadoBusqueda[3] = c;
							this->resultadoBusquedaJ[3] = 0;
							valoracionMin = c->calcularMediaVehiculo();
							referenteAsignado = true;
					}
				}			
			}
		}

		//Buscamos en los garajes de los usuarios
		for (int i = 0; i < this->getTotalPlayers(); i++){
			u = this->listaPlayers[i];

			for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
				if ((u->getVehiculo(j))->calcularMediaVehiculo() <= valoracionMin){
					if (tipoV == "moto"){
						if (Motocicleta *m = dynamic_cast<Motocicleta*>(u->getVehiculo(j))){
								this->resultadoBusqueda[3] = m;
								this->resultadoBusquedaJ[3] = u;
								valoracionMin = m->calcularMediaVehiculo();
								referenteAsignado = true;
						}
					}
					else if (tipoV == "coche"){
						if (Coche *c = dynamic_cast<Coche*>(u->getVehiculo(j))){
								this->resultadoBusqueda[3] = c;
								this->resultadoBusquedaJ[3] = u;
								valoracionMin = c->calcularMediaVehiculo();
								referenteAsignado = true;
						}
					}
					else if (tipoV == "camion"){
						if (Camion *c = dynamic_cast<Camion*>(u->getVehiculo(j))){
								this->resultadoBusqueda[3] = c;
								this->resultadoBusquedaJ[3] = u;
								valoracionMin = c->calcularMediaVehiculo();
								referenteAsignado = true;
						}
					}
				}
			}
		}
	}

	//Vehiculo Nitro-Indomable (Peor nivel de manejo + Mayor nivel de aceleración)
	referenteAsignado = false;
	posAuxiliar = 0;
	//Primero asignamos el primer vehículo del tipo concreto del catálogo (para tener un referente válido)
	for (int i = 0; (i < this->getTotalModelos()) && (!referenteAsignado); i++){
		if (tipoV == "moto"){
			if (Motocicleta *m = dynamic_cast<Motocicleta*>(this->catalogoVehiculos[i])){
					this->resultadoBusqueda[4] = m;
					this->resultadoBusquedaJ[4] = 0;
					manejoMin = m->getManejo();
					aceleracionMax = m->getAceleracion();
					referenteAsignado = true;
					posAuxiliar = i;
			}
		}
		else if (tipoV == "coche"){
			if (Coche *c = dynamic_cast<Coche*>(this->catalogoVehiculos[i])){
					this->resultadoBusqueda[4] = c;
					this->resultadoBusquedaJ[4] = 0;
					manejoMin = c->getManejo();
					aceleracionMax = c->getAceleracion();
					referenteAsignado = true;
					posAuxiliar = i;
			}
		}
		else if (tipoV == "camion"){
			if (Camion *c = dynamic_cast<Camion*>(this->catalogoVehiculos[i])){
					this->resultadoBusqueda[4] = c;
					this->resultadoBusquedaJ[4] = 0;
					manejoMin = c->getManejo();
					aceleracionMax = c->getAceleracion();
					referenteAsignado = true;
					posAuxiliar = i;
			}
		}
	}

	if (this->resultadoBusqueda[4] != 0){ // Si hemos encontrado al menos un referente en catálogo
		//Buscamos en el resto del catálogo
		for (int i = posAuxiliar; i < this->getTotalModelos(); i++){
			if ((this->catalogoVehiculos[i])->getManejo() == manejoMin){ //Si tiene el mismo nivel de manejo, comparamos la aceleracionMax
				if ((this->catalogoVehiculos[i])->getAceleracion() >= aceleracionMax){
					if (tipoV == "moto"){
						if (Motocicleta *m = dynamic_cast<Motocicleta*>(this->catalogoVehiculos[i])){
								this->resultadoBusqueda[4] = m;
								this->resultadoBusquedaJ[4] = 0;
								manejoMin = m->getManejo();
								aceleracionMax = m->getAceleracion();
						}
					}
					else if (tipoV == "coche"){
						if (Coche *c = dynamic_cast<Coche*>(this->catalogoVehiculos[i])){
								this->resultadoBusqueda[4] = c;
								this->resultadoBusquedaJ[4] = 0;
								manejoMin = c->getManejo();
								aceleracionMax = c->getAceleracion();
						}
					}
					else if (tipoV == "camion"){
						if (Camion *c = dynamic_cast<Camion*>(this->catalogoVehiculos[i])){
								this->resultadoBusqueda[4] = c;
								this->resultadoBusquedaJ[4] = 0;
								manejoMin = c->getManejo();
								aceleracionMax = c->getAceleracion();
						}
					}
				}
			}
			else if ((this->catalogoVehiculos[i])->getManejo() < manejoMin){ //Si es menor, asignamos directamente
				if (tipoV == "moto"){
					if (Motocicleta *m = dynamic_cast<Motocicleta*>(this->catalogoVehiculos[i])){
							this->resultadoBusqueda[4] = m;
							this->resultadoBusquedaJ[4] = 0;
							manejoMin = m->getManejo();
							aceleracionMax = m->getAceleracion();
					}
				}
				else if (tipoV == "coche"){
					if (Coche *c = dynamic_cast<Coche*>(this->catalogoVehiculos[i])){
							this->resultadoBusqueda[4] = c;
							this->resultadoBusquedaJ[4] = 0;
							manejoMin = c->getManejo();
							aceleracionMax = c->getAceleracion();
					}
				}
				else if (tipoV == "camion"){
					if (Camion *c = dynamic_cast<Camion*>(this->catalogoVehiculos[i])){
							this->resultadoBusqueda[4] = c;
							this->resultadoBusquedaJ[4] = 0;
							manejoMin = c->getManejo();
							aceleracionMax = c->getAceleracion();
					}
				}		
			}
		}

		//Buscamos en los garajes de los usuarios
		for (int i = 0; i < this->getTotalPlayers(); i++){
			u = this->listaPlayers[i];

			for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
				if ((u->getVehiculo(j))->getManejo() == manejoMin){ //Si el manejo es igual, tendremos que comparar la aceleración
					if ((u->getVehiculo(j))->getAceleracion() >= aceleracionMax){
						if (tipoV == "moto"){
							if (Motocicleta *m = dynamic_cast<Motocicleta*>(u->getVehiculo(j))){
									this->resultadoBusqueda[4] = m;
									this->resultadoBusquedaJ[4] = u;
									manejoMin = m->getManejo();
									aceleracionMax = m->getAceleracion();
							}
						}
						else if (tipoV == "coche"){
							if (Coche *c = dynamic_cast<Coche*>(u->getVehiculo(j))){
									this->resultadoBusqueda[4] = c;
									this->resultadoBusquedaJ[4] = u;
									manejoMin = c->getManejo();
									aceleracionMax = c->getAceleracion();
							}
						}
						else if (tipoV == "camion"){
							if (Camion *c = dynamic_cast<Camion*>(u->getVehiculo(j))){
									this->resultadoBusqueda[4] = c;
									this->resultadoBusquedaJ[4] = u;
									manejoMin = c->getManejo();
									aceleracionMax = c->getAceleracion();
							}
						}
					}
				}
				else if ((u->getVehiculo(j))->getManejo() < manejoMin){ //Si es menor, asignamos directamente
					if (tipoV == "moto"){
						if (Motocicleta *m = dynamic_cast<Motocicleta*>(u->getVehiculo(j))){
								this->resultadoBusqueda[4] = m;
								this->resultadoBusquedaJ[4] = u;
								manejoMin = m->getManejo();
								aceleracionMax = m->getAceleracion();
						}
					}
					else if (tipoV == "coche"){
						if (Coche *c = dynamic_cast<Coche*>(u->getVehiculo(j))){
								this->resultadoBusqueda[4] = c;
								this->resultadoBusquedaJ[4] = u;
								manejoMin = c->getManejo();
								aceleracionMax = c->getAceleracion();
						}
					}
					else if (tipoV == "camion"){
						if (Camion *c = dynamic_cast<Camion*>(u->getVehiculo(j))){
								this->resultadoBusqueda[4] = c;
								this->resultadoBusquedaJ[4] = u;
								manejoMin = c->getManejo();
								aceleracionMax = c->getAceleracion();
						}
					}
				}
			}
		}
	}

	//Imprimimos TOP 3
	cout << endl << "***Top 3 Vehículos***" << endl;
	for (int i=0; i < 3; i++){
		if (this->resultadoBusqueda[i] != 0){
			cout << "[" << (i + 1) << "] - [Propietario: ";

			if (this->resultadoBusquedaJ[i] == 0)
				cout << "Catálogo";
			else
				cout << (this->resultadoBusquedaJ[i])->getLogin();

			cout << "] - ";	this->resultadoBusqueda[i]->printMinimo();
		}
	}

	//Imprimimos FATBAD
	if (this->resultadoBusqueda[3] != 0){
		cout << endl << "***Vehículo FatBad***" << endl;
		cout << "Propietario: ";

		if (this->resultadoBusquedaJ[3] == 0)
			cout << "Catálogo" << endl;
		else
			cout << (this->resultadoBusquedaJ[3])->getLogin() << endl;

		this->resultadoBusqueda[3]->print();
	}
	else
		cout << "No existe un vehículo FatBad del tipo " << tipoV << endl;

	//Imprimimos NitroIndomable
	if (this->resultadoBusqueda[4] != 0){
		cout << endl << "***Vehículo Nitro-Indomable***" << endl;
		cout << "Propietario: ";

		if (this->resultadoBusquedaJ[3] == 0)
			cout << "Catálogo" << endl;
		else
			cout << (this->resultadoBusquedaJ[3])->getLogin() << endl;

		this->resultadoBusqueda[4]->print();
	}
	else
		cout << "No existe un vehículo Nitro-Indomable del tipo " << tipoV << endl;

	//Borramos los resultados
	delete [] this->resultadoBusqueda;
	this->resultadoBusqueda = 0;

	delete [] this->resultadoBusquedaJ;
	this->resultadoBusquedaJ = 0;
}

void VistaPrograma::topJugadores(){
	this->resultadoBusquedaJ = new Jugador* [3]; //Freak + ReadyPlayerOne + Messi

	int vehiculosMax = 0;
	int vehiculosMin = 0;
	double valoracionMediaActual = 0;
	double valoracionMediaMax = 0;
	double valoracionMediaMin = 0;

	//Freak: Más vehículos + Mejor Valoración Media (Garaje)
	//ReadyPlayerOne: Más victorias
	//Messi: Menos vehículos + Menor Valoración Media (Garaje)

	//Vamos a buscar el jugador Freak (1º asignamos el primer jugador de la lista para tener un referente)
	this->resultadoBusquedaJ[0] = this->listaPlayers[0];
	vehiculosMax = (this->resultadoBusquedaJ[0])->getTotalVehiculosGaraje();
	
	for (int i=0; i < (this->resultadoBusquedaJ[0])->getTotalVehiculosGaraje(); i++){
		valoracionMediaMax += ((this->resultadoBusquedaJ[0])->getVehiculo(i))->calcularMediaVehiculo();
	}

	valoracionMediaMax = valoracionMediaMax / (this->resultadoBusquedaJ[0])->getTotalVehiculosGaraje();

	//Ahora que ya tenemos asignado el jugador, buscamos en el resto de listaPlayers
	for (int i=1; i < this->getTotalPlayers(); i++){
		if (vehiculosMax < (this->listaPlayers[i])->getTotalVehiculosGaraje()){ //Si tiene más vehículos, asignamos directamente
			this->resultadoBusquedaJ[0] = this->listaPlayers[i];
			valoracionMediaMax = valoracionMediaActual;
			vehiculosMax = (this->listaPlayers[i])->getTotalVehiculosGaraje();
		}
		else if (vehiculosMax == (this->listaPlayers[i])->getTotalVehiculosGaraje()){ //Si tiene los mismos vehículos, compara las valoraciones de cada jugador
			//Calculamos la media actual del jugador listaPlayers[i]
			valoracionMediaActual = 0;

			for (int j=0; j < (this->listaPlayers[i])->getTotalVehiculosGaraje(); j++){
				valoracionMediaActual += ((this->listaPlayers[i])->getVehiculo(j))->calcularMediaVehiculo();
			}

			valoracionMediaActual = valoracionMediaActual / (this->listaPlayers[i])->getTotalVehiculosGaraje();

			if (valoracionMediaActual >= valoracionMediaMax){ //Asignamos un nuevo jugador freak
				this->resultadoBusquedaJ[0] = this->listaPlayers[i];
				valoracionMediaMax = valoracionMediaActual;
				vehiculosMax = (this->listaPlayers[i])->getTotalVehiculosGaraje();
			}
		}
	}

	//Ahora vamos a buscar al jugador ReadyPlayerOne (Asignamos el primero de igual forma)
	this->resultadoBusquedaJ[1] = this->listaPlayers[0];

	for (int i=0; i < this->getTotalPlayers(); i++){
		if ((this->listaPlayers[i])->getNumeroVictorias() >= (this->resultadoBusquedaJ[1])->getNumeroVictorias())
			this->resultadoBusquedaJ[1] = this->listaPlayers[i];
	}
	
	//Ahora vamos a buscar al jugador Messi
	this->resultadoBusquedaJ[2] = this->listaPlayers[0];
	vehiculosMin = (this->resultadoBusquedaJ[2])->getTotalVehiculosGaraje();
	
	for (int i=0; i < (this->resultadoBusquedaJ[2])->getTotalVehiculosGaraje(); i++){
		valoracionMediaMin += ((this->resultadoBusquedaJ[2])->getVehiculo(i))->calcularMediaVehiculo();
	}

	valoracionMediaMin = valoracionMediaMin / (this->resultadoBusquedaJ[2])->getTotalVehiculosGaraje();

	//Ahora que ya tenemos asignado el jugador, buscamos en el resto de listaPlayers
	for (int i=1; i < this->getTotalPlayers(); i++){
		if (vehiculosMin > (this->listaPlayers[i])->getTotalVehiculosGaraje()){ //Si tiene menos vehículos, asignamos directamente
			this->resultadoBusquedaJ[2] = this->listaPlayers[i];
			valoracionMediaMin = valoracionMediaActual;
			vehiculosMin = (this->listaPlayers[i])->getTotalVehiculosGaraje();
		}
		else if (vehiculosMin == (this->listaPlayers[i])->getTotalVehiculosGaraje()){ //Si tiene el mismo número de vehículos, comparamos valoraciones
			//Calculamos la media actual del jugador listaPlayers[i]
			valoracionMediaActual = 0;

			for (int j=0; j < (this->listaPlayers[i])->getTotalVehiculosGaraje(); j++){
				valoracionMediaActual += ((this->listaPlayers[i])->getVehiculo(j))->calcularMediaVehiculo();
			}

			valoracionMediaActual = valoracionMediaActual / (this->listaPlayers[i])->getTotalVehiculosGaraje();

			if (valoracionMediaActual <= valoracionMediaMin){ //Asignamos un nuevo jugador freak
				this->resultadoBusquedaJ[2] = this->listaPlayers[i];
				valoracionMediaMin = valoracionMediaActual;
				vehiculosMin = (this->listaPlayers[i])->getTotalVehiculosGaraje();
			}
		}
	}

	//Imprimimos los resultados
	cout << "********RANKING DE JUGADORES*******" << endl;
	cout << "Freak: \t\t" << (this->resultadoBusquedaJ[0])->getLogin() << " | Total Vehículos: " << vehiculosMax << " | Valoración Media: " << valoracionMediaMax << endl;
	cout << "ReadyPlayerOne: " << (this->resultadoBusquedaJ[1])->getLogin() << " | Total Victorias: " << (this->resultadoBusquedaJ[1])->getNumeroVictorias() << endl;
	cout << "Messi: \t\t" << (this->resultadoBusquedaJ[2])->getLogin() << " | Total Vehículos: " << vehiculosMin << " | Valoración Media: " << valoracionMediaMin << endl;

	//Borramos los resultados de la búsqueda
	delete [] this->resultadoBusquedaJ;
	this->resultadoBusquedaJ = 0;
}

void VistaPrograma::imprimirMenuAdminJugadores(){
	int opcion = 0;

	do{
		cout << endl << "******Administración de Usuarios******" << endl;
		cout << "1. Agregar Nuevo Jugador al Sistema" << endl;
		cout << "2. Eliminar Jugador del Sistema" << endl;
		cout << "3. Buscar Jugador en el Sistema" << endl;
		cout << "4. Modificar Datos Jugador del Sistema" << endl;
		cout << "0. Volver" << endl;

		cout << endl << "Opcion:";
		cin >> opcion;

		switch(opcion){
			case 0:
				break;
			case 1:
				this->menuAgregarUsuario();
				break;
			case 2:
				if (this->getTotalPlayers() != 0)
					this->menuEliminarUsuario();
				else
					cout << "No existen usuarios en el sistema" << endl;
				break;
			case 3:
				if (this->getTotalPlayers() != 0)
					this->menuBusquedaUsuario();
				else
					cout << "No existen usuarios en el sistema" << endl;
				break;
			case 4:
				if (this->getTotalPlayers() != 0)
					this->menuModificarUsuario();
				else
					cout << "No existen usuarios en el sistema" << endl;
				break;
			default:
				cout << "Introduzca una opción válida" << endl;
		}
	}while(opcion != 0);
}

void VistaPrograma::menuAgregarUsuario(){
	int id = this->getTotalPlayers();
	string login;
	string passwd;
	double creditos = 10000;
	int numeroVictorias = 0;

	bool loginExistente = false;
	
	cout << endl << "¡Bienvenido a la creación de Usuarios!" << endl;
	
	do{	
		loginExistente = false;
		cout << endl << "Introduzca el login del nuevo usuario: ";
		cin >> login;

		for (int i=0; i < this->getTotalPlayers(); i++)
			if ((this->listaPlayers[i])->getLogin() == login){
				loginExistente = true;
				cout << "Ya existe un usuario con este login" << endl;
			}
	}while(loginExistente);

	cout << "Introduzca la contraseña del nuevo usuario: ";
	cin >> passwd;

	//Agregamos el jugador
	this->agregarNuevoJugadorAlSistema(new Jugador(id, login, passwd, creditos, numeroVictorias));
}

void VistaPrograma::menuEliminarUsuario(){
	string login;
	bool loginExistente = false;
	int pos = 0;

	cout << endl << "Introduzca el login del usuario que desea eliminar: ";
	cin >> login;

	//Buscamos el usuario
	for (int i=0; i < this->getTotalPlayers(); i++)
		if ((this->listaPlayers[i])->getLogin() == login){
			loginExistente = true;
			pos = i;
		}

	if (loginExistente){ //Si existe
		delete this->listaPlayers[pos];

		//Desplazamos los jugadores hacia la izquierda a partir del jugador que eliminamos
		for (int i = pos; i < (this->getTotalPlayers() - 1); i++)
			this->listaPlayers[i] = this->listaPlayers[i + 1];

		//Ponemos a 0 el último puntero del vector antes de hacer resize (¡Borraria el usuario!)
		this->listaPlayers[this->getTotalPlayers() - 1] = 0;
		
		//Hacemos un resize
		this->resizeListaPlayers(this->getTotalPlayers() - 1);
	}
	else
		cout << "No existe un usuario con ese login en el sistema" << endl;
}

void VistaPrograma::menuBusquedaUsuario(){
	int opcion = 0;
	string login = "";
	Jugador* jugadorBuscado = 0;

	do{
		cout << "Búsqueda de Usuarios" << endl;
		cout << "1. Mostrar todos los usuarios del sistema" << endl;
		cout << "2. Buscar usuario por Login" << endl;
		cout << "0. Volver" << endl;

		cout << endl << "Opción: ";
		cin >> opcion;

		switch(opcion){
			case 0:
				break;
			case 1:
				for (int i=0; i < this->getTotalPlayers(); i++)
					(this->listaPlayers[i])->print();
				break;
			case 2:
				cout << "Introduzca el login deseado: ";
				cin >> login;

				for (int i=0; i < this->getTotalPlayers(); i++)
					if ((this->listaPlayers[i])->getLogin() == login)
						jugadorBuscado = listaPlayers[i];

				if (jugadorBuscado != 0)
					jugadorBuscado->print();
				else
					cout << "No existe ese jugador en el sistema" << endl;

				break;
			default:
				cout << "Introduzca una opción válida" << endl;		
		}
	}while(opcion != 0);
}

void VistaPrograma::menuModificarUsuario(){
	string loginBusqueda = "";
	Jugador* usuarioModificado = 0;
	int opcion = 0;

	string login = "";
	string passwd = "";
	double creditos = 0;

	cout << endl << "Introduzca el login del usuario que desea modificar: ";
	cin >> loginBusqueda;

	//Buscamos el usuario
	for (int i=0; i < this->getTotalPlayers(); i++)
		if ((this->listaPlayers[i])->getLogin() == loginBusqueda)
			usuarioModificado = listaPlayers[i];

	if (usuarioModificado != 0){
		do{
			cout << "¿Qué dato desea modificar?" << endl;
			cout << "1. Login" << endl;
			cout << "2. Contraseña" << endl;
			cout << "3. Créditos" << endl;
			cout << "0. Salir" << endl;

			cout << endl << "Opción: ";
			cin >> opcion;

			switch(opcion){
				case 0:
					break;
				case 1:
					cout << "Introduzca el nuevo login: ";
					cin >> login;
					usuarioModificado->setLogin(login);
					break;
				case 2:
					cout << "Introduzca la nueva contraseña: ";
					cin >> passwd;
					usuarioModificado->setPasswd(passwd);
					break;
				case 3:
					cout << "Introduzca la nueva cantidad de créditos: ";
					cin >> creditos;
					usuarioModificado->setCreditos(creditos);
					break;
				default:
					cout << "Introduzca una opción válida" << endl;		
			}
		}while(opcion != 0);
	}
	else
		cout << "El usuario no existe en el sistema" << endl;
}

void VistaPrograma::imprimirMenuAdminCatalogo(){
	int opcion = 0;

	do{
		cout << endl << "******Administración de Catálogo******" << endl;
		cout << "1. Agregar Nuevo Vehículo al Sistema" << endl;
		cout << "2. Eliminar Vehículo del Sistema" << endl;
		cout << "3. Buscar Vehículo en (TODO) el Sistema" << endl;
		cout << "4. Modificar Datos de un Vehículo del Sistema" << endl;
		cout << "5. Consultar Precio Medio Vehículo en el Sistema" << endl;
		cout << "0. Volver" << endl;

		cout << endl << "Opcion: ";
		cin >> opcion;

		switch(opcion){
			case 0:
				break;
			case 1:
				this->menuAgregarVehiculo();
				break;
			case 2:
				if (this->getTotalModelos() != 0)
					this->menuEliminarVehiculo();
				else
					cout << "No existen vehículos en el sistema" << endl;
				break;
			case 3:
				if (this->getTotalModelos() != 0)
					this->menuBusquedaVehiculo();
				else
					cout << "No existen vehículos en el sistema" << endl;
				break;
			case 4:
				if (this->getTotalModelos() != 0)
					this->menuModificarVehiculo();
				else
					cout << "No existen vehículos en el sistema" << endl;
				break;
			case 5:
				if (this->getTotalModelos() != 0)
					this->menuConsultarPrecioMedio();
				else
					cout << "No existen vehículos en el sistema" << endl;
				break;
			default:
				cout << "Introduzca una opción válida" << endl;
		}
	}while(opcion != 0);
}

void VistaPrograma::menuAgregarVehiculo(){
	string tipoVehiculo = "";

	int id = this->getTotalModelos();
	string marca = "";
	string modelo = "";
	string tipoCombustible = "";
	int cilindrada = 0;	
	double capacidadDepositoMax = 0;
	double combustibleActual = 0;

	//Estadísticas
	int caballos = 0;
	int aerodinamica = 0;
	int aceleracion = 0;
	int manejo = 0;
	int velocidadMax = 0;
	int frenada = 0;

	int capacidadCarga = 0;

	//Precios
	int precioBase = 0;
	bool disponible = false;

	bool vehiculoExistente = false;
	
	cout << endl << "¡Bienvenido a la creación de Vehículos!" << endl;
	
	do{
		cout << "¿Qué tipo de vehículo vas a agregar (Coche / Moto / Camion)?: ";
		cin >> tipoVehiculo;
	}while((tipoVehiculo != "Coche") && (tipoVehiculo != "Moto") && (tipoVehiculo != "Camion")); 

	do{	
		vehiculoExistente = false;
		cout << endl << "Introduzca la marca del nuevo vehículo: ";
		cin >> marca;

		cout << "Introduzca el modelo del nuevo vehículo: ";
		cin >> modelo;

		for (int i=0; i < this->getTotalPlayers(); i++)
			if (((this->catalogoVehiculos[i])->getMarca() == marca) && ((this->catalogoVehiculos[i])->getModelo() == modelo)){
				vehiculoExistente = true;
				cout << "Ya existe este vehículo en el sistema" << endl;
			}
	}while(vehiculoExistente);

	do{
		cout << "Introduzca el tipo de combustible (gasolina / diesel): ";
		cin >> tipoCombustible;
	}while((tipoCombustible != "gasolina") && (tipoCombustible != "diesel"));

	cout << "Introduzca la cilindrada del vehículo: ";
	cin >> cilindrada;

	cout << "Introduzca la capacidad del depósito: ";
	cin >> capacidadDepositoMax;

	cout << "Introduzca las siguientes estadísticas: " << endl;
	cout << "Caballos: ";
	cin >> caballos;
	cout << "Aerodinámica: ";
	cin >> aerodinamica;
	cout << "Aceleración: ";
	cin >> aceleracion;
	cout << "Manejo: ";
	cin >> manejo;
	cout << "Velocidad Máxima: ";
	cin >> velocidadMax;
	cout << "Frenada: ";
	cin >> frenada;

	if (tipoVehiculo == "Camion"){
		cout << "Capacidad de Carga: ";
		cin >> capacidadCarga;
	}

	cout << "Introduzca el precio base del vehículo: ";
	cin >> precioBase;

	//Agregamos el nuevo vehículo
	if (tipoVehiculo == "Coche")
		this->agregarNuevoVehiculoAlSistema(new Coche(id, marca, modelo, tipoCombustible, cilindrada, combustibleActual, capacidadDepositoMax, caballos, aerodinamica, aceleracion, manejo, velocidadMax, frenada, precioBase, disponible));
	else if (tipoVehiculo == "Moto")
		this->agregarNuevoVehiculoAlSistema(new Motocicleta(id, marca, modelo, tipoCombustible, cilindrada, combustibleActual, capacidadDepositoMax, caballos, aerodinamica, aceleracion, manejo, velocidadMax, frenada, precioBase, disponible));
	else if (tipoVehiculo == "Camion")
		this->agregarNuevoVehiculoAlSistema(new Camion(id, marca, modelo, tipoCombustible, cilindrada, combustibleActual, capacidadDepositoMax, caballos, aerodinamica, aceleracion, manejo, velocidadMax, frenada, precioBase, capacidadCarga, disponible));
}

void VistaPrograma::menuEliminarVehiculo(){
	string marca = "";
	string modelo = "";	
	Vehiculo* vehiculoEliminado = 0;

	cout << endl << "Introduzca la marca del vehículo: ";
	cin >> marca;

	cout << "Introduzca el modelo del vehículo: ";
	cin >> modelo;

	//Buscamos el vehículo en el sistema
	for (int i=0; i < this->getTotalModelos(); i++)
		if (((this->catalogoVehiculos[i])->getMarca() == marca) && ((this->catalogoVehiculos[i])->getModelo() == modelo)){
			vehiculoEliminado = this->catalogoVehiculos[i];
		}
	
	//Mensaje de error
	if (vehiculoEliminado == 0)
		cout << "No existe este vehículo en el sistema" << endl;
	else //Si existe
		if (vehiculoEliminado->getDisponible())
			vehiculoEliminado->setDisponible(false);
		else
			cout << "El vehículo ya está descatalogado" << endl;
}

void VistaPrograma::menuBusquedaVehiculo(){
	int opcion = 0;

	do{
		cout << "*******Búsqueda de Vehículos*******" << endl;
		cout << "1. Marca y modelo" << endl;
		cout << "2. Precio (menor)" << endl;
		cout << "3. Precio (mayor)" << endl;
		cout << "4. Valoracion media" << endl;
		cout << "0. Salir" << endl;

		do{
			cout << "Criterio: ";
			cin >> opcion;
		}while(opcion < 0);

		switch(opcion){
			case 0:
				break;
			case 1:
				this->busquedaMarcaModelo();
				break;
			case 2:
				this->busquedaPrecioMenor();
				break;
			case 3:
				this->busquedaPrecioMayor();
				break;
			case 4:
				this->busquedaValoracionMedia();
				break;
			default:
				cout << "Seleccione una opción válida" << endl;
		}
	}while(opcion != 0);
}

void VistaPrograma::menuModificarVehiculo(){
	int tam = 0;
	int util = 0;
	int pos = 0;

	Jugador* u = 0;

	string marca = "";
	string modelo = "";

	tam += this->getTotalModelos();

	for (int i=0; i<this->getTotalPlayers(); i++)
		tam += (this->listaPlayers[i])->getTotalVehiculosGaraje();

	this->resultadoBusqueda = new Vehiculo* [tam];
	this->resultadoBusquedaJ = new Jugador* [tam];

	cout << endl << "Introduzca la marca del vehículo que desea modificar: ";
	cin >> marca;

	cout << "Introduzca el modelo del vehículo que desea modificar: ";
	cin >> modelo;

	//Buscamos primero en catálogo
	for (int i=0; i < this->getTotalModelos(); i++){
		if (((this->catalogoVehiculos[i])->getMarca() == marca) && ((this->catalogoVehiculos[i])->getModelo() == modelo)){
			this->resultadoBusqueda[util] = this->catalogoVehiculos[i];
			this->resultadoBusquedaJ[util] = 0;
			util++;
		}
	}

	//Buscamos en cada jugador
	for (int i=0; i < this->getTotalPlayers(); i++){
		u = this->listaPlayers[i];

		for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
			if (((u->getVehiculo(j))->getMarca() == marca) && ((u->getVehiculo(j))->getModelo() == modelo)){
				this->resultadoBusqueda[util] = u->getVehiculo(j);
				this->resultadoBusquedaJ[util] = u;
				util++;			
			}
		}	
	}

	//Por último, imprimimos el resultado de la búsqueda
	cout << endl;
	for (int i=0; i < util; i++){
		cout << "[" << i << "] - Propietario: ";
		if (this->resultadoBusquedaJ[i] == 0)
			cout << "Catálogo";
		else
			cout << (this->resultadoBusquedaJ[i])->getLogin();
		
		cout << " - "; this->resultadoBusqueda[i]->printMinimo();
	}

	do{
		cout << endl << "Seleccione el vehículo que desea modificar (Negativo para salir): ";
		cin >> pos;
	}while(pos >= util);

	if (pos >= 0)
		this->subModificarVehiculo(this->resultadoBusqueda[pos]);

	//Nos deshacemos del vector de busqueda actual
	delete [] this->resultadoBusqueda;
	this->resultadoBusqueda = 0;
}

void VistaPrograma::subModificarVehiculo(Vehiculo* v){
	int opcion;
	string cadena = "";
	int stat = 0;

	cout << endl << "¿Qué datos desea modificar?" << endl;
	cout << "1. Marca" << endl;
	cout << "2. Modelo" << endl;
	cout << "3. Tipo de Combustible" << endl;
	cout << "4. Caballos" << endl;
	cout << "5. Aerodinámica" << endl;
	cout << "6. Aceleración" << endl;
	cout << "7. Manejo" << endl;
	cout << "8. Velocidad Máxima" << endl;
	cout << "9. Frenada" << endl;
	cout << "0. Salir" << endl;

	do{
		cout << endl << "Opción: ";
		cin >> opcion;
	}while(opcion > 9);

	switch(opcion){
		case 0:
			break;
		case 1:
			cout << "Introduce la nueva marca: ";
			cin >> cadena;
			v->setMarca(cadena);
			break;
		case 2:
			cout << "Introduce el nuevo modelo: ";
			cin >> cadena;
			v->setModelo(cadena);
			break;
		case 3:
			do{
				cout << "Introduce el tipo de combustible (gasolina / diesel): ";
				cin >> cadena;
			}while((cadena != "gasolina") && (cadena != "diesel"));
			v->setModelo(cadena);
			break;
		case 4:
			cout << "Introduce los nuevos caballos: ";
			cin >> stat;
			v->setCaballos(stat);
			break;
		case 5:
			cout << "Introduce la nueva aerodinámica: ";
			cin >> stat;
			v->setAerodinamica(stat);
			break;
		case 6:
			cout << "Introduce la nueva aceleración: ";
			cin >> cadena;
			v->setAceleracion(stat);
			break;
		case 7:
			cout << "Introduce el nuevo manejo: ";
			cin >> stat;
			v->setManejo(stat);
			break;
		case 8:
			cout << "Introduce la nueva velocidad máxima: ";
			cin >> stat;
			v->setVelocidadMax(stat);
			break;
		case 9:
			cout << "Introduce la nueva frenada: ";
			cin >> stat;
			v->setFrenada(stat);
			break;
		default:
			cout << "Introduce una opción válida" << endl;
	}
}

void VistaPrograma::busquedaMarcaModelo(){
	int tam = 0;
	int util = 0;

	Jugador* u = 0;

	string marca = "";
	string modelo = "";

	tam += this->getTotalModelos();

	for (int i=0; i<this->getTotalPlayers(); i++)
		tam += (this->listaPlayers[i])->getTotalVehiculosGaraje();

	this->resultadoBusqueda = new Vehiculo* [tam];
	this->resultadoBusquedaJ = new Jugador* [tam];

	cout << "Introduzca la marca del vehículo que desea buscar: ";
	cin >> marca;

	cout << "Introduzca el modelo del vehículo que desea buscar: ";
	cin >> modelo;

	//Buscamos primero en catálogo
	for (int i=0; i < this->getTotalModelos(); i++){
		if (((this->catalogoVehiculos[i])->getMarca() == marca) && ((this->catalogoVehiculos[i])->getModelo() == modelo)){
			this->resultadoBusqueda[util] = this->catalogoVehiculos[i];
			this->resultadoBusquedaJ[util] = 0;
			util++;
		}
	}

	//Buscamos en cada jugador
	for (int i=0; i < this->getTotalPlayers(); i++){
		u = this->listaPlayers[i];

		for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
			if (((u->getVehiculo(j))->getMarca() == marca) && ((u->getVehiculo(j))->getModelo() == modelo)){
				this->resultadoBusqueda[util] = u->getVehiculo(j);
				this->resultadoBusquedaJ[util] = u;
				util++;			
			}
		}	
	}

	//Por último, imprimimos el resultado de la búsqueda
	for (int i=0; i < util; i++){
		cout << "[" << i << "] - Propietario: ";
		if (this->resultadoBusquedaJ[i] == 0)
			cout << "Catálogo";
		else
			cout << (this->resultadoBusquedaJ[i])->getLogin();
		cout << " - "; (this->resultadoBusqueda[i])->printMinimo();
	}

	//Nos deshacemos del vector de busqueda actual
	delete [] this->resultadoBusqueda;
	this->resultadoBusqueda = 0;
	delete [] this->resultadoBusquedaJ;
	this->resultadoBusquedaJ = 0;
}

void VistaPrograma::busquedaPrecioMenor(){
	int tam = 0;
	int util = 0;

	Jugador* u = 0;

	int precio = 0;

	tam += this->getTotalModelos();

	for (int i=0; i<this->getTotalPlayers(); i++)
		tam += (this->listaPlayers[i])->getTotalVehiculosGaraje();

	resultadoBusqueda = new Vehiculo* [tam];
	resultadoBusquedaJ = new Jugador* [tam];

	cout << "Introduzca el precio máximo del vehículo: ";
	cin >> precio;

	//Buscamos primero en catálogo
	for (int i=0; i < this->getTotalModelos(); i++){
		if ((this->catalogoVehiculos[i])->getPrecioActual() <= precio){
			this->resultadoBusqueda[util] = this->catalogoVehiculos[i];
			this->resultadoBusquedaJ[util] = 0;
			util++;
		}
	}

	//Buscamos en cada jugador
	for (int i=0; i < this->getTotalPlayers(); i++){
		u = this->listaPlayers[i];

		for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
			if ((u->getVehiculo(j))->getPrecioActual() <= precio){
				this->resultadoBusqueda[util] = u->getVehiculo(j);
				this->resultadoBusquedaJ[util] = u;
				util++;			
			}
		}	
	}

	//Por último, imprimimos el resultado de la búsqueda
	for (int i=0; i < util; i++){
		cout << "[" << i << "] - Propietario: ";
		if (this->resultadoBusquedaJ[i] == 0)
			cout << "Catálogo";
		else
			cout << (this->resultadoBusquedaJ[i])->getLogin();
		cout << " - "; (this->resultadoBusqueda[i])->printMinimo();
	}

	//Nos deshacemos del vector de busqueda actual
	delete [] this->resultadoBusqueda;
	this->resultadoBusqueda = 0;
	delete [] this->resultadoBusquedaJ;
	this->resultadoBusquedaJ = 0;
}

void VistaPrograma::busquedaPrecioMayor(){
	int tam = 0;
	int util = 0;

	Jugador* u = 0;

	int precio = 0;

	tam += this->getTotalModelos();

	for (int i=0; i<this->getTotalPlayers(); i++)
		tam += (this->listaPlayers[i])->getTotalVehiculosGaraje();

	this->resultadoBusqueda = new Vehiculo* [tam];
	this->resultadoBusquedaJ = new Jugador* [tam];

	cout << "Introduzca el precio mínimo del vehículo: ";
	cin >> precio;

	//Buscamos primero en catálogo
	for (int i=0; i < this->getTotalModelos(); i++){
		if ((this->catalogoVehiculos[i])->getPrecioActual() >= precio){
			this->resultadoBusqueda[util] = this->catalogoVehiculos[i];
			this->resultadoBusquedaJ[util] = 0;
			util++;
		}
	}

	//Buscamos en cada jugador
	for (int i=0; i < this->getTotalPlayers(); i++){
		u = this->listaPlayers[i];

		for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
			if ((u->getVehiculo(j))->getPrecioActual() >= precio){
				this->resultadoBusqueda[util] = u->getVehiculo(j);
				this->resultadoBusquedaJ[util] = u;
				util++;			
			}
		}	
	}

	//Por último, imprimimos el resultado de la búsqueda
	for (int i=0; i < util; i++){
		cout << "[" << i << "] - Propietario: ";
		if (this->resultadoBusquedaJ[i] == 0)
			cout << "Catálogo";
		else
			cout << (this->resultadoBusquedaJ[i])->getLogin();
		cout << " - "; (this->resultadoBusqueda[i])->printMinimo();
	}

	//Nos deshacemos del vector de busqueda actual
	delete [] this->resultadoBusqueda;
	this->resultadoBusqueda = 0;
	delete [] this->resultadoBusquedaJ;
	this->resultadoBusquedaJ = 0;
}

void VistaPrograma::busquedaValoracionMedia(){
	int tam = 0;
	int util = 0;

	Jugador* u = 0;

	double valoracion = 0;

	tam += this->getTotalModelos();

	for (int i=0; i<this->getTotalPlayers(); i++)
		tam += (this->listaPlayers[i])->getTotalVehiculosGaraje();

	resultadoBusqueda = new Vehiculo* [tam];
	resultadoBusquedaJ = new Jugador* [tam];

	cout << "Introduzca la valoración media mínima del vehículo: ";
	cin >> valoracion;

	//Buscamos primero en catálogo
	for (int i=0; i < this->getTotalModelos(); i++){
		if ((this->catalogoVehiculos[i])->calcularMediaVehiculo() <= valoracion){
			this->resultadoBusqueda[util] = this->catalogoVehiculos[i];
			this->resultadoBusquedaJ[util] = 0;
			util++;
		}
	}

	//Buscamos en cada jugador
	for (int i=0; i < this->getTotalPlayers(); i++){
		u = this->listaPlayers[i];

		for (int j = 0; j < u->getTotalVehiculosGaraje(); j++){
			if ((u->getVehiculo(j))->calcularMediaVehiculo() <= valoracion){
				this->resultadoBusqueda[util] = u->getVehiculo(j);
				this->resultadoBusquedaJ[util] = u;
				util++;			
			}
		}	
	}

	//Por último, imprimimos el resultado de la búsqueda
	for (int i=0; i < util; i++){
		cout << "[" << i << "] - Propietario: ";
		if (this->resultadoBusquedaJ[i] == 0)
			cout << "Catálogo";
		else
			cout << (this->resultadoBusquedaJ[i])->getLogin();
		cout << " - "; (this->resultadoBusqueda[i])->printMinimo();
	}

	//Nos deshacemos del vector de busqueda actual
	delete [] this->resultadoBusqueda;
	this->resultadoBusqueda = 0;
	delete [] this->resultadoBusquedaJ;
	this->resultadoBusquedaJ = 0;
}

void VistaPrograma::menuConsultarPrecioMedio(){
	int tamaniomax = 0;
	int util = 0;

	string marca = "";
	string modelo = "";

	Jugador* jugadorActual = 0;
	double preciomedio = 0;

	//Calculamos el tamaño máximo del vector de búsqueda
	for (int i=0; i < this->getTotalPlayers(); i++)
		tamaniomax += (this->listaPlayers[i])->getTotalVehiculosGaraje();

	//Ahora que ya lo tenemos calculado, reservamos el espacio necesario
	this->resultadoBusqueda = new Vehiculo* [tamaniomax];

	//Preguntamos por la marca y el modelo
	cout << endl << "Introduce la marca del vehículo: ";
	cin >> marca;
	cout << "Introduce el modelo del vehículo: ";
	cin >> modelo;

	//Procedemos a buscar en los garajes de cada usuario
	for (int i=0; i < this->getTotalPlayers(); i++){
		jugadorActual = listaPlayers[i];
		
		for (int j=0; j < jugadorActual->getTotalVehiculosGaraje(); j++){
			if (((jugadorActual->getVehiculo(j))->getMarca() == marca) && ((jugadorActual->getVehiculo(j))->getModelo() == modelo)){
				this->resultadoBusqueda[util] = jugadorActual->getVehiculo(j);
				util++;			
			}
		}
	}

	//Si hemos encontrado alguno, procedemos a calcular el precio medio
	if (util > 0){
		for (int i=0; i < util; i++)
			preciomedio += resultadoBusqueda[i]->getPrecioActual();

		//Dividimos entre las útiles
		preciomedio = preciomedio / util;

		cout << "Precio medio de " << marca << " " << modelo << ": " << preciomedio << endl;
	}
	else
		cout << "No se ha encontrado el vehículo en ningún garaje" << endl;

	delete [] this->resultadoBusqueda;
	resultadoBusqueda = 0;
}

void VistaPrograma::imprimirMenuUsuario(){
	int opcion = 0;

	do{
		cout << endl << "******Menú de Usuario******" << endl;
		cout << "1. Consultar Garaje" << endl;
		cout << "2. Comprar Vehículo (a catálogo)" << endl;
		cout << "3. Vender Vehículo (a jugador)" << endl;
		cout << "4. Asignar Pieza a un Vehículo" << endl;
		cout << "5. Quitar Pieza a un Vehículo" << endl;
		cout << "6. Competir" << endl;
		cout << "0. Volver" << endl;

		cout << endl << "Opcion: ";
		cin >> opcion;

		switch(opcion){
			case 0:
				break;
			case 1:
				jugadorActivo->consultarGaraje();
				break;
			case 2:
				this->menuComprarVehiculo();
				break;
			case 3:
				this->menuVenderVehiculo();
				break;
			case 4:
				this->menuAsignarPieza();
				break;
			case 5:
				this->menuEliminarPieza();
				break;
			case 6:
				this->menuCompeticion();
				break;
			default:
				cout << "Introduzca una opción válida" << endl;
		}
	}while(opcion != 0);
}

void VistaPrograma::menuComprarVehiculo(){
	this->resultadoBusqueda = new Vehiculo* [this->getTotalModelos()];
	int utiles = 0;
	int pos = 0;

	//Añadimos a resultadoBusqueda los vehículos disponibles del catálogo
	for(int i=0; i < this->getTotalModelos(); i++){
		if ((this->catalogoVehiculos[i])->getDisponible()){
			this->resultadoBusqueda[utiles] = this->catalogoVehiculos[i];
			utiles++;
		}
	}

	//Los mostramos al usuario
	cout << "*******CATALOGO*******" << endl;
	for (int i=0; i < utiles; i++){
		cout << "[" << i << "] - "; (this->resultadoBusqueda[i])->printMinimo();
	}

	cout << endl << "Créditos disponibles: " << jugadorActivo->getCreditos() << endl;
	cout << "¿Qué vehículo desea comprar? (Negativo para salir): ";
	cin >> pos;

	if (pos >= 0){
		//Comprobamos si el jugador tiene créditos suficientes
		if (((this->resultadoBusqueda[pos])->getPrecioActual()) <= jugadorActivo->getCreditos())
			jugadorActivo->comprarVehiculo(this->resultadoBusqueda[pos]);
		else
			cout << "¡No dispones de los créditos suficientes!" << endl;
	}

	delete [] this->resultadoBusqueda;
	this->resultadoBusqueda = 0;
}

void VistaPrograma::menuVenderVehiculo(){
	string login = "";
	int posV = 0;
	Jugador* cliente = 0;
	Vehiculo* vehiculoActual = 0;

	cout << "¿A qué jugador deseas vender el vehículo?: ";
	cin >> login;

	//Buscamos al jugador
	for (int i = 0; i < this->getTotalPlayers(); i++){
		if ((this->listaPlayers[i])->getLogin() == login)
			cliente = this->listaPlayers[i];
	}

	//Si hemos encontrado al jugador
	if (cliente != 0){
		jugadorActivo->verGaraje();

		do{
			cout << "¿Qué vehículo deseas vender? (Negativo para salir): ";
			cin >> posV;
		}while(posV >= jugadorActivo->getTotalVehiculosGaraje());

		if (posV >= 0){
			vehiculoActual = jugadorActivo->getVehiculo(posV);
			
			if (cliente->getCreditos() >= vehiculoActual->getPrecioActual()){
				jugadorActivo->venderVehiculo(posV, cliente);
			}
			else
				cout << "¡No dispones de los créditos suficientes!" << endl;
		}
	}	
	else
		cout << "El jugador no existe en el sistema" << endl;
}

void VistaPrograma::menuAsignarPieza(){
	Vehiculo* vehiculoActual = 0;
	Pieza* piezaActual = 0;

	int posV = 0;
	int posP = 0;

	bool piezaEquipada = false;

	jugadorActivo->verGaraje();

	do{
		cout << endl << "¿A qué coche deseas asignarle la pieza? (Negativo para salir): ";
		cin >> posV;
	}while(posV >= jugadorActivo->getTotalVehiculosGaraje());

	if (posV >= 0){
		vehiculoActual = jugadorActivo->getVehiculo(posV);

		//Imprimimos las piezas del catálogo
		for (int i=0; i < this->getTotalPiezas(); i++){
			cout << "[" << i << "] - "; (this->catalogoPiezas[i])->printMinimo();		
		}

		do{
			cout << endl << "Créditos disponibles: " << jugadorActivo->getCreditos() << endl;
			cout << "¿Qué pieza deseas comprar? (Negativo para salir): ";
			cin >> posP;
		}while(posP >= this->getTotalPiezas());

		if (posP >= 0){
			piezaActual = this->catalogoPiezas[posP];

			if (piezaActual->getPrecio() <= jugadorActivo->getCreditos()){
				//Recorremos el vector de tunning del vehículo para comprobar que la pieza no está ya asignada
				for (int i=0; i < vehiculoActual->getTotalPiezas(); i++){
					if((vehiculoActual->getPieza(i))->getID() == piezaActual->getID()){
						cout << "El vehículo ya tiene equipada esta pieza" << endl;
						piezaEquipada = true;
					}
				}

				if (!piezaEquipada)
					vehiculoActual->setPieza(vehiculoActual->getTotalPiezas(), piezaActual);
			}
			else
				cout << "No dispones de los créditos suficientes" << endl;
		}
	}
}

void VistaPrograma::menuEliminarPieza(){
	Vehiculo* vehiculoActual = 0;

	int posV = 0;
	int posP = 0;

	//Imprimimos el garaje del jugador activo	
	jugadorActivo->verGaraje();

	do{
		cout << endl << "¿A qué coche deseas asignarle la pieza? (Negativo para salir): ";
		cin >> posV;
	}while(posV >= jugadorActivo->getTotalVehiculosGaraje());

	if (posV >= 0){
		vehiculoActual = jugadorActivo->getVehiculo(posV);

		//Mostramos las piezas equipadas a ese vehículo
		vehiculoActual->printTunning();

		do{
			cout << endl << "¿Qué pieza desea eliminar? (Negativo para salir): ";
			cin >> posP;
		}while(posP >= vehiculoActual->getTotalPiezas());

		if (posP >= 0){
			vehiculoActual->quitarPieza(posP);
		}
	}
}

void VistaPrograma::menuCompeticion(){
	Vehiculo* v1 = 0;

	Jugador* contrincante = 0;
	Vehiculo* v2 = 0;

	string loginCont = "";
	int modalidad = 0;
	int pos = 0;
	
	bool condAuxiliar = false;

	cout << endl << "Bienvenido al menú de competición, " << (this->getJugadorActivo())->getLogin() << endl;
	cout << "¿En qué modalidad desea competir?: " << endl;
	cout << "1. Coches" << endl;
	cout << "2. Motos" << endl;
	cout << "3. Camiones" << endl;
	cout << "0. Volver" << endl;

	do{
		cout << endl << "Opción: ";
		cin >> modalidad;
	}while((modalidad > 3) || (modalidad < 0));
	cout << endl;

	if ((this->getJugadorActivo())->getTipoCarnet(modalidad - 1)){
		this->getJugadorActivo()->verGaraje();
		do{
			do{
				cout << "¿Con qué vehículo quieres competir? (Negativo para salir): ";
				cin >> 	pos;	
			}while(pos >= (this->getJugadorActivo())->getTotalVehiculosGaraje());

			if (pos >= 0){
				v1 = (this->getJugadorActivo())->getVehiculo(pos);

				//Comprobamos que el vehículo que escogemos es válido para la categoría escogida
				if (modalidad == 1){
					if (Coche *c = dynamic_cast<Coche*>(v1)){
						condAuxiliar = true;
					}
				}
				else if (modalidad == 2){
					if (Motocicleta *m = dynamic_cast<Motocicleta*>(v1)){
						condAuxiliar = true;
					}
				}
				else if (modalidad == 3){
					if (Camion *c1 = dynamic_cast<Camion*>(v1)){
						condAuxiliar = true;
					}
				}

				if (!condAuxiliar)
					cout << "Has escogido un vehículo de otra modalidad" << endl;
			}
			else
				condAuxiliar = true;
		}while(!condAuxiliar);

		if (pos >= 0){
			do{
				cout << "¿Contra quién quieres competir?: ";
				cin >> loginCont;
			}while(loginCont == (this->getJugadorActivo())->getLogin());

			//Buscamos al contrincante
			for (int i=0; i < this->getTotalPlayers(); i++){
				if ((this->listaPlayers[i])->getLogin() == loginCont)
					contrincante = this->listaPlayers[i];
			}

			if (contrincante != 0){ //Si existe el contrincante
				if (contrincante->getTipoCarnet(modalidad - 1)){ //Y tiene el carnét necesario para competir
					contrincante->verGaraje();
					do{
						do{
							cout << "¿Contra qué vehículo quieres competir? (Negativo para salir): ";
							cin >> 	pos;	
						}while(pos >= contrincante->getTotalVehiculosGaraje());

						if (pos >= 0){
							v2 = contrincante->getVehiculo(pos);

							//Comprobamos que el vehículo que escogemos es válido para la categoría escogida
							condAuxiliar = false;
							if (modalidad == 1){
								if (Coche *c = dynamic_cast<Coche*>(v2)){
									condAuxiliar = true;
								}
							}
							else if (modalidad == 2){
								if (Motocicleta *m = dynamic_cast<Motocicleta*>(v2)){
									condAuxiliar = true;
								}
							}
							else if (modalidad == 3){
								if (Camion *c1 = dynamic_cast<Camion*>(v2)){
									condAuxiliar = true;
								}
							}

							if (!condAuxiliar)
								cout << "Has escogido un vehículo de otra modalidad" << endl;
						}
						else
							condAuxiliar = true;
					}while(!condAuxiliar);

					if (pos >= 0){
						//Hacemos una competición entre los dos vehículos
						this->competirBasico(this->getJugadorActivo(), v1, contrincante, v2);
					}
				}
				else
					cout << "El contrincante no dispone del carnét necesario" << endl;
			}
			else
				cout << "El contrincante no existe en el sistema" << endl;
		}
	}
	else
		cout << "No dispones del carnét necesario" << endl;
}

void VistaPrograma::competirBasico(Jugador* j1, Vehiculo* v1, Jugador* j2, Vehiculo* v2){
	//Fórmula a aplicar: 0.1*manejo + 0.2*aceleracion + 0.2*frenada + 0.5*vmax
	int dado = rand() % 100 + 1; //Generamos un dado aleatorio que nos devuelve un valor entre 1 y 100

	Vehiculo** vehiculos = new Vehiculo* [2];
	Jugador** jugadores = new Jugador* [2];

	double formula1 = (0.1*v1->getManejo()) + (0.2*v1->getAceleracion()) + (0.2*v1->getFrenada()) + (0.5*v1->getVelocidadMax());
	double formula2 = (0.1*v2->getManejo()) + (0.2*v2->getAceleracion()) + (0.2*v2->getFrenada()) + (0.5*v2->getVelocidadMax());

	if (formula1 > formula2){
		vehiculos[0] = v1;
		jugadores[0] = j1;
		vehiculos[1] = v2;
		jugadores[1] = j2;
	}
	else{
		vehiculos[0] = v2;
		jugadores[0] = j2;
		vehiculos[1] = v1;
		jugadores[1] = j1;
	}

	if (dado > 70){
		cout << "¡Ha ganado " << jugadores[0]->getLogin() << " con su flamante " << vehiculos[0]->getMarca() << " " << vehiculos[0]->getModelo() << "!" << endl;
		jugadores[0]->setNumeroVictorias(jugadores[0]->getNumeroVictorias() + 1);
		jugadores[0]->setCreditos(jugadores[0]->getCreditos() + 500);
	}
	else{
		cout << "¡Ha ganado " << jugadores[1]->getLogin() << " con su flamante " << vehiculos[1]->getMarca() << " " << vehiculos[1]->getModelo() << "!" << endl;
		jugadores[0]->setNumeroVictorias(jugadores[1]->getNumeroVictorias() + 1);
		jugadores[0]->setCreditos(jugadores[1]->getCreditos() + 500);
	}
}
