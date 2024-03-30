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
	void dashboard();
	void list();
	void AddItem();
	void EditItem();
	void removeItem();
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
	
	int choice;
	
		do{
		cout << endl;
		cout << "  +---------------------------------------------------+" << endl;
		cout << "  |              Payroll Management System            |" << endl;
		cout << "  +---------------------+-----------------------------+" << endl;
		cout << "  |        Menu         |    Welcome Administrator!   |" << endl;
		cout << "  |---------------------+-----------------------------+" << endl;
		cout << "  | [1] - Dashboard     | [3] -                       |" << endl;        
		cout << "  | [2] - Employee List | [0] - Logout                |" << endl;
		cout << "  +---------------------+-----------------------------" << endl;
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
		}
		
		
	} while(choice != 0);
}


void Admin::dashboard(){
	
		system("cls"); 
		int totalEmployee, choice;
		fstream data;
		
		data.open("database.txt");
		
		data >> id >> fname >> lname >> payHour >> totalHour;
		
		while(data){
			
			totalEmployee = id;
			
			data >> id >> fname >> lname >> payHour >> totalHour;
		}
	
	
		cout << "  +--------------------------------+" << endl;
		cout << "  |           Dashboard            |" << endl;
		cout << "  +--------------------------------+" << endl;
		cout << "  |      Total Employee: " << totalEmployee <<  "         |" << endl;
		cout << "  |      Total Admin:   1          |" << endl;
		cout << "  +--------------------------------+" << endl;
		
		cout << "  +-----------------------------------+" << endl;
		cout << "  |             OPTIONS               |" << endl;
		cout << "  +-----------------------------------+" << endl;
		cout << "  |    [1] - Employee List            |" << endl;
		cout << "  |    [0] - Back to Main Menu        |" << endl;
		cout << "  +-----------------------------------+" << endl;
		
		cout << "  Select Option: ";
		cin >> choice;
		
		switch(choice){
			case 1:
		 	list();
			break;
			case 0:
			home();
			break;
		}
		
}

void Admin::list(){
	
	int totalSalary, choice;
	
	system("cls");
	
	fstream data;
	
	data.open("database.txt");
	
	data >> id >> fname >> lname >> payHour >> totalHour;
		
	cout << "  +-----------------------------------------------------------------------+" << endl;
	cout << "  |                              EMPLOYEE LIST                            |" << endl;
	cout << "  +------+------------+-----------+----------+-------------+--------------+" << endl;
	cout << "  |  ID  | First Name | Last Name | pay/hour |  total hrs  | TOTAL SALARY |"<< endl;
	cout << "  +------+------------+-----------+----------+-------------+--------------+" << endl;
	
	if(data.is_open()){
		while(data){
		
		totalSalary = payHour * totalHour;
		
		cout << "  |   " << id << "\t    " << fname << "\t" << lname << "\t       " << payHour << "\t   " << totalHour;
		cout << "\t        " << totalSalary << "      |" << endl;
		
		data >> id >> fname >> lname >> payHour >> totalHour;
		}
	} else {
		cout << "database not found!";
	}
		cout << "  +-----------------------------------------------------------------------+" << endl;
		
		
	cout << "  +-----------------------------------+" << endl;
	cout << "  |             OPTIONS               |" << endl;
	cout << "  +-----------------------------------+" << endl;
	cout << "  |    [1] - ADD Employee             |" << endl;
	cout << "  |    [2] - EDIT Employee            |" << endl;
	cout << "  |    [3] - DELETE Employee          |" << endl;
	cout << "  |    [0] - Back to Main Menu        |" << endl;
	cout << "  +-----------------------------------+" << endl;
	
	cout << "  Select Option: ";
	cin >> choice;
	
	
	
	switch(choice){
		case 1:
		cout << "Add employee";
		break;
		case 2:
		cout << "Edit employee";
		break;
		case 3:
		cout << "Delete employee";
		break;
		case 0:
			system("cls");
			home();
		break;
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

