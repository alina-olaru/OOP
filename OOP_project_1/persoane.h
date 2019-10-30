#pragma once
#include "Resources.h"

using namespace std;

class persoane
{

private:
	std::string nume;
	int anul_nasterii;
	char sex;
public:
	//supraincarcarea operatorului << pt persoane
	friend ostream& operator << (ostream& out, const persoane& c);
	//Getter pentru nume
	std::string GetName();
	//Setter pentru nume
	void SetName(std::string);
	//Getter pentru data
	int GetBirth();
	//Setter pentru data
	void SetBirth(int);
	//Getter pentru sex
	char GetSex();
	//Setter pentru sex
	void SetSex(char);


};
