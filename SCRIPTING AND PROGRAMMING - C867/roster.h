#include "student.h"
#pragma once

//Create Roster Class
class Roster {
private:
	int studentGuide;
	int listSize;

	//Create classRosterArray
	Student** classRosterArray;

public:
	Roster();
	Roster(int listSize);

	Student* getStudentAt(int studentGuide);

	void parseandadd(string studentData);

	void add(string studentIDr, string firstNr, string lastNr, string emailAddr, int studentAger, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dProgramr);

	bool remove(string studentIDr);

	void printAll();

	void printAverageDaysInCourse(string studentIDr);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram dProgramr);

	~Roster();
};
