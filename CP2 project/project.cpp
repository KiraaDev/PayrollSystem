#include <iostream>
#include <fstream>


using namespace std;

class Admin {
private:
	int id;
	string fname;
	string lname;
	int payHour;
	int totalHour;
	
public: 
	void home();
	void payslip();
	void dashboard();
	void list();
	void addEmployee();
	void editEmployee();
	void removeEmployee();
	void logout();
};


void login(){
	system("cls");
	string email, password;
	Admin myObj;

		cout << "  +---------------------+" << endl;
		cout << "  |     Admin Login     |" << endl;
		cout << "  +---------------------+" << endl;
		cout << "  Enter Your Email: ";
		cin >> email;
		cout << "  Enter Your Password: ";
		cin >> password;
		
		if(email == "admin" && password == "admin"){
			system("cls");
			myObj.home();
		} else {
			system("cls");
			cout << endl << endl;
			cout << "  ERROR LOGIN!!!" << endl;
			login();
		}
	
}

void menu(int choice){
	
		do{
			cout << "  +---------------------------+" << endl;
			cout << "  | Payroll Management System |" << endl;
			cout << "  +---------------------------+" << endl;
			cout << "  | [1] - Admin Login         |" << endl;        
			cout << "  | [0] - Exit                |" << endl;
			cout << "  +---------------------------+" << endl;
			cout << "  Select Option: ";
			cin >> choice;
			
			switch(choice){
			case 1:
				login();
			break;
			case 0:
				exit(0);
			break;
			}
			
			system("cls");
			cout << "  !!! Error choice !!! " << endl;
		} while(choice != 0);

		
}

int main(){
	
	int choice;
	
	menu(choice);	

	
	return 0;
	
}

void Admin::home(){
	
	system("cls");
	
	int choice;
	
		do{
		cout << endl;
		cout << "  +---------------------------------------------------+" << endl;
		cout << "  |              Payroll Management System            |" << endl;
		cout << "  +---------------------+-----------------------------+" << endl;
		cout << "  |        Menu         |    Welcome Administrator!   |" << endl;
		cout << "  |---------------------+-----------------------------+" << endl;
		cout << "  | [1] - Dashboard     |" << endl;        
		cout << "  | [2] - Employees     |" << endl;
		cout << "  | [0] - Logout        |" << endl;
		cout << "  +---------------------+" << endl;
		
		cout << "  Select Option: ";
		cin >> choice;
		
		switch(choice){
			case 1:
			 dashboard();
			break;
			case 2:
				list();
			break;
			case 0:
				logout();
			break;
			default:
				home();
		}
		
		
	} while(choice != 0);
}

void Admin::dashboard(){
	
		system("cls"); 
		int totalEmployee, choice;
		fstream data;
		
		data.open("employees.txt");
		
		data >> id >> fname >> lname >> payHour >> totalHour;
		
		while(data){
			
			totalEmployee = id;
			
			data >> id >> fname >> lname >> payHour >> totalHour;
			
		}
		
		data.close();
	
	
		cout << "  +--------------------------------+" << endl;
		cout << "  |           Dashboard            |" << endl;
		cout << "  +--------------------------------+" << endl;
		cout << "  |      Total Employee(s): " << totalEmployee <<  "      |" << endl;
		cout << "  |      Total Admin: 1            |" << endl;
		cout << "  +--------------------------------+" << endl;
		
		cout << "  +-----------------------------------+" << endl;
		cout << "  |             OPTIONS               |" << endl;
		cout << "  +-----------------------------------+" << endl;
		cout << "  |    [1] - Employees                |" << endl;
		cout << "  |    [0] - Back to Main Menu        |" << endl;
		cout << "  +-----------------------------------+" << endl;
		
		cout << "  Select Option: ";
		cin >> choice;
			
			switch(choice){
			case 1:
			system("cls");
		 	list();
			break;
			case 0:
			system("cls");
			home();
			break;
			default:
			 dashboard();		
			}
		

		
}

void Admin::payslip(){
	
	int employeeId, choice;
	int grossPay, totalSalary, tax;
	
	cout << "  +---------------------------------------+" << endl;
	cout << "  |          Employee's Payslip'          |" << endl;
	cout << "  +---------------------------------------+" << endl;
	
	cout << "  Enter emplyee's ID: ";
	cin >> employeeId;
	
	fstream data;
	
	data.open("employees.txt");
	
	data >> id >> fname >> lname >> payHour >> totalHour;
	
	while(!data.eof()){
		
		if(employeeId == id){
			
			system("cls");
			
			grossPay = payHour * totalHour;
			
			tax = 10 * totalHour / 10;
			
			totalSalary = grossPay - tax;
			
			cout << endl;
			cout << "                                                                    " << endl;
			cout << "  |"<< fname << "'s Payslip|" << endl;
			cout << "                                                                    " << endl;
			
			cout << "  Gross pay: $"  << grossPay << endl;
			cout << endl;
			cout << "  Tax : $" << tax << endl;
			cout << endl;
			cout << "  Total Salary: $" << totalSalary << endl;
			cout << endl;
			
			data.close();
			
			cout << "  +-----------------------------------+" << endl;
			cout << "  |             OPTIONS               |" << endl;
			cout << "  +-----------------------------------+" << endl;
			cout << "  |    [1] - Payslip                  |" << endl;
			cout << "  |    [2] - Back to Main Menu        |" << endl;
			cout << "  +-----------------------------------+" << endl;
			
			cout << "  Select Option: ";
			cin >> choice;
				
			switch(choice){
				case 1:
					payslip();
				break;
				case 2:
				 	home();
				break;
			}
			
		} else {
			data >> id >> fname >> lname >> payHour >> totalHour;
		}
		
	}
	
	
	
	
}

void Admin::list(){
	
	int totalSalary, choice;
	
	system("cls");
	
	fstream data;
	
	data.open("employees.txt");
	
	data >> id >> fname >> lname >> payHour >> totalHour;
		
	cout << "  +--------------------------------------------------------+" << endl;
	cout << "  |                              EMPLOYEE LIST             |" << endl;
	cout << "  +------+------------+-----------+----------+-------------+" << endl;
	cout << "  |  ID  | First Name | Last Name | pay/hour |  total hrs  |"<< endl;
	cout << "  +------+------------+-----------+----------+-------------+" << endl;
	
	if(data.is_open()){
		while(data){
		
		cout << "  |   " << id << "\t    " << fname << "\t" << lname << "\t       " << payHour << "\t   " << totalHour;
		cout << "     |" << endl;
		
		data >> id >> fname >> lname >> payHour >> totalHour;
		
		}
		
		data.close();
	} else {
		cout << "database not found!";
	}
		cout << "  +--------------------------------------------------------+" << endl;
		
		
	cout << "  +-----------------------------------+" << endl;
	cout << "  |             OPTIONS               |" << endl;
	cout << "  +-----------------------------------+" << endl;
	cout << "  |    [1] - Employee Payslip         |" << endl;
	cout << "  |    [2] - ADD Employee             |" << endl;
	cout << "  |    [3] - EDIT Employee            |" << endl;
	cout << "  |    [4] - DELETE Employee          |" << endl;
	cout << "  |    [0] - Back to Main Menu        |" << endl;
	cout << "  +-----------------------------------+" << endl;

	cout << "  Select Option: ";
	cin >> choice;
	
	
	
	switch(choice){
		case 1:
			payslip();
		break;
		case 2:
			addEmployee();
		break;
		case 3:
			editEmployee();
		break;
		case 4:
		 	removeEmployee();
		break;
		case 0:
			system("cls");
			home();
		break;
		default:
			list();
		break;
	}	
	
}

void Admin::addEmployee(){
	
	cout << "  +--------------------------+" << endl;
	cout << "  |    Add a new Employee    |" << endl;
	cout << "  +--------------------------+" << endl;
	
	cout << "  Enter Employee ID: ";
	cin >> id;
	
	cout << "  Enter First Name: ";
	cin >> fname;
	
	cout << "  Enter Last Name: ";
	cin >> lname;
	
	cout << "  Enter Pay per Hour: ";
	cin >> payHour;
	
	cout << "  Enter Total Hour: ";
	cin >> totalHour;
	
	fstream data;
	
	data.open("employees.txt", ios::app | ios::out);
	
	if(data.is_open()){
		
		data << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << "\n";
		
		data.close();
		
	} else {
		cout << "Error with database:(" << endl;
	}
	
		
	
	cout << "new employee added!" << endl;
	list();

}

void Admin::editEmployee(){
	
	int employeeId, newEmployeeId, newPayHour, newTotalHour;
	
	string newFname, newLname;
	
	fstream data, data2;
	
	cout << "  +--------------------------+" << endl;
	cout << "  |      Modify Employee     |" << endl;
	cout << "  +--------------------------+" << endl;
	cout << endl;
	
	cout << "  Enter employee's ID: ";
	cin >> employeeId;
	
	
	data.open("employees.txt");
	
	if(!data){
		cout << "Error with database:(" << endl;
	} else {
		
		data2.open("employees2.txt", ios::app | ios::out);
		
		data >> id >> fname >> lname >> payHour >> totalHour;	
		
		while(!data.eof()){
			
			if(employeeId == id){
				
				cout << "  Enter New First Name: ";
				cin >> newFname;
				cout << "  Enter New Last Name: ";
				cin >> newLname;
				cout << "  Enter New Pay per Hour: ";
				cin >> newPayHour;
				cout << "  Enter New Total Hour: ";
				cin >> newTotalHour;												
				
				data2 << id << " " << newFname << " " << newLname << " " << newPayHour << " " << newTotalHour << "\n";
					
				cout << "Item successfully edited";
							
			} else {

				data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << "\n";
			}
			
			data >> id >> fname >> lname >> payHour >> totalHour;

		}
			data.close();	
			data2.close();

		
			remove("employees.txt");
			rename("employees2.txt", "employees.txt");
			
			list();
	}	
	
}

void Admin::removeEmployee(){
	
	int employeeId;
	
	fstream data, data2;
	
	cout << "  +--------------------------+" << endl;
	cout << "  |      Modify Employee     |" << endl;
	cout << "  +--------------------------+" << endl;
	cout << endl;
	
	cout << "  Enter employee's ID: ";
	cin >> employeeId;
	
	data.open("employees.txt");
	
	if(!data){
		cout << "Error with database:(" << endl;
	} else {
		
		data2.open("employees2.txt", ios::app | ios::out);
		
		data >> id >> fname >> lname >> payHour >> totalHour;	
		
		while(!data.eof()){
			
			if(employeeId == id){
				
				cout << "Item successfully removed!";
							
			} else {

				data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << "\n";
			}
			
			data >> id >> fname >> lname >> payHour >> totalHour;

		}
			data.close();	
			data2.close();

		
			remove("employees.txt");
			rename("employees2.txt", "employees.txt");
			
			
			list();
	}
	
}

void Admin::logout(){
	
	system("cls");
	
	int choice;
	
	cout << "  +--------------------------+" << endl;
	cout << "  | Successfully logged out! |" << endl;
	cout << "  +--------------------------+" << endl;
		
		
	menu(choice);
}

