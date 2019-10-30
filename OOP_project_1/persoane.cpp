#include "Resources.h"


//In functiile GetName,GetBirth,GetSex se returneaza campurile corespunzatoare,astfel putand fi accesate din main.
//In functiile SetName,SetBirth,SetSex se salveaza datele corespunzatoare campurilor persoanei (acestea fiind private)
//Am facut verificari pentru fiecare Setter pentru a nu intruce date eronate in campurile clasei.
//throw arunca o exceptie in cazul introducerii unei date invalide (pe care o accesez din main)
//invalid_argument este tipul exceptiei folosit in cazul asta(toate verificarile sunt facute pt validarea datelor)


string persoane::GetName()
{
	return this->nume;
	
}

void persoane::SetName(string name)
{

	if (name.length() < 3)
	{
		throw std::invalid_argument("Numele trebuie sa aiba minim 3 litere.Reintroduceti numele.");
	}
	this->nume = name;
}


int persoane::GetBirth()
{
	return this->anul_nasterii;
}

void persoane::SetBirth(int an_nastere)
{
	if ((an_nastere < 1000) || (an_nastere > 2019)) {
		throw std::invalid_argument("Anul de nastere trebuie sa aiba 4 cifre si sa nu depaseasca anul 2019.");
	}
	this->anul_nasterii = an_nastere;
}


char persoane::GetSex()
{
	return this->sex;
}

void persoane::SetSex(char sex)
{
	if ((sex != 'M') && (sex != 'F')) {
		throw std::invalid_argument("Nu ati introdus niciuna dintre variantele acceptate(F/M).Va rugam,reintroduceti sexul.");
	}
	this->sex = sex;
}

//metoda primeste ca parametri un stream de iesire si o instanta a clasei persoane si returneaza operatorul.
ostream& operator << (ostream& out, const persoane& pers) {
	out << "-----------------------------------------" << endl;
	out << "Numele persoanei: " << pers.nume << endl;
	out << "Anul nasterii: " << pers.anul_nasterii << endl;
	out << "Sex: " << pers.sex << endl;
	out << "-----------------------------------------" << endl;
	return out;
}