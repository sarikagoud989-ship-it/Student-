#include <iostream>
#include <fstream>
using namespace std;

class Student
{
  public:
	int rollNo;
	char name[50];
	float marks;

	void addStudent()
	{
		cout << "\nEnter Roll Number: ";
		cin >> rollNo;

		cout << "Enter Name: ";
		cin >> name;

		cout << "Enter Marks: ";
		cin >> marks;
	}

	void displayStudent()
	{
		cout << "\nRoll Number : " << rollNo;
		cout << "\nName        : " << name;
		cout << "\nMarks       : " << marks << endl;
	}
};

int main()
{
	Student s;
	int choice;

	do
	{
		cout << "\n\n===== Student Management System =====";
		cout << "\n1. Add Student";
		cout << "\n2. Display Student";
		cout << "\n3. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ofstream file("student.txt", ios::app);

			s.addStudent();

			file << s.rollNo << " "
				 << s.name << " "
				 << s.marks << endl;

			file.close();

			cout << "\nStudent Record Saved Successfully!";
			break;
		}

		case 2:
		{
			ifstream file("student.txt");

			cout << "\n\n===== Student Records =====";

			while (file >> s.rollNo >> s.name >> s.marks)
			{
				s.displayStudent();
			}

			file.close();
			break;
		}

		case 3:
			cout << "\nExiting Program...";
			break;

		default:
			cout << "\nInvalid Choice!";
		}

	} while (choice != 3);

	return 0;
}