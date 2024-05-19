#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class PayrollAdmin {
private:
	int payrollId;
	string payrollFrom;
	string payrollTo;
	string fname;
	string lname;
	int payHour;
	int totalHour;
	string attendance;
	int timeIn, timeOut;

public:
	void home();
	void payslip();
	void dashboard();
	void list();
	void employeeAttendance();
	void employeeTimeIn();
	void employeeTimeOut();
	void searchEmployee();
	void searchById();
	void searchByFname();
	void searchByLname();
	void addEmployee();
	void editEmployee();
	void removeEmployee();
	void logout();
};

class EmployeePortal {
private:
	string employeeUsername;
	int timeIn, timeOut;
	string employeePass;
	int employeeId;
	int id;
	string fname;
	string lname;
	int payHour;
	int totalHour;


public:
	void employeeLogin();
	void employeeHome();
	void employeeInfo();
	void employeePayslip();
	void employeeTotalHour();
	void employeeLogout();
};


void login(){

	string email, password;
	PayrollAdmin myObj;
	char pass;

		cout << "  +======================+" << endl;
		cout << "  |      Admin Login     |" << endl;
		cout << "  +======================+" << endl;
		cout << "  Enter Your Email: ";
		cin >> email;
		cout << "  Enter Your Password: ";


		 while ((pass = _getch()) != '\r') {
            if (pass == '\b') {
                if (!password.empty()) {
                    cout << "\b \b";
                    password.pop_back();
                }
            } else {
                cout << '*';
                password.push_back(pass);
            }
        }


		if(email == "admin" && password == "admin"){
			system("cls");
			myObj.home();
		} else {
			system("cls");
			cout << "  +======================+" << endl;
			cout << "  |    INVALID LOGIN     |" << endl;
			cout << "  +======================+" << endl;
			login();
		}

}

int main(){

	int choice;

	EmployeePortal myObj;

		do{

			cout << " *                      *            ____*                   *  _  _                            *    " << endl;
			cout << "    *                               |  _  | ___  _ _  ___  ___ | || |  *                             " << endl;
			cout << "          *            *            |   __|| .'|| | ||  _|| . || || |             *                 *" << endl;
			cout << "                               *    |__|   |__,||_  ||_|  |___||_||_|                                " << endl;
			cout << "                                            *   |___|                                 *              " << endl;
			cout << "         *                   _____                                            _                      " << endl;
			cout << "                           |     | ___  ___  ___  ___  ___  _____  ___  ___ | |_                     " << endl;
			cout << "                           | | | || .'||   || .'|| . || -_||     || -_||   ||  _|    *               " << endl;
			cout << "               *           |_|_|_||__,||_|_||__,||_  ||___||_|_|_||___||_|_||_|                     *" << endl;
			cout << "                          *                      |___|                                        *      " << endl;
			cout << "                 *                    _____            _                     *                       " << endl;
			cout << "  *                                  |   __| _ _  ___ | |_  ___  _____ *                             " << endl;
			cout << "           *                         |__   || | ||_ -||  _|| -_||     |                              " << endl;
			cout << "                                 *   |_____||_  ||___||_|  |___||_|_|_|*                             " << endl;
			cout << "                                            |___|                                             *      " << endl;

			cout << endl;
			cout << "  +===========================+                                               Developers:" << endl;
			cout << "  |         OPTIONS           |                                               Gomer Gaufo JR." << endl;
			cout << "  +===========================+                                               John Kenneth Nacion" << endl;
			cout << "  | [1] - Admin Login         |                                               Reymond Vinas" << endl;
			cout << "  | [2] - Employee Portal     |                                               Mico Andes" << endl;
			cout << "  | [0] - Exit                |                                               Clark Balane" << endl;
			cout << "  +===========================+" << endl;
			cout << "  Select Option: ";
			cin >> choice;

			switch(choice){
			case 1:
				system("cls");
				login();
			break;
			case 2:
				system("cls");
				myObj.employeeLogin();
			break;
			case 0:
				exit(0);
			break;
			}

			system("cls");
			cout << "  +======================+" << endl;
			cout << "  |     ERROR CHOICE     |" << endl;
			cout << "  +======================+" << endl;

		} while(choice != 0);

	return 0;

}

void PayrollAdmin::home(){

	system("cls");

	int choice;

		do{
		cout << endl;
		cout << "  +===================================================+" << endl;
		cout << "  |              Payroll Management System            |" << endl;
		cout << "  +=====================+=============================+" << endl;
		cout << "  |        Menu         |    Welcome Administrator!   |" << endl;
		cout << "  +=====================+=============================+" << endl;
		cout << "  | [1] - Dashboard     | [0] - Logout                |" << endl;
		cout << "  | [2] - Employees     |                             |" << endl;
		cout << "  +=====================+=============================+" << endl;

		cout << "  Select Option: ";
		cin >> choice;

		switch(choice){
			case 1:
				system("cls");
			 	dashboard();
			break;
			case 2:
				system("cls");
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

void PayrollAdmin::dashboard(){

		system("cls");
		int choice;
		int totalEmployee = 0;
		fstream data;

		data.open("employees.txt");

			data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

		while(data){

                totalEmployee++;

			data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

		}

		data.close();


		cout << "  +================================+" << endl;
		cout << "  |           Dashboard            |" << endl;
		cout << "  +================================+" << endl;
		cout << "  |      Total Employee(s): " << totalEmployee <<  "      |" << endl;
		cout << "  |      Total Admin: 1            |" << endl;
		cout << "  +================================+" << endl;

		cout << "  +===============================+" << endl;
		cout << "  |             OPTIONS           |" << endl;
		cout << "  +===============================+" << endl;
		cout << "  |    [1] - Employees            |" << endl;
		cout << "  |    [0] - Back to Main Menu    |" << endl;
		cout << "  +===============================+" << endl;

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

void PayrollAdmin::payslip(){

	int employeeId, choice;
	int id = 0;
	int grossPay, totalSalary, tax, sss, philHealth, pagIbig;

	cout << "  +=======================================+" << endl;
	cout << "  |          Employee's Payslip'          |" << endl;
	cout << "  +=======================================+" << endl;

	cout << "  Enter emplyee's ID: ";
	cin >> employeeId;

	fstream data;

	data.open("employees.txt");

	data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

	while(!data.eof()){

            id++;

		if(employeeId == id){

			system("cls");

			grossPay = payHour * totalHour;

			sss = 0.03 * grossPay;

			philHealth = 0.02 * grossPay;

			pagIbig = 0.02 * grossPay;

			totalSalary = grossPay - (sss + philHealth + pagIbig);

			cout << endl;
			cout << "  +===================================+" << endl;
			cout << "       " << fname << "'s Payslip       " << endl;
			cout << "  +===================================+" << endl;

			cout << "  Gross pay: PHP"  << grossPay << endl;
			cout << endl;
			cout << "  SSS (3%): PHP" << sss << endl;
			cout << endl;
			cout << "  PhilHealth (2%): PHP" << philHealth << endl;
			cout << endl;
			cout << "  Pag-ibig (2%): PHP" << pagIbig << endl;
			cout << endl;
			cout << "  +===================================+" << endl;
			cout << "      Total Salary: PHP" << totalSalary <<  "  " << endl;
			cout << "  +===================================+" << endl;
			cout << endl << endl;

			data.close();

			cout << "  +===================================+" << endl;
			cout << "  |             OPTIONS               |" << endl;
			cout << "  +===================================+" << endl;
			cout << "  |    [1] - Employees                |" << endl;
			cout << "  |    [0] - Back to Main Menu        |" << endl;
			cout << "  +===================================+" << endl;

			cout << "  Select Option: ";
			cin >> choice;

			switch(choice){
				case 1:
					system("cls");
					list();
				break;
				case 0:
				 	home();
				break;
				default:
					system("cls");
					list();
				break;
			}

		} else {
			data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		}

	}

    system("cls");
    cout << "  +===============================+" << endl;
    cout << "  |      Employee Not Found       |" << endl;
    cout << "  +===============================+" << endl;
	list();

}

void PayrollAdmin::list(){

	int choice;
    int id = 0;
	fstream data;

	data.open("employees.txt");

	data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

	cout << "  +========================================================+" << endl;
	cout << "  |                     EMPLOYEE LIST                      |" << endl;
	cout << "  +======+============+===========+==========+=============+" << endl;
	cout << "  |  ID  | First Name | Last Name | pay/hour |  total hrs  |"<< endl;
	cout << "  +======+============+===========+==========+=============+" << endl;

	if(data.is_open()){

		while(!data.eof()){

            id++;

			cout << "     " << id << "\t    " << fname << "\t" << lname << "\t     PHP" << payHour << "\t  " << totalHour;
			cout << " hr(s)" << endl;

			data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

		}

		data.close();
	} else {
		cout << "database not found!";
	}
	cout << "  +========================================================+" << endl;



	cout << "  +===================================+" << endl;
	cout << "  |             OPTIONS               |" << endl;
	cout << "  +===================================+" << endl;
	cout << "  |    [1] - Employee Payslip         |" << endl;
	cout << "  |    [2] - Employee Attendance      |" << endl;
    cout << "  |    [3] - Search Employee          |" << endl;
	cout << "  |    [4] - ADD Employee             |" << endl;
	cout << "  |    [5] - EDIT Employee            |" << endl;
	cout << "  |    [6] - DELETE Employee          |" << endl;
	cout << "  |    [0] - Back to Main Menu        |" << endl;
	cout << "  +===================================+" << endl;

	cout << "  Select Option: ";
	cin >> choice;



	switch(choice){
		case 1:
			payslip();
		break;
		case 2:
			employeeAttendance();
		break;
		case 3:
            searchEmployee();
		break;
		case 4:
			addEmployee();
		break;
		case 5:
		 	editEmployee();
		break;
		case 6:
		 	removeEmployee();
		break;
		case 0:
			system("cls");
			home();
		break;
		default:
			system("cls");
			list();
	}

}

void PayrollAdmin::employeeAttendance() {

    int choice, emIn, emOut;
    string timeChoose;

    cout << "  +====================================================+" << endl;
    cout << "  |                EMPLOYEE ATTENDANCE                 |" << endl;
    cout << "  +------------------------+===========================+" << endl;
	cout << "  | [1] - TIME IN          | [0] - Back to Main Menu   |" << endl;
	cout << "  | [2] - TIME OUT         |                           |" << endl;
	cout << "  +========================+===========================+" << endl;
	cout << "  Select Option: ";
	cin >> choice;

	switch(choice){
		case 1:
			employeeTimeIn();
		break;
		case 2:
			employeeTimeOut();
		break;
		case 0:
			system("cls");
			home();
		break;
		default:
			system("cls");
			employeeAttendance();
	}

}

void PayrollAdmin::employeeTimeIn(){

	int employeeId, emIn;
	string timeChoice;
	bool validTime = false;
	int id = 0;

	cout << "  +==========================+" << endl;
	cout << "  |         TIME IN          |" << endl;
	cout << "  +==========================+" << endl;
	cout << "  Enter employee's ID: ";
    cin >> employeeId;

    fstream data, data2;

    data.open("employees.txt");
    data2.open("employees2.txt", ios::app | ios::out);

    data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

    while(data){

        id++;

    	if(employeeId == id){

    		if(timeIn == 0){

                do{
                    cout << "  Employee time In [1-12]: ";
                    cin >> emIn;

                } while(emIn > 12 || emIn < 1);

                while(!validTime){

                    cout << "  [AM or PM]: ";
                    cin >> timeChoice;

                    if(timeChoice == "PM" || timeChoice == "pm" || timeChoice == "AM" || timeChoice == "am"){
                        validTime = true;
                    } else {
                        cout << "  Invalid time input" << endl;
                    }

                }


        		if (timeChoice == "PM") {
            		emIn += 12;
        		}

        		data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << emIn << " " << timeOut << endl;

        		system("cls");

        		cout << "  +=============================================================+  " << endl;
				cout << "      SUCCESSFULLY ADDED TIME IN ATTENDANCE FOR " << fname << "   " << endl;
				cout << "  +=============================================================+  " << endl;

			} else {

				system("cls");

				cout << "  +==========================================================+  " << endl;
				cout << "  |    TIME IN ATTENDANCE ALREADY ADDED FOR THIS EMPLOYEE    |  " << endl;
				cout << "  +==========================================================+  " << endl;

				data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << endl;

			}

		} else {
			data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << endl;
		}

		data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

	}

	    data.close();
		data2.close();


		remove("employees.txt");
		rename("employees2.txt", "employees.txt");

		list();

}

void PayrollAdmin::employeeTimeOut(){

    int employeeId, emOut, newTotalHour;
    int id = 0;
	string timeChoice;

	cout << "  +==========================+" << endl;
	cout << "  |         TIME OUT         |" << endl;
	cout << "  +==========================+" << endl;
	cout << "  Enter employee's ID: ";
    cin >> employeeId;

    fstream data, data2;

    data.open("employees.txt");
    data2.open("employees2.txt", ios::app | ios::out);

    data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

    while(data){

        id++;
        bool validTime = false;

    	if(employeeId == id){

    		if(timeIn == 0){

    			system("cls");

    			cout << "  +===========================================================+  " << endl;
				cout << "  |     YOU NEED TO ADD TIME IN FIRST FOR THIS EMPLOYEE!      |  " << endl;
    			cout << "  +===========================================================+  " << endl;

				data.close();
				data2.close();

				remove("employees2.txt");

				list();

			} else {

				if(timeOut == 0){

	        		do{

                        cout << "  Employee time Out [1-12]: ";
                        cin >> emOut;

	        		} while(emOut > 12 || emOut < 1);

                while(!validTime){

                    cout << "  [AM or PM]: ";
                    cin >> timeChoice;

                    if(timeChoice == "PM" || timeChoice == "pm" || timeChoice == "AM" || timeChoice == "am"){

                        if (timeChoice == "PM" || timeChoice == "pm") {
                            emOut += 12;
                        }

                        validTime = true;

                    } else {
                        cout << "  Invalid time input" << endl;
                    }

                }

                newTotalHour = emOut - timeIn;

        		data2 << fname << " " << lname << " " << payHour << " " << newTotalHour << " " << timeIn << " " << emOut << endl;

        		system("cls");

    			cout << "  +=============================================================+  " << endl;
				cout << "      SUCCESSFULLY ADDED TIME OUT ATTENDANCE FOR " << fname << "   " << endl;
    			cout << "  +=============================================================+  " << endl;

			} else {

					system("cls");

    				cout << "  +=============================================================+  " << endl;
					cout << "  |    TIME OUT ATTENDANCE ALREADY ADDED FOR THIS EMPLOYEE      |  " << endl;
    				cout << "  +=============================================================+  " << endl;

					data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << endl;

				}

			}


		} else {
			data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << endl;
		}

		data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

	}

	    data.close();
		data2.close();


		remove("employees.txt");
		rename("employees2.txt", "employees.txt");

		list();

}


void PayrollAdmin::addEmployee(){

	cout << "  +==========================+" << endl;
	cout << "  |    Add a new Employee    |" << endl;
	cout << "  +==========================+" << endl;

	cout << "  Enter First Name: ";
	cin >> fname;

	cout << "  Enter Last Name: ";
	cin >> lname;

	cout << "  Enter Pay per Hour: ";
	cin >> payHour;

	fstream data;

	data.open("employees.txt", ios::app | ios::out);

	if(data.is_open()){

		data << fname << " " << lname << " " << payHour << " " << 0 << " " << 0 << " " << 0 << " \n";

		data.close();

	} else {
		cout << "Error with database:(" << endl;
	}


	fstream database;

	database.open("database.txt", ios::app | ios::out);


	if(database.is_open()){

		database << fname << " " << lname << endl;

		database.close();

	}

	system("cls");
	cout << "  +=======================================+" << endl;
	cout << "  |          New Employee Added           |" << endl;
	cout << "  +=======================================+" << endl;
	list();

}

void PayrollAdmin::searchEmployee(){

    int choice;

    cout << "  +============================+" << endl;
	cout << "  |      Search Employee       |" << endl;
	cout << "  +============================+" << endl;

    cout << "  +====================+" << endl;
	cout << "  |     Search By      |" << endl;
    cout << "  +====================+" << endl;
	cout << "  |   [1] ID           |" << endl;
	cout << "  |   [2] First name   |" << endl;
    cout << "  |   [3] Last Name    |" << endl;
    cout << "  |   [0] List         |" << endl;
	cout << "  +====================+" << endl;
    cout << "  Select Option: ";
	cin >> choice;

	switch(choice){
        case 1:
            searchById();
        break;
        case 2:
            searchByFname();
        break;
        case 3:
            searchByFname();
        break;
        case 0:
            system("cls");
            list();
        break;
        default:
            system("cls");
            searchEmployee();
	}

}

void PayrollAdmin::searchById(){

    int id = 0;
    int employeeId;

    fstream data;

    cout << "  +============================+" << endl;
	cout << "  |       Search By ID         |" << endl;
	cout << "  +============================+" << endl;

    cout << "  Enter employee's ID: ";
    cin >> employeeId;

    data.open("employees.txt");
    data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

    while(data){
        id++;
        if(employeeId == id){

            system("cls");
            cout << "  Result: " << endl;
            cout << "  +======+============+===========+==========+=============+" << endl;
            cout << "  |  ID  | First Name | Last Name | pay/hour |  total hrs  |"<< endl;
            cout << "  +======+============+===========+==========+=============+" << endl;
            cout << "     " << id << "\t    " << fname << "\t" << lname << "\t     PHP" << payHour << "\t";
			cout << totalHour << " hr(s)" << endl;

            data.close();
            searchEmployee();

        } else {
            data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
        }
    }

    system("cls");
    cout << "  +===============================+" << endl;
    cout << "  |      Employee Not Found       |" << endl;
    cout << "  +===============================+" << endl;
    list();

}

void PayrollAdmin::searchByFname(){

    int id = 0;
    string employeeFname;

    fstream data;

    cout << "  +============================+" << endl;
	cout << "  |    Search By First Name    |" << endl;
	cout << "  +============================+" << endl;

    cout << "  Enter employee's First Name: ";
    cin >> employeeFname;

    data.open("employees.txt");
    data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

    while(data){
        id++;
        if(fname == employeeFname){

            system("cls");
            cout << "  Result: " << endl;
            cout << "  +======+============+===========+==========+=============+" << endl;
            cout << "  |  ID  | First Name | Last Name | pay/hour |  total hrs  |"<< endl;
            cout << "  +======+============+===========+==========+=============+" << endl;
            cout << "     " << id << "\t    " << fname << "\t" << lname << "\t     PHP" << payHour << "\t";
			cout << totalHour << " hr(s)" << endl;

            data.close();
            searchEmployee();

        } else {
            data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
        }
    }

    system("cls");
    cout << "  +===============================+" << endl;
    cout << "  |      Employee Not Found       |" << endl;
    cout << "  +===============================+" << endl;
    list();


}

void PayrollAdmin::searchByLname(){

    int id = 0;
    string employeeLname;

    fstream data;

    cout << "  +============================+" << endl;
	cout << "  |    Search By Last Name     |" << endl;
	cout << "  +============================+" << endl;

    cout << "  Enter employee's Last Name: ";
    cin >> employeeLname;

    data.open("employees.txt");
    data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

    while(data){
        id++;
        if(lname == employeeLname){

            system("cls");
            cout << "  Result: " << endl;
            cout << "  +======+============+===========+==========+=============+" << endl;
            cout << "  |  ID  | First Name | Last Name | pay/hour |  total hrs  |"<< endl;
            cout << "  +======+============+===========+==========+=============+" << endl;
            cout << "     " << id << "\t    " << fname << "\t" << lname << "\t     PHP" << payHour << "\t";
			cout << totalHour << " hr(s)" << endl;

            data.close();
            searchEmployee();

        } else {
            data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
        }
    }

    system("cls");
    cout << "  +===============================+" << endl;
    cout << "  |      Employee Not Found       |" << endl;
    cout << "  +===============================+" << endl;
    list();

}

void PayrollAdmin::editEmployee(){

	int employeeId, newEmployeeId, newPayHour, newTotalHour, choice;
    int id = 0;
	string newFname, newLname;

	fstream data, data2;

	cout << "  +==========================+" << endl;
	cout << "  |      Modify Employee     |" << endl;
	cout << "  +==========================+" << endl;

    cout << "  +=====================+" << endl;
	cout << "  |   [1] First name    |" << endl;
	cout << "  |   [2] Last name     |" << endl;
    cout << "  |   [3] Pay/Hour      |" << endl;
	cout << "  +=====================+" << endl;
    cout << "  Select Option: ";
	cin >> choice;

    data.open("employees.txt");

    data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

    data2.open("employees2.txt", ios::app | ios::out);

    cout << "  Enter employee's ID: ";
    cin >> employeeId;


	if(choice == 1){

        while(!data.eof()){
            id++;
            if(employeeId == id){

                cout << "  Enter New Fist Name: ";
                cin >> newFname;

                data2 << newFname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << " \n";

                cout << "  +==============================================+" << endl;
                cout << "  |        Successfully Editing First Name       |" << endl;
                cout << "  +==============================================+" << endl;

                data.close();
                data2.close();


                remove("employees.txt");
                rename("employees2.txt", "employees.txt");

                system("cls");
                searchEmployee();

            } else {
                data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << "\n";
            }
                data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
        }

	} else if(choice == 2){

        while(data){
            id++;
            if(employeeId == id){

                cout << "  Enter New Last Name: ";
                cin >> newLname;

                data2 << fname << " " << newLname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << " \n";

                cout << "  +==============================================+" << endl;
                cout << "  |      Successfully Editing Pay per Hour       |" << endl;
                cout << "  +==============================================+" << endl;

                data.close();
                data2.close();


                remove("employees.txt");
                rename("employees2.txt", "employees.txt");

                system("cls");
                list();

            } else {
                data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << "\n";
            }
                data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
        }

	} else if(choice == 3){

        while(data){
            id++;
            if(employeeId == id){

                cout << "  Enter New Pay per Hour: ";
                cin >> newPayHour;

                data2 << fname << " " << lname << " " << newPayHour << " " << totalHour << " " << timeIn << " " << timeOut << " \n";
            } else {
                data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << "\n";
            }
                data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
        }

	} else {
	    system("cls");
        cout << "  +============================+" << endl;
        cout << "  |       Invalid Option       |" << endl;
        cout << "  +============================+" << endl;
        list();
	}




        system("cls");
        cout << "  +============================+" << endl;
        cout << "  |        Invalid Id!         |" << endl;
        cout << "  +============================+" << endl;
        list();


}

void PayrollAdmin::removeEmployee(){

	int employeeId;
    int id = 0;
    int id2 = 0;
	fstream data, data2;

	cout << "  +==========================+" << endl;
	cout << "  |      DELETE Employee     |" << endl;
	cout << "  +==========================+" << endl;

	cout << "  Enter employee's ID: ";
	cin >> employeeId;

	data.open("employees.txt");

		data2.open("employees2.txt", ios::app | ios::out);

		data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

		while(!data.eof()){

                id++;

			if(employeeId == id){

				system("cls");
				cout << "  +==============================================+" << endl;
				cout << "  |        Successfully Removing Employee        |" << endl;
				cout << "  +==============================================+" << endl;

			} else {

				data2 << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << "\n";
			}

			data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

		}

			data.close();
			data2.close();

			remove("employees.txt");
			rename("employees2.txt", "employees.txt");

			fstream database, database2;

			database.open("database.txt");

			database >> fname >> lname;

			database2.open("database2.txt", ios::app | ios::out);

			while(!database.eof()){

                id2++;


				if(employeeId == id2){

					system("cls");
						cout << "  +==============================================+" << endl;
						cout << "  |        Successfully Removing Employee        |" << endl;
						cout << "  +==============================================+" << endl;

				} else {

					database2 << fname << " " << lname << endl;
				}

				database >> fname >> lname;
			}


			database.close();
			database2.close();

			remove("database.txt");
			rename("database2.txt", "database.txt");

			list();


}

void PayrollAdmin::logout(){

	system("cls");

	int choice;

		cout << "  +===================================+" << endl;
		cout << "  |      Successfully logged out!     |" << endl;
		cout << "  +===================================+" << endl;


	main();
}


void EmployeePortal::employeeLogin(){

	fstream data;
	string username, password;
	char pass;
    int id = 0;

		cout << "  +==========================+" << endl;
		cout << "  |     Employee Portal      |" << endl;
		cout << "  +==========================+" << endl;
		cout << "  Enter Your Username (firstname): ";
		cin >> username;
        cout << "  Enter Your Password (lastname): ";

        while ((pass = _getch()) != '\r') {
            if (pass == '\b') {
                if (!password.empty()) {
                    cout << "\b \b";
                    password.pop_back();
                }
            } else {
                cout << '*';
                password.push_back(pass);
            }
        }

		data.open("database.txt");

		data >> employeeUsername >> employeePass;

			while(data){
                id++;
				if(username == employeeUsername){
					if(password == employeePass){

						employeeId = id;
						employeePass = password;

						data.close();
						employeeHome();
					} else {
						system("cls");
						cout << "  +======================+" << endl;
						cout << "  |    INVALID LOGIN     |" << endl;
						cout << "  +======================+" << endl;
						employeeLogin();
					}
				} else {

                    data >> employeeUsername >> employeePass;

				}

			}

				system("cls");

				data.close();
                cout << "  +======================+" << endl;
                cout << "  |      ERROR LOGIN     |" << endl;
                cout << "  +======================+" << endl;
				employeeLogin();


}

void EmployeePortal::employeeHome() {

		system("cls");

		int choice;

		cout << "  +===================================================+" << endl;
		cout << "  |                  Employee PORTAL                  |" << endl;
		cout << "  +=====================+=============================+" << endl;
		cout << "  |        Menu         |    Welcome Employee!        |" << endl;
		cout << "  +=====================+=============================+" << endl;
		cout << "  | [1] - Check Info.   | [0] - Logout                |" << endl;
		cout << "  +=====================+=============================+" << endl;
		cout << "  Select Option: ";
		cin >> choice;

		switch(choice){
			case 1:
				employeeInfo();
			break;
			case 0:
				employeeLogout();
			break;

		}

}

void EmployeePortal::employeeInfo(){
	system("cls");

	int choice;

		cout << "  +===================================+" << endl;
		cout << "  |             OPTION                |" << endl;
		cout << "  +===================================+" << endl;
		cout << "  |    [1] - My Payslip               |" << endl;
		cout << "  |    [2] - Total Work Hour          |" << endl;
		cout << "  |    [0] - Back to Main Menu        |" << endl;
		cout << "  +===================================+" << endl;
		cout << "  Select Option: ";
		cin >> choice;

		switch(choice){
			case 1:
				employeePayslip();
			break;
			case 2:
				employeeTotalHour();
			break;
			default:
				system("cls");
				employeeHome();
			break;
		}

}

void EmployeePortal::employeePayslip() {

	int choice, totalEmployeeHour;
	int grossPay, totalSalary, tax, sss, philHealth, pagIbig;
	int id = 0;

	fstream data;

	data.open("employees.txt");

	data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

	while(data){

        id++;

		if(employeeId == id){

			if(timeIn != 0 && timeOut != 0){

				totalEmployeeHour = timeOut - timeIn;

			} else {

				totalEmployeeHour = totalHour;

			}

			grossPay = payHour * totalEmployeeHour;

			sss = 0.03 * grossPay;

			philHealth = 0.02 * grossPay;

			pagIbig = 0.02 * grossPay;

			totalSalary = grossPay - (sss + philHealth + pagIbig);

			system("cls");

			cout << endl;
			cout << "  +===================================+" << endl;
			cout << "  |           YOUR  PAYSLIP           |" << endl;
			cout << "  +===================================+" << endl;

			cout << "  Gross pay: PHP"  << grossPay << endl;
			cout << endl;
			cout << "  SSS (3%): PHP" << sss << endl;
			cout << endl;
			cout << "  PhilHealth (2%): PHP" << philHealth << endl;
			cout << endl;
			cout << "  Pag-ibig (2%): PHP" << pagIbig << endl;
			cout << endl;
			cout << "  +===================================+" << endl;
			cout << "      Total Salary: PHP" << totalSalary <<  "  " << endl;
			cout << "  +===================================+" << endl;
			cout << endl;

			cout << "  +===================================+" << endl;
			cout << "  |             OPTION                |" << endl;
			cout << "  +===================================+" << endl;
			cout << "  |    [0] - Back to Main Menu        |" << endl;
			cout << "  +===================================+" << endl;

			cout << "  Select Option: ";
			cin >> choice;

			switch(choice){
				case 0:
					employeeHome();
				break;
				default:
					system("cls");
					employeePayslip();
				break;
			}

		} else {
			data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		}

	}

}

void EmployeePortal::employeeTotalHour() {

	system("cls");

	int choice, totalEmployeeHour;
	int id = 0;
	fstream data;

	data.open("employees.txt");

	data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

	while(data){

            id++;

		if(employeeId == id){

			if(timeIn != 0 && timeOut != 0){

				totalEmployeeHour = timeOut - timeIn;

			} else {

				totalEmployeeHour = totalHour;

			}

			cout << "  +===================================+" << endl;
			cout << "  |             TOTAL HOUR            |" << endl;
			cout << "  +===================================+" << endl;
			cout << "     RATE/HOUR: PHP" << payHour<< endl;
			cout << "     TOTAL HOUR: " << totalEmployeeHour << "hr(s)" << endl;

			cout << "  +===================================+" << endl;
			cout << "  |             OPTION                |" << endl;
			cout << "  +===================================+" << endl;
			cout << "  |    [0] - Back to Main Menu        |" << endl;
			cout << "  +===================================+" << endl;

			data.close();

			cout << "  Select Option: ";
			cin >> choice;

			switch(choice){
				case 0:
					employeeHome();
				break;
				default:
					system("cls");
					employeeTotalHour();
				break;
			}

		} else {
			data >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		}
	}

}

void EmployeePortal::employeeLogout() {

	system("cls");

	int choice;

		cout << "  +===================================+" << endl;
		cout << "  |      Successfully logged out!     |" << endl;
		cout << "  +===================================+" << endl;

	main();

}
