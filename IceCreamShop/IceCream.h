#pragma once

#include<iostream>
#include<map>
#include<set>
#include <string>
#include <iomanip>

using namespace std;

class IceCream {
private:
	string type;
public:
	IceCream(string type) {
		this->type = type;
	}
	//~IceCream() {			Destructor was causing problems so I got rid of it
	//	description();
	//	cout << " finished." << endl;
	//}
	string getType() {  
		return type;
	}
	virtual string getSize() = 0;
	virtual double getPrice() = 0;
	virtual string getFlavor() = 0;
	virtual void description() = 0;
};
class SoftServe : public IceCream {		//Derived class soft serve
public:
	enum softFlavors { Vanilla = 1, Chocolate, Twist, FlavorBurst };
	static map<softFlavors, string> softFlavorMap;	//map of enumerated flavors to their string value names
	static map<string, double> softServeSizePrice;	//Size to price map
private:
	softFlavors flavor;
	string size;
public:
	SoftServe(softFlavors flavor, string size): IceCream("Soft Serve") {
		this->flavor=flavor;
		this->size = size;
	}
	double getPrice() {			//returns price based on size
		return softServeSizePrice[size];
	}
	string getSize() {		//returns size
		return size;
	}
	string getFlavor() {	//returns flavor
		return softFlavorMap[flavor];
	}
	void description() {		//Gves a flavor, size, and price of the item
		cout << getFlavor() << " soft serve ice cream. " << getSize() <<  ". $" << setprecision(3) << getPrice();
	}
};
class HomeMade : public IceCream { //Derived Class
public:
	enum hardFlavors { Vanilla = 1, Chocolate, ButterPecan, Cookies, CookieD, Straw, OP, Lemon};
	static map<hardFlavors, string> hardFlavorMap; //map of enumerated flavors to their string value names
	static map<string, double> hardSizePrice; //Size to price map
private:
	hardFlavors flavor;
	string size;
public:
	HomeMade(hardFlavors flavor, string size) : IceCream("Homemade") {
		this->flavor = flavor;
		this->size = size;
	}
	string getFlavor() {		//return flavor
		return hardFlavorMap[flavor];
	}
	double getPrice() {		//returns price based on size
		return hardSizePrice[size];
	}
	string getSize() {		//returns size
		return size;	
	}
	void description() {  //Gves a flavor, size, and price of the item
		cout << getFlavor() << " homemade ice cream." << getSize() << ". $" << setprecision(3) << getPrice();

	}
};
class Sundae : public IceCream {		//Derived Sundae Class
public:
	enum sundaeFlavors {Chocolate = 1, Fudge, Caramel, PeanutButter, Straw, Banana };
	static map<set<sundaeFlavors>, string> specialtymap;	//map of enumerated flavors to their string value names
	static map<sundaeFlavors, string> sundaeFlavorMap;	//map of enumerated flavor sets to their string value names. Unused, caused problems
	static map<string, double> sundaeSizePrice;			//map of size to price
private:
	sundaeFlavors flavor;
	string size;
public:
	Sundae(sundaeFlavors flavor, string size) : IceCream("Sundae") {
		this->flavor = flavor;
		this->size = size;
	}
	string getFlavor() {		//return flavor
		return sundaeFlavorMap[flavor];
	}
	double getPrice() {		//returns price based on size
		return sundaeSizePrice[size];
	}
	string getSize() {		//returns size
		return size;
	}
	void description() {  //Gves a flavor, size, and price of the item
		cout << getFlavor() << " sundae. " << getSize() << ". $" << setprecision(3) << getPrice();

	}
};
class MilkShake : public IceCream {		//Derived class
public:
	enum shakeFlavors {Vanilla = 1, Choc, Peanut, Straw, Fudge, Caramel  };		
	static map<shakeFlavors, string> shakeFlavorMap; //map of enumerated flavors to their string value names
	static map<string, double> shakeSizePrice;		//map of prices to size
private:
	shakeFlavors flavor;
	string size;
public:
	MilkShake(shakeFlavors flavor, string size) : IceCream("Milk Shake") {
		this->flavor = flavor;
		this->size = size;
	}
	string getFlavor() {		//returns flavor
		return shakeFlavorMap[flavor];
	}
	double getPrice() {		//returns price based on size
		return shakeSizePrice[size];
	}
	string getSize() {		//returns size
		return size;
	}
	void description() {  //Gves a flavor, size, and price of the item
		cout << getFlavor() << " milk shake. " << getSize() << ". $" << setprecision(3) << getPrice();

	}
};


map<SoftServe::softFlavors, string> SoftServe::softFlavorMap{ {Vanilla, "Vanilla"}, { Chocolate, "Chocolate" }, { Twist, "Twist" }, {FlavorBurst, "A flavor burst flavor"}};
map<string, double> SoftServe::softServeSizePrice{ {"Small", 2.39}, {"Medium", 2.69}, {"Large", 2.99} };

map<HomeMade::hardFlavors, string> HomeMade::hardFlavorMap{ {Vanilla ,"Vanilla"}, {Chocolate, "Chocolate"}, {ButterPecan,"Butter Pecan"}, {Cookies,"Cookies-N-Cream"}, {CookieD,"Cookie Dough"}, {Straw,"Strawberry"}, {OP,"Orange Pinapple"}, {Lemon, "Lemon"} };
map<string, double> HomeMade::hardSizePrice{ {"Small", 2.39}, {"Medium", 3.39}, {"Large", 4.39} };


map<Sundae::sundaeFlavors, string> Sundae::sundaeFlavorMap{ {Chocolate, "Chocolate"}, {Fudge, "Hot Fudge"}, {Caramel,"Caramel"}, {PeanutButter, "Peanut Butter"}, {Straw, "Strawberyy"}, {Banana, "Banana"} };
map<set<Sundae::sundaeFlavors>, string> Sundae::specialtymap{ {{Fudge, Caramel}, "Turtle" }, {{PeanutButter, Chocolate}, "Reeses Cup" }, {{Straw, Banana}, "Strawberry Banana"} };
map<string, double> Sundae::sundaeSizePrice{ {"Small", 2.99}, {"Medium", 3.99}, {"Large", 4.99} };

map<MilkShake::shakeFlavors, string> MilkShake::shakeFlavorMap{ {Vanilla, "Vanilla"}, {Choc, "Chocolate"}, {Peanut, "Peanut Butter"}, {Straw, "Strawberry"}, {Fudge, "Hot Fudge"}, {Caramel, "Caramel"} };
map<string, double> MilkShake::shakeSizePrice{ {"Small", 3.39}, {"Medium", 3.89}, {"Large", 4.39} };;
