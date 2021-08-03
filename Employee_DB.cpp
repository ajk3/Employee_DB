// anurag kunwar
// 11/20

#include <iostream>
#include <list>
#include <string>

using namespace std;

// structure
struct EmployeeList
{
	int employeeNum_ = 0;
	string firstN_;
	string lastN_;
	int age_ = 0;
};

enum { ADD = 1, CHANGE, DELETE, DISPLAY, COUNT, EXIT };

// prototypes
void addEmployee(list<EmployeeList>&);
void changeEmployeeInfo(list<EmployeeList>&);
void deleteEmployee(list<EmployeeList>&);
void displayEmployee(const list<EmployeeList>&);
void countEmployee(const list<EmployeeList>&);

int main()
{
	int choice;
	list<EmployeeList> employeeData;

	do
	{
		cout << "\t1.Add Employee " << endl;
		cout << "\t2.Change Employee Info " << endl;
		cout << "\t3.Delete Employee Info " << endl;
		cout << "\t4.Display Employee Info " << endl;
		cout << "\t5.Show Employee count " << endl;
		cout << "\t6.Exit " << endl << endl;

		cout << "Enter the Choice: ";
		cin >> choice;
		while (choice < 1 || cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid Choice!!!!! " << endl;
			cout << "Enter the Choice: ";
			cin >> choice;
		}

		cout << endl;
		switch (choice)
		{
		case ADD:
		{
			addEmployee(employeeData);
			cout << endl;
			break;
		}

		case CHANGE:
		{
			if (employeeData.size() != 0)
			{
				changeEmployeeInfo(employeeData);
				cout << endl;
			}
			else
			{
				cout << "Database is empty!";
				cout << "First add a employee's data " << endl;
			}
			break;
		}

		case DISPLAY:
		{

			if (employeeData.size() != 0)
			{
				displayEmployee(employeeData);
				cout << endl;
			}
			else
			{
				cout << "Database is empty!";
				cout << "First add a employee's data " << endl;
			}
			break;
		}

		case COUNT:
		{
			countEmployee(employeeData);
			break;
		}

		case DELETE:
		{
			if (employeeData.size() != 0)
			{
				deleteEmployee(employeeData);
				cout << endl;
			}
			else
			{
				cout << "Database is empty!";
				cout << "First add a employee's data " << endl;
			}
			break;
		}

		case EXIT:
		{
			cout << " Thanks for using our program!!!! " << endl << endl;
			break;
		}

		default:
		{
			cout << " Invalid Choice!!!!! " << endl << endl;;
			break;
		}
		}
	} while (choice != 6);

	cout << endl;
	system("pause");
	return 0;
}

void addEmployee(list<EmployeeList>& employeeList)
{
	cout << "Enter the following Information: " << endl;
	EmployeeList tempStruct;

	int id;
	string fName;
	string lName;
	int age;

	cout << "Enter the Employee Id: "; // id
	cin >> id;
	while (id < 101 || cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid ID!!!!! " << endl;
		cout << "Enter the Emplyee Id: ";
		cin >> id;
	}

	cin.ignore();
	cout << "Enter the Employee First Name: "; // first name
	getline(cin, fName);

	cout << "Enter the Employee Last Name: "; // last name
	getline(cin, lName);

	cout << "Enter the Employee Age: "; // age
	cin >> age;
	while (age < 16 || cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid AGE!!!!! " << endl;
		cout << "Enter the Age: ";
		cin >> age;
	}

	tempStruct.employeeNum_ = id;
	tempStruct.firstN_ = fName;
	tempStruct.lastN_ = lName;
	tempStruct.age_ = age;

	employeeList.push_back(tempStruct); // adding node 

	return;

}

void changeEmployeeInfo(list<EmployeeList>& employeelist)
{
	
	int id;
	string fName;
	string lName;
	int age;

	bool found = false;

	list<EmployeeList> :: iterator it;
	it = employeelist.begin();


	cout << "Enter The Employee Number: ";
	cin >> id;

	while (it != employeelist.end() && !found)
	{
		
		if (it->employeeNum_ == id)
		{
			cout << endl;
			cout << "Current Record Shows: " << endl;
			cout << " Employee Id: " << it->employeeNum_ << endl;
			cout << " Employee First Name: " << it->firstN_ << endl;
			cout << " Employee Last Name: " << it->lastN_ << endl;
			cout << " Employee Age: " << it->age_ << endl << endl;

			cout << "Enter the New Information " << endl;

			cout << " Employee Id: ";
			cin >> id;
			while (id < 101 || cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Invalid ID!!!!! " << endl;
				cout << "Enter the Emplyee Id: ";
				cin >> id;
			}

			it->employeeNum_ = id;
			cin.ignore();

			cout << " Employee First Name: ";
			getline(cin, fName);
			it->firstN_ = fName;

			cout << " Employee Last Name: ";
			getline(cin, lName);
			it->lastN_ = lName;

			cout << " Employee Age: ";
			cin >> age;

			while (age < 16 || cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Invalid AGE!!!!! " << endl;
				cout << "Enter the Age: ";
				cin >> age;
			}
			it->age_ = age;

			found = true;

			cout << " Data OverWritten!!!! " << endl;
		}

		it++;
	}
	
	if (found == false)
	{
		cout << " Employee with Id: " << id << " Not found!!!! " << endl;
	}
	return;
}

void displayEmployee(const list<EmployeeList>& employeelist)
{
	cout << "Displaying All Records: " << endl << endl;

	for (auto it = employeelist.begin(); it != employeelist.end(); it++)
	{
		cout << " Employee Id: " << it->employeeNum_ << endl;
		cout << " Employee First Name: " << it->firstN_ << endl;
		cout << " Employee Last Name: " << it->lastN_ << endl;
		cout << " Employee Age: " << it->age_ << endl << endl;
	}
	return;
}

void countEmployee(const list<EmployeeList>& employeelist)
{
	cout << "The Employee List Contains " << employeelist.size() << " entries." << endl << endl;
	return;
}

void deleteEmployee(list<EmployeeList>& employeelist)
{
	int id;
	bool found = false;

	list<EmployeeList> :: iterator it;
	list <EmployeeList> :: iterator tempIt;

	cout << "Enter the Employee Id: ";
	cin >> id;

	it = (employeelist.begin());

	while (it != employeelist.end() && !found)
	{
		if (it->employeeNum_ == id && it != employeelist.end())
		{
			tempIt = it;
			found = true;	
		}
		it++;
	}

	if (found == false)
	{
		cout << " Employee with Id: " << id << " Not found!!!! " << endl;
		return;
	}

	employeelist.erase(tempIt);
	cout << "Data deleted!!!!! " << endl;

	return;
}
