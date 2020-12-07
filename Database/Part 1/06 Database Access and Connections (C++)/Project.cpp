//Yongtak Jun, Aug/02/2020, DBS211 - Project

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <occi.h>


using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

struct Employee
{
	int employeeNumber;
	char lastName[50];
	char firstName[50];
	char email[100];
	char phone[50];
	char extension[10];
	char reportsTo[100];
	char jobTitle[50];
	char city[50];

};

int menu(void)
{
	cout << "********************* HR Menu *********************" << endl;
	cout << "1) Find Employee" << endl;
	cout << "2) Employees Report" << endl;
	cout << "3) Add Employee" << endl;
	cout << "4) Update Employee" << endl;
	cout << "5) Remove Employee" << endl;
	cout << "6) Exit" << endl;

	int selection;
	cin >> selection;
	while (!cin || selection < 1 || selection > 6)
	{
		cout << "Invalid selection, try again: ";
		cin.clear();
		cin.ignore(2000, '\n');
		cin >> selection;
	}

	return selection;
}
int findEmployee(Connection* conn, int employeeNumber, struct Employee* emp)
{
	Statement* stmt = conn->createStatement("SELECT employeenumber, lastname, firstname, email, phone, extension, reportsto, jobtitle, city FROM employees e INNER JOIN offices o ON e.officecode = o.officecode WHERE employeenumber = :1");
	stmt->setInt(1, employeeNumber);
	ResultSet* rs = stmt->executeQuery();

	int result;
	if (!rs->next()) //if the result set is empty
	{
		result = 0;
	}
	else //if the result set is not empty
	{
		result = 1;
		emp->employeeNumber = rs->getInt(1);
		strcpy(emp->lastName, rs->getString(2).data());
		strcpy(emp->firstName, rs->getString(3).data());
		strcpy(emp->email, rs->getString(4).data());
		strcpy(emp->phone, rs->getString(5).data());
		strcpy(emp->extension, rs->getString(6).data());
		strcpy(emp->reportsTo, rs->getString(7).data());
		strcpy(emp->jobTitle, rs->getString(8).data());
		strcpy(emp->city, rs->getString(9).data());
	}
	conn->terminateStatement(stmt);
	return result;
}
void displayEmployee(Connection* conn, struct Employee emp)
{
	cout << "employeeNumber = " << emp.employeeNumber << endl;
	cout << "lastName = " << emp.lastName << endl;
	cout << "firstName = " << emp.firstName << endl;
	cout << "email = " << emp.email << endl;
	cout << "phone = " << emp.phone << endl;
	cout << "extension = " << emp.extension << endl;
	cout << "reportsTo = " << emp.reportsTo << endl;
	cout << "jobTitle = " << emp.jobTitle << endl;
	cout << "city = " << emp.city << endl;
}
void displayAllEmployees(Connection* conn)
{
	Statement* stmt = conn->createStatement("SELECT e.employeenumber, e.firstname, e.lastname, e.email, o.phone, e.extension, t.firstname, t.lastname FROM employees e INNER JOIN offices o ON e.officecode = o.officecode LEFT OUTER JOIN employees t ON e.reportsto = t.employeenumber ORDER BY e.employeenumber");
	ResultSet* rs = stmt->executeQuery();

	if (!rs->next()) //if the result is empty
	{
		cout << "There is no employees¡¯ information to be displayed." << endl;
	}
	else //if the result set is not empty
	{
		cout << left << setw(7) << "E" << left << setw(25) << "Employee Name " << left << setw(38) << "Email" << left << setw(21) << "Phone"
			<< left << setw(11) << "Ext" << left << setw(20) << "Manager" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
		do
		{
			int number = rs->getInt(1);
			string name = rs->getString(2) + " " + rs->getString(3);
			string email = rs->getString(4);
			string phone = rs->getString(5);
			string extension = rs->getString(6);
			string manager = rs->getString(7) + " " + rs->getString(8);

			cout << left << setw(7) << number << left << setw(25) << name << left << setw(38) << email << left << setw(21) << phone
				<< left << setw(11) << extension << left << setw(20) << manager << endl;
		} while (rs->next()); //if there is more rows, iterate
	}
	conn->terminateStatement(stmt);
}
void insertEmployee(Connection* conn, struct Employee emp)
{
	if (findEmployee(conn, emp.employeeNumber, &emp))
	{
		cout << "An employee with the same employee number exists." << endl;
	}
	else
	{
		Statement* stmt = conn->createStatement();
		stmt->setSQL("INSERT INTO employees VALUES (:1,:2,:3,:4,:5,:6,:7,:8) ");
		stmt->setInt(1, emp.employeeNumber);
		stmt->setString(2, emp.lastName);
		stmt->setString(3, emp.firstName);
		stmt->setString(4, emp.extension);
		stmt->setString(5, emp.email);
		stmt->setString(6, "1");
		stmt->setInt(7, 1002);
		stmt->setString(8, emp.jobTitle);
		stmt->executeUpdate();

		cout << "The new employee is added successfully." << endl;
		conn->terminateStatement(stmt);
	}

}
void updateEmployee(Connection* conn, int employeeNumber)
{
	Employee emp;
	if (findEmployee(conn, employeeNumber, &emp))
	{
		string newExtension;
		cout << "Enter the new phone extension: ";
		cin >> newExtension;

		Statement* stmt = conn->createStatement();
		stmt->setSQL("UPDATE employees SET extension = :1 WHERE employeenumber = :2");
		stmt->setString(1, newExtension);
		stmt->setInt(2, employeeNumber);
		stmt->executeUpdate();

		cout << "The employee is updated." << endl;

		conn->terminateStatement(stmt);
	}
	else
	{
		cout << "An employee with the given employee number does not exist." << endl;
	}
}
void deleteEmployee(Connection* conn, int employeeNumber)
{
	Employee emp;
	if (findEmployee(conn, employeeNumber, &emp))
	{
		Statement* stmt = conn->createStatement();
		stmt->setSQL("DELETE FROM employees WHERE employeenumber = :1");
		stmt->setInt(1, employeeNumber);
		stmt->executeUpdate();

		cout << "The employee is deleted." << endl;

		conn->terminateStatement(stmt);
	}
	else
	{
		cout << "The employee does not exist." << endl;
	}
}
int main(void)
{
	// OCCI Variables
	Environment* env = nullptr;
	Connection* conn = nullptr;
	// User Variables
	string str;
	string usr = "dbs211_202d13";
	string pass = "23734230";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		//cout << "Connection is Successful!" << endl;

		int selection;
		int eNumber;
		do
		{
			selection = menu();

			switch (selection)
			{
			case 1:
				cout << "Enter the Employee Number: ";
				cin >> eNumber;
				cout << endl;

				Employee emp;
				if (findEmployee(conn, eNumber, &emp))
				{
					displayEmployee(conn, emp);
				}
				else
				{
					cout << "Employee " << eNumber << " does not exist." << endl;
				}
				cout << endl;

				break;
			case 2:
				cout << endl;
				displayAllEmployees(conn);
				cout << endl;

				break;
			case 3:
				Employee newEmp;

				cout << endl;
				cout << "Employee Number: ";
				cin >> newEmp.employeeNumber;
				cin.ignore();
				cout << "Last Name: ";
				cin.getline(newEmp.lastName, 50);
				cout << "First Name: ";
				cin.getline(newEmp.firstName, 50);
				cout << "Email: ";
				cin.getline(newEmp.email, 100);
				cout << "extension: ";
				cin.getline(newEmp.extension, 10);
				cout << "Job Title: ";
				cin.getline(newEmp.jobTitle, 50);

				cout << endl;
				insertEmployee(conn, newEmp);
				cout << endl;

				break;
			case 4:
				cout << endl;
				cout << "Enter the Employee Number: ";
				cin >> eNumber;

				updateEmployee(conn, eNumber);
				cout << endl;

				break;
			case 5:
				cout << endl;
				cout << "Enter the Employee Number: ";
				cin >> eNumber;

				deleteEmployee(conn, eNumber);
				cout << endl;

				break;
			}
		} while (selection != 6);


		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp)
	{
		cout << "error";
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}