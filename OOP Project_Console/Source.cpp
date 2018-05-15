#include<iostream>
#include <string>
#include <vector>
#include "Source.h"
using namespace std;
//system("cls");

class Person
{
public:
	//data members
	string name;
	string password;

};
class Citizen :public Person
{
public:
	vector<Person>citizens;
};
class owner :public Person
{
public:
	vector<Person>owners;
};
class Employee :public Person
{
	string name;
	int id;
public:
	void setName(string name) { this->name = name; }
	void setID(int id) { this->id = id; }
	string getName() { return name; }
	int getID() { return id; }

};
class Form
{
	int formID;
	string formName;
public:
	void setID(int id) { this->formID = id; }
	void setName(string name) { this->formName = name; }
	int getID() { return formID; }
	string getName() { return formName; }

};
class Department
{
public:
	string depName;
	vector<Form>depForm;
	vector<Employee>emp;
//	vector <Form>form;
};
class Ministry
{
protected:
	int id;
	string name;
	
public:
	static int number_of_ministries;
	int number_of_dep;
	vector<Department>dep;
	string getString() {return this->name;}
	int getID() {return this->id;}
	void setString(string tempName)
	{
		this->name = tempName;
	}
	Ministry()
	{
		number_of_dep = 1;
	}

};
class M_Interior:public Ministry
{
	
public:
	M_Interior(string name,int ID)
	{
		this->name = name;
		id = ID;
		Department d1;
		d1.depName = "Civil Status";
		this->dep.push_back(d1);
		number_of_ministries++;
	}

};
class M_Education :public Ministry
{
public:
	M_Education(string name,int ID)
	{
		this->name = name;
		id = ID;
		Department d1;
		d1.depName = "Specific Stage";
		this->dep.push_back(d1);
		number_of_ministries++;
	}

}; 
class M_Finance :public Ministry
{
public:
	M_Finance(string name, int ID)
	{
		this->name = name;
		id = ID;
		Department d1;
		d1.depName = "Currency";
		this->dep.push_back(d1);
		number_of_ministries++;
	}
}; 
class M_Transportation :public Ministry
{
public:
	M_Transportation(string name,int ID)
	{
		this->name = name;
		id = ID;
		Department d1;
		d1.depName = "Train Schedule";
		this->dep.push_back(d1);
		number_of_ministries++;
	}

};
class M_Tourism :public Ministry
{
public:
	M_Tourism(string name,int ID)
	{
		this->name = name;
		id = ID;
		Department d1;
		d1.depName = "Travels";
		this->dep.push_back(d1);
		number_of_ministries++;
	}
};
class M_Electricity :public Ministry
{
public:
	M_Electricity(string name,int ID)
	{
		this->name = name;
		id = ID;
		Department d1;
		d1.depName = "Electricity Bills";
		this->dep.push_back(d1);
		number_of_ministries++;
	}
};
class M_Health :public Ministry
{
public:
	M_Health(string name,int ID)
	{
		this->name = name;
		id = ID;
		Department d1;
		d1.depName = "Quantity of Bloods";
		this->dep.push_back(d1);
		number_of_ministries++;
	}

};
Person p1;
Citizen c1;
owner o1;
Department d1;
Ministry * min[7];
int Ministry::number_of_ministries = 0;
void displayDep()
{
	int a; 
	bool check_Department = false;
	//display all ministries name
	for (int i = 0; i < 7; i++)
		cout<<min[i]->getID()<< " " << min[i]->getString() << endl;

	cout << "Enter ID of ministry you want to Edit: ";
	cin >> a;

	for(int i = 0; i < 7; i++)
	{
		if (a == min[i]->getID())
		{
			int x;
				cout << "To add, Press 1 "<<endl;
				cout<<"To Remove, Press 2 "<<endl;
			cin >> x;
			if (x == 1)
			{
				string name;
				cout << "Enter name of Department you want to add \n";
				cin >> name;
				Department d1;
				d1.depName = name;
				min[i]->dep.push_back(d1);
				min[i]->number_of_dep++;
			}
			else if (x == 2)
			{
				// display all departments in all ministries 
				for (int i = 0; i < 7; i++)
				{
					if (min[i]->getID() == a)
					{
						for  (int j = 0; j < min[j]->number_of_dep;j++)
						{
							cout << min[i]->dep[j].depName << endl;
						}
						string name;
						cout << "Enter name of Department you want to remove : ";
						cin >> name;
						for (int j = 0; j < min[j]->number_of_dep; j++)
						{
							if (min[i]->dep[j].depName == name) {
								min[i]->dep.erase(min[i]->dep.begin() + j);
								check_Department = true;
								break;
							}
						}
					}
					if (check_Department)break;
				}
				if (check_Department == false)
				{
					cout << "This Name is not Correct !" << endl;
					displayDep();
				}
			}
			}
		}
	}
void sign_up()
{
	
	string name;
	string password;
	char a;
	cout << "Enter your name: ";
	cin >> name;
	p1.name = name;
	cout << "Enter your password: ";
	cin >> password;
	p1.password = password;
	while (true)
	{
		cout << "If you are citizen press 'C'\nIf you are owner press 'O'\n";
		cin >> a;
		if (a == 'C')
		{
			c1.citizens.push_back(p1);
			cout << "DONE!" << endl;
			break;
		}

		else if (a == 'O')
		{
			o1.owners.push_back(p1);
			cout << "DONE!" << endl;
			break;
		}
		else
		{
			cout << "Choose again please (C or O)" << endl;
		}
	}

}
void Owner()
{
	int a;  //ozbot el cout hnaaaaaaaaaaaaaaa#
	cout << "Press 1 To Add Ministry" << endl;
	cout << "Press 2 To Edit Ministry " << endl;
	cout << "Press 3 To Remove Ministry" << endl;
	cout << "Press 4 to Add/Remove Employees" << endl;
	cout << "Press 5 To Add/Remve Forms" << endl;
	cout << "Press 6 Number Of Ministries" << endl;
	cout << "Press 7 Number Of Registed Citizen" << endl;
	cin >> a;
	if (a == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			cout << min[i]->getString() << endl;
		}
		int addID; cin >> addID;
		for (int i = 0; i < 7; i++)
		{
			if (min[i]->getID() == addID && min[i]->getString() == "")
			{
				if (addID == 1)
					min[i]->setString("Education");
				else if (addID == 2)
					min[i]->setString("Electricity");
				else if (addID == 3)
					min[i]->setString("Finance");
				else if (addID == 4)
					min[i]->setString("Health");
				else if (addID == 5)
					min[i]->setString("Interior");
				else if (addID == 6)
					min[i]->setString("Tourism");
				else if (addID == 7)
					min[i]->setString("Transportation");
			}
		}

		for (int i = 0; i < 7; i++)
		{
			cout << min[i]->getID() << " " << min[i]->getString() << endl;
		}
	}
	else if (a == 2)
	{
		displayDep();
	}
	else if (a == 3)
	{
		for (int i = 0; i < 7; i++)
		{
			cout << min[i]->getID() << " " << min[i]->getString() << endl;
		}
		cout << "Enter the id of ministry you want to remove" << endl;
		int x; cin >> x;
		for (int i = 0; i < 7; i++)
		{
			if (x == min[i]->getID())
			{
				min[i]->setString("");
				cout << "Remove Done !!" << endl;
			}
		}
	}
	else if (a == 4) {
		int check;
		cout << "Press 1 To Add Employee" << endl;
		cout << "Press 2 To Remove Employee" << endl;
		cin >> check;
		if (check == 1) {
			cout << "Our Ministries" << endl << endl;
			// display our ministries
			for (int i = 0; i < 7; i++)
			{
				cout << min[i]->getID() << " " << min[i]->getString() << endl;
			}
			cout << endl;
			// choose id of the ministry
			cout << "Choose the id of the ministry : ";
			int idNumber; cin >> idNumber;
			for (int i = 0; i < 7; i++)
			{
				if (idNumber == min[i]->getID())
				{
					// display all departments on one ministry 
					for (int j = 0; j < min[j]->number_of_dep; j++)
					{
						cout << min[i]->dep[j].depName << endl;
					}
					cout << endl;
					cout << "Write the Name of the Department to Add Employee : ";
					cin.ignore();
					string ourdep; getline(cin, ourdep);
					// search for this department

					for (int j = 0; j < min[j]->number_of_dep; j++)
					{
						if (min[i]->dep[j].depName == ourdep)
						{
							// Now You can Add Employee
							Employee e1;
							cout << "Please Enter Name of The Employee : ";
							string empName;
							cin.ignore();
							getline(cin, empName);
							cout << "Please Enter ID of the Employee : ";
							int empID;
							cin >> empID;
							e1.setName(empName);
							e1.setID(empID);
							min[i]->dep[j].emp.push_back(e1);
						}
					}
				}
			}
		}
		else if (check == 2) {
			// to remove employee from department

			// first --> add all ministries

			for (int i = 0; i < 7; i++)
			{
				cout << min[i]->getID() << " " << min[i]->getString() << endl;
			}
			cout << endl;
			// second --> choose minstry to remove employees from it
			cout << "Choose the id of the ministry : ";
			int idMin; cin >> idMin;

			for (int i = 0; i < 7; i++)
			{
				if (min[i]->getID() == idMin)
				{
					// then we choose department from this ministry

					//display all departments on this ministry

					for (int j = 0; j < min[j]->number_of_dep; j++)
					{
						cout << min[i]->dep[j].depName << endl;
					}
					cout << endl;

					// write the name of department
					cout << "Write The Name of Department : ";
					cin.ignore();
					string department; getline(cin, department);
					// check for this name 

					for (int j = 0; j < min[j]->number_of_dep; j++)
					{
						if (min[i]->dep[j].depName == department)
						{
							// we can remove employee here
							cout << "Write the Name of Employee To Remove : ";
							string empName; getline(cin, empName);
							for (int k = 0; k < min[i]->dep[j].emp.size(); k++)
							{
								if (empName == min[i]->dep[j].emp[k].getName())
								{
									min[i]->dep[j].emp.erase(min[i]->dep[j].emp.begin() + k);
								}
							}
						}
					}

				}
			}

		}
	}
	else if (a == 5) {
		int check;
		cout << "Press 1 To Add Form" << endl;
		cout << "Press 2 To Remove Form" << endl;
		cin >> check;
		if (check == 1) {
			cout << "Our Ministries" << endl << endl;
			// display our ministries
			for (int i = 0; i < 7; i++)
			{
				cout << min[i]->getID() << " " << min[i]->getString() << endl;
			}
			cout << endl;
			// choose id of the ministry
			cout << "Choose the id of the ministry : ";
			int idNumber; cin >> idNumber;
			for (int i = 0; i < 7; i++)
			{
				if (idNumber == min[i]->getID())
				{
					// display all departments on one ministry 
					for (int j = 0; j < min[j]->number_of_dep; j++)
					{
						cout << min[i]->dep[j].depName << endl;
					}
					cout << endl;
					cout << "Write the Name of the Department to Add Employee : ";
					cin.ignore();
					string ourdep; getline(cin, ourdep);
					// search for this department

					for (int j = 0; j < min[j]->number_of_dep; j++)
					{
						if (min[i]->dep[j].depName == ourdep)
						{
							// Now You can Add Employee
							Form f1;
							cout << "Please Enter Name of The Employee : ";
							string FormName;
							cin.ignore();
							getline(cin, FormName);
							cout << "Please Enter ID of the Employee : ";
							int FormID;
							cin >> FormID;
							f1.setID(FormID);
							f1.setName(FormName);
							min[i]->dep[j].depForm.push_back(f1);
						}
					}
				}
			}
		}
		else if (check == 2) {
			// to remove Form from department

			// first --> add all ministries

			for (int i = 0; i < 7; i++)
			{
				cout << min[i]->getID() << " " << min[i]->getString() << endl;
			}
			cout << endl;
			// second --> choose minstry to remove Form from it
			cout << "Choose the id of the ministry : ";
			int idMin; cin >> idMin;

			for (int i = 0; i < 7; i++)
			{
				if (min[i]->getID() == idMin)
				{
					// then we choose department from this ministry

					//display all departments on this ministry

					for (int j = 0; j < min[j]->number_of_dep; j++)
					{
						cout << min[i]->dep[j].depName << endl;
					}
					cout << endl;

					// write the name of department
					cout << "Write The Name of Department : ";
					cin.ignore();
					string department; getline(cin, department);
					// check for this name 

					for (int j = 0; j < min[j]->number_of_dep; j++)
					{
						if (min[i]->dep[j].depName == department)
						{
							// we can remove Form here
							cout << "Write the Name of Employee To Remove : ";
							string FormName; getline(cin, FormName);
							for (int k = 0; k < min[i]->dep[j].emp.size(); k++)
							{
								if (FormName == min[i]->dep[j].depForm[k].getName())
								{
									min[i]->dep[j].depForm.erase(min[i]->dep[j].depForm.begin() + k);
								}
							}
						}
					}

				}
			}

		}
	}
	else if (a == 6) {
		cout << Ministry::number_of_ministries << endl;
	}
	else if (a == 7) {
		cout << c1.citizens.size() << endl;
	}
}
int login()
{
	string name;
	string password;
	bool check = false;
	cout << "Enter your username: ";
	cin >> name;
	cout << "Enter your password: ";
	cin >> password;
		//check if he is owner	
		for (int i = 0; i < o1.owners.size(); i++)
		{
			if (name == o1.owners[i].name&&password == o1.owners[i].password)
			{
				cout << "WELCOME " << name << endl;
				check = true;
				Owner();
				
				break;
			}
		}
		//check if he is citizen
		for (int i = 0; i < c1.citizens.size(); i++)
		{
			if (name == c1.citizens[i].name&&password == c1.citizens[i].password)
			{
				cout << "WELCOME " << name << endl;
				check = true;
				break;
			}
		}
		//lw da5l b login w howa m4 3aml signup 
		if(check==false)
		{
			cout << "Sorry! You should sign up at first \n";
			cout << "To sign up press 1 \nTo exit press 0 \n";
			int t;
			cin >> t;
			if (t == 1)
				sign_up();
			else
			{
				return 0;
			}
		}
}
void display()               //de 34an ngrb el7aga bs m4 aktr 
                             //momkn n5leha bta3t elcount 
{
	cout << "Citizens are :" << endl;
	for (int i = 0;i<c1.citizens.size();i++)
	{
		cout << c1.citizens[i].name << endl;
	}
	cout << "Owners are :" << endl;
	for (int i = 0; i<o1.owners.size(); i++)
	{
		cout << o1.owners[i].name << endl;
	}
	cout <<"----------------------------------------------------------------"<< endl;
} 
void start()
{
	min[0] = new M_Education("Education",1);
	min[1] = new M_Electricity("Electricty",2);
	min[2] = new M_Finance("Finance",3);
	min[3] = new M_Health("Health",4);
	min[4] = new M_Interior("Interior",5);
	min[5] = new M_Tourism("Tourism",6);
	min[6] = new M_Transportation("Transportation",7);
}
int main()
{
	start();
	while (true)
	{
		int x;
		cout << "If you want to sign up press 1\nIf you want to login press 2\nFor exit press 3\n";
		cin >> x;
		if (x == 1)
		{
			sign_up();
		}

		else if (x == 2)
		{
			login();
			
		}
		else if (x == 3)
		{
			break;
		}
		else { continue; }
		display();
	}
	system("pause");
	return 0;
}