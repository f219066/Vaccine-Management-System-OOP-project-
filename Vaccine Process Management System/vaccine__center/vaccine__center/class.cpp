#include<iostream>
#include<fstream>
#include"class.h"
using namespace std;

void RegisteredCitizen::Login()
{
	ifstream input("Citizen.txt");

	int count = 0;

	string firstName, password1, id, pass, last_name1, read1;

	firstName = password1 = id = pass = last_name1 = read1 = " ";

	cout << "\n\n\t  Please enter UserName and Password " << endl;


	cout << "\n\n\t  Enter First Name : ";
	cin >> firstName;

	cout << "\n\n\t  Enter Last Name : ";
	cin >> last_name1;

	cout << "\n\t  Enter Password(Don't use backspace) : ";
	cin >> password1;

	while (!(input.eof()))
	{
		input >> read1;

		if (read1 == firstName)
		{
			input >> read1;
			if (read1 == last_name1)
			{
				input >> read1;
				if (read1 == password1)
				{
					count = 1;
					break;
				}
			}			
		}
	}

	if (count == 1)
	{
		cout << "\n\n\t  Your LOGIN is successful. \n\t  Thanks for Logging in!" << endl;
	}
	else
	{
		if (count == 0)
		{
			cout << "\n\n\t  LOGIN ERROR!. \n\t  Please check your username and Password!" << endl;
		}
	}

	input.close();

}


void RegisteredCitizen::SignUp()
{


	fstream output("Citizen.txt", ios::app);

	string r_user_id, r_pssword, rid, rpass;
	system("cls");


	cout << "\n\n\t  Enter First Name : ";
	cin >> first_name;

	cout << "\n\n\t  Enter Last Name : ";
	cin >> last_name;

	cout << "\n\t  Enter Strong Password(Don't use backspace) : ";
	cin >> password;

	cout << "\n\n\t  Enter CNIC : ";
	cin >> CNIC;

	cout << "\n\n\t  Enter Email : ";
	cin >> email;

	cout << "\n\n\t  Enter Blood Type : ";
	cin >> blood_type;

	cout << "\n\n\t  Enter Phone No : ";
	cin >> phone_number;

	cout << "\n\n\t  Enter Cith: ";
	cin >> city;

	cout << "\n\n\t  Enter State : ";
	cin >> state;

	cout << "\n\n\t  Enter Address : ";
	cin >> address;
	cin.ignore();
	cout << "\n\n\t  Enter DOB Format ( dd mm yy ) : ";
	getline(cin, DOB);



	output << CNIC << "\n" << city << "\n" << first_name << "\n" << last_name << "\n" << password << "\n" << DOB << "\n" << email << "\n" << blood_type << "\n" << phone_number << "\n" << state << "\n" << address << "\n" << "-1" << endl;

	cout << "\n\n\t  Registration is successful.\n\t  Thanks for registring!" << endl;

	output.close();
}


void RegisteredCitizen::Forget_Password()
{
	int option = 0;

	cout << "\n\t  You forgot the password? No worries" << endl;
	cout << "\n\t |  1). To search your id by username." << endl;
	cout << "\t |  2). To go back to main menu." << endl;
	cout << "\n\t  Enter your choice : ";
	cin >> option;

	switch (option)
	{
	case 1:
	{
		ifstream read("Citizen.txt");

		int count = 0, choice = 0;

		string firstname, lastname, cnic, dataRead, temp_cnic, temp_firstname, temp_lastname, temp_password, temp_firstname1;

		firstname = lastname = cnic = dataRead = temp_cnic = temp_firstname = temp_lastname = temp_password = temp_firstname1 = " ";

		cout << "\n\n\t  Enter any following which you remember : ";

		cout << "\n\n    1) User Name";
		cout << "\n    2) CNIC";
		cin >> choice;


		if (choice == 1)
		{
			cout << "\n\t  Enter the First Name which you remembered : ";
			cin >> firstname;
			cout << "\n\t  Enter the Last Name which you remembered : ";
			cin >> lastname;
		}
		else
		{
			if (choice == 2)
			{
				cout << "\n\t  Enter the CNIC which you remembered : ";
				cin >> cnic;
			}
		}



		while (!(read.eof()))
		{
			read >> dataRead;

			if ((choice == 2) && (dataRead == cnic))
			{
				temp_cnic = dataRead;

				read >> dataRead;       // city

				read >> dataRead;       //first name

				temp_firstname = dataRead;

				read >> dataRead;       //last name

				temp_lastname = dataRead;

				read >> dataRead;       //password

				temp_password = dataRead;

				count = 1;

				break;

			}

			if (dataRead == firstname)
			{
				temp_firstname = dataRead;             // first name.
			}

			if ((choice == 1) && (firstname == temp_firstname) && (dataRead == lastname))
			{

				temp_lastname = dataRead;       // last name.

				read >> dataRead;       //password

				temp_password = dataRead;

				count = 1;

				break;
			}
		}

		if (count == 1)
		{
			cout << "\n\n\t  Your Account is found!!" << endl;
			cout << "\n\n\t     First Name : " << temp_firstname << endl;
			cout << "\n\t     Last Name : " << temp_lastname << endl;
			cout << "\n\n\t  Your Password is : " << temp_password << endl;
		}
		else
		{
			cout << "\n\n\t  Sorry!! You cannot access any Account by entered information." << endl;
			if (choice == 1)
			{
				cout << "\n\n\t     First Name : " << firstname << endl;
				cout << "\n\t     Last Name : " << lastname << endl;
			}
			if (choice == 2)
			{
				cout << "\n\n\t    CNIC : " << cnic << endl;
			}
			read.close();
		}
		break;
	}		
	case 2:
	{
		cout << endl;
		break;
	}

	default:
	{
		cout << "\n\t  Wrong choice ! Please try again." << endl;
		RegisteredCitizen::Forget_Password();
		break;
	}
	}

}




void Filing::signup(string fn, string ls, string passwrd, int numm)
{
	string str = "";

	if (numm == 1)
	{
		str = "admin.txt";
	}
	else
	{
		if (numm == 2)
		{
			str = "doctor.txt";
		}
		else
		{
			if (numm == 3)
			{
				str = "fdo.txt";
			}
		}
	}

	fstream output(str, ios::app);

	output << "\n" << fn << "  " << ls << "  " << passwrd << "  " << "-1";

	output.close();

}



bool Filing::login(string fn, string ln, string passwrd, int numm)
{
	string str = "";

	int count = 0;

	if (numm == 1)
	{
		str = "admin.txt";
	}
	else
	{
		if (numm == 2)
		{
			str = "doctor.txt";
		}
		else
		{
			if (numm == 3)
			{
				str = "fdo.txt";
			}
		}
	}

	fstream input(str, ios::in);

	string First_n, Last_n, Pswrd, read1;

	First_n = Last_n = Pswrd = read1 = " ";


	while (!(input.eof()))
	{
		input >> read1;

		if (read1 == fn)
		{
			First_n = read1;
			input >> read1;

			if (read1 == ln)
			{
				Last_n = read1;
				input >> read1;

				if (read1 == passwrd)
				{
					Pswrd = read1;
					count = 1;
					break;
				}
			}
		}

	}

	input.close();

	if (count == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}




void Warehouse::add_warehouse(string city,int batch_id,int quantity,string vacc_name)
{
	string readd, readd1;
	int count = 0, count1 = 0, count2 = 0;

	fstream warhuse_out("temp_warehouse.txt",ios::out);
	fstream warhuse_in("warehouse.txt", ios::in);
	


	while (!(warhuse_in.eof()))
	{
		if (count1 != 1 || readd != "-1")
		{
			warhuse_in >> readd;

			if (warhuse_in.eof())
			{
				break;
			}

			if (readd != "-1" || count2 < 2)
			{
				warhuse_out << readd << endl;
			}

			if (readd != city)
			{
				count1 = 1;
			}
			else
			{
				count1 = 0;
			}

		}

		if (readd == city || count1 != 1)
		{
			warhuse_in >> readd;
			warhuse_out << readd << endl;
			warhuse_out << batch_id << endl;
			++count;
			warhuse_out << quantity << endl;
			++count;
			warhuse_out << vacc_name << endl;
			++count;

			warhuse_in >> readd;
			count2++;
			warhuse_out << readd << endl;
		}

		
		if (readd == "-1")
		{
			count1 = 0;
			continue;
		}
	}

	if (count == 3)
	{
		ifstream warhuse_out1("temp_warehouse.txt");
		ofstream warhuse_in1("warehouse.txt");
		while (!(warhuse_out1.eof()))
		{
			warhuse_out1 >> readd1;

			if (warhuse_out1.eof())
			{
				break;
			}

			warhuse_in1 << readd1 << endl;
		}
	}



}




void Warehouse::creat_warehouse(string name, string city, int capacity, int terminator)
{
	fstream warhour("warehouse.txt", ios::app);

	warhour << name << "\n" << city << "\n" << capacity << "\n" << terminator << endl;

	warhour.close();

}


bool FDO::check_eligibility(string cnic)
{
	string read_data = " ";
	int check = 0;

	fstream read("Eligibility.txt", ios::in);

	while (!(read.eof()))
	{
		read >> read_data;

		if (read_data == cnic)
		{
			check = 1;
		}

	} 
    
	read.close();

	if (check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}



void FDO::add_eligible_person(string cnic)
{
	string temp_cnic = " ", temp_DOB = " ", read_data = " ", temp_city = " ";
	int temp_int_DOB = 0;
	int dd, mm, yy;
	int age = 0;

	dd = mm = yy = 0;

	fstream read("Citizen.txt", ios::in);

	fstream write("Eligibility.txt", ios::out);


	//struct tm
//{
//	tm_hour;
//	tm_hur;
//	tm_hour;
//};

	int batch_ID = 0;
	int currnt_year = 0, currnt_month = 0, currnt_day = 0;
	//current time checker
	time_t t = time(0);                                      // get time now

	tm* now = localtime(&t);

	currnt_year = (now->tm_year + 1900);

	currnt_month = (now->tm_mon + 1);

	currnt_day = (now->tm_mday);


	while (!(read.eof()))
	{
		read >> read_data;

		if (read_data == cnic)
		{
			temp_cnic = read_data;

			read >> read_data;    //city

			temp_city = read_data;

			read >> read_data;   //first name

			read >> read_data;    //last name

			read >> read_data;    //password

			read >> dd;
			
			read >> mm;
			//cout << "\n  mm " << mm << endl;
			read >> yy;			
			//cout << "\n  yy " << yy << endl;

			break;
		}		
	}

	age = currnt_year - yy;

	if (dd < currnt_day && mm < currnt_month)
	{
		cout << endl;
	}
	else
	{
		if (dd >= currnt_day && mm >= currnt_month)
		{
			age++;
		}
	}

	if (age >= 15 && age <= 60)
	{
		write << temp_cnic << "\n" << temp_city << "\n" << age << "\n-1" << endl;
	}

	read.close();
	write.close();

}


