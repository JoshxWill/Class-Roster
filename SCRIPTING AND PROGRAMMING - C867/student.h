#pragma once
#include <string>
#include "degree.h"


class Student {
public:
	const static int daysToCompArray = 3;

protected:

	string studentID;
	string firstN;
	string lastN;
	string emailAdd;
	int studentAge;
	int daysToFinish[3];
	DegreeProgram dProgram;

public:
	//Use Accessor for getting value
	string getStudentID();
	string getFirstN();
	string getLastN();
	string getEmailAdd();
	int getStudentAge();
	int* getDaysToFinish();
	virtual DegreeProgram getDProgram();

	//Use Mutator for setting value
	void setStudentID(string studentIDr);
	void setFirstN(string firstNr);
	void setLastN(string lastNr);
	void setEmailAdd(string emailAddr);
	void setStudentAge(int studentAger);
	void setDaysToFinish(int daysToFinishr[]);
	void setDProgram(DegreeProgram dProgramr);


	Student();
	Student(string studentIDr, string firstNr, string lastNr, string emailAddr, int studentAger, int daysToFinishr[], DegreeProgram dProgramr);


	void print();

	~Student();
};

