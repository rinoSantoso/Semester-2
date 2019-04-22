#include <iostream>
#include <string.h>

using namespace std;

//Abstract class 
class Food {
	protected:
		int basePrice;
		int price;
	public:
		//Virtual method inside abstract class
		virtual void setTotalPrice (){
			}
		void setBasePrice(int price){
			this -> basePrice = basePrice;
		}
		int getPrice(){
			return this -> price;
		}
		
		int getBasePrice(){
			return this->basePrice;
		}
};

//Inheritance of Pasta from Food
class Pasta : public Food{
	protected:
		//Profit in dollars
		int pastaProfit;
	public:
		//Constructor
		Pasta(int pastaProfit, int basePrice){
			setBasePrice(basePrice);
			setTotalPrice(basePrice, pastaProfit);
		}
		//Setter and Getter
		void setPastaProfit(int pastaProfit){
			this -> pastaProfit = pastaProfit;
			
		}
		int getPastaProfit(){
			return this->pastaProfit;
		}
		//OVERRIDE
		void setTotalPrice(int basePrice, int pastaProfit){
			price = basePrice + pastaProfit;
		}
};

//Inheritance of Steak from Food
class Steak : public Food{
	protected:
		//Profit in dollars
		int steakProfit;
	public:
		//Constructor
		Steak(int steakProfit, int basePrice){
			setBasePrice(basePrice);
			setTotalPrice(basePrice, steakProfit);
		}
		//Setter and Getter
		void setSteakProfit(int steakProfit){
			this -> steakProfit = steakProfit;
			
		}
		int getSteakProfit(){
			return this->steakProfit;
		}
		//OVERRIDE
		void setTotalPrice(int basePrice, int steakProfit){
			price += basePrice + steakProfit;
		}
};


//Inheritance of Spaghetti from Pasta as the parent class
class Spaghetti : public Pasta{
	protected:	
		string desc = "Spaghetti is a long, thin, solid, cylindrical pasta. It is a staple food of traditional Italian cuisine.";
	public:
		Spaghetti(int pastaProfit, int price):
		Pasta(pastaProfit, price){
			
		}
	//Getter
	string getDesc(){
		return this-> desc;
	}
};
	
//Inheritance of Fettuccine from Pasta as the parent class
class Fettuccine : public Pasta{
	protected:	
		string desc = "Fettuccine is a flat thick pasta made of egg and flour, it is a type of pasta popular in Roman and Tuscan cuisine.";
	public:
		Fettuccine(int pastaProfit, int price):
		Pasta(pastaProfit, price){
			
		}
	//Getter
	string getDesc(){
		return this-> desc;
	}
};

//Inheritance of Ribeye from Steak as the parent class
class Ribeye : public Steak{
	protected:	
		string desc = "Ribeye Steak is a flavorful and tender beef steak sliced from the rib primal of a beef animal, with rib bone attached.";
	public:
		Ribeye(int steakProfit, int price):
		Steak(steakProfit, price){
			
		}
	//Getter
	string getDesc(){
		return this-> desc;
	}
};

//Inheritance of Tenderloin from Steak as the parent class
class Tenderloin : public Steak{
	protected:	
		string desc = "Grilled beef tenderloin with peppercorn sauce served with au gratin potatoes.";
	public:
		Tenderloin(int steakProfit, int price):
		Steak(steakProfit, price){
			
		}
	//Getter
	string getDesc(){
		return this-> desc;
	}
};
	
//Server Class
class Serve{
	public:
		Serve(){
		}
		
		void serveFood(Spaghetti food1){
			cout << food1.getDesc() << "\n";
			cout << "Price: $" << food1.getPrice() << "\n";
		}
		
		void serveFood(Fettuccine food2){
			cout << food2.getDesc() << "\n";
			cout << "Price: $" << food2.getPrice() << "\n";
		}
		
		void serveFood(Ribeye food3){
			cout << food3.getDesc() << "\n";
			cout << "Price: $" << food3.getPrice() << "\n";
		}
		
		void serveFood(Tenderloin food4){
			cout << food4.getDesc() << "\n";
			cout << "Price: $" << food4.getPrice() << "\n";
		}
};

int main(){
	Spaghetti spaghett(30, 100);
	Fettuccine fet(20, 80);
	Ribeye rib(50, 140);
	Tenderloin steak(40, 100);
	Serve serve;
	serve.serveFood(spaghett);
	serve.serveFood(fet);
	serve.serveFood(rib);
	serve.serveFood(steak);
	
	return 0;
};

