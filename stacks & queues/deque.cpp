#include<iostream>
using namespace std;

class deque
{
    int *arr, capacity, size;
    int front, rear;
    public:
    deque(int totalsize)
    {
        arr = new int[totalsize];
        capacity = totalsize;
        size = 0;
        rear = 0;
        front = -1;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void insertFront(int element)
    {
        if(size == capacity)
        {
            cout << -1 << endl;
            return;
        }
        else if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = ((front - 1) % capacity + capacity) % capacity;
        }
        arr[front] = element;
        ++size;
    }
    void insertRear(int element)
    {
        if(size == capacity)
        {
            cout << -1 << endl;
            return;
        }
        else if(front == -1)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = element;
        ++size;
    }
    void deleteFront()
    {
        if(isEmpty())
        {
            cout << -1 << endl;
            return;
        }
        if(size == 0)
        {
            front = -1;
            rear = 0;
        }
        else
        {
            front= (front + 1) % capacity;
        }
        --size;
    }
    void deleteRear()
    {
        if(isEmpty())
        {
            cout << -1 << endl;
            return;
        }
        if(size == 0)
        {
            front = -1;
            rear = 0;
        }
        else
        {
            rear = ((rear - 1) % capacity + capacity) % capacity;
        }
        size--;
    }
    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }
};

int main()
{
    int choice = 1, opchoice;
    int size, data;
    cout << "Enter the size of the queue\n";
    cin >> size;
    deque q(size);
    while(choice)
    {
        cout << "Enter the operation you want to performe\n";
        cout << "1.InsertFront\n2.Insertrear\n3.DeleteFront\n4.DeleteRear\n5.GetFront\n6.Getrear\n7.Exit\n";
        cin >> opchoice;
        if(opchoice == 1)
        {
            cin >> data;
            q.insertFront(data);
        }
        else if(opchoice == 2)
        {
            cin >> data;
            q.insertRear(data);
        }
        else if(opchoice == 3)
        {
            q.deleteFront();
        }
        else if(opchoice == 4)
        {
            q.deleteRear();
        }
        else if(opchoice == 5)
        {
            cout << q.getFront();
        }
        else if(opchoice == 6)
        {
            cout << q.getRear();
        }
        else
        {
            exit(0);
        }
        cout << "\nDo you want to performe any other operation\n";
        cin >> choice;
        if(!choice)
        {
            break;
        }
    }
    return 0;
}