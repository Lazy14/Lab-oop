

#include <iostream>
#include <string>   //підклучаємо базу данних string

using namespace std;

class Animals  // створуємо структуру "тварини"
{
private:
    string name, kind; //створуємо поля "імя" "вид" типу "string"
	int average_weight; //створуємо поле "середня вага" типу "integer"


public:

	Animals(string N, string k, int av)
	{
		name = N;
		kind = k;
		average_weight = av;
		

	}

	~Animals() {

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

	Animals tiger("Тигр", "Тигр", 70);
	Animals cheetah("Гепард", "Гепард", 50);
	Animals hare("Заєць", "Заєць", 3);
	
	tiger.Print();
	cheetah.Print();
	hare.Print();

	return 0;
}

