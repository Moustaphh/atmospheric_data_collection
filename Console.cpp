#include "Console.h"
#include <sstream>
#include<string.h>
using namespace std;




//Constructeur
Console::Console()
{

}

//Destructeur
Console::~Console()
{
  cout << "Destruction de l'objet Console" << std::endl;
}

//Methodes

void Console::Affichage_Capteur_BME280(std::string jason_d)
{    
    
    nlohmann::json json_data = nlohmann::json::parse(jason_d);
    
     //Show the features of the Sensor (Temp, Hum, Pres)
     
    cout << "Données Capteur BME280\n" << endl;
     for(int i(0); i<json_data["measurement"].size();i++)
     {
      cout << "Date : " << json_data["measurement"][i].value("jour","not found");
      cout << "/" << json_data["measurement"][i].value("mois","not found");
      cout << "/" << json_data["measurement"][i].value("annee","not found");
      cout << " |  Heure : " << json_data["measurement"][i].value("heure","not found");
      cout << "h : " << json_data["measurement"][i].value("minute","not found");
     cout << "m" << endl;
     cout << "Temperature : " << json_data["measurement"][i].value("temperature","not found") << "°C" << endl;
     cout << "Humidite : " << json_data["measurement"][i].value("humidite","not found") << " %" << endl;
     cout << "Pression : " << json_data["measurement"][i].value("pression","not found") << "hPa" << endl;
     cout << "------------------------------------------------------------------------" << endl;
     }
		

}

void Console::Affichage_Capteur_GY521(std::string jason_d)
{
//Show the features of the Magnetometer (X, Y, Z)
	
     nlohmann::json json_data = nlohmann::json::parse(jason_d);
     
     cout << "Données Capteur GY521\n" << endl;
     for(int i(0); i<json_data["measurement"].size();i++)
     {
      cout << "Date : " << json_data["measurement"][i].value("jour","not found");
      cout << "/" << json_data["measurement"][i].value("mois","not found");
      cout << "/" << json_data["measurement"][i].value("annee","not found");
      cout << " |  Heure : " << json_data["measurement"][i].value("heure","not found");
      cout << "h : " << json_data["measurement"][i].value("minute","not found");
     cout << "m" << endl;   
     cout << "X: " << json_data["measurement"][i].value("x","not found") << endl;
     cout << "Y: " << json_data["measurement"][i].value("y","not found") << endl;
     cout << "Z: " << json_data["measurement"][i].value("z","not found") << endl;
     cout << "------------------------------------------------------------------------" << endl;
     }

}

void Console::Affichage_Par_Periodes(std::string jason_d)
{
  unsigned short int min_debut(0);
  unsigned short int min_fin(0);
  int min_file(0);
  
	do
	{
	 cout << endl << "Minutes debut : ";
         cin >> min_debut;
		    cout << endl << "Minutes fin : ";
		    cin >> min_fin;
        
        	if(min_debut < 0 || min_fin < 0 || min_debut > 59 || min_fin > 59)
        	{
        	  cout << endl << "Minutes erronées !" << endl;
        	}
        
        	
	}while(min_debut < 0 || min_fin < 0 || min_debut > 59 || min_fin > 59);
	
	  //Parsing du fichier json
		nlohmann::json json_data = nlohmann::json::parse(jason_d);
		
	   
	   	cout << "Données Capteur BME280\n" << endl;
	   	
       for(int i(0); i<json_data["measurement"].size(); i++)
	   	{	
		   min_file=stoi(json_data["measurement"][i].value("minute","not found"));
		   if((min_file >= min_debut) && (min_file <= min_fin))
		   {
		       cout << "Date : " << json_data["measurement"][i].value("jour","not found");
		       cout << "/" << json_data["measurement"][i].value("mois","not found");
		       cout << "/" << json_data["measurement"][i].value("annee","not found");
           	   cout << " | Heure : " << json_data["measurement"][i].value("heure","not found");
     		   cout << "h : " << json_data["measurement"][i].value("minute","not found");
     		   cout << "m" << endl;
     		   cout << "Temperature : " << json_data["measurement"][i].value("temperature","not found") << "°C" << endl;
     		   cout << "Humidite : " << json_data["measurement"][i].value("humidite","not found") << " %" << endl;
     		   cout << "Pression : " << json_data["measurement"][i].value("pression","not found") << "hPa" << endl;
     		   cout << "------------------------------------------------------------------------" << endl;	   
		   }
	   	}
	   	
      		cout << endl << "Données Capteur GY521\n" << endl;
	   	for(int i(0); i<json_data["measurement"].size(); i++)
	   	{
		     min_file=stoi(json_data["measurement"][i].value("minute","not found"));
  		   if((min_file >= min_debut) && (min_file <= min_fin))
  		   {
  		       cout << "Date : " << json_data["measurement"][i].value("jour","not found");
		       cout << "/" << json_data["measurement"][i].value("mois","not found");
		       cout << "/" << json_data["measurement"][i].value("annee","not found");
           	   cout << " |  Heure : " << json_data["measurement"][i].value("heure","not found");
     		   cout << "h : " << json_data["measurement"][i].value("minute","not found");
     		   cout << "m" << endl;
       		   cout << "X : " << json_data["measurement"][i].value("x","not found") << endl;
       		   cout << "Y : " << json_data["measurement"][i].value("y","not found") << endl;
       		   cout << "Z : " << json_data["measurement"][i].value("z","not found") << endl;
       		   cout << "------------------------------------------------------------------------" << endl;	   
  		    }
	   	}	
	
	
}
void Console::listeFichiers(void)
{ 
    if(Console::getNumbersOfFiles() != 0)
    {
	    cout << "Liste des Fichiers : ";
	    for(map<std::string,std::string>::iterator it=fichiers.begin(); it!=fichiers.end(); it++)
	    {
		    cout << it->first << " | ";
	    }
	    cout << endl << endl;
    }
    else
    {
	    cout << "Aucun fichiers présent dans la console !" << endl; 
    }
}

void Console::recupererFichier(void)
{	
	
	std::string extension= ".json";
	std::string filename,file_heure,jason_tcp;
  
	  do
	  {
	   cout << "Entrer une heure : " ;
	   cin >> file_heure;
	   
	   if(stoi(file_heure)<0 || stoi(file_heure)>23)
	     cout << "Heure erronée !" << endl;

	  }while(stoi(file_heure)<0 || stoi(file_heure)>23);

	  filename = "H" + file_heure;

	  jason_tcp = get_tcp(filename);

	  filename+=extension; //ex ("H1.json")
	  
	  //Ajout du fichier dans la liste
	  Console::ajouterFichier(filename,jason_tcp);

}
void Console::ajouterFichier(std::string nom, std::string jason_tcp)
{
    //Verif si le fichier est déjà existant	
    if(this->fichiers.count(nom) != 0)
    {
       cout << "Fichier déjà existant ! " << endl;
    }
    else
    {
       this->fichiers[nom] = jason_tcp;	    
    }

}

std::string Console::rechercheFichier(void)
{  
   if(Console::getNumbersOfFiles() == 0)
   {
    Console::listeFichiers();
   }
   else
   {   
   	Console::listeFichiers();
   	std::string filename;
   	cout << endl << "Veuillez rentrer le fichier : ";
   	fflush(stdin);
   	cin >> filename;

   	for(map<string,string>::iterator it=fichiers.begin(); it != fichiers.end(); it++)
   	{
      	   if(it->first == filename)
	      	return it->second; //Renvoie le fichier json correspondant
   	}
   }
   return "Fichier non present !";

}
