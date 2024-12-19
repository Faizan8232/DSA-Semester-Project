#include <iostream>
using namespace std;

class QueueArray
{
private:
    int* queue;
    int front;
    int rear;
    int size;

public:
    QueueArray(int size)
    {
        this->size = size;
        queue = new int[size];
        front = -1;
        rear = -1;
    }


    bool IsEmpty() 
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    
    bool IsFull()
    {
        if (rear == size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void EnQueue(int data) 
    {
        if (IsFull())
        {
            cout << "Queue Is Full";
            return;
        }
        if (IsEmpty())
        {
            front = 0;
        }
        queue[++rear] = data;
    }

    void DeQueue() {
        if (IsEmpty())
        {
            cout << "Queue is Empty";
            return;
        }
        front++;
    }

    void display() {
        if (IsEmpty())
        {
            cout << "Queue is Empty!";
            return;
        }
        cout << "Queue elements: "<<endl;
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << endl;
        }
    }
};

int main()
 {
    QueueArray queue(5);

    queue.EnQueue(10);
    queue.EnQueue(20);
    queue.EnQueue(30);
    queue.EnQueue(40);
    queue.EnQueue(50);
  queue.DeQueue();
    queue.display();
    return 0;
}
