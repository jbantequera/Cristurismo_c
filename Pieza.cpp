/* 
 * File:   Pieza.cpp
 * Author: Javier
 *
 * Created on 21 de mayo de 2018, 19:41
 */

#include <iostream>
#include <string>
#include "Pieza.h"

using namespace std;

/*********************
*	CONSTRUCTORES	 *
*********************/
Pieza::Pieza(){
	this->setID(0);
	this->setNombre("");

	this->setAerodinamica(0);
	this->setFrenada(0);
	this->setVelocidadMax(0);
	this->setManejo(0);
	this->setAceleracion(0);

	this->setPrecio(0);
}

Pieza::Pieza(int id, string nombre, int aer, int fren, int vmax, int man, int acel, int precio){
	this->setID(id);
	this->setNombre(nombre);

	this->setAerodinamica(aer);
	this->setFrenada(fren);
	this->setVelocidadMax(vmax);
	this->setManejo(man);
	this->setAceleracion(acel);

	this->setPrecio(precio);
}


/*********************
*	  DESTRUCTOR	 *
*********************/
Pieza::~Pieza(){
	//cout << "debug: Borrando pieza (" << this->getID() << ")" << endl;
	//Reiniciamos los valores por metodología, como no hay memoria dinámica podríamos dejar actuar al destructor por defecto de C++
	this->setID(0);
	this->setNombre("");

	this->setAerodinamica(0);
	this->setFrenada(0);
	this->setVelocidadMax(0);
	this->setManejo(0);
	this->setAceleracion(0);

	this->setPrecio(0);
}

/*********************
*	MÉTODOS SET 	 *
*********************/
void Pieza::setID(int id){
	this->id = id;
}

void Pieza::setNombre(string nombre){
	this->nombre = nombre;
}

void Pieza::setAerodinamica(int aerodinamica){
	this->aerodinamica = aerodinamica;
}

void Pieza::setFrenada(int frenada){
	this->frenada = frenada;
}

void Pieza::setVelocidadMax(int velocidadMax){
	this->velocidadMax = velocidadMax;
}

void Pieza::setManejo(int manejo){
	this->manejo = manejo;
}

void Pieza::setAceleracion(int aceleracion){
	this->aceleracion = aceleracion;
}

void Pieza::setPrecio(int precio){
	this->precio = precio;
}

/*********************
*	MÉTODOS GET 	 *
*********************/
int Pieza::getID() const{
	return (this->id);
}

string Pieza::getNombre() const{
	return (this->nombre);
}

int Pieza::getAerodinamica() const{
	return (this->aerodinamica);
}

int Pieza::getFrenada() const{
	return (this->frenada);
}

int Pieza::getVelocidadMax() const{
	return (this->velocidadMax);
}

int Pieza::getManejo() const{
	return (this->manejo);
}

int Pieza::getAceleracion() const{
	return (this->aceleracion);
}

int Pieza::getPrecio() const{
	return (this->precio);
}

/*********************
*	SOBRECARGA OP. 	 *
*********************/
Pieza& Pieza::operator=(const Pieza &p){
	this->setID(p.getID());
	this->setNombre(p.getNombre());

	this->setAerodinamica(p.getAerodinamica());
	this->setFrenada(p.getFrenada());
	this->setVelocidadMax(p.getVelocidadMax());
	this->setManejo(p.getManejo());
	this->setAceleracion(p.getAceleracion());

	this->setPrecio(p.getPrecio());
}

/*********************
*	 OTROS MÉTODOS	 *
*********************/
void Pieza::print() const{
	cout << "*****" << this->getNombre() << "*****" << endl;
	//cout << "ID: " << this->getID() << endl;
	cout << "Aerodinámica: " this->getAerodinamica() << endl;
	cout << "Frenada: " << this->getFrenada() << endl;
	cout << "VelocidadMax: " << this->getVelocidadMax() << endl;
	cout << "Manejo: " << this->getManejo() << endl;
	cout << "Aceleración: " << this->getAceleracion() << endl;
	cout << "Precio: " << this->getPrecio() << endl;
	cout << "*************************" << endl;
}

void Pieza::printMinimo() const{
	cout << "Pieza: " << this->getNombre() << " (" << this->getPrecio() << "€)" << endl;
}
