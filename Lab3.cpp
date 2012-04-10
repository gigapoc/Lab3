#include <iostream>

using namespace std;

const int MAX_FICHIERS = 4;
//Nombre maximum de fichiers dans la FAT

const int TAILLE_FAT = 256;
//Taille de la FAT

const string cheminFichier;
//Contient le chemin du fichier HD.DH

class OS {
	
	private :
	
	string tampLecture;
	string tampEcriture;
		
	public:
	
	void read(string nomFichier, int position, int nbCar, string &tampLecture);
	//Ouvre un fichier, s'il existe, et lis selon les paramètres les données 
	//pour les mettres dans TampLecture, puis le referme.
	
	void write(string nomFichier, int position, int nbCar, string tampEcriture);
	//Ouvre ou crée au besoin un fichier et 
	//écrit selon les paramètres le tampon de données, puis le referme.
	
	void deleteEOF(string nomFichier, int position);
	//ouvre un fichier existant et le coupe à "position", 
	//puis le referme. Si position est 0, efface le fichier.
};

class DD {
	private :
	
	string tampLecture;
	string tampEcriture;
	
	public :
	
	void readBlock(int numBlock, string &tampLecture);
	//Lis un block de données et renvoie le résultat dans tampLecture
	
	void writeBlock(int numBlock, string tampEcriture);
	//Ecrit dans un block donné
};

class Fichier {
	
	private :
		
	string fichiers[MAX_FICHIERS];
	string fat[2][TAILLE_FAT];
	
	public :
	
//** Partie interaction avec le fichier permanent **//
	
	void initTab();
	//Prends les valeurs du fichier permanent pour les mettre dans les tableaux
	
	void saveTab();
	//Prends les valeurs des tableaux pour les mettre dans le fichier permanent
	
//** Fin partie interaction avec le fichier permanent **//
	
	
//** Partie tableau fat **//
	
	string getBlock(int numBlock);
	//Méthode qui retourne le string contenu dans un block donné
	
	int getNumBlockSuivant(int numBlock);
	//Méthode qui retourne le numéro du block suivant un block donné
	//Retourne -1 si le fichier est fini (EOF)
	
//** Fin partie tableau fat **//
	
	
	
//** Partie tableau fichiers **//
	
	int getDebutFic(string nomFichier);
	//Méthode qui retourne le block de départ du fichier dont le numéro est passé en paramètre
	
	int getTailleFic(string nomFichier);
	//Méthode qui retourne la taille du fichier dont le numéro est passé en paramètre
	
//**Fin partie tableau fichiers **//
	
	
};

int main (int argc, char * const argv[]) {
    
    return 0;
}
