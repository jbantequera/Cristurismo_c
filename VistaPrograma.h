/* 
 * File:   VistaPrograma.h
 * Author: Javier
 *
 * Created on 19 de mayo de 2018, 23:51
 */

#ifndef VISTAPROGRAMA_H
#define VISTAPROGRAMA_H

#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>

#include "Pieza.h"
#include "Vehiculo.h"
#include "Jugador.h"

using namespace std;

class VistaPrograma{
	private:
		Jugador** listaPlayers;
		int totalPlayers;
		Jugador* jugadorActivo;

		Vehiculo** catalogoVehiculos;
		int totalModelos;

		Pieza** catalogoPiezas;
		int totalPiezas;

		double precioGasolina;
		double precioDiesel;

		string login;
		string passwd;

		bool partidaCargada;
		Vehiculo** resultadoBusqueda;
		Jugador** resultadoBusquedaJ;

		//Resizes
		void resizeListaPlayers(int nuevotam);
		void resizeCatalogoVehiculos(int nuevotam);
		void resizeCatalogoPiezas(int nuevotam);
		void resizeResultadoBusqueda(int nuevotam);

	public: 
		//Constructores y Destructores
		VistaPrograma(); //Constructor Base
		~VistaPrograma(); //Destructor

		//Métodos Básicos
		//Sets
		/**
		/@brief Almacena en el puntero la dirección del jugador que está activo en el sistema (El que está loggeado)
		*/
		void setJugadorActivo(Jugador* jugadorActivo);

		void setTotalPlayers(int totalPlayers);
		void setTotalModelos(int totalModelos);
		void setTotalPiezas(int totalPiezas);

		void setPrecioGasolina(double precioGasolina);
		void setPrecioDiesel(double precioDiesel);

		void setLogin(string login);
		void setPasswd(string passwd);

		void setPartidaCargada(bool partidaCargada);

		//Gets
		Jugador* getJugadorActivo() const;
		
		int getTotalPlayers() const;
		int getTotalModelos() const;
		int getTotalPiezas() const;

		double getPrecioGasolina() const;
		double getPrecioDiesel() const;

		string getLogin() const;
		string getPasswd() const;

		bool getPartidaCargada() const;

		//Otros métodos
		/**
		@brief imprime por pantalla el título del juego en ASCII ART
		*/
		void tituloASCII() const;
		/**
		@brief Pide los credenciales del administrador del sistema (this->login y this->passwd), si son correctos llama a imprimirMenu
		*/
		void autentificacionAdmin();
		/**
		@brief Pide los credenciales de un jugador del sistema, si son correctos asigna su dirección a jugadorActivo
		*/
		void loginUsuario();

		/**
		@brief Imprime la bienvenida al juego y llama a autentificacionAdmin
		*/
		void Bienvenida();
		/**
		@brief Imprime un menú principal que nos permite escoger entre el menú de administrador y el del usuario, si escogemos el de usuario nos redirige a loginUsuario
		*/
		void imprimirMenu();

		//MENÚ DE ADMINISTRADOR CON SUBMENÚS
		/**
		@brief Imprime el menú de administrador
		*/
		void imprimirMenuAdmin();
		/**
		@brief Imprime el menú de administración de jugadores
		*/
		void imprimirMenuAdminJugadores();
		/**
		@brief Guía al administrador para crear un nuevo usuario en el sistema
		*/
		void menuAgregarUsuario();
		/**
		@brief Guía al administrador para eliminar un usuario del sistema
		*/
		void menuEliminarUsuario();
		/**
		@brief Nos permite buscar un usuario por login, y nos muestra sus datos si existe
		*/
		void menuBusquedaUsuario();
		/**
		@brief Busca un usuario por login y si existe, muestra un menú que nos permite modificar algunos datos referentes a él
		*/
		void menuModificarUsuario();

		/**
		@brief Muestra un menú que nos permite elegir qué ranking consultar
		*/
		void menuRankings();
		/**
		@brief Muestra el ránking de vehículos general
		*/
		void topVehiculos();
		/**
		@brief Muestra el ránking de los vehículos de un tipo específico (el que escoja el usuario)
		*/
		void topVehiculosEspecifico();
		/**
		@brief Muestra el ránking de jugadores
		*/
		void topJugadores();

		/**
		@brief Muestra el menú de administración del catálogo de vehículos
		*/
		void imprimirMenuAdminCatalogo();
		/**
		@brief Guía al administrador para añadir un vehículo al catálogo
		*/
		void menuAgregarVehiculo();
		/**
		@brief Busca un vehículo en el catálogo y, si existe, lo descataloga
		*/
		void menuEliminarVehiculo();
		/**
		@brief Busca los vehículos que coincidan con los parámetros que indique el usuario (marca y modelo) y pregunta cuál desea modificar
		*/
		void menuModificarVehiculo();
		/**
		@brief Muestra un menú que permite modificar ciertos campos del vehículo al que apunta v
		@param Vehiculo *v apunta al vehículo que queremos modificar
		*/
		void subModificarVehiculo(Vehiculo* v);
		/**
		@brief Muestra un menú para que el administrador decida según qué criterios quiere buscar vehículos
		*/
		void menuBusquedaVehiculo();
		/**
		@brief Busca vehículos que coincidan con la marca y el modelo especificados por el usuario
		*/
		void busquedaMarcaModelo();
		/**
		@brief Busca vehículos con un precio menor al indicado por el usuario
		*/
		void busquedaPrecioMenor();
		/**
		@brief Busca vehículos con un precio mayor al indicado por el usuario
		*/
		void busquedaPrecioMayor();
		/**
		@brief Busca vehículos con una valoración media mayor a la indicada por el usuario
		*/
		void busquedaValoracionMedia();

		/**
		@brief Pide al usuario la marca y el modelo de un vehículo y muestra por pantalla el precio medio de ese vehículo basado en los garajes de los usuarios
		*/
		void menuConsultarPrecioMedio();

		/**
		@brief Imprime el menú para que el jugadorActual interaccione con el juego
		*/
		void imprimirMenuUsuario();
		/**
		@brief Imprime un menú que permite al usuario comprar un vehículo del catálogo si dispone de los créditos suficientes
		*/
		void menuComprarVehiculo();
		/**
		@brief Imprime un menú que permite al usuario vender un vehículo de su garaje a otro jugador si este dispone de los créditos suficientes
		*/
		void menuVenderVehiculo();
		/**
		@brief Imprime un menú que permite al usuario asignar una pieza a un vehículo de su garaje si dispone de los créditos suficientes
		*/
		void menuAsignarPieza();
		/**
		@brief Imprime un menú que permite al jugador desasignar una pieza a un vehículo de su garaje
		*/
		void menuEliminarPieza();

		/**
		@brief Imprime un menú que permite al jugador competir con otro jugador (Escoger el vehículo con el que quiere competir y el vehículo contra el que quiere competir)
		*/
		void menuCompeticion();
		/**
		@brief Simula una carrera entre v1 y v2 (Se asignan subintervalos entre el 1 y el 100 a cada jugador basandose en las estadisticas de los vehiculos y se tira un dado)
		@param Jugador* j1, Jugador* j2 son los dos jugadores que compiten entre sí
		@param Vehiculo* v1, Vehiculo* v2 son los vehículos de los jugadores correspondientes
		@post El ganador obtiene 500 créditos
		*/
		void competirBasico(Jugador* j1, Vehiculo* v1, Jugador* j2, Vehiculo* v2);

		/**
		@brief Importa los datos de una partida guardada en varios ficheros .xml
		*/
		void importarDatos();
		void importarCatalogo();
		void importarPiezas();
		void importarJugadores();

		/**
		@brief Exporta los datos de la partida en varios ficheros .xml
		*/
		void exportarDatos();
		void exportarCatalogo();
		void exportarJugadores();

		/**
		@brief Agrega el vehículo al que apunta *v al catálogo de vehículos
		*/
		void agregarNuevoVehiculoAlSistema(Vehiculo* v);
		/**
		@brief Agrega la pieza a la que apunta *p al catálogo de piezas
		*/
		void agregarNuevaPiezaAlSistema(Pieza* p);
		/**
		@brief Agrega el jugador al que apunta j a la lista de jugadores
		*/
		void agregarNuevoJugadorAlSistema(Jugador *j);

		/**
		@brief Imprime el catálogo de vehículos del sistema (usado para debug)
		*/
		void verCatalogoVehiculos() const;
		/**
		@brief Imprime el catálogo de piezas del sistema (usado para debug)
		*/
		void verCatalogoPiezas() const;

		/**
		@brief Busca un vehículo con la ID idvehiculo en el catálogo de vehículos y devuelve su dirección de memoria (Usado en importar jugadores)
		@param int idvehiculo la ID que queremos comprobar
		@return Vehiculo* resultado, que apunta a 0 si no se ha encontrado el vehículo y al vehículo del catálogo si lo ha encontrado 
		*/
		Vehiculo* buscarCatalogoVehiculosID(int idvehiculo);
		/**
		@brief Busca una pieza con la ID idpieza en el catálogo de piezas y devuelve su dirección de memoria (Usado en importar jugadores)
		@param int idpieza la ID que queremos comprobar
		@return Pieza* resultado, que apunta a 0 si no se ha encontrado la pieza y a la pieza del catálogo si la ha encontrado
		*/
		Pieza* buscarPieza(int idpieza);
};

#endif /*VISTAPROGRAMA_H*/