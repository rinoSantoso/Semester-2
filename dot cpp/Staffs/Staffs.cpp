#include <iostream>
#include <string.h>

using namespace std;

class Employee{
	protected:
		string name;
		string DOB;
		string gender;
		string address;
		double phone;
		string email;
		string position;
		double salary;
		
	
	public:
		Employee(string name, string DOB, string gender, string address, double phone, string email, int position, double salary){
			this->name = name;
			this->DOB = DOB;
			this->gender = gender;
			this->address = address;
			this->phone = phone;
			this->email = email;
			if(position == 1){
				this->position = "Associate";
			}
			if(position == 2){
				this->position = "Member";
			}
			if(position == 3){
				this->position = "Supervisor";
			}
			this->salary = salary;
			
		}
		virtual void setName(string name){
			this->name = name;
		}
		void setDOB(string DOB){
			this->DOB = DOB;
		}
		void setGender(string gender){
			this->gender = gender;
		}
		void setAddress(string address){
			this->address = address;
		}
		void setPhone(double phone){
			this->phone = phone;
		}
		void setEmail(string email){
			this->email = email;
		}
		void setPosition(int position){
			if(position == 1){
				this->position = "Associate";
			}
			if(position == 2){
				this->position = "Member";
			}
			if(position == 3){
				this->position = "Supervisor";
			}
		}
		virtual void setSalary(double salary){
			this->salary = salary;
		}
			
		
		string getName(){
			return name;
		}
		string getDOB(){
			return DOB;
		}
		string getGender(){
			return gender;
		}
		string getAddress(){
			return address;
		}
		double getPhone(){
			return phone;
		}
		string getEmail(){
			return email;
		}
		string getPosition(){
			return position;
		}
		virtual double getSalary(){
			return salary;
		}
};

class Regular : public Employee{
	public:
		Regular(string name, string DOB, string gender, string address, double phone, string email, int position, double salary) : Employee(name, DOB, gender, address, phone, email, position, salary){
			setSalary(salary);
		}
		
		void setSalary(double salary){
			this->salary = salary;
			while(true){
				if (position == "Associate" && this->salary >=400 && this->salary<=550){
					break;
				}
				else if (position == "Member" && this->salary >=500 && this->salary<=700){
					break;
				}
				else if (position == "Supervisor" && this->salary > 700){
					break;
				}
				else{
					cout << "Invalid Salary for this employee level. Please input a different salary: ";
					cin >> this->salary;
				}
			}
		}
};

class Sales : public Employee{
	protected:
		double totalSalary;
		double commision;
	
	public:
		Sales(string name, string DOB, string gender, string address, double phone, string email, int position, double salary, int totalSales) : Employee(name, DOB, gender, address, phone, email, position, salary){
			setCommision(totalSales);
			setSalary(salary);
		}
		
		void setCommision(int totalSales){
			this->commision = totalSales * 0.5/100;
			this->totalSalary = commision + salary;
		}
		
		void setSalary(double salary){
			this->salary = salary;
			while(true){
				if (position == "Associate" && this->salary >=350 && this->salary<=500){
					break;
				}
				else if (position == "Member" && this->salary >=450 && this->salary<=600){
					break;
				}
				else if (position == "Supervisor" && this->salary > 600){
					break;
				}
				else{
					cout << "Invalid Salary for this employee level. Please input a different salary: ";
					cin >> this->salary;
				}
			}
			this->totalSalary = commision + this->salary;
		}
		
		double getSalary(){
			return totalSalary;
		}
		
};

int main(){
	
	Regular Rino("Rino", "Dec 5 2000", "Male", "Lippo Cikarang", 81519045928, "santosorino8@yahoo.com", 3, 300);
	Sales Santos("Santos", "12 May 2000", "Male", "Jakarta", 123456789, "asdf@someemail.com", 2, 500, 60);
	cout << Rino.getName() << "'s Salary is: $" << Rino.getSalary() << "\n";
	cout << Santos.getName() << "'s Salary is: $" << Santos.getSalary();
}








