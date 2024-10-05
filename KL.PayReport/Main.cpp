
//Pay Report Assignment - Kristy Lee

#include <iostream>
#include <conio.h>

using namespace std;

struct Employee
{
	int ID;
	string FirstName;
	string LastName;
	float HoursWorked;
	float HourlyRate;
};

void PrintEmployee(Employee* pEmployee)
{
	cout << pEmployee->ID
		<< pEmployee->FirstName
		<< pEmployee->LastName
		<< pEmployee->HoursWorked
		<< pEmployee->HourlyRate << ".\n";
}

//Display the size of the array
void PrintEmployeesHours(int ID, Employee* employees, int size, float HoursWorked, float HourlyRate)
{
	for (int i = 0; i < size; i++)
	{
		if(employees[i].ID >= ID &&
		employees[i].HoursWorked >= HoursWorked &&
		employees[i].HourlyRate >= HourlyRate)
		PrintEmployee(&employees[i]);
	}
}

//Get the employee info
Employee *GetEmployeeInfo(int index)
{
	Employee* pE = new Employee;
	cout << "Enter the ID for Employee " << index + 1 << " : ";
	cin >> pE->ID;
	cout << "Enter the First Name for Employee " << index + 1 << " : ";
	cin >> pE->FirstName;
	cout << "Enter the Last Name for Employee " << index + 1 << " : ";
	cin >> pE->LastName;
	cout << "Enter the Hours Worked for Employee " << index + 1 << " : ";
	cin >> pE->HoursWorked;
	cout << "Enter the Hourly Rate for Employee " << index + 1 << " : ";
	cin >> pE->HourlyRate;
	cout << "\n";
	return pE; 
}

//Calculate the pay report
float CalculatePay(Employee* pE)
{
	return pE->HoursWorked * pE->HourlyRate;
}

//Display the pay report 
void PrintEmployeePay(Employee* pE)
{
	float pay = CalculatePay(pE);
	cout << pE->ID << ". " << pE->FirstName << " " << pE->LastName << ": $" << pay << "\n";
}

int main()
{
	cout << "Enter the number of employees: ";
	int size = 0;
	cin >> size;
	cout << "\n";

	//Create the array
	Employee* employees = new Employee[size];
	for (int i = 0; i < size; i++)
	{
		employees[i] = *GetEmployeeInfo(i);
	}

	//Display the employee
	PrintEmployeesHours;

	//Display the weekly pay for employee
	cout << "Pay Report \n" << "---------- \n"; 
	float totalPay = 0;
	
	for (int i = 0; i < size; i++)
	{
		PrintEmployeePay(&employees[i]);
		totalPay += CalculatePay(&employees[i]);
	}

	cout << "\n" << "Total Pay: $ " << totalPay << "\n";


	(void)_getch();
	return 0; 
}