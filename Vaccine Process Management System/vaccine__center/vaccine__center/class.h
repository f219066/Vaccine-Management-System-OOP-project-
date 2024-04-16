#pragma once


#pragma once

#include<string>
using namespace std;

class PERSON
{
public:
	string first_name, last_name, phone_number, email, CNIC, blood_type, city, state, address, DOB, password, idNo, status, vaccine_name;
};


class Admin : public PERSON
{
public:


};


class FDO : public PERSON
{
public:
	void add_eligible_person(string);
	bool check_eligibility(string);
};


class Doctor : public PERSON
{

};


class Vaccine 
{

};


class Warehouse
{
public:
	void creat_warehouse(string, string, int, int);
	void add_warehouse(string, int, int, string);
};



class Supplier : public PERSON
{

};

class RegisteredCitizen :public PERSON
{
public:

	void Login();
	void SignUp();
	void Forget_Password();
};



class Filing
{
public:

	void signup(string F_Name, string L_Name, string password, int num);
	bool login(string F_Name, string L_Name, string password, int num);
	void supplier(string F_Name, string L_Name);
};

