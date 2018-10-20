/* 
 * File:   Vehiculo.h
 * Author: Javier
 *
 * Created on 14 de mayo de 2018, 20:13
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
#include "Pieza.h"

class Vehiculo{
	protected:
		int id;
		string marca;
		string modelo;

		//Depósito
		string tipoCombustible;
		int cilindrada;
		double combustibleActual;
		double capacidadDepositoMax;

		//Estadísticas
		int caballos;
		int aerodinamica;
		int aceleracion;
		int manejo;
		int velocidadMax;
		int frenada;

		//Personalización
		Pieza** tunning;
		int totalPiezas;

		//Precios
		int precioBase;
		int precioActual;
		bool disponible;

		//Resize
		void resizeTunning(int nuevotam);
		
	public:
		//Constructores y Destructores
		Vehiculo();
		Vehiculo(const Vehiculo &v);
		Vehiculo(int id, string marca, string modelo, string tipoComb, int cil, int combActual, int capDepMax, int cab, int aer, int acel, int man, int vmax, int fren, int precioBase, bool disponible);
		virtual ~Vehiculo();
		
		//Métodos Básicos
		//Sets
		void setID(int id);
		void setMarca(string marca);
		void setModelo(string modelo);

		void setTipoCombustible(string tipo);
		void setCilindrada(int cilindrada);
		void setCombustibleActual(double combustibleActual);
		void setCapacidadDepositoMax(double capacidadDepositoMax);

		void setCaballos(int caballos);
		void setAerodinamica(int aerodinamica);
		void setAceleracion(int aceleracion);
		void setManejo(int manejo);
		void setVelocidadMax(int velocidadMax);
		void setFrenada(int frenada);

		/**
		@brief Asigna la pieza p al vector de tunning, aumentando el precio actual del vehículo y sus estadísticas
		*/
		void setPieza(int pos, Pieza* p);
		void setTotalPiezas(int totalPiezas);

		void setPrecioBase(int precioBase);
		void setDisponible(bool disponible);
		
		/**
		@brief Suma el precio base del vehículo + El precio de las piezas equipadas (Las que existen dentro del vector tunning), y lo asigna al atributo precioActual
		*/
		void calcularPrecioActual();

		//Gets
		int getID() const;
		string getMarca() const;
		string getModelo() const;

		string getTipoCombustible() const;
		int getCilindrada() const;
		double getCombustibleActual() const;
		double getCapacidadDepositoMax() const;

		int getCaballos() const;
		int getAerodinamica() const;
		int getAceleracion() const;
		int getManejo() const;
		int getVelocidadMax() const;
		int getFrenada() const;

		Pieza* getPieza(int pos) const;
		int getTotalPiezas() const;
		int getPrecioBase() const;
		int getPrecioActual() const;
		bool getDisponible() const;

		//Sobrecarga Operador
		Vehiculo& operator=(const Vehiculo &p);

		//Otros Métodos
		virtual void correr() = 0;
		/**
		@brief Calcula la media del vehículo, es decir, la suma de todos sus stats dividida entre 6
		@return La media de las estadísticas del vehículo
		*/
		double calcularMediaVehiculo() const;
		/**
		@brief Desasigna una pieza al vector de tunning del vehículo, reduciendo su precio y alterando sus estadísticas
		*/
		void quitarPieza(int pos);
		/**
		@brief Imprime los datos completos del vehículo (Modelo, marca, tipo combustible, tunning, valoracion y precio actual)
		*/
		void print() const;
		/**
		@brief Imprime de forma minimalista la info de un vehículo (Modelo, marca, valoración y precio)
		*/
		void printMinimo() const;
		/**
		@brief Imprime el vector de tunning del vehículo
		*/
		void printTunning() const;
};

class Motocicleta : public Vehiculo{
	public:
		//Constructores
		Motocicleta();
		Motocicleta(const Motocicleta &m);
		Motocicleta(int id, string marca, string modelo, string tipoComb, int cil, int combActual, int capDepMax, int cab, int aer, int acel, int man, int vmax, int fren, int precioBase, bool disponible);
		//Destructores
		~Motocicleta();

		//Otros métodos
		/**
		@brief Imprime cómo correría una moto
		*/
		void correr();
		/**
		@brief Imprime por pantalla cómo haría un caballito una moto
		*/
		void hacerCaballito();
};

class Camion : public Vehiculo{
	private:
		int capacidadCarga;

	public:
		//Constructores
		Camion();
		Camion(const Camion &c);
		Camion(int id, string marca, string modelo, string tipoComb, int cil, int combActual, int capDepMax, int cab, int aer, int acel, int man, int vmax, int fren, int precioBase, int capacidadCarga, bool disponible);
		//Destructores
		~Camion();

		//Sets
		void setCapacidadCarga(int capacidadCarga);
		//Gets
		int getCapacidadCarga() const;

		//Otros métodos
		/**
		@brief Imprime cómo correría un camión
		*/
		void correr();
		/**
		@brief Imprime el sonido de una bocina (¡MEEEEC!)
		*/
		void tocarBocina();
};

class Coche : public Vehiculo{
	public:
		//Constructores
		Coche();
		Coche(const Coche &c);
		Coche(int id, string marca, string modelo, string tipoComb, int cil, int combActual, int capDepMax, int cab, int aer, int acel, int man, int vmax, int fren, int precioBase, bool disponible);
		//Destructor
		~Coche();

		//Otros métodos
		/**
		@brief Imprime cómo correría un coche
		*/
		void correr();
		/**
		@brief Imprime por pantalla que el vehículo da un trompo
		*/
		void hacerTrompo();
};

#endif /*VEHICULO_H*/
