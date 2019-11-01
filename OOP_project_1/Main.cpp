#include "Resources.h"




int main()	
{
	//Am folosit o enumeratie pentru optiunile meniului (switch) deoarece este mai usor de urmarit codul si de adaugat alte optiuni.
	enum Choices { exit, add_pers, del_by_name, del_by_year, del_by_sex, afis_alf=100, afis_cresc ,afis_desc,afis_desc_alf};





	
	int choice;
	string name;
	int year;
	char sex;
	int nr_persoane_initial;

	//Am ciit nr. de persoane existente in baza de date(numarul intial) si am verificat sa fie >=0 pt validare.
	while (true) {
		cout << "Introdu numarul de persoane initial din baza de date:";
		cin >> nr_persoane_initial;

		if (nr_persoane_initial < 0) {
			cout << endl << "Numarul de persoane trebuie sa fie un numar intreg pozitiv!" << endl;
			continue;
		}

		break;

	}
	
	

	//Am creat o instanta a bazei de date care a fost initalizata cu numarul de persoane initial introdus de la tastatura cu ajutorul constructorului.
	baza_de_date* BD = new baza_de_date(nr_persoane_initial);
	//Exemplu utilizarea supraincarii operatoruli cout.
	//cout << *BD;
	
	do {
	//Afisarea meniului cu ajutorul enumeratiei de mai sus-->aceasta se face pana la introducere keyword-ului necesar pt iesire(-1 in cazul acesta)

		cout << endl << "---------------------------------------------" << endl;
		cout << "Pentru adaugarea unei persoane - tasteaza "<<add_pers << endl;
		cout << "Pentru stergerea dupa nume - tasteaza "<< del_by_name << endl;
		cout << "Pentru stergerea dupa anul nasterii - tasteaza "<<del_by_year << endl;
		cout << "Pentru stergerea dupa sex - tasteaza "<< del_by_sex << endl;
		cout << "Pentru afisarea in ordine alfabetica - tasteaza "<<afis_alf << endl;
		cout << "Pentru afisarea in ordine crescatoare dupa anul nasterii - tasteaza "<< afis_cresc << endl;
		cout << "Pentru afisarea in ordine descrescatoare dupa anul nasterii-tasteaza "<< afis_desc << endl;
		cout << "Pentru afisarea in ordine descrescatoare dupa nume -tasteaza "<< afis_desc_alf << endl;
		cout << "Exit - tasteaza "<< exit << endl<<endl;

		cout << "Introdu optiunea:";
		cin >> choice;


		switch (choice)
		{
		//adaugare o noua persoana
		case add_pers: 
			BD->adaugare_pers();
			
			break;
		//stergere persoana dupa nume
		case del_by_name:
			cout << "Introdu numele persoanei pe care vrei sa o stergi din baza de date: ";
			cin >> name;
			BD->eliminare(name);
			break;
		//stergere persoana dupa an
		case del_by_year:
			cout << "Introdu anul nasterii pentru persoana pe care vrei sa o stergi din baza de date: ";
			cin >> year;
			BD->eliminare(year);
			break;
		//stergere persoana dupa sex
		case del_by_sex:
			cout << "Introdu sexul persoanei pe care vrei sa o stergi din baza de date: ";
			cin >> sex;
			BD->eliminare(sex);
			break;
		//afisare alfabetic 
		case afis_alf:
			BD->afis_alfabetic();
			break;
		//afisare dupa an crescator
		case afis_cresc:
			BD->afis_cresc();
			break;
		//afisare dupa an descrescator
		case afis_desc:
			BD->afis_descr();
			break;
		//Afisare descrescator dupa nume
		case afis_desc_alf:
			BD->afis_alfabetic_desc();
			break;
		default:
			cout << endl;
			cout << "Optiunea nu e valida" << endl << endl << endl;
			break;
		}
		//conditia de oprire(keyword-ul)
	} while (choice != exit);



	
}



//Definiti constructorii (initializare, parametrizati, copiere) si destructorul; FACUTA
//

/*Se considera o clasa din cadrul proiectului individual.
Realizati urmatoarele cerinte, astfel incat sa aiba sens in cadrul proiectului:
- Definiti constructorii (initializare, parametrizati, copiere) si destructorul;
- Adaugati un constructor parametrizat care, prin intermediul unui parametru bool
sa atribuie valori campurilor clasei de la consola ("true") si din fisier ("false");
- Implementati supraincarcarea operatorilor: -(minus) - schimba semnul campurilor;
--(decrementare), atat in forma prefixata cat si postfixata;
!= (diferit); (float) - operatorul de cast catre float.
- Transformati o functie prieten din cadrul proiectului intr-o functie membra;
- Transformati o functie membra din cadrul proiectului intr-o functie friend;
- Implementati tot ce este necesar ca sa functioneze urmatorul demo:
Obiect v[4];
cin>>v[1];
cout<<v[1];
v[2]=v[3]=(v[1] + v[1]);
- Adaugati o clasa "Management" in care se retine un vector de obiecte si pentru ea sa implementeze 
<<, >>, operator=, copy instructor.*/