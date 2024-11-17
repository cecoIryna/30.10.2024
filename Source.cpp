#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template <typename T>
class Queue {
    Node<T>* Head; 
    Node<T>* Tail; 
    int count; 

public:
    // Конструктор
    Queue() : Head(nullptr), Tail(nullptr), count(0) {}

    // Деструктор
    ~Queue() {
        Clear();
    }

    // Добавление элемента
    void Add(const T& value) {
        Node<T>* temp = new Node<T>;
        temp->data = value;
        temp->next = nullptr;
        temp->prev = Tail;

        if (Tail) {
            Tail->next = temp;
        }
        else {
            Head = temp;
        }

        Tail = temp;
        count++;
    }

    // Удаление элемента из начала очереди
    T Del() {
        if (isEmpty()) {
            cout << "Queue is empty!";
        }

        Node<T>* temp = Head;
        T value = temp->data;

        Head = Head->next;

        if (Head) {
            Head->prev = nullptr;
        }
        else {
            Tail = nullptr;
        }

        delete temp;
        count--;

        return value;
    }

    // Получение элемента из начала очереди без удаления
    T Extract() const {
        if (isEmpty()) {
            cout << "Queue is empty!";
        }
        return Head->data;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return count == 0;
    }

    // Получение размера очереди
    int getCount() const {
        return count;
    }

    // Очистка очереди
    void Clear() {
        while (!isEmpty()) {
            Del();
        }
    }

    // Вывод элементов очереди
    void Print() const {
        Node<T>* temp = Head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Пример использования
int main() {
    Queue<int> q;

    q.Add(10);
    q.Add(20);
    q.Add(30);

    cout << "Queue contents: ";
    q.Print();

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Head element: " << q.Extract() << endl;

    cout << "Delete: " << q.Del() << endl;
    cout << "Queue contents after delete: ";
    q.Print();

    cout << "Queue count: " << q.getCount() << endl;

    q.Clear();
    cout << "Queue cleared.\n";
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}