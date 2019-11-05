#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
	/* Attention : il faut que le fichier uniprot_sprot.fasta.pin se trouve dans le meme repertoire que ce programme-ci pour que tout fonctionne */ 
	ifstream fichier("uniprot_sprot.fasta.pin", ios::in | ios::binary);
	if(fichier.is_open())
	{
		//declaration des variables
		int version;
		int db_type;
		int title_length;
		char* title;
		
		fichier.read( (char*)(&version), sizeof(version) ); // besoin d'un cast vers char* car read() lit les [sizeof(version)] bits suivants du fichier uniprot
		                                                    // et les place dans un pointeur de type char* (alors que &version est un pointeur de type int*)
		                                                    
		fichier.read( (char*)(&db_type), sizeof(db_type) );	// pas tres important, donne juste si on a affaire a une base d'ADN ou de proteines
		fichier.read( (char*)(&title_length), sizeof(title_length) ); //on stocke title_length ; necessaire pour initialiser title
		
		title = new char[title_length]; 					//on connait maintenant la taille de title -> on peut l'initialiser (taille d'un tableau est fixe)
		fichier.read(title, sizeof(title));
		
		cout << "Version : " << version << endl;
		cout << "Titre : " << title << endl;
		
		delete[] title;
	}
	fichier.close();
	return 0;
}
