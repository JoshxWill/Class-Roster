#include <iomanip>
#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;


Student::Student() {
	this->studentID = "";
	this->firstN = "";
	this->lastN = "";
	this->emailAdd = "";
	this->studentAge = 0;
	for (int i = 0; i < daysToCompArray; i++) {
		this->daysToFinish[i] = 0;
	}
}

Student::Student(string studentIDr, string firstNr, string lastNr, string emailAddr, int studentAger, int daysToFinishr[], DegreeProgram dProgramr) {
	this->studentID = studentIDr;
	this->firstN = firstNr;
	this->lastN = lastNr;
	this->emailAdd = emailAddr;
	this->studentAge = studentAger;
	for (int i = 0; i < daysToCompArray; i++) {
		this->daysToFinish[i] = daysToFinishr[i];
	}
	this->dProgram = dProgramr;
}

//Accessors
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstN() {
	return firstN;
}

string Student::getLastN() {
	return lastN;
}

string Student::getEmailAdd() {
	return emailAdd;
}

int Student::getStudentAge() {
	return studentAge;
}

int* Student::getDaysToFinish() {
	return daysToFinish;
}
DegreeProgram Student::getDProgram() {
	return dProgram;
}


//Mutators
void Student::setStudentID(string studentIDr) {
	this->studentID = studentIDr;
}

void Student::setFirstN(string firstNr) {
	this->firstN = firstNr;
}

void Student::setLastN(string lastNr) {
	this->lastN = lastNr;
}

void Student::setEmailAdd(string emailAddr) {
	this->emailAdd = emailAddr;
}

void Student::setStudentAge(int studentAger) {
	this->studentAge = studentAger;
}

void Student::setDaysToFinish(int daysToFinishr[]) {
	for (int i = 0; i < daysToCompArray; i++)
		this->daysToFinish[i] = daysToFinish[i];
}

void Student::setDProgram(DegreeProgram dProgramr) {
	this->dProgram = dProgramr;
}


void Student::print() {
	std::cout << getStudentID() << "\t" << getFirstN() << "\t" << getLastN() << "\t" << getEmailAdd() << "\t" << getStudentAge() << "\t";
	int* numDaysInCourse = getDaysToFinish();
	cout << numDaysInCourse[0] << "\t" << numDaysInCourse[1] << "\t" << numDaysInCourse[2] << "\t";
	cout << degreeStrings[(int)getDProgram()] << endl;
}

Student::~Student() {}