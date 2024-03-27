#include <iostream>
#include <fstream>


using namespace std;

class Admin {
	public: 
	void list();
	void home();
	void dashboard();
	
};


void login(){
	string email, password;
	Admin myObj;

		cout << endl << endl;
		cout << "  +---------------------+" << endl;
		cout << "  |     Admin Login     |" << endl;
		cout << "  +---------------------+" << endl;
		cout << "  Email: ";
		cin >> email;
		cout << "  Password: ";
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

int main(){
	
	int choice;
	
	do{
		cout << "  +---------------------------+" << endl;
		cout << "  | Payroll Management System |" << endl;
		cout << "  +---------------------------+" << endl;
		cout << "  |  1 - Admin Login          |" << endl;        
		cout << "  |  0 - Exit                 |" << endl;
		cout << "  +---------------------------+" << endl;
		cout << "  Enter here: ";
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
	
	return 0;
}

void Admin::home(){
	
	int choice;
	
		do{
		cout << "  +---------------------+-----------------------------+" << endl;
		cout << "  | PAYROLL SYSTEM      |    Welcome Administrator!   |" << endl;
		cout << "  |---------------------+-----------------------------+" << endl;
		cout << "  |  1 - Dashboard      |" << endl;        
		cout << "  |  2 - Employee List  |" << endl;
		cout << "  +---------------------+" << endl;
		cout << "  Enter here: ";
		cin >> choice;
		
		switch(choice){
			case 1:
			cout << "Dashboard";
			break;
			case 2:
			list();
			break;
		}
		
		
	} while(choice != 0);
}

void Admin::list(){
	
	system("cls");
	
	string output;
	
	ifstream file("database.txt");	
		
	cout << "  +-----------------------+" << endl;
	cout << "  |     Employee List     |" << endl;
	cout << "  +-----------------------+" << endl;
	cout << "  |First Name | Last Name |" << endl;
	cout << "  +-----------------------+" << endl;
	if(file.is_open()){
		while(getline(file, output)){
			cout << "  |" << output << "\t" << endl;
			cout << "  +-------------------+" << endl;
		}
	}

	
	exit(0);
}

