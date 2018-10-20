/* 
 * File:   Jugador.h
 * Author: Javier
 *
 * Created on 14 de mayo de 2018, 20:13
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include "Pieza.h"
#include "Vehiculo.h"

using namespace std;

class Jugador{
	private: 
		int id;
		string login;
		string passwd;
		double creditos;
		int numeroVictorias;
		bool tipoCarnet [3];
		Vehiculo** garaje;
		int totalVehiculosGaraje;
		
		void resizeGaraje(int nuevotam);
		
	public:
		//Constructor base
		Jugador();
		//Constructor por copia
		Jugador(const Jugador &j);
		//Constructor por parámetros
		Jugador(int id, string login, string passwd, double creditos, int numeroVictorias);
		//Destructor
		~Jugador();
		
		//Métodos Básicos
		void setID(int id);
		void setLogin(string login);
		void setPasswd(string passwd);
		void setCreditos(double creditos);
		void setNumeroVictorias(int numeroVictorias);
		void setTipoCarnet(int posicion, bool carnet);
		void setTotalVehiculosGaraje(int nuevoTotal);

		int getID() const;
		string getLogin() const;
		string getPasswd() const;
		double getCreditos() const;
		int getNumeroVictorias() const;
		bool getTipoCarnet(int posicion) const;
		int getTotalVehiculosGaraje() const;
		Vehiculo* getVehiculo(int posicion) const;		

		//Sobrecarga del operador =
		Jugador& operator=(const Jugador &j);

		
		//Otras funciones
		/**
		@brief Agrega al vehículo al que apunta v (Llamando al constructor por copia) al vector garaje
		@param Vehiculo* v, que apunta al vehículo que queremos añadir (copiar) al vector garaje
		@post Una copia del vehículo al que apunta *v se encuentra en garaje
		@post totalVehiculosGaraje incrementado en 1
		*/
		void agregarVehiculo(Vehiculo* v);
		/**
		@brief Asigna al vector de tunning del vehiculo v la pieza a la que apunta p
		@param Vehiculo *v, que apunta al vehículo al que queremos añadir la pieza
		@param Pieza *p, que apunta a la pieza que queremos asignar al vehículo
		@post Una componente del vector tunning del vehículo al que apunta v contiene p
		*/
		void asignarPiezaVehiculo(Vehiculo* v, Pieza* p);
		/**
		@brief Imprime los datos del jugador
		*/
		void print() const;
		/**
		@brief Muestra los datos de forma mínima de los vehículos almacenados en el vector garaje
		*/
		void verGaraje() const;
		/**
		@brief Muestra los datos de forma mínima de los vehículos almacenados en el vector garaje y permite mostrar los datos detallados del vehículo que desee el usuario
		*/
		void consultarGaraje() const;
		/**
		@brief Asigna al vector garaje del jugador una copia del vehículo al que apunta v y le resta el precio actual del vehículo a los créditos
		@param Vehiculo* v, puntero que apunta al vehículo que deseamos comprar
		@pre creditos >= precioActual de *v
		@post totalVehículosGaraje incrementado en 1 y creditos = creditos - precioActual de *v
		*/
		void comprarVehiculo(Vehiculo* v);
		/**
		@brief Vende el vehículo garaje[pos] al jugador al que apunta cliente
		@pre cliente->getCreditos() >= garaje[pos]->getPrecioActual()
		@post El vehículo que vendemos ya no se encuentra en el garaje del jugador this, sino que se encuentra en el garaje de *cliente
		@post this->creditos aumenta en el precioActual del vehiculo que vendemos
		@post cliente->creditos disminuye en el precioActual del vehiculo que vendemos
		*/
		void venderVehiculo(int pos, Jugador* cliente);
};

#endif /* JUGADOR_H */
