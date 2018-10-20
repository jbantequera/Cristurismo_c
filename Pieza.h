/* 
 * File:   Pieza.h
 * Author: Javier
 *
 * Created on 21 de mayo de 2018, 18:32
 */

#ifndef PIEZA_H
#define PIEZA_H

#include <iostream>
#include <string>

using namespace std;

class Pieza{
	private:
		int id;
		string nombre;

		//Stats (Stat Resultante en Vehículo = Stat base + Stat pieza)
		int aerodinamica;
		int frenada;
		int velocidadMax;
		int manejo;
		int aceleracion;

		int precio;

	public:
		//Constructores
		Pieza();
		Pieza(int id, string nombre, int aer, int fren, int vmax, int man, int acel, int precio);
		//Destructor
		~Pieza();

		//Métodos Básicos
		//Sets
		void setID(int id);
		void setNombre(string nombre);

		void setAerodinamica(int aerodinamica);
		void setFrenada(int frenada);
		void setVelocidadMax(int velocidadMax);
		void setManejo(int manejo);
		void setAceleracion(int aceleracion);

		void setPrecio(int precio);

		//Gets
		int getID() const;
		string getNombre() const;

		int getAerodinamica() const;
		int getFrenada() const;
		int getVelocidadMax() const;
		int getManejo() const;
		int getAceleracion() const;

		int getPrecio() const;

		//Sobrecarga de operadores
		Pieza& operator=(const Pieza &p);

		//Otros métodos
		/**
		@brief Imprime una pieza con todos sus stats
		*/
		void print() const;
		/**
		@brief Imprime una pieza (sólo su nombre y precio)
		*/
		void printMinimo() const;
};

#endif /*PIEZA_H*/
