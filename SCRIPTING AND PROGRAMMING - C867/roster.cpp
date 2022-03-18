#include <string>
#include <iostream>
#include <iomanip>
#include "roster.h"
#include "student.h"
#include "degree.h"

Roster::Roster() {
	this->listSize = 0;
	this->studentGuide = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int listSize) {
	this->listSize = listSize;
	this->studentGuide = -1;
	this->classRosterArray = new Student * [listSize];
}

Student* Roster::getStudentAt(int studentGuide) {
	return classRosterArray[studentGuide];
}

void Roster::parseandadd(string rosterData) {
	if (studentGuide < listSize) {
		studentGuide++;
	}

	int rs = rosterData.find(",");
	string rosterStudentID = rosterData.substr(0, rs);

	int ls = rs + 1;
	rs = rosterData.find(",", ls);
	string rosterFirstN = rosterData.substr(ls, rs - ls);

	ls = rs + 1;
	rs = rosterData.find(",", ls);
	string rosterLastN = rosterData.substr(ls, rs - ls);

	ls = rs + 1;
	rs = rosterData.find(",", ls);
	string rosterEmailAdd = rosterData.substr(ls, rs - ls);

	ls = rs + 1;
	rs = rosterData.find(",", ls);
	int rosterStudentAge = stoi(rosterData.substr(ls, rs - ls));

	ls = rs + 1;
	rs = rosterData.find(",", ls);
	int DIC1 = stoi(rosterData.substr(ls, rs - ls));

	ls = rs + 1;
	rs = rosterData.find(",", ls);
	int DIC2 = stoi(rosterData.substr(ls, rs - ls));

	ls = rs + 1;
	rs = rosterData.find(",", ls);
	int DIC3 = stoi(rosterData.substr(ls, rs - ls));

	ls = rs + 1;
	rs = rosterData.find(",", ls);
	DegreeProgram dProgram0{};
	string degProgram1 = rosterData.substr(ls, rs - ls);
	if (degProgram1 == "SOFTWARE") {
		dProgram0 = DegreeProgram::SOFTWARE;
	}
	else if (degProgram1 == "SECURITY") {
		dProgram0 = DegreeProgram::SECURITY;
	}
	else if (degProgram1 == "NETWORK") {
		dProgram0 = DegreeProgram::NETWORK;
	}


	add(rosterStudentID, rosterFirstN, rosterLastN, rosterEmailAdd, rosterStudentAge, DIC1, DIC2, DIC3, dProgram0);

}

void Roster::add(string studentID, string firstN, string lastN, string emailAdd, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dProgram) {
	int completeDays[Student::daysToCompArray];

	completeDays[0] = daysInCourse1;
	completeDays[1] = daysInCourse2;
	completeDays[2] = daysInCourse3;

	classRosterArray[studentGuide] = new Student(studentID, firstN, lastN, emailAdd, studentAge, completeDays, dProgram);
}

bool Roster::remove(string studentIDr) {
	bool found = false;
	for (int i = 0; i <= studentGuide; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentIDr) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[studentGuide];
			studentGuide--;
		}
	}
	return found;
}

void Roster::printAll() {
	for (int i = 0; i <= studentGuide; i++)
		(this->classRosterArray)[i]->print();
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; ++i) {
		string rosterStudentID = classRosterArray[i]->getStudentID();
		string rosterEmailAdd = classRosterArray[i]->getEmailAdd();
		if ((rosterEmailAdd.find("@") == string::npos || rosterEmailAdd.find(".") == string::npos) || (rosterEmailAdd.find(" ") != string::npos)) {
			cout << rosterEmailAdd << "- is invalid." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram dProgramr) {
	for (int i = 0; i < 5; ++i) {
		DegreeProgram degProgram = classRosterArray[i]->getDProgram();
		if (degProgram == dProgramr) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentIDr) {
	int averageDays = 0;

	for (int i = 0; i < 5; ++i) {
		string rosterStudentID = classRosterArray[i]->getStudentID();
		if (rosterStudentID == studentIDr) {
			averageDays = ((classRosterArray[i]->getDaysToFinish()[0] + classRosterArray[i]->getDaysToFinish()[1] + classRosterArray[i]->getDaysToFinish()[2]) / 3);
			cout << "Student ID: " << rosterStudentID << ", average days in course is: " << averageDays << endl;
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}
