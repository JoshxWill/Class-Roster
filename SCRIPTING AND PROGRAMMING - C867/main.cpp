#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {

	//Print out ,via application, course title, programming language used, WGU student ID and Name to screen

	cout << "C867: Scripting and Programming - Applications " << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 004225670 " << endl;
	cout << "Name: Joshua Williams" << endl;


	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Joshua,Williams,jwi3411@wgu.edu,24,35,45,55,SOFTWARE",
	};
	int studentCount = 5;
	Roster* classList = new Roster(studentCount);

	for (int i = 0; i < studentCount; i++) {
		classList->parseandadd(studentData[i]);
	}
	cout << "\n";
	cout << "Displaying all students: " << endl;
	classList->printAll();
	cout << "\n";

	cout << "Displaying invalid emails: " << endl;
	cout << "\n";
	classList->printInvalidEmails();
	cout << "\n";

	for (int i = 0; i < studentCount; i++) {
		classList->printAverageDaysInCourse(classList->getStudentAt(i)->getStudentID());
	}

	cout << "\n";

	cout << "Showing students in degree program: SOFTWARE " << endl;
	cout << "\n";
	classList->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "\n";

	cout << "Removing A3: " << endl;
	cout << "\n";
	if (classList->remove("A3")) {
		classList->printAll();
		studentCount--;
	}

	cout << "\n";
	cout << "Removing A3 again" << endl;
	cout << "\n";
	if (classList->remove("A3")) classList->printAll();
	else cout << "The student with the ID: A3 was not found. " << endl;

	system("pause");
	return 0;
}