#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Employee {
protected:
	string name;
	string DOB;
	string gender;
	string address;
	int phone;
	string email;
	string position;
	int salary;

public:
	void setName(string name) {
		this->name = name;
	}
	void setDOB(string DOB) {
		this->DOB = DOB;
	}
	void setGender(string gender) {
		this->gender = gender;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setPhone(int phone) {
		this->phone = phone;
	}
	void setEmail(string email) {
		this->email = email;
	}
	void setPosition(int position) {
		if (position == 1) {
			this->position = "Associate";
		}
		if(position == 2) {
			this->position = "Member";
		}
		if (position == 3) {
			this->position = "Supervisor";
		}
		;
	}
	string getName() {
		return name;
	}
	string getDOB() {
		return DOB;
	}
	string getGender() {
		return gender;
	}
	string getAddress() {
		return address;
	}
	int getPhone() {
		return phone;
	}
	string getEmail() {
		return email;
	}
	string getPosition() {
		return position;
	}
	Employee(string name, string DOB, string gender, string address, int phone, string email, int position) {
		
		this->name = name;
		setDOB(DOB);
		setGender(gender);
		setAddress(address);
		setPhone(phone);
		setEmail(email);
		setPosition(position);

	}
	~Employee(){
	}
	void setSalary(int salary) {
		this->salary = salary;
	}
	int getSalary() {
		return salary;
	}
	int calcSalary() {
		return this->salary;
	}
};
class Regular : public Employee {
public:
	Regular(string name, string DOB, string gender, string address, int phone, string email, int position, int salary) :
		Employee(name, DOB, gender, address, phone, email, position) {
		setSalary(salary);

	}
	~Regular(){
	}
	void setSalary(int salary) {
		if (this->position == "Associate" && salary > 400 && salary < 550) {
			this->salary = salary;
		}
		else if (this->position == "Member" && salary > 500 && salary < 700) {
			this->salary = salary;
		}
		else if (this->position == "Supervisor" && salary > 700) {
			this->salary = salary;
		}
		else {
			cout << "The salary is invalid";
			this->salary = 0;
		}
	}
};
class Sales : public Employee {
private:
	int productsold;
public:
	Sales(string name, string DOB, string gender, string address, int phone, string email, int position, int salary, int productsold) :
		Employee(name, DOB, gender, address, phone, email, position) {
		setSalary(salary);
		this->productsold = productsold;
	}
	~Sales(){
	}

	
	void setSalary(int salary) {
		if (this->position == "Associate" && salary > 350 && salary < 500) {
			this->salary = salary;
		}
		else if (this->position == "Member" && salary > 450 && salary < 600) {
			this->salary = salary;
		}
		else if (this->position == "Supervisor" && salary > 600) {
			this->salary = salary;
		}
		else {
			cout << "The salary is invalid.";
			this->salary = 0;
		}
	}
	double calcSalary() {
		double x = this->salary + 0.005* this->productsold;
		return x;
	}
		
	

};
int main() {
	Sales reg1("Marcell", "test", "test", "test", 69, "test", 1, 400, 5);
	cout << reg1.getAddress();
	getchar();
	return 0;
}

