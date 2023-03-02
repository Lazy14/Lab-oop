

#include <iostream>
#include <string>   //підклучаємо базу данних string

using namespace std;

class Animals  // створуємо структуру "тварини"
{
private:
    string name, kind; //створуємо поля "імя" "вид" типу "string"
	int average_weight; //створуємо поле "середня вага" типу "integer"


public:
    Animals()
	{
		name = "0";
		kind = "0";
		average_weight = 0;
		cout << "Визвався конструктор ,без параметрiв | "<< endl;

	}
	Animals(string N, string k, int av)
	{
		name = N;
		kind = k;
		average_weight = av;
		cout << "Визвався конструктор | ";

	}

	

	~Animals() {
		cout << "Визвався денструктор | ";
	}
	
	string GetName() {
		return name;
	}
	string GetKind() {
		return kind;
	}
	int GetAverage_weight() {
		return average_weight;
	}

	void Print() 
	{
		cout << endl << "\tIмя: " << name << endl << "\tВид: " << kind << endl <<"\tСередня вага: " << average_weight <<"кг" << endl;
	}
	
};

int main() {
	setlocale(LC_ALL, "ukr");

	Animals a[1];


	Animals tiger("Тигр", "Тигр", 70);
	Animals cheetah("Гепард", "Гепард", 50);
	Animals hare("Заєць", "Заєць", 3);
	
	tiger.Print();
	cheetah.Print();
	hare.Print();

	return 0;
}

