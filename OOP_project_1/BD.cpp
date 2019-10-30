#include "Resources.h"

using namespace std;

//Am folosit constructor parametrizat cu valoare default=0 pentru cazul cand nu e dat ca parametru constructorului la crearea unei noi instante.

baza_de_date::baza_de_date(int n=0) {

	this->nr_persoane = n;
	//Alocare memorie in campul p pt n pointeri de persoane
	this->p = new persoane * [n];
//Initializez toate campurile cu n
	for(int i=0; i<this->nr_persoane;i++){
		this->p[i] = NULL;
	}
	//Populez vectorul de persoane apelandu-se metoda de creare a unei instante de persoane.
	for (int i = 0; i < this->nr_persoane; i++) {
		this->p[i] = this->create_person();
	}
	cout << "Baza de date a fost initializata!" << endl;
}


baza_de_date::~baza_de_date() {
//Se dezaloca memoria pentru fiecare instanta
	for (int i = 0; i < this->nr_persoane; i++) {
		delete this->p[i];
	}
	// si apoi se dezaloca memoria si pt vectorul de persoane.
	delete this->p;

}

persoane* baza_de_date::create_person() {
	//se creaza o noua instanta a persoanei
	
	persoane* newPersoana = new persoane();
	string nume;
	int an_nastere;

	char sex;
	cout << "--------------------------------------------------" << endl;
	//folosesc while infinit pentru fiecare camp in parte impreuna cu un try->catch pentru a se asigura ca se citesc date valide.
	//block try-catch va "prinde" exceptiile "aruncate" de setterele campurilor clasei persoane in cazul in care se introduc date eronate.
	//Se folosesc 2 catch-uri
				//1.(invalid_argument) pt exceptia specifica aruncata de setterele campurilor
				//2.catch(...) , exceptia generala , pentru orice alta eventuala eroare.
	while (1)
	{
		try {
			cout << "Numele persoanei: ";
			getchar();
			std::getline(std::cin, nume);
			newPersoana->SetName(nume);
			break;
		}

		catch (const std::invalid_argument & n) {
			cout << n.what() << endl;
			continue;
		}


		catch (...) {
			cout << "A aparut o eroare.Va rog reintroduceti numele" << endl;
			continue;
		}
	}
	while (1) {
		try {
			cout << "Anul nasterii: ";
			cin >> an_nastere;
			newPersoana->SetBirth(an_nastere);
			break;
		}
		catch (const std::invalid_argument & e) {
			cout << e.what() << endl;
			continue;
		}
		catch (...) {
			cout << "A aparut o eroare.Reintrodu anul nasterii." << endl;
			continue;
		}
	}


	while (1) {
		try {

			cout << "Sex (M/F):";
			cin >> sex;
			newPersoana->SetSex(sex);
			break;

		}
		catch (const std::invalid_argument & f) {
			cout << f.what() << endl;
			continue;
		}
		catch (...) {
			cout << "A aparut o eroare.Reintroduceti sexul" << endl;
			continue;
		}
	}

	return newPersoana;
}

void baza_de_date::adaugare_pers() {
	//apelez functia de redimensionare care va aloca memorie pt nr de persoane existent in baza+1(cea noua)
	this->redimensionare_array(this->nr_persoane + 1);
	//apoi o apelez pe cea de creare a noii instante si o atribui pozitiei corespunzatoare din vector
	this->p[this->nr_persoane] = this->create_person();
	//cresc nr de persoane existent in vector.
	this->nr_persoane = this->nr_persoane + 1;
	
}

void baza_de_date::eliminare(string nume) {
	//fac for-ul de la ultima pozitie pana la prima pentru ca in cazul gasirii unei persoane cu acel nume s-ar fi sters persoana,s-ar fi shtiftat ,dar la urmatoarea iteratie a for-ul
	//se sare peste persoana care ajunge pe pozitia de pe care a fost stearsa cea cu numele cautat.
	for (int i = this->nr_persoane - 1; i >= 0; i--) {
		//cand gasim persoana cu numele cautat
		if (this->p[i]->GetName() == nume) {
			//dezalocam meoria pt persoana respectiva din vector
			delete this->p[i];
			//il shiftam la stanga cu o pozitie
			this->shift_left(i);
			//nr de persoane scade.
			this->nr_persoane = this->nr_persoane - 1;
		}

	}
	//apelez functia de redimensionare a vectorului cu noul nr de persoane.
	this->redimensionare_array(this->nr_persoane);

}


//celelate 2 metode de eliminare sunt identice,numai ca se verifica conditia corespunzatoare(se sterge o persoana cu un anumit sex,sau an de nastere)
void baza_de_date::eliminare(int an_nastere) {

	for (int i = this->nr_persoane - 1; i >= 0; i--) {

		if (this->p[i]->GetBirth() == an_nastere) {
			delete this->p[i];
			this->shift_left(i);
			this->nr_persoane = this->nr_persoane - 1;
		}

	}

	this->redimensionare_array(this->nr_persoane);

}

void baza_de_date::eliminare(char sex) {

	for (int i = this->nr_persoane - 1; i >= 0; i--)
	{

		if (this->p[i]->GetSex() == sex) {
			delete this->p[i];
			this->shift_left(i);
			this->nr_persoane = this->nr_persoane - 1;
		}

	}

	this->redimensionare_array(this->nr_persoane);

}

void baza_de_date::redimensionare_array(int dimensiune) {
	//creaza un nou vector de pointeri cu o dimensiune noua(cea primita ca paramtru)
	persoane** p1 = new persoane * [dimensiune];
	//se copiaza toata zona de memorie ocupata de vectorul p ce contine persoane in noul vector creat.
	memcpy(p1, this->p, this->nr_persoane * sizeof(persoane*));

	delete[] this->p;
	this->p = p1;

}

void baza_de_date::shift_left(int position) {
//se shifteaza la stanga pointerii din vectorul de persoane,pornind de la pozitia primita ca parametru pana la final
	for (int i = position; i < this->nr_persoane - 1; i++) {
		this->p[i] = this->p[i + 1];
	}

}
//getter pt nr persoane
int baza_de_date::get_no_pers()
{
	return this->nr_persoane;

}
//functia comparator pt qsort in cazul afisarii alfabetice
int compare_alfabetic(const void* a, const void* b) {
	persoane* a1 = *(persoane**)a;
	persoane* b1 = *(persoane**)b;

	return a1->GetName().compare(b1->GetName());

}
//Am folosit qsort pentru ca e una dintre cele mai rapide metode.
void baza_de_date::afis_alfabetic() {
	qsort(this->p, this->nr_persoane, sizeof(persoane*), compare_alfabetic);
	this->afis();
	//cout << *(this);
}
//functia comparator pt qsort in cazul afisarii dupa anul nasterii cresc

int compare_cresc(const void* a, const void* b) {
	persoane* a1 = *(persoane**)a;
	persoane* b1 = *(persoane**)b;

	return a1->GetBirth() - b1->GetBirth();

}
//functia de afisare dupa anul nasterii-crescator
void baza_de_date::afis_cresc() {
	qsort(this->p, this->nr_persoane, sizeof(persoane*), compare_cresc);
	this->afis();
	//cout << *(this);
}
//verific daca nr de persoane este 0,in acest caz baza de date este goala si afisez un mesaj.
void baza_de_date::afis() {
	cout << endl << endl;
	if (this->nr_persoane == 0) {
		cout << "Nu exista persoane in baza de date!" << endl << endl;
	}
	//altfel afisez campurile
	else {

		cout << "Afisare baza de date: " << endl << endl;
		for (int i = 0; i < this->nr_persoane; i++) {
			cout << "-----------------------------------------" << endl;
			cout << "Numele persoanei: " << this->p[i]->GetName() << endl;
			cout << "Anul nasterii: " << this->p[i]->GetBirth() << endl;
			cout << "Sex: " << this->p[i]->GetSex() << endl;
			cout << "-----------------------------------------" << endl;
		
		}
	}

}



void baza_de_date::afis_operator() {
	cout << endl << endl;
	if (this->nr_persoane == 0) {
		cout << "Nu exista persoane in baza de date!" << endl << endl;
	}
	else {
		//aici afisez campurile utilizand operatorul cout (supraincrcat)
		cout << "Afisare baza de date: " << endl << endl;
		for (int i = 0; i < this->nr_persoane; i++) {
			cout << *(this->p[i]);
		}
	}

}

//supraincarcarea operatorului << pt baza de date.
ostream& operator << (ostream& out, const baza_de_date& bd) {
	cout << endl << endl;
	if (bd.nr_persoane == 0) {
		cout << "Nu exista persoane in baza de date!" << endl << endl;
	}
	else {

		cout << "Afisare baza de date: " << endl << endl;
		for (int i = 0; i < bd.nr_persoane; i++) {
			cout << *(bd.p[i]);
		}
	}
	return out;
}

//functia comparator pt afisarea descr. dupa data nasterii
int compare_descresc(const void* a, const void* b) {
	persoane* a1 = *(persoane**)a;
	persoane* b1 = *(persoane**)b;

	return b1->GetBirth() - a1->GetBirth();

}



void baza_de_date::afis_descr() {
	qsort(this->p, this->nr_persoane, sizeof(persoane*), compare_descresc);
	//this->afis();
	cout << *(this);
}

//functia comparator dupa afisarea descrescatoare dupa nume
int compare_d_alfabetic(const void* a, const void* b) {
	persoane* a1 = *(persoane**)a;
	persoane* b1 = *(persoane**)b;

	return b1->GetName().compare(a1->GetName());

}

void baza_de_date::afis_alfabetic_desc() {
	qsort(this->p, this->nr_persoane, sizeof(persoane*), compare_d_alfabetic);
	this->afis();
	//cout << *(this);
}