#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"class.h"
using namespace std;



int main()
{

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


	
	srand(NULL);

	int temp_time = ((rand() % 10) + 1);

	currnt_day += temp_time;

	if (currnt_day > 30)
	{                                              // convert nto function to create random values and use file or globle varable.  
		currnt_month++;
		currnt_day -= 30;

		if (currnt_month > 12)
		{
			currnt_year++;
			currnt_month -= 12;
		}

	}


	int main_choice = 0, super_admin_input = 0, admin_input = 0, super_count = 0, vaccine_assign_count, admin_name_pass = 0, types_count = 0;
	int quantity1 = 0, quantity2 = 0, quantity3 = 0, vacine_count1 = 0, vacine_count2 = 0, vacine_count3 = 0, warehouse_capacity = 0, total_enter_quantity = 0;
	string super_admin_name, name_super, pass_super, superadmin_pass, admin_last, admin_last_name;
	int batchID = 0;
	PERSON person;
	Filing file;
	FDO FDO_obj;


	fstream superadmin("superadmin.txt", ios::in);

	fstream vaccine("tempvaccname.txt", ios::app);

	cout << "\n  1)  Do you want Super-admin access? " << endl;

	cout << "\n  2)  Do you want Admin access? " << endl;

	cout << "\n  3)  Do you want Doctor access? " << endl;

	cout << "\n  4)  Do you want FDO access? " << endl;

	cout << "\n  5)  Do you want User access? " << endl;

	cout << "\n  6)  Do you want Government access? " << endl;



	cin >> main_choice;


	if (main_choice == 1)

	{

		cout << "\n    Please enter the Name of Super Admin : ";
		cin >> name_super;

		cout << "\n    Please enter the Password of Super Admin : ";
		cin >> pass_super;


		while (superadmin >> super_admin_name >> superadmin_pass)
		{
			if (super_admin_name == name_super && superadmin_pass == pass_super)
			{
				super_count = 1;
			}
		}


		if (super_count == 1)
		{
			cout << "\n  1)  To Creating" << endl;

			cout << "\n  2)  To Retrieve" << endl;

			cout << "\n  3)  To Update" << endl;

			cout << "\n  4)  To Delete" << endl;

			cin >> super_admin_input;


			switch (super_admin_input)
			{
			case 1:
			{
				cout << "\n  1)  To Create Admin" << endl;
				cout << "\n  2)  To Create Doctor" << endl;
				cout << "\n  3)  To Create FDO" << endl;
				cout << "\n  4)  To Create Supplier" << endl;
				cin >> admin_input;

				{
					switch (admin_input)
					{
					case 1:
					{
						cout << "\n    Please enter First Name of Admin : ";
						cin >> person.first_name;
						cout << "\n    Please enter Last Name of Admin : ";
						cin >> person.last_name;
						cout << "\n    Please enter Password for Login : ";
						cin >> person.password;

						file.signup(person.first_name, person.last_name, person.password, admin_input);
						break;
					}

					case 2:
					{
						cout << "\n    Please enter First Name of Doctor : ";
						cin >> person.first_name;
						cout << "\n    Please enter Last Name of Doctor : ";
						cin >> person.last_name;
						cout << "\n    Please enter Password for Doctor : ";
						cin >> person.password;

						file.signup(person.first_name, person.last_name, person.password, admin_input);

						break;
					}

					case 3:
					{
						cout << "\n    Please enter First Name of FDO : ";
						cin >> person.first_name;
						cout << "\n    Please enter Last Name of FDO : ";
						cin >> person.last_name;
						cout << "\n    Please enter Password for FDO : ";
						cin >> person.password;

						file.signup(person.first_name, person.last_name, person.password, admin_input);
						break;
					}

					case 4:
					{

						int choice2 = 0;

						fstream supplier("Supplier.txt", ios::app);
						fstream id("tempid.txt", ios::app);

		
						cout << "\n    Please enter ID for this Supplier : ";
						cin >> person.idNo;
						cout << "\n    Please enter Status of this Supplier( Local , International ) : ";
						cin >> person.status;

						cout << "\n    How many Types you want to assign ( Minimum Type 1 , Maximum Types 2 ) : ";
						cin >> vaccine_assign_count;

						id << person.idNo;

						if (vaccine_assign_count == 1)
						{
							vaccine << person.idNo;
						}

						supplier << "\n" << person.idNo << "  " << person.status;


						for (int i = 0; i < vaccine_assign_count; i++)
						{
							cout << "\n\n    1) Pfizer";
							cout << "\n    2) Sinovac";
							

							cout << "\n\n   Please select ( " << i + 1 << " ) Type of vaccine : " << endl;

							cin >> choice2;

							cout << endl;

							if (choice2 == 1 || choice2 == 2)
							{
								if (choice2 == 1)
								{
									person.vaccine_name = "Pfizer";
									supplier << "  " << person.vaccine_name;
									vaccine << "  " << "Pfizer" << endl;

								}
								else
								{
									if (vaccine_assign_count != 2) 
									{
										supplier << "  " << "0";
									}
								}

								if (choice2 == 2)
								{
									person.vaccine_name = "Sinovac";
									supplier << "  " << person.vaccine_name;
									vaccine << "  " << "Sinovac" << endl;
								}
								else
								{
									if (vaccine_assign_count != 2)
									{
										supplier << "  " << "0";
									}
								}


								id << "  " << vaccine_assign_count << endl;
								
							}
							else
							{
								cout << "\n    Invalid Input" << endl;
							}
						}

						supplier << "  " << "-1";
						vaccine.close();
						id.close();
						supplier.close();
						break;
					}

					default:
					{
						cout << "\n\n     Choice unavailable!!" << endl;
						break;
					}

					}
				}
				break;
			}

			case 2:
			{
				cout << "\n\n     To retrieve the data" << endl;
				break;
			}
			case 3:
			{
				cout << "\n\n     To update the data" << endl;
				break;
			}
			case 4:
			{
				cout << "\n\n     To delete the data" << endl;
				break;
			}

			default:
			{
				cout << "\n\n     Choice unavailable!!" << endl;
				break;
			}

			}
		}
	}

	else
	{

		super_count = 0;

		fstream admin("admin.txt", ios::in);

		fstream vaccine_1("tempvaccname.txt", ios::in);

		if (main_choice == 2)
		{

			fstream i_d("tempid.txt", ios::in);
			PERSON person1;
			Warehouse wrhouse;
			int check = 0, choice_admin = 0, id_supplier = 0, vaccine_id_count = 0, file_data_1 = 0, temp_id = 0, temp_countt = 0;
			Filing file1;
			fstream warehouse("warehouse.txt", ios::app);
			fstream supplier("Supplier.txt", ios::in);
			string  temp_ids = " ", file_data11 = " ", vaccine_name3 = " ", user_in = " ", choice_vaccine = " ", temp_vaccine_name1 = " ", temp_vaccine_name2 = " ";
			string supplier_name = " ", vaccine_name1 = " ", vaccine_name2 = " ", supplier_status = " ", warehouse_name = " ", warehouse_city = " ", warhous_name = " ", warhous_city = " ";

			cout << "\n    Please enter First Name of Admin : ";
			cin >> person1.first_name;
			cout << "\n    Please enter Last Name of Admin : ";
			cin >> person1.last_name;
			cout << "\n    Please enter Password for Login : ";
			cin >> person1.password;

			check = file1.login(person1.first_name, person1.last_name, person1.password, 1);

			if (check == 1)
			{
				system("cls");

				cout << "\n\n      Login is successful " << endl;

				cout << "\n\n    1) To purchase vaccine from Supplier";
				cout << "\n    2) To create warehouse";
				cout << "\n    3) To pass in vaccination center";
				cin >> choice_admin;

				if (choice_admin == 1)
				{
					string file_data, temp;

					char ch;

					fstream batchId("BatchID.txt", ios::in);

					while (!(batchId.eof()))
					{
						batchId >> batchID;

						batch_ID = batchID;
					}

					batchId.close();

					fstream batch__id("BatchID.txt", ios::app);

					batch_ID++;

					batch__id << "\n" << batch_ID;

					batch__id.close();

					cout << "\n\n\t\tID" << setw(20) << "\tStatus" << setw(25) << "\tVaccine Types\n" << endl;

					cout << setw(20);

					while (!(supplier.eof()))
					{
						supplier >> file_data;

						if (file_data == "-1")
						{
							cout << endl;
							continue;
						}

						if (file_data == "0")
						{

						}
						else
						{

							cout << file_data << setw(20);
						}

					}

					file_data = "";
					temp_countt = 0;

					id_supplier = 0;
					supplier_status = vaccine_name1 = vaccine_name2 = " ";

					cout << "\n\n    To purchase the vaccines from Supplier Enter the ID for that : ";
					cin >> user_in;


					int temp_stoi = 0;

					temp_stoi = atoi(user_in.c_str());       // convert the String Into Integer.

					while (!(i_d.eof()))
					{
						i_d >> temp_id;

						if (temp_countt == 1)
						{
							break;
						}

						if (temp_id == temp_stoi)
						{
							temp_countt = 1;
							continue;
						}
					}


					int tempp = 0, big_count = 0, final_countt = 0;
					string vaccine_name_v1, vaccine_name_v2;

					vaccine_name_v1 = vaccine_name_v2 = "0";

					while (!(supplier.eof()))
					{

						supplier >> file_data;

						if ((file_data == user_in) || (tempp == 1))
						{
							if (file_data != "-1")
							{
								++big_count;
								tempp = 1;
							}



							if (file_data == "Pfizer" || file_data == "pfizer")
							{
								vaccine_name_v1 = "Pfizer";
								//++final_countt;
							}

							if (file_data == "Sinovac" || file_data == "sinovac")
							{
								vaccine_name_v2 = "Sinovac";
							}

							if (file_data == "-1")
							{
								tempp = 0;
								break;
							}
							if (file_data == "0")
							{
								continue;
							}
						}

					}



					if (temp_id == 2)
					{
						cout << "\n\n     Choose a Type : ";
						cout << "\n     1) Pfizer";
						cout << "\n     2) Sinovac";
						cin >> choice_vaccine;

						if (choice_vaccine == "1")
						{
							cout << "\n\n    Enter the quantity of ( Pfizer ) vaccine : ";
							cin >> quantity1;
							vaccine_name1 = "Pfizer";
						}
						if (choice_vaccine == "2")
						{
							cout << "\n\n    Enter the quantity of ( Sinovac ) vaccine : ";
							cin >> quantity1;
							vaccine_name1 = "Sinovac";
						}
					}
					else
					{
						temp_countt = 0;

						vaccine_name1 = " ";

						if (temp_id == 1)
						{
							while (!(vaccine_1.eof()))
							{
								vaccine_1 >> vaccine_name1;

								if (temp_countt == 1)
								{
									break;
								}

								if (vaccine_name1 == user_in)
								{
									temp_countt = 1;
									continue;
								}

								vaccine_name1 = "0";

							}


							if (vaccine_name1 != "0")
							{
								cout << "\n\n    Enter the quantity of ( " << vaccine_name1 << " ) vaccine : ";
								cin >> quantity1;
							}
						}
					}

					string city_name;



					cout << "\n\n     Enter the Name of City of warehouse : ";
					cin >> city_name;


					wrhouse.add_warehouse(city_name, batch_ID, quantity1, vaccine_name1);

					batch__id.close();
					supplier.close();
					admin.close();
					superadmin.close();
					vaccine.close();
					vaccine_1.close();
					warehouse.close();
				}
				else
				{
					if (choice_admin == 2)
					{
						int chooc = 0;

						cout << "\n\n   How many Warehouses you want to creat : ";
						cin >> chooc;
						for (int i = 0; i < chooc; i++)
						{
							cout << "\n\n    Please enter the Name of Warehouse : ";
							cin >> warehouse_name;
							cout << "\n    Please enter the City of Warehouse : ";
							cin >> warehouse_city;
							cout << "\n    Please enter the Capacity of Warehouse : ";
							cin >> warehouse_capacity;

							wrhouse.creat_warehouse(warehouse_name, warehouse_city, warehouse_capacity, -1);
						}

					}
					else
					{
						if (choice_admin == 3)
						{
							fstream warehouse("warehouse.txt", ios::in);
							fstream temp_ware("Temp_vaccenter.txt", ios::out);
							fstream second_temp_warehouse("second_temp_warehouse", ios::out);
							fstream actual_center("vaccinationcenter.txt", ios::app);
							int cont = 0, cont1 = 0;
							bool termnate = true;
							string temp_batchid = "", temp_city = "", cont_1 = " ";

							cout << "\n\n    Enter the City of Warehouse : ";
							cin >> warehouse_city;

							cout << "\n\n  Batch ID" << setw(12) << "Quantity" << setw(15) << "Vacc Name" << endl;

							while (!(warehouse.eof()))
							{
								warehouse >> vaccine_name1;

								if (vaccine_name1 == warehouse_city)
								{

									while (termnate)
									{

										warehouse >> vaccine_name1;             //capacity.

										if (cont1 > 0)
										{
											cout << vaccine_name1 << setw(10);
										}

										warehouse >> vaccine_name1;             //batchid.

										cout << vaccine_name1 << setw(10);

										warehouse >> vaccine_name1;             //quantity.

										cout << vaccine_name1 << setw(10);

										warehouse >> vaccine_name1;             //vacc name.
										cont1++;

										if (vaccine_name1 == "Pfizer" || vaccine_name1 == "pfizer" || vaccine_name1 == "Sinovac" || vaccine_name1 == "sinovac")
										{
											cout << endl;
										}

										if (vaccine_name1 != "-1")
										{
											cout << vaccine_name1 << setw(10);
										}

										if (vaccine_name1 == "-1")
										{
											cont1 = 0;
											break;
										}
									}

								}


							}

							warehouse.close();

							cout << "\n\n     Please enter the Batch ID for which( vaccine ) you want to load : ";
							cin >> cont_1;


							warehouse.open("warehouse.txt", ios::in);

							int temp_rnd = 0;
							srand(NULL);
							temp_rnd = ((rand() % 50) + 50);

							while (!(warehouse.eof()))
							{
								warehouse >> vaccine_name1;  // it is city name.

								if (vaccine_name1 == warehouse_city)
								{
									temp_city = vaccine_name1;
								}

								if (vaccine_name1 == cont_1)
								{
									temp_ware << temp_city << endl;

									temp_ware << temp_rnd << endl;
									temp_ware << vaccine_name1 << endl;
									// batch.
									temp_batchid = vaccine_name1;
									cont = 1;
									warehouse >> vaccine_name1;     // capacity
									temp_ware << vaccine_name1 << endl;

									warehouse >> vaccine_name1;       // vaccine name.
									temp_ware << vaccine_name1 << endl;



									temp_ware << currnt_day << "-" << currnt_month << "-" << currnt_year << endl;

									temp_ware << "-1" << endl;

									break;

								}

							}

							temp_ware.close();
							warehouse.close();


							if (cont == 1)
							{

								warehouse.open("warehouse.txt", ios::in);

								while (!(warehouse.eof()))
								{
									warehouse >> vaccine_name2;

									if (warehouse.eof())
									{
										break;
									}

									second_temp_warehouse << vaccine_name2 << endl;

									if (vaccine_name2 == temp_city)
									{
										//second_temp_warehouse << temp_city << endl;         // city.
										warehouse >> vaccine_name2;
										second_temp_warehouse << vaccine_name2 << endl;     // capacity.
										warehouse >> vaccine_name2;    // batch
										warehouse >> vaccine_name2;     // quantity
										warehouse >> vaccine_name2;    // vacc name
									}
								}

								second_temp_warehouse.close();
								warehouse.close();
							}


							if (cont == 1)
							{
								second_temp_warehouse.open("second_temp_warehouse", ios::in);

								warehouse.open("warehouse.txt", ios::out);

								while (!(second_temp_warehouse.eof()))
								{
									second_temp_warehouse >> vaccine_name2;

									if (second_temp_warehouse.eof())
									{
										break;
									}

									warehouse << vaccine_name2 << endl;
								}

								second_temp_warehouse.close();
								warehouse.close();
							}


							if (cont == 1)
							{
								temp_ware.open("Temp_vaccenter.txt", ios::in);

								while (!(temp_ware.eof()))
								{
									temp_ware >> vaccine_name3;

									if (temp_ware.eof())
									{
										break;
									}
									actual_center << vaccine_name3 << endl;
								}

								temp_ware.close();
								actual_center.close();
							}
						}
						else
						{
							cout << "\n\n    Invalid Input!!" << endl;
						}
					}
				}
			}
			else
			{
				cout << "\n\n     Something is INCORRECT ( First Name  OR  Last Name  OR  Password)";
			}
		}
		else
		{
			if (main_choice == 3)
			{  
				string doc_name, doc_namelast, doc_pass, cniC;
				bool check = false, check1 = false;
				string temp_city = " ", read_data, read_data1, batch_id;
				int quantity_1 = 0, blood_press = 0, oxygen_level = 0, glucose_level = 0;

				fstream read_vacc_center("vaccinationcenter.txt", ios::in);
				fstream read_eligibility("Eligibility.txt", ios::in);
				fstream write_vaccenter("Temp_vaccenter_2.txt", ios::out);


				cout << "\n    Please enter First Name of Doctor : ";
				cin >> doc_name;
				cout << "\n    Please enter Last Name of Doctor : ";
				cin >> doc_namelast;
				cout << "\n    Please enter Password for Doctor : ";
				cin >> doc_pass;

				check = file.login(doc_name, doc_namelast, doc_pass, 2);

				if (check == 1)
				{
					cout << "\n\n    Login is successful!! " << endl;

					cout << "\n    Enter the CNIC of Patient : ";
					cin >> cniC;

					FDO_obj.add_eligible_person(cniC);

					check1 = FDO_obj.check_eligibility(cniC);

					if (check1 == 1)
					{
						system("cls");

						cout << "\n\n\t    Patient is Eligible!!" << endl;

						cout << "\n\n    Enter Blood Pressue : ";
						cin >> blood_press;
						cout << "\n\n    Enter Oxygen Level : ";
						cin >> oxygen_level;
						cout << "\n\n    Enter Glucose Level : ";
						cin >> glucose_level;

						if (blood_press >= 80 && blood_press <= 120)
						{
							if (oxygen_level >= 95 && oxygen_level <= 100)
							{
								if (glucose_level >= 77 && glucose_level <= 99)
								{
									while (!(read_eligibility.eof()))
									{
										read_eligibility >> read_data;

										if (read_data == cniC)
										{
											read_eligibility >> read_data;
											
											temp_city = read_data;
											cout << temp_city << endl;
										}
									}

									cout << "\n   Batch ID " << setw(20) << "Quantity" << setw(20) << "Vaccine Name \n" << endl;

									while (!(read_vacc_center.eof()))
									{
										read_vacc_center >> read_data1;
										
										if (temp_city == read_data1)
										{
											read_vacc_center >> read_data1;     //vaccine id
											read_vacc_center >> read_data1;     // batch id.
											
											cout << setw(3) << read_data1 << setw(15);

											read_vacc_center >> read_data1;    //quantity.

											cout << read_data1 << setw(15);

											read_vacc_center >> read_data1;    //vacc name.

											cout << read_data1 << endl;

										}
									}

									read_vacc_center.close();
									write_vaccenter.close();

									read_vacc_center.open("vaccinationcenter.txt", ios::in);
									write_vaccenter.open("Temp_vaccenter_2.txt", ios::out);

									cout << "\n\n     These are Batches Available in this City( Patient's City )" << endl;
									cout << "\n    Enter Batch ID : ";
									cin >> batch_id;

									while (!(read_vacc_center.eof()))
									{
										read_vacc_center >> read_data;

										if (read_vacc_center.eof())
										{
											break;
										}

										write_vaccenter << read_data << endl;

										if (read_data == batch_id)
										{
											read_vacc_center >> quantity_1;
											cout << "\n  Quantity = " << quantity_1 << endl;
											--quantity_1;
											write_vaccenter << quantity_1 << endl;
											cout << "\n  Quantity decrement = " << quantity_1 << endl;
										}
									}

									read_vacc_center.close();
									write_vaccenter.close();


									fstream read_vacc_center1("vaccinationcenter.txt", ios::out);
									fstream write_vaccenter1("Temp_vaccenter_2.txt", ios::in);


									while (!(write_vaccenter1.eof()))
									{
										write_vaccenter1 >> read_data;
									
										if (write_vaccenter1.eof())
										{
											cout << "open break" << endl;
											break;
										}
										cout << "open" << endl;
										read_vacc_center1 << read_data << endl;
									}


									read_vacc_center1.close();
									write_vaccenter1.close();


									cout << "\n\n\t    Patient is Vaccinated Successfully!" << endl;

								}
								else
								{
									cout << "\n\n    Patient's condition is not Normal!!  Please visit again. " << endl;
								}
							}
							else
							{
								cout << "\n\n    Patient's condition is not Normal!!  Please visit again. " << endl;
							}
						}
						else
						{
							cout << "\n\n    Patient's condition is not Normal!!  Please visit again. " << endl;
						}
					}
					else
					{
						cout << "\n\n    Patient is Not Eligible!!" << endl;
					}
				}
			}
			else
			{
				if (main_choice == 4)
				{
					//cout << "\n  FDO" << endl;
					
				}
				else
				{
					if (main_choice == 5)
					{
						//cout << "\n  User" << endl;

						int choice = 0;
						RegisteredCitizen obj;

						cout << "\t\tWelcome to the Login page." << endl;
						cout << "\n\n----Menu----\n" << endl;
						cout << "\n  |  1).  Login. " << endl;
						cout << "\n  |  2).  SignUp.  " << endl;
						cout << "\n  |  3).  Forget Password.  " << endl;
						cout << "\n  |  4).  Exit.  " << endl;
						cin >> choice;

						switch (choice)
						{
						case 1:
						{
							obj.Login();
							for (double i = 0;i < 800000000;)
							{
								i++;
							}
							system("cls");
							main();

							break;

						}
						case 2:
						{
							obj.SignUp();

							for (double i = 0;i < 800000000;)
							{
								i++;
							}
							system("cls");
							main();
							break;

						}
						case 3:
						{
							obj.Forget_Password();

							for (double i = 0;i < 3000000000;)
							{
								i++;
							}
							system("cls");
							main();
							break;

						}
						case 4:

							cout << "\n\n    Thank You!!" << endl;
							for (double i = 0;i < 700000000;)
							{
								i++;
							}
							system("cls");
							main();
							break;
						default:
							system("cls");
							cout << "\n\n     Please select from the options given above!!" << endl;
							for (double i = 0;i < 700000000;)
							{
								i++;
							}
							main();
							break;
						}
					}
					else
					{
						if (main_choice == 6)
						{
							cout << "\n  Gov official" << endl;
						}
						else
						{
							cout << "\n\n      Choice unavailable!!" << endl;
						}
					}
				}
			}
		}
	}
	

    
	for (double i = 0;i < 800000000;)
	{
		i++;
	}

	system("cls");

	main();

	return 0;
}