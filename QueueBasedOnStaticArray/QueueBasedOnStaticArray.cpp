#include <iostream>
using namespace std;

template <typename T, int SIZE> // non-type параметр
class Queue 
{
private:
    T arr[SIZE]; // Масив для зберігання даних
    int front; // Індекс початку черги
    int rear; // Індекс кінця черги
    int count; // Кількість елементів у черзі


    bool isEmpty() const
    {
        return count == 0;
    }

    bool isFull() const
    {
        return count == SIZE;
    }

public:
    Queue() : 
        front(0), 
        rear(-1),
        count(0) 
    {
    }

    void enqueue(const T& value) 
    {
        if (isFull()) 
        {
            cerr << "Queue is full. Cannot enqueue." << endl;

            return;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
    }

    void dequeue()
    {
        if (isEmpty()) 
        {
            cerr << "Queue is empty. Cannot dequeue." << endl;

            return;
        }

        front = (front + 1) % SIZE;
        count--;
    }

    const T& peek() const 
    {
        if (isEmpty())
        {
            cerr << "Queue is empty." << endl;

            static T dummy;

            return dummy;
        }
        return arr[front];
    }

    void display() const 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        }

        cout << arr[rear] << endl;
    }
};

int main() 
{
    const int SIZE = 5;
    Queue<int, SIZE> myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Front of the queue: " << myQueue.peek() << endl;

    cout << "Queue elements: ";
    myQueue.display();

    myQueue.dequeue();
    cout << "After dequeue:" << endl;
    cout << "Front of the queue: " << myQueue.peek() << endl;
    cout << "Queue elements: ";
    myQueue.display();

    return 0;
}