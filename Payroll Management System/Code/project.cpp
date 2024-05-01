#include <iostream>
#include <fstream>


using namespace std;

class PayrollAdmin {
private:
	int payrollId;
	string payrollFrom;
	string payrollTo;
	int id;
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
	void addEmployee();
	void editEmployee();
	void removeEmployee();
	void logout();
};

class EmployeePortal {
private:
	int employeeId;
	int timeIn, timeOut;
	string employeePass;
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

		cout << "  +======================+" << endl;
		cout << "  |      Admin Login     |" << endl;
		cout << "  +======================+" << endl;
		cout << "  Enter Your Email: ";
		cin >> email;
		cout << "  Enter Your Password: ";
		cin >> password;
		
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
		int totalEmployee, choice;
		fstream data;
		
		data.open("employees.txt");
		
			data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		
		while(data){
			
			totalEmployee = id;
			
			data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
			
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
	
	int employeeId, choice, totalEmployeeHour;
	int grossPay, totalSalary, tax, sss, philHealth, pagIbig;
	
	cout << "  +=======================================+" << endl;
	cout << "  |          Employee's Payslip'          |" << endl;
	cout << "  +=======================================+" << endl;
	
	cout << "  Enter emplyee's ID: ";
	cin >> employeeId;
	
	fstream data;
	
	data.open("employees.txt");
	
	data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
	
	while(!data.eof()){
		
		if(employeeId == id){
			
			if(timeIn != 0 && timeOut != 0){
				totalEmployeeHour = timeOut - timeIn;			
			} else {
				totalEmployeeHour = totalHour;	
			}
			
			system("cls");
			
			grossPay = payHour * totalEmployeeHour;
			
			sss = 0.03 * grossPay;
			
			philHealth = 0.02 * grossPay;
			
			pagIbig = 0.02 * grossPay;
			
			totalSalary = (sss + philHealth + pagIbig) - grossPay;
			
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
			data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		}
		
	}
	
	list();
		
}

void PayrollAdmin::list(){
	
	int choice, totalEmployeeHour;
	
	fstream data;
	
	data.open("employees.txt");
	
	data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		
	cout << "  +========================================================+" << endl;
	cout << "  |                     EMPLOYEE LIST                      |" << endl;
	cout << "  +======+============+===========+==========+=============+" << endl;
	cout << "  |  ID  | First Name | Last Name | pay/hour |  total hrs  |"<< endl;
	cout << "  +======+============+===========+==========+=============+" << endl;
	
	if(data.is_open()){
		
		while(!data.eof()){
			
			if(timeIn != 0 && timeOut != 0){
				totalEmployeeHour = timeOut - timeIn;			
			} else {
				totalEmployeeHour = totalHour;	
			}
		
			cout << "     " << id << "\t    " << fname << "\t" << lname << "\t     PHP" << payHour << "\t  " << totalEmployeeHour;
			cout << " hr(s)" << endl;
		
			data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		
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
	cout << "  |    [3] - ADD Employee             |" << endl;
	cout << "  |    [4] - EDIT Employee            |" << endl;
	cout << "  |    [5] - DELETE Employee          |" << endl;
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
			addEmployee();
		break;
		case 4:
		 	editEmployee();
		break;
		case 5:
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
	
    int choice, employeeId, emIn, emOut;
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
	
	cout << "  +==========================+" << endl;
	cout << "  |         TIME IN          |" << endl;
	cout << "  +==========================+" << endl;
	cout << "  Enter employee's ID: ";
    cin >> employeeId;
    
    fstream data, data2;

    data.open("employees.txt");
    data2.open("employees2.txt", ios::app | ios::out);

    data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
    
    while(data){
    	
    	if(employeeId == id){
    		
    		if(timeIn == 0){
    			
    			cout << "  Employee time In: ";
        		cin >> emIn;
        		
        		cout << "  [AM or PM]: ";
        		cin >> timeChoice;

        		if (timeChoice == "PM" || timeChoice == "pm") {
            		emIn += 12;
        		} else if(timeChoice == "AM" || timeChoice == "am"){
        			
				} else{
        			cout << "  Please Choose Again" << endl;
        			cout << "  [AM or PM]: ";
        			cin >> timeChoice;
				}
        		
        		data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << " " << emIn << " " << timeOut << endl;
        		
        		system("cls");
        		
        		cout << "  +=============================================================+  " << endl;
				cout << "      SUCCESSFULLY ADDED TIME IN ATTENDANCE FOR " << fname << "   " << endl;
				cout << "  +=============================================================+  " << endl;
        		
			} else {
				
				system("cls");
				
				cout << "  +==========================================================+  " << endl;
				cout << "  |    TIME IN ATTENDANCE ALREADY ADDED FOR THIS EMPLOYEE    |  " << endl;
				cout << "  +==========================================================+  " << endl;
				
				data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << endl;
				
			}
		
		} else {
			data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << endl;
		}
	
		data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		
	}
	
	    data.close();	
		data2.close();
		
		
		remove("employees.txt");
		rename("employees2.txt", "employees.txt");
	
		list();
	
}

void PayrollAdmin::employeeTimeOut(){
	
		int employeeId, emOut;
	string timeChoice;
	
	cout << "  +==========================+" << endl;
	cout << "  |         TIME OUT         |" << endl;
	cout << "  +==========================+" << endl;
	cout << "  Enter employee's ID: ";
    cin >> employeeId;
    
    fstream data, data2;

    data.open("employees.txt");
    data2.open("employees2.txt", ios::app | ios::out);

    data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
    
    while(data){
    	
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
    			
	    			cout << "  Employee time Out: ";
	        		cin >> emOut;
	        		
	        		cout << "  [AM or PM]: ";
	        		cin >> timeChoice;

	        		if (timeChoice == "PM" || timeChoice == "pm") {
	            		emOut += 12;
	        		} else if(timeChoice == "AM" || timeChoice == "am"){
        			
					} else{
	        			cout << "  Please Choose Again" << endl;
	        			cout << "  [AM or PM]: ";
	        			cin >> timeChoice;
	        			
				}
        		
        		data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << emOut << endl;
        		
        		system("cls");
        		
    			cout << "  +=============================================================+  " << endl;
				cout << "      SUCCESSFULLY ADDED TIME OUT ATTENDANCE FOR " << fname << "   " << endl;
    			cout << "  +=============================================================+  " << endl;
        		
			} else {
				
					system("cls");
					
    				cout << "  +=============================================================+  " << endl;
					cout << "  |    TIME OUT ATTENDANCE ALREADY ADDED FOR THIS EMPLOYEE      |  " << endl;
    				cout << "  +=============================================================+  " << endl;
					
					data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << endl;
				
				}
				
			}
    		
		
		} else {
			data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << endl;
		}
	
		data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		
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
	
	cout << "  Enter Employee ID: ";
	cin >> id;
	
	cout << "  Enter First Name: ";
	cin >> fname;
	
	cout << "  Enter Last Name: ";
	cin >> lname;
	
	cout << "  Enter Pay per Hour: ";
	cin >> payHour;
	
	fstream data;
	
	data.open("employees.txt", ios::app | ios::out);
	
	if(data.is_open()){
		
		data << id << " " << fname << " " << lname << " " << payHour << " " << 0 << " " << 0 << " " << 0 << " \n";
		
		data.close();
		
	} else {
		cout << "Error with database:(" << endl;
	}
	
	
	fstream database;
	
	database.open("database.txt", ios::app | ios::out);
	
	
	if(database.is_open()){
		 
		database << id << " " << fname << endl;
		
		database.close();
		
	}
	
	system("cls");
	cout << "  +=======================================+" << endl;
	cout << "  |          New Employee Added           |" << endl;
	cout << "  +=======================================+" << endl;
	list();

}

void PayrollAdmin::editEmployee(){
	
	int employeeId, newEmployeeId, newPayHour, newTotalHour;
	
	string newFname, newLname;
	
	fstream data, data2;
	
	cout << "  +==========================+" << endl;
	cout << "  |      Modify Employee     |" << endl;
	cout << "  +==========================+" << endl;
	cout << endl;
	
	cout << "  Enter employee's ID: ";
	cin >> employeeId;
	
	
	data.open("employees.txt");
	
	if(!data){
		cout << "Error with database:(" << endl;
	}
		
		data2.open("employees2.txt", ios::app | ios::out);
		
		data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		
		while(!data.eof()){
			
			if(employeeId == id){
				
				cout << "  Enter New First Name: ";
				cin >> newFname;
				cout << "  Enter New Last Name: ";
				cin >> newLname;
				cout << "  Enter New Pay per Hour: ";
				cin >> newPayHour;												
				
				data2 << id << " " << newFname << " " << newLname << " " << newPayHour << " " << totalHour << " " << timeIn << " " << timeOut << "\n";
					
				system("cls");
				
					cout << "  +==============================================+" << endl;
					cout << "  |        Successfully Editing Employee         |" << endl;
					cout << "  +==============================================+" << endl;
							
			} else {

				data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << "\n";
			}
			
			data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

		}
			data.close();	
			data2.close();

		
			remove("employees.txt");
			rename("employees2.txt", "employees.txt");
			
			system("cls");
			list();
	
}

void PayrollAdmin::removeEmployee(){
	
	int employeeId;
	
	fstream data, data2;
	
	cout << "  +==========================+" << endl;
	cout << "  |      DELETE Employee     |" << endl;
	cout << "  +==========================+" << endl;
	cout << endl;
	
	cout << "  Enter employee's ID: ";
	cin >> employeeId;
	
	data.open("employees.txt");
		
		data2.open("employees2.txt", ios::app | ios::out);
		
		data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		
		while(!data.eof()){
			
			if(employeeId == id){ 
				
				system("cls");
				cout << "  +==============================================+" << endl;
				cout << "  |        Successfully Removing Employee        |" << endl;
				cout << "  +==============================================+" << endl;
							
			} else {

				data2 << id << " " << fname << " " << lname << " " << payHour << " " << totalHour << " " << timeIn << " " << timeOut << "\n";
			}
			
			data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;

		}
		
			data.close();	
			data2.close();
		
			remove("employees.txt");
			rename("employees2.txt", "employees.txt");
			
			fstream database, database2;
			
			database.open("database.txt");
			
			database >> id >> fname;
			
			database2.open("database2.txt", ios::app | ios::out);
			
			while(!database.eof()){
				
				if(employeeId == id){
					
					system("cls");
						cout << "  +==============================================+" << endl;
						cout << "  |        Successfully Removing Employee        |" << endl;
						cout << "  +==============================================+" << endl;
									
				} else {
					
					database2 << id << " " << fname << endl;
				}
				
				database >> id >> fname;
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
	
	int id;
	string password;

		cout << "  +==========================+" << endl;
		cout << "  |     Employee Portal      |" << endl;
		cout << "  +==========================+" << endl;
		cout << "  Enter Your ID: ";
		cin >> id;
		cout << "  Enter Your Password: ";
		cin >> password;
		
		data.open("database.txt");
		
		data >> employeeId >> employeePass;
		
			while(data){
				if(id == employeeId){
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
					
					data >> employeeId >> employeePass;
					
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
	
	fstream data;
	
	data.open("employees.txt");
	
	data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
	
	while(data){
		
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
				
			totalSalary = (sss + philHealth + pagIbig) - grossPay;
			
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
			data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
		}
		
	}	
	
}

void EmployeePortal::employeeTotalHour() {
	
	system("cls");
	
	int choice, totalEmployeeHour;
	
	fstream data;
	
	data.open("employees.txt");		
	
	data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
	
	while(data){
		
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
			data >> id >> fname >> lname >> payHour >> totalHour >> timeIn >> timeOut;
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



