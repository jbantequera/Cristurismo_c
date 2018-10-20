/* 
 * File:   Jugador.cpp
 * Author: Javier
 *
 * Created on 14 de mayo de 2018, 20:13
 */

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "Pieza.h"
#include "Vehiculo.h"
#include "Jugador.h"

using namespace std;

/*******************
*	CONSTRUCTORES  *
*******************/
Jugador::Jugador(){
	this->setID(0);
	this->setLogin("NULL");
	this->setPasswd("NULL");
	this->setCreditos(0);
	this->setNumeroVictorias(0);
	
	for (int i=0; i<3; i++)
		this->setTipoCarnet(i, false);
	
	this->garaje = new Vehiculo* [1];
	this->setTotalVehiculosGaraje(0);
}

Jugador::Jugador(const Jugador &j){
	this->setID(j.getID());
	this->setLogin(j.getLogin());
	this->setPasswd(j.getPasswd());
	this->setCreditos(j.getCreditos());
	this->setNumeroVictorias(j.getNumeroVictorias());
	
	for (int i=0; i<3; i++)
		this->setTipoCarnet(i, j.getTipoCarnet(i));
	
	this->garaje = new Vehiculo* [j.getTotalVehiculosGaraje()];

	//Copiamos los vehículos del garaje de j al del nuevo jugador
	for (int i=0; i < j.getTotalVehiculosGaraje(); i++){
		this->garaje[i] = j.garaje[i];
	}

	this->totalVehiculosGaraje = j.getTotalVehiculosGaraje();
}

Jugador::Jugador(int id, string login, string passwd, double creditos, int numeroVictorias){
	this->setID(id);
	this->setLogin(login);
	this->setPasswd(passwd);
	this->setCreditos(creditos);
	this->setNumeroVictorias(numeroVictorias);
	
	for (int i=0; i<3; i++)
		this->setTipoCarnet(i, false);
	
	this->garaje = new Vehiculo* [1];
	this->setTotalVehiculosGaraje(0);
}

/*********************
*	  DESTRUCTOR	 *
*********************/
Jugador::~Jugador(){
	//cout << "debug: Borrando jugador (" << this->getID() << ")" << endl;
	this->setID(0);
	this->setLogin("");
	this->setPasswd("");
	this->setCreditos(0);
	this->setNumeroVictorias(0);

	for (int i=0; i<3; i++)
		this->setTipoCarnet(i, false);

	for (int i=0; i < this->getTotalVehiculosGaraje(); i++){
		delete this->garaje[i];
	}

	this->setTotalVehiculosGaraje(0);

	delete [] this->garaje;
	this->garaje = 0;
}

/**********************
*	MÉTODOS PRIVADOS  *
**********************/
void Jugador::resizeGaraje(int nuevotam){
	//cout << "debug: Entrando a resizeGaraje" << endl;
	int tope = this->getTotalVehiculosGaraje();
	Vehiculo** auxiliar = new Vehiculo* [nuevotam];

	//Comprobamos si el nuevo vector va a ser menor
	if (nuevotam < tope)
		tope = nuevotam;

	//Copiamos los vehículos al nuevo vector
	for (int i=0; i < tope; i++){
		auxiliar[i] = this->garaje[i];
	}

	//Borramos los vehículos sobrantes si reducimos el tamaño del vector
	for (int i=tope; i < this->getTotalVehiculosGaraje(); i++){
		delete garaje[i];
	}

	//Asignamos el nuevo vector de vehiculos
	this->garaje = auxiliar;

	//Actualizamos las útiles
	this->setTotalVehiculosGaraje(tope);
}

/*********************
*	MÉTODOS SET/GET  *
*********************/
void Jugador::setID(int id){
	this->id = id;
}

void Jugador::setLogin(string login){
	this->login = login;
}

void Jugador::setPasswd(string passwd){
	this->passwd = passwd;
}

void Jugador::setCreditos(double creditos){
	this->creditos = creditos;
}

void Jugador::setNumeroVictorias(int numeroVictorias){
	this->numeroVictorias = numeroVictorias;
}

void Jugador::setTipoCarnet(int posicion, bool carnet){
	this->tipoCarnet[posicion] = carnet;
}

void Jugador::setTotalVehiculosGaraje(int nuevoTotal){
	this->totalVehiculosGaraje = nuevoTotal;
}

int Jugador::getID() const{
	return (this->id);
}

string Jugador::getLogin() const{
	return (this->login);
}

string Jugador::getPasswd() const{
	return (this->passwd);
}

double Jugador::getCreditos() const{
	return (this->creditos);
}

int Jugador::getNumeroVictorias() const{
	return (this->numeroVictorias);
}

bool Jugador::getTipoCarnet(int posicion) const{
	return (this->tipoCarnet[posicion]);
}

int Jugador::getTotalVehiculosGaraje() const{
	return (this->totalVehiculosGaraje);
}

Vehiculo* Jugador::getVehiculo(int posicion) const{
	return (this->garaje[posicion]);
}

/*******************
*	SOBRECARGAS    *
*******************/
Jugador& Jugador::operator=(const Jugador &j){
	this->setID(j.getID());
	this->setLogin(j.getLogin());
	this->setPasswd(j.getPasswd());
	this->setCreditos(j.getCreditos());
	this->setNumeroVictorias(j.getNumeroVictorias());
	
	for (int i=0; i<3; i++)
		this->setTipoCarnet(i, j.getTipoCarnet(i));
	
	//Antes de asignar un garaje a this, necesitamos borrar de memoria el actual 
	//(Se llama a los destructores de los vehículos automáticamente)
	delete [] this->garaje;

	//Creamos el nuevo garaje
	this->garaje = new Vehiculo* [j.getTotalVehiculosGaraje()];

	//Copiamos los vehículos del garaje de j al del nuevo jugador
	for (int i=0; i < j.getTotalVehiculosGaraje(); i++){
		this->garaje[i] = j.garaje[i];
	}

	this->setTotalVehiculosGaraje(j.getTotalVehiculosGaraje());
}

/*********************
*	 OTROS MÉTODOS	 *
*********************/
void Jugador::agregarVehiculo(Vehiculo* v){
	//cout << "debug: Agregando vehiculo a jugador" << endl;
	//Llamamos a resize de garaje si es necesario
	if (this->getTotalVehiculosGaraje() != 0){
		this->resizeGaraje(this->getTotalVehiculosGaraje() + 1);
		//cout << "debug: Resize realizado" << endl;
	}

	this->garaje[this->getTotalVehiculosGaraje()] = v;

	this->setTotalVehiculosGaraje(this->getTotalVehiculosGaraje() + 1);
}

void Jugador::asignarPiezaVehiculo(Vehiculo* v, Pieza* p){
	v->setPieza(v->getTotalPiezas(), p);
	//cout << "debug: Pieza asignada (" << p->getID() << ")" << endl;
}

void Jugador::print() const{
	cout << "*******" << this->getLogin() << "*******" << endl;
	cout << "Contraseña: " << this->getPasswd() << endl;
	cout << "Créditos: " << this->getCreditos() << endl;
	cout << "Victorias: " << this->getNumeroVictorias() << endl;
	cout << "Carnéts: " << endl;
		cout << "\tCoche: " << this->getTipoCarnet(0) << endl;
		cout << "\tMoto: " << this->getTipoCarnet(1) << endl;
		cout << "\tCamión: " << this->getTipoCarnet(2) << endl;
	this->verGaraje();
}

void Jugador::verGaraje() const{
	cout << "Garaje: " << endl;
	
	for(int i=0; i < this->getTotalVehiculosGaraje(); i++){
		cout << "[" << i << "] - "; (this->garaje[i])->printMinimo();
	}
}

void Jugador::consultarGaraje() const{
	int pos = 0;

	this->verGaraje();

	do{
		cout << endl << "¿Qué coche desea consultar? (Negativo para salir): ";
		cin >> pos;

		if ((pos >= 0) && (pos < this->getTotalVehiculosGaraje()))
			(this->garaje[pos])->print();
	}while (pos >= 0);
}

void Jugador::comprarVehiculo(Vehiculo *v){
	this->setCreditos(this->getCreditos() - v->getPrecioActual());

	if (Coche* c = dynamic_cast<Coche*>(v))
		this->agregarVehiculo(new Coche(*(dynamic_cast<Coche*>(v))));
	else if (Motocicleta* m = dynamic_cast<Motocicleta*>(v))
		this->agregarVehiculo(new Motocicleta(*(dynamic_cast<Motocicleta*>(v))));
	else if (Camion *c = dynamic_cast<Camion*>(v))
		this->agregarVehiculo(new Camion(*(dynamic_cast<Camion*>(v))));
}

void Jugador::venderVehiculo(int pos, Jugador* cliente){
	cliente->comprarVehiculo(this->getVehiculo(pos));
	
	//Añadimos el dinero al jugador
	this->setCreditos(this->getCreditos() + (this->getVehiculo(pos))->getPrecioActual());

	//Borramos el vehículo del jugador
	delete this->garaje[pos];

	//Movemos el vector hacia la izquierda desde pos
	for (int i = pos; i < this->getTotalVehiculosGaraje() - 1; i++)
		this->garaje[i] = this->garaje[i + 1];
	
	//Ponemos el último puntero a 0
	this->garaje[this->getTotalVehiculosGaraje() - 1] = 0;

	//Llamamos a resize
	this->resizeGaraje(this->getTotalVehiculosGaraje() - 1);
}
