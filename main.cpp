#include "Console.h"


using namespace std;

int main(void)
{
 
 Console c;

 char choix(0);
 std::string jason_tcp{" "};
 
 cout << "\t                                                                                                                 " << endl;
 cout << "\t    "<<"\033[1;32m"<< "   $$$$$$\\   $$$$$$\\  $$$$$$$$\\ $$$$$$$$\\ $$\\   $$\\   " <<"\033[0m"<<"                    $$$$$$\\     $$$$$\\  $$$$$$\\         " << endl;
 cout << "\t     " <<"\033[1;32m"<<"  $$  __$$\\ $$  __$$\\ \\__$$  __|$$  _____|$$ | $$  |       " <<"\033[0m"<<"             $$  __$$\\    \\__$$ |$$  __$$\\        " << endl;
 cout << "\t     " <<"\033[1;32m"<<"  $$ /  $$ |$$ /  \\__|   $$ |   $$ |      $$ |$$  /          " <<"\033[0m"<<"            $$ /  $$ |      $$ |$$ /  \\__|       " << endl;
 cout << "\t     " <<"\033[1;32m"<<"  $$$$$$$$ |\\$$$$$$\\     $$ |   $$$$$\\    $$$$$  /  " <<"\033[0m"<<"       $$$$$$\\       $$$$$$$$ |      $$ |$$ |             " << endl;
 cout << "\t    " <<"\033[1;32m"<<"   $$  __$$ | \\____$$\\    $$ |   $$  __|   $$  $$<     " <<"\033[0m"<<"     \\______|      $$  __$$ |$$\\   $$ |$$ |             " << endl;
 cout << "\t    " <<"\033[1;32m"<<"   $$ |  $$ |$$\\   $$ |   $$ |   $$ |      $$ |\\$$\\     " <<"\033[0m"<<"                  $$ |  $$ |$$ |  $$ |$$ |  $$\\        " << endl;
 cout << "\t    " <<"\033[1;32m"<<"   $$ |  $$ |\\$$$$$$  |   $$ |   $$$$$$$$\\ $$ | \\$$\\     " <<"\033[0m"<<"                 $$ |  $$ |\\$$$$$$  |\\$$$$$$  |       " << endl;
 cout << "\t    " <<"\033[1;32m"<<"   \\__|  \\__| \\______/    \\__|   \\________|\\__|  \\__|   " <<"\033[0m"<<"                  \\__|  \\__| \\______/  \\______/        " << endl;
 cout << "\t                                                                                                                 " << endl;
 cout << "\t                                                                                                                 " << endl;

 do{
	cout << "\n                             _________________________________________________________________ " << endl;
	cout << "\n                            |                            MENU                                 |" << endl;
	cout << "\n                            |                                                                 |" << endl;
	cout << "\n                            | 0 => Liste des Fichiers                                         |" << endl;
        cout << "\n			    | 1 => Choix du Fichier à observer                                | "  << endl;
	cout << "\n			    | 2 => Ajout d' un  Fichier                                       |" << endl;
	cout << "\n                            | 3 => Données du Capteur BCM280				      |" << endl;
	cout << "\n                            | 4 => Données du Capteur GY521    	                              |" << endl;
	cout << "\n                            | 5 => Données suivant périodes	                              |" << endl;
	cout << "\n                            | 					                              |" << endl;
	cout << "\n                            |                                                                 |" << endl;
	cout << "\n                            |                     6 => EXIT  (BYE)                            |" << endl;
	cout << "\n                            |_________________________________________________________________|" << endl;
	cout << "\n\n\t" << endl;

	do
	{
	cout << "Votre Choix ? : ";
	fflush(stdin);
        cin >> choix;

	if(isdigit(choix))
	{
		//choix est bien un nombre
	}
	else
	  cout << "Veuillez rentrer un nombre !" << endl;

	}while(isdigit(choix) == 0);

	switch(choix)
	{
		case('0'):
		   c.listeFichiers();
		   break;
		case('1'):
		   jason_tcp = c.rechercheFichier();
		   break;
		case('2'):
	           c.recupererFichier();
		   break;
		case('3'):
		   if((jason_tcp == " ") || (jason_tcp == "Fichier non present !"))
		   {
	             cout << "fichier non défini " << endl;
		   }
		   else
		     c.Affichage_Capteur_BME280(jason_tcp);
		   break;
		case('4'):
		   if((jason_tcp == " ") || (jason_tcp == "Fichier non present !"))
		   {
	             cout << "fichier non défini " << endl;
		   }
		   else		  
		     c.Affichage_Capteur_GY521(jason_tcp);
		   break;
		case('5'):
		   if((jason_tcp == " ") || (jason_tcp == "Fichier non present !"))
		   {
	             cout << "fichier non défini " << endl;
		   }
		   else
		    c.Affichage_Par_Periodes(jason_tcp);
		   break;
		case('6'):
		   cout << endl << "Au revoir !\n\n";
		   break;

		default:
		   cout << endl << "Action inconnue !\n"; 
		   break;  
	}

 }while(choix!='6');
    
 return 0;
}
