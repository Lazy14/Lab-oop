﻿#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

class Student {
public:
    Student(const string& name) : name(name) {}

    string getName() const {
        return name;
    }

    virtual bool hasPassedAllExams() const = 0;
    virtual ~Student() {}

private:
    string name;
};

class UndergraduateStudent : public Student {
public:
    UndergraduateStudent(const string& name) : Student(name) {}

    bool hasPassedAllExams() const override {
        // Логіка перевірки, чи здав студент всі іспити для бакалавра
        return false; // Повертаємо false як приклад
    }
};

class GraduateStudent : public Student {
public:
    GraduateStudent(const string& name) : Student(name) {}

    bool hasPassedAllExams() const override {
        // Логіка перевірки, чи здав студент всі іспити для магістра
        return true; // Повертаємо true як приклад
    }
};

int main() {
    setlocale(LC_ALL, "ukr"); // Встановлюємо локаль за замовчуванням
    system("chcp 65001"); // Змінюємо кодування консолі на UTF-8

    vector<Student*> students;
    students.push_back(new UndergraduateStudent("Назар"));
    students.push_back(new GraduateStudent("Ігор"));
    students.push_back(new UndergraduateStudent("Андрій"));

    cout << "Студенти, які не здали всі іспити:" << endl;
    try {
        for (const auto& student : students) {
            if (!student->hasPassedAllExams()) {
                cout << student->getName() << endl;
            }
        }
    }
    catch (const std::exception& e) {
        cerr << "Виникла помилка: " << e.what() << endl;
    }

    // Звільняємо пам'ять
    for (const auto& student : students) {
        delete student;
    }

    return 0;
}