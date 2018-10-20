/* 
 * File:   Vehiculo.cpp
 * Author: Javier
 *
 * Created on 21 de mayo de 2018, 20:05
 */

#include <iostream>
#include <string>

#include "Pieza.h"
#include "Vehiculo.h"

using namespace std;

/*********************
*	CONSTRUCTORES	 *
*********************/
Vehiculo::Vehiculo(){
	this->setID(0);
	this->setMarca("");
	this->setModelo("");

	this->setTipoCombustible("");
	this->setCilindrada(0);

	this->setCombustibleActual(0);
	this->setCapacidadDepositoMax(0);

	this->setCaballos(0);
	this->setAerodinamica(0);
	this->setAceleracion(0);
	this->setManejo(0);
	this->setVelocidadMax(0);
	this->setFrenada(0);

	this->tunning = new Pieza* [1];
	this->setTotalPiezas(0);

	this->setPrecioBase(0);
	this->calcularPrecioActual();
	this->setDisponible(false);
}

Vehiculo::Vehiculo(const Vehiculo &v){
	this->setID(v.getID());
	this->setMarca(v.getMarca());
	this->setModelo(v.getModelo());

	this->setTipoCombustible(v.getTipoCombustible());
	this->setCilindrada(v.getCilindrada());

	this->setCombustibleActual(v.getCombustibleActual());
	this->setCapacidadDepositoMax(v.getCapacidadDepositoMax());

	this->setCaballos(v.getCaballos());
	this->setAerodinamica(v.getAerodinamica());
	this->setAceleracion(v.getAceleracion());
	this->setManejo(v.getManejo());
	this->setVelocidadMax(v.getVelocidadMax());
	this->setFrenada(v.getFrenada());

	this->tunning = new Pieza* [v.getTotalPiezas()];
	
	for (int i=0; i < v.getTotalPiezas(); i++){
		this->tunning[i] = v.getPieza(i);
	}

	this->setTotalPiezas(v.getTotalPiezas());

	this->setPrecioBase(v.getPrecioBase());
	this->calcularPrecioActual();
	this->setDisponible(v.getDisponible());
}

Vehiculo::Vehiculo(int id, string marca, string modelo, string tipoComb, int cil, int combActual, int capDepMax, int cab, int aer, int acel, int man, int vmax, int fren, int precioBase, bool disponible){
	this->setID(id);
	this->setMarca(marca);
	this->setModelo(modelo);

	this->setTipoCombustible(tipoComb);
	this->setCilindrada(cil);

	this->setCombustibleActual(combActual);
	this->setCapacidadDepositoMax(capDepMax);

	this->setCaballos(cab);
	this->setAerodinamica(aer);
	this->setAceleracion(acel);
	this->setManejo(man);
	this->setVelocidadMax(vmax);
	this->setFrenada(fren);

	this->tunning = new Pieza* [1];
	this->setTotalPiezas(0);

	this->setPrecioBase(precioBase);
	this->calcularPrecioActual();
	this->setDisponible(disponible);
}

/*********************
*	  DESTRUCTOR	 *
*********************/
Vehiculo::~Vehiculo(){
	//cout << "debug: Borrando vehiculo (" << this->getID() << ")" << endl;
	this->setID(0);
	this->setMarca("");
	this->setModelo("");

	this->setTipoCombustible("");
	this->setCilindrada(0);

	this->setCombustibleActual(0);
	this->setCapacidadDepositoMax(0);

	this->setCaballos(0);
	this->setAerodinamica(0);
	this->setAceleracion(0);
	this->setManejo(0);
	this->setVelocidadMax(0);
	this->setFrenada(0);

	this->tunning = 0;
	this->setTotalPiezas(0);

	this->setPrecioBase(0);
	this->calcularPrecioActual();
	this->setDisponible(false);
}

/*********************
*		RESIZES		 *
*********************/
void Vehiculo::resizeTunning(int nuevotam){
	int tope = this->getTotalPiezas();
	Pieza** auxiliar = new Pieza*[nuevotam];

	//Comprobamos si el nuevo vector va a ser menor
	if (nuevotam < tope)
		tope = nuevotam;

	//Copiamos los vehículos al nuevo vector
	for (int i=0; i < tope; i++){
		auxiliar[i] = this->tunning[i];
	}

	//Actualizamos el puntero al vector, sin borrar el anterior porque llamaríamos al destructor de Piezas y queremos mantenerlas en el sistema
	this->tunning = auxiliar;

	//Actualizamos las útiles
	this->setTotalPiezas(tope);
}

/*********************
*	MÉTODOS SET 	 *
*********************/
void Vehiculo::setID(int id){
	this->id = id;
}

void Vehiculo::setMarca(string marca){
	this->marca = marca;
}

void Vehiculo::setModelo(string modelo){
	this->modelo = modelo;
}

void Vehiculo::setTipoCombustible(string tipo){
	this->tipoCombustible = tipo;
}

void Vehiculo::setCilindrada(int cilindrada){
	this->cilindrada = cilindrada;
}

void Vehiculo::setCombustibleActual(double combustibleActual){
	this->combustibleActual = combustibleActual;
}

void Vehiculo::setCapacidadDepositoMax(double capacidadDepositoMax){
	this->capacidadDepositoMax = capacidadDepositoMax;
}

void Vehiculo::setCaballos(int caballos){
	this->caballos = caballos;
}

void Vehiculo::setAerodinamica(int aerodinamica){
	this->aerodinamica = aerodinamica;
}

void Vehiculo::setAceleracion(int aceleracion){
	this->aceleracion = aceleracion;
}

void Vehiculo::setManejo(int manejo){
	this->manejo = manejo;
}

void Vehiculo::setVelocidadMax(int velocidadMax){
	this->velocidadMax = velocidadMax;
}

void Vehiculo::setFrenada(int frenada){
	this->frenada = frenada;
}

void Vehiculo::setPieza(int pos, Pieza* p){
	//Llamamos a resize si es necesario
	if (this->getTotalPiezas() <= pos)
		this->resizeTunning(pos);

	this->tunning[pos] = p;

	this->setTotalPiezas(this->getTotalPiezas() + 1);

	//Actualizamos el precio
	this->calcularPrecioActual();

	//Actualizamos los stats
	this->setAerodinamica(this->getAerodinamica() + p->getAerodinamica());
	this->setFrenada(this->getFrenada() + p->getFrenada());
	this->setVelocidadMax(this->getVelocidadMax() + p->getVelocidadMax());
	this->setManejo(this->getManejo() + p->getManejo());
	this->setAceleracion(this->getAceleracion() + p->getAceleracion());
}

void Vehiculo::setTotalPiezas(int totalPiezas){
	this->totalPiezas = totalPiezas;
}

void Vehiculo::setPrecioBase(int precioBase){
	this->precioBase = precioBase;
}

void Vehiculo::calcularPrecioActual(){
	int resultado = 0;

	//Añadimos el precio base del vehiculo
	resultado = this->getPrecioBase();

	//Y le sumamos el precio de las piezas equipadas
	for (int i=0; i<this->getTotalPiezas(); i++)
		resultado += (this->getPieza(i))->getPrecio();

	//Asignamos el resultado de la suma
	this->precioActual = resultado;
}

void Vehiculo::setDisponible(bool disponible){
	this->disponible = disponible;
}

/*********************
*	MÉTODOS GET 	 *
*********************/
int Vehiculo::getID() const{
	return (this->id);
}

string Vehiculo::getMarca() const{
	return (this->marca);
}

string Vehiculo::getModelo() const{
	return (this->modelo);
}

string Vehiculo::getTipoCombustible() const{
	return (this->tipoCombustible);
}

int Vehiculo::getCilindrada() const{
	return (this->cilindrada);
}

double Vehiculo::getCombustibleActual() const{
	return (this->combustibleActual);
}

double Vehiculo::getCapacidadDepositoMax() const{
	return (this->capacidadDepositoMax);
}

int Vehiculo::getCaballos() const{
	return (this->caballos);
}

int Vehiculo::getAerodinamica() const{
	return (this->aerodinamica);
}

int Vehiculo::getAceleracion() const{
	return (this->aceleracion);
}

int Vehiculo::getManejo() const{
	return (this->manejo);
}

int Vehiculo::getVelocidadMax() const{
	return (this->velocidadMax);
}

int Vehiculo::getFrenada() const{
	return (this->frenada);
}

Pieza* Vehiculo::getPieza(int pos) const{
	return (this->tunning[pos]);
}

int Vehiculo::getTotalPiezas() const{
	return (this->totalPiezas);
}

int Vehiculo::getPrecioBase() const{
	return (this->precioBase);
}

int Vehiculo::getPrecioActual() const{
	return (this->precioActual);
}

bool Vehiculo::getDisponible() const{
	return (this->disponible);
}

/*********************
*	SOBRECARGA OP.	 *
*********************/
Vehiculo& Vehiculo::operator=(const Vehiculo &v){
	this->setID(v.getID());
	this->setMarca(v.getMarca());
	this->setModelo(v.getModelo());

	this->setTipoCombustible(v.getTipoCombustible());
	this->setCilindrada(v.getCilindrada());

	this->setCombustibleActual(v.getCombustibleActual());
	this->setCapacidadDepositoMax(v.getCapacidadDepositoMax());

	this->setCaballos(v.getCaballos());
	this->setAerodinamica(v.getAerodinamica());
	this->setAceleracion(v.getAceleracion());
	this->setManejo(v.getManejo());
	this->setVelocidadMax(v.getVelocidadMax());
	this->setFrenada(v.getFrenada());

	//Si existía un vector de tunning lo borramos
	if (tunning != 0){
		for (int i=0; i < this->getTotalPiezas(); i++)
			delete this->tunning[i];

		delete [] this->tunning;
	}

	//Creamos uno nuevo para copiar las piezas de p
	this->tunning = new Pieza* [v.getTotalPiezas()];
	
	for (int i=0; i < v.getTotalPiezas(); i++){
		this->setPieza(i, v.getPieza(i));
	}

	this->setTotalPiezas(v.getTotalPiezas());

	this->setPrecioBase(v.getPrecioBase());
	this->calcularPrecioActual();	
	this->setDisponible(v.getDisponible());
}

/*********************
*	 OTROS MÉTODOS	 *
*********************/
double Vehiculo::calcularMediaVehiculo() const{
	double media = (this->getCaballos() + this->getAerodinamica() + this->getAceleracion() + this->getManejo() + this->getVelocidadMax() + this->getFrenada()) * 1.0 / 6;

	return (media);
}

void Vehiculo::quitarPieza(int pos){
	cout << "debug: Entrando a quitarPieza" << endl;

	//Actualizamos los stats
	this->setAerodinamica(this->getAerodinamica() - (this->tunning[pos])->getAerodinamica());
	this->setFrenada(this->getFrenada() - (this->tunning[pos])->getFrenada());
	this->setVelocidadMax(this->getVelocidadMax() - (this->tunning[pos])->getVelocidadMax());
	this->setManejo(this->getManejo() - (this->tunning[pos])->getManejo());
	this->setAceleracion(this->getAceleracion() - (this->tunning[pos])->getAceleracion());

	//Desplazamos los punteros
	for (int i = pos; i < (this->getTotalPiezas() - 1); i++)
		this->tunning[i] = this->tunning[i+1];
	cout << "debug: Punteros desplazados" << endl;

	//Ponemos el último puntero del vector a 0
	this->tunning[this->getTotalPiezas() - 1] = 0;

	//Llamamos a resize
	cout << "debug: Llamamos a resize dentro de quitarPieza" << endl;
	this->resizeTunning(this->getTotalPiezas() - 1);

	//Actualizamos el precio del vehículo
	this->calcularPrecioActual();
}

void Vehiculo::print() const{
	cout << "*****" << this->getMarca() << " - " << this->getModelo() << "*****" << endl;
	cout << "Combustible: " << this->getTipoCombustible() << endl;
	//cout << "debug: Total piezas: " << this->getTotalPiezas() << endl;
	this->printTunning();
	cout << "Valoracion: " << this->calcularMediaVehiculo() << endl;
	cout << "Precio actual: " << this->getPrecioActual() << endl;
	cout << "*************************" << endl;
}

void Vehiculo::printMinimo() const{
	cout << this->getMarca() << " " << this->getModelo() << " (Valoración: " << this->calcularMediaVehiculo() << " || Precio: " << this->getPrecioActual() << ")" << endl;
}

void Vehiculo::printTunning() const{
	if (this->getTotalPiezas() > 0){
		cout << "-- Tunning --" << endl;
		for (int i=0; i < this->getTotalPiezas(); i++){
			cout << "[" << i << "] - "; (this->tunning[i])->printMinimo();		
		}
	}
}
/********************************************************************************************************************************************************************************************************
*	 																						MOTOCICLETA																									*
********************************************************************************************************************************************************************************************************/

/*********************
*	CONSTRUCTORES	 *
*********************/
Motocicleta::Motocicleta() : Vehiculo() {}

Motocicleta::Motocicleta(const Motocicleta &m) : Vehiculo(m.getID(), m.getMarca(), m.getModelo(), m.getTipoCombustible(), m.getCilindrada(), m.getCombustibleActual(), m.getCapacidadDepositoMax(), m.getCaballos(), m.getAerodinamica(), m.getAceleracion(), m.getManejo(), m.getVelocidadMax(), m.getFrenada(), m.getPrecioBase(), m.getDisponible()){
	this->tunning = new Pieza* [m.getTotalPiezas()];
	
	for (int i=0; i < m.getTotalPiezas(); i++){
		this->tunning[i] = m.getPieza(i);
	}

	this->setTotalPiezas(m.getTotalPiezas());

	this->setPrecioBase(m.getPrecioBase());
	this->calcularPrecioActual();
	this->setDisponible(m.getDisponible());
}

Motocicleta::Motocicleta(int id, string marca, string modelo, string tipoComb, int cil, int combActual, int capDepMax, int cab, int aer, int acel, int man, int vmax, int fren, int precioBase, bool disponible) : Vehiculo(id, marca, modelo, tipoComb, cil, combActual, capDepMax, cab, aer, acel, man, vmax, fren, precioBase, disponible){}

/*********************
*	  DESTRUCTOR	 *
*********************/
Motocicleta::~Motocicleta(){} //No hace nada porque la clase Motocicleta no tiene atributos no heredados

/*********************
*	 OTROS MÉTODOS	 *
*********************/
void Motocicleta::correr(){
	cout << "Mira como derrapa la moto neño" << endl;
}

void Motocicleta::hacerCaballito(){
	cout << "Arre moto, arre!" << endl;
}

/********************************************************************************************************************************************************************************************************
*	 																						CAMION																										*
********************************************************************************************************************************************************************************************************/

/*********************
*	CONSTRUCTORES	 *
*********************/
Camion::Camion() : Vehiculo(){
	this->setCapacidadCarga(0);
}

Camion::Camion(const Camion &c) : Vehiculo(c.getID(), c.getMarca(), c.getModelo(), c.getTipoCombustible(), c.getCilindrada(), c.getCombustibleActual(), c.getCapacidadDepositoMax(), c.getCaballos(), c.getAerodinamica(), c.getAceleracion(), c.getManejo(), c.getVelocidadMax(), c.getFrenada(), c.getPrecioBase(), c.getDisponible()){
	this->setCapacidadCarga(c.getCapacidadCarga());

	this->tunning = new Pieza* [c.getTotalPiezas()];
	
	for (int i=0; i < c.getTotalPiezas(); i++){
		this->tunning[i] = c.getPieza(i);
	}

	this->setTotalPiezas(c.getTotalPiezas());

	this->setPrecioBase(c.getPrecioBase());
	this->calcularPrecioActual();
	this->setDisponible(c.getDisponible());
}

Camion::Camion(int id, string marca, string modelo, string tipoComb, int cil, int combActual, int capDepMax, int cab, int aer, int acel, int man, int vmax, int fren, int precioBase, int capacidadCarga, bool disponible) : Vehiculo(id, marca, modelo, tipoComb, cil, combActual, capDepMax, cab, aer, acel, man, vmax, fren, precioBase, disponible){
	this->setCapacidadCarga(capacidadCarga);
}

/*********************
*	  DESTRUCTOR	 *
*********************/
Camion::~Camion(){
	this->setCapacidadCarga(0);
}

/*********************
*	MÉTODOS SET 	 *
*********************/
void Camion::setCapacidadCarga(int capacidadCarga){
	this->capacidadCarga = capacidadCarga;
}

/*********************
*	MÉTODOS GET 	 *
*********************/
int Camion::getCapacidadCarga() const{
	return (this->capacidadCarga);
}

/*********************
*	 OTROS MÉTODOS	 *
*********************/
void Camion::correr(){
	cout << "Corre a la velocidad de una tortuga" << endl;
}

void Camion::tocarBocina(){
	cout << "¡MEEEEEEEEEEEEEEEEEEEEEEEEEEC!" << endl;
}

/********************************************************************************************************************************************************************************************************
*	 																						COCHE																										*
********************************************************************************************************************************************************************************************************/

/*********************
*	CONSTRUCTORES	 *
*********************/
Coche::Coche() : Vehiculo() {}

Coche::Coche(const Coche &c) : Vehiculo(c.getID(), c.getMarca(), c.getModelo(), c.getTipoCombustible(), c.getCilindrada(), c.getCombustibleActual(), c.getCapacidadDepositoMax(), c.getCaballos(), c.getAerodinamica(), c.getAceleracion(), c.getManejo(), c.getVelocidadMax(), c.getFrenada(), c.getPrecioBase(), c.getDisponible()){
	this->tunning = new Pieza* [c.getTotalPiezas()];
	
	for (int i=0; i < c.getTotalPiezas(); i++){
		this->tunning[i] = c.getPieza(i);
	}

	this->setTotalPiezas(c.getTotalPiezas());

	this->setPrecioBase(c.getPrecioBase());
	this->calcularPrecioActual();
	this->setDisponible(c.getDisponible());
}

Coche::Coche(int id, string marca, string modelo, string tipoComb, int cil, int combActual, int capDepMax, int cab, int aer, int acel, int man, int vmax, int fren, int precioBase, bool disponible) : Vehiculo(id, marca, modelo, tipoComb, cil, combActual, capDepMax, cab, aer, acel, man, vmax, fren, precioBase, disponible){}

/*********************
*	  DESTRUCTOR	 *
*********************/
Coche::~Coche(){}

/*********************
*	 OTROS MÉTODOS	 *
*********************/
void Coche::correr(){
	cout << "Corre sobre 4 ruedas" << endl;
}

void Coche::hacerTrompo(){
	cout << "Mira que trompo más guapo vieo" << endl;
}
