#include <iostream>
#include <stdexcept>

using namespace std;

class LinkedList
{
private:
    class Node
    {
    public:
        char data;
        Node* next;
        Node(char data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
    Node* head;

public:

    LinkedList()
    {
        head = nullptr;
    }

    void PushBack(char data)
    {
        Node* NewNode = new Node(data);
        if (head == nullptr)
        {
            head = NewNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = NewNode;
        }
    }

    void PopBack()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }


    bool operator != (const LinkedList& other) const
    {
        Node* current1 = head;
        Node* current2 = other.head;
        while (current1->data != current2->data)
        {
            return true;
        }
        current1 = current1->next;
        current2 = current2->next;
        return current1 != current2;
    }

    friend LinkedList operator+(const LinkedList& list, char data)
    {
        LinkedList reesult = list;
        reesult.PushBack(data);
        return reesult;
    }
    friend LinkedList operator--(LinkedList& list, int)
    {
        LinkedList result = list;
        list.PopBack();
        return  result;
    }

    void print() const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
void list()
{

}
// Клас MyClass
class MyClass {
private:
    int value;

public:
    MyClass() {
        // Конструктор за замовчуванням
    }

    MyClass(int val) {
        // Конструктор з параметрами
        value = val;
    }

    ~MyClass() {
        // Деструктор
    }

    MyClass& operator=(const MyClass& other) {
        // Перевантажена операція присвоювання
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Інші методи та операції для класу

    int getValue() const {
        return value;
    }
};

// Виняток для класу MyClass
class MyClassException : public exception {
private:
    string message;

public:
    explicit MyClassException(const string& msg) : message(msg) {}

    virtual const char* what() const throw() {
        return message.c_str();
    }
};

// Шаблон класу MyTemplate
template <class T>
class MyTemplate {
private:
    T data;

public:
    MyTemplate() {
        // Конструктор за замовчуванням
    }

    MyTemplate(const T& value) {
        // Конструктор з параметрами
        data = value;
    }

    ~MyTemplate() {
        // Деструктор
    }

    MyTemplate& operator=(const MyTemplate& other) {
        // Перевантажена операція присвоювання
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    T getData() const {
        return data;
    }

    // Інші методи та операції для класу MyTemplate

};


int main() {

    LinkedList list1;
    list1.PushBack('1');
    list1.PushBack('2');
    list1.PushBack('3');
    cout << "List 1: ";
    list1.print();

    LinkedList list2;
    list2.PushBack('a');
    list2.PushBack('b');
    list2.PushBack('c');
    cout << "List 2: ";
    list2.print();

    if (list1 != list2) {
        cout << "List 1 i List 2 ne rivni" << endl;
    }
    else {
        cout << "List 1 і List 2 rivni" << endl;
    }

    LinkedList list3 = list1 + 'd';
    cout << "List 3 (List 1 + 'd'): ";
    list3.print();

    LinkedList list4 = list2--;
    cout << "List 4 (List 2--): ";
    list4.print();
    cout << "List 2 pisla List 2--: ";
    list2.print();
    try {
        // Тестування шаблону зі стандартними типами даних
        MyTemplate<int> myInt(10);
        cout << "Value: " << myInt.getData() << endl;

        MyTemplate<double> myDouble(3.14);
        cout << "Value: " << myDouble.getData() << endl;

        MyTemplate<string> myString("Hello");
        cout << "Value: " << myString.getData() << endl;
        
        // Тестування шаблону з типом, що визначений класом
        MyTemplate<MyClass> myObj(MyClass(10));
        cout << "Value: " << myObj.getData().getValue() << endl;

        // Приклад використання винятків для шаблону
        if (myInt.getData() > 100) {
            throw runtime_error("Value exceeds limit");
        }

        // Приклад використання винятків для типу, що визначений класом
        if (myObj.getData().getValue() > 100) {
            throw MyClassException("Value exceeds limit");
        }

        // Решта коду для тестування шаблону

    }
    catch (const MyClassException& e) {
        cout << "MyClassException: " << e.what() << endl;
    }
    catch (const std::exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
