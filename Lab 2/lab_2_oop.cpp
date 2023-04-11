

#include <iostream>
using namespace std;


class LinkedList
{
private:
    class Node
    {
    public:
        char data;
        Node* next;
        Node (char data, Node* next = nullptr)
        {
            this ->data = data;
            this ->next = next;
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
            while (current ->next != nullptr)
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
            cout << current -> data <<" ";
            current = current->next;
        }
        cout << endl;
    }
};  
void list()
{
     LinkedList operator = (const LinkedList& obj);
    {
        
    }
}

int main()
{
    LinkedList list1;
    list1.PushBack('1');
    list1.PushBack('2');
    list1.PushBack(')3';
    std::cout << "List 1: ";
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
    

    return 0;
}
        
    


