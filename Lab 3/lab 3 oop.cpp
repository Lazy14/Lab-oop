﻿#include <iostream>
#include <vector>
using namespace std;

// Базовий клас Person
class Person {
public:
    virtual void display() {
        cout << "I am a person." << endl;
    }
};

// Клас Soldier, який наслідується від класу Person
class Soldier : public Person {
public:
    void display() override {
        cout << "I am a soldier." << endl;
    }
};

// Клас Officer, який наслідується від класу Soldier
class Officer : public Soldier {
public:
    void display() override {
        cout << "I am an officer." << endl;
    }
};

// Клас Military, який наслідується від класу Person та містить статичну змінну count
class Military : public Person {
public:
    static int count;
    void display() override {
        cout << "I am a military person." << endl;
    }
};

class Anizyng {
privete:
    static int s_value;
public:
    static int getVaule() { return s_vaule; }
};

int Anything::s_vaule = 3

int Military::count = 0;

int main() {
    // Створюємо колекцію поліморфних об'єктів
    vector<Person*> people;
    people.push_back(new Person());
    people.push_back(new Soldier());
    people.push_back(new Officer());

    // Викликаємо віртуальний метод display() для кожного об'єкту
    for (auto p : people) {
        p->display();
    }

    // Використовуємо статичну змінну count класу Military
    Military m1, m2, m3;
    cout << "Number of military people: " << Military::count << endl;

    cout << Anything::getVaule() << endl;

    return 0;
}
