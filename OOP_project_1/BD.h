#include "persoane.h"


class baza_de_date
{
private:

	int nr_persoane;
	//vector de pointeri pentru persoanele din baza.
	persoane** p;
	//mutarea la stanga cu o pozitie in vectorul de persoane in cazul stergerii.
	void shift_left(int);
	//functia folosita pentru redimensionarea vectorului de persoane in cazul stergerii/adaugarii
	void redimensionare_array(int);
	void afis();
	//Functia creaza o noua instanta de persoana si completeaza valorile campurile de la tastatura.Aceasta este folosita atat din constructor pentru a initializa vectorul de persoane (unde am alocat deja
	//memorie),cat si pentru adaugarea unei persoane.
	persoane* create_person();
public:
	//constructorul care initilizeaza baza de date si primeste nr. initial de persoane
	baza_de_date(int);
	//destuctorul care dezaloca memoria pt fiecare instanta a persoanei si pentru vectorul de persoane.
	~baza_de_date();
	//metoda pt. adaugarea unei persoane
	void adaugare_pers();
	//metodele de eliminare dupa an,nume,sex prin supraincarcare.
	void eliminare(int);
	void eliminare(char);
	void eliminare(std::string);
	//Getter pt numarul de persoane;
	int get_no_pers();
	//metoda afisare alfabetic
	void afis_alfabetic();
	//metoda afisare dupa an crescator
	void afis_cresc();
	//metoda afisare dupa an descr.
	void afis_descr();
	//afisare dupa nume descr.
	void afis_alfabetic_desc();
	//exemplu functie de afisare unde am folosit supraincarcarea operatorului << 
	void afis_operator();
	//supraincarcarea operatorului <<
	friend ostream& operator << (ostream& out, const baza_de_date& bd);
};
