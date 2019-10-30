#pragma once
#include <string>

class helper
{
public:
	std::string stergere_dupa_nume = "Introduceti numele studentului pe care vreti sa il stergeti";;
	std::string stergere_dupa_sex = "Introduceti sexul studentilor pe care vreti sa ii stergeti .F/M.";
	std::string stergere_dupa_an_nastere="Introduceti anul de nastere al studentilor pe care vreti sa ii stergeti.";
	std::string adaugare_persoana = "Pentru adaugare persoana,introduceti textul ADD.";
private:
	friend class persoane;
};
