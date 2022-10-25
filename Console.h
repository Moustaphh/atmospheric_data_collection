#ifndef CONSOLE_H
#define CONSOLE_H

#include "client.h"

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <map>

using namespace std;

class Console
{
	public:
		//Constructeur
		Console();
		//Destructeur
		~Console();

		//Methodes
		void Affichage_Capteur_BME280(std::string);
		void Affichage_Capteur_GY521(std::string);
		void Affichage_Par_Periodes(std::string);
		void recupererFichier(void);
		void ajouterFichier(std::string, std::string);
		std::string rechercheFichier(void);
		void listeFichiers(void);
		unsigned int getNumbersOfFiles(void){return this->fichiers.size();}

	private:
		std::map<std::string,std::string>fichiers;

};

#endif
