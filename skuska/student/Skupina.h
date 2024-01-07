#pragma once
#include "Student.h"

class Skupina
{
private:
	Student** studenti;
	int pocetStudentov;
public:
	Skupina();
	~Skupina();
	bool nachadzaSa(int id);
	void InfoSkupina();
	void Pridaj(const Student& novy);
	void Vyluc(int idVyluc);
};
