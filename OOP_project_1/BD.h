#include "persoane.h"

//clasa mea Management
class baza_de_date
{
private:
	void initializare_bd_console(int);
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
	//pt cerinta 2
	baza_de_date(int, bool);
	baza_de_date();
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
	void afis_nr_persoane();
	//supraincarcarea operatorului <<
	friend ostream& operator << (ostream& out, const baza_de_date& bd);
	//supraincarcarea operatorului >>
	friend istream& operator >> (istream& in, const baza_de_date& bd);
	//--(decrementare)
	//Am declarat inline pentru ca era scurt codul
	baza_de_date operator-- (int) {
		baza_de_date bd;
		bd.nr_persoane = nr_persoane--;
		return bd;

	}
	//decrementare prefix
	/*baza_de_date operator-- (int) {
		baza_de_date bd;
		--nr_persoane;
		bd.nr_persoane = nr_persoane;
		return bd;

	}*/
	//!= (diferit); 
	friend bool operator!=(baza_de_date&a, baza_de_date&b);
};


//Transformati o functie membra din cadrul proiectului intr-o functie friend
//- Transformati o functie prieten din cadrul proiectului intr-o functie membra; pt asta am adaugat functia afis_alfabetic_desc();
