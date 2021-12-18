#include<iostream>
using namespace std;
template <typename type>

class queue
{
    type *arr;
    int front, rear, size, capacity;
    public:
    queue(int totalsize)
    {
        arr = new int[totalsize];
        rear = 0;
        front = -1;
        size = 0;
        capacity = totalsize;
    }
    bool isEmpty()
    {
        return 0;
    }
    void enqueue(type element)
    {
        if(size == capacity)
        {
            int *newarr = new type[capacity * 2], temp = front, j = 0;
            for(int i = 0; i < size; i++)
            {
                newarr[i] = arr[temp];
                temp = (temp + 1) % size;
            }
            rear = capacity;
            type *duplicate = arr;
            arr = newarr;
            capacity *= 2;
            delete [] duplicate;
            front = 0;
        }
        arr[rear] = element;
        rear =  (rear + 1) % capacity;
        if(front == -1)
        {
            front = 0;
        }
        ++size;
    }
    type deque()
    {
        if(isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        --size;
        int element = arr[front];
        front = (front + 1) % capacity;
        if(size == 0)
        {
            front = -1;
            rear = 0;
        }
        return element;
    }
    type getFront()
    {
        if(!isEmpty())
        {
            return arr[front];
        }
        cout << "Queue is empty\n";
        return 0;
    }
    int getSize()
    {
        if(rear == 0)
        {
            return 0;
        }
        return size;
    }
    void display()
    {
        if(isEmpty())
        {
            cout << "Queue is empty\n";
            return;   
        }
        int temp = front;
        for(int i = 0; i < size; i++)
        {
            cout << arr[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    int choice = 1, opchoice;
    int size;
    cout << "Enter the size of the queue\n";
    cin >> size;
    queue <int> q(size);
    while(choice)
    {
        cout << "Enter the operation you want to performe\n";
        cout << "1.Enqueue\n2.Deque\n3.Size\n4.Front\n5.Display\n6.Exit\n";
        cin >> opchoice;
        if(opchoice == 1)
        {
            int data;
            cin >> data;
            while(data != -1)
            {
                q.enqueue(data);
                cin >> data;
            }
            q.display();
        }
        else if(opchoice == 2)
        {
            int data = q.deque();
            cout << data << endl;
        }
        else if(opchoice == 3)
        {
            int size = q.getSize();
            cout << size << endl;
        }
        else if(opchoice == 4)
        {
            int top = q.getFront();
            cout << top << endl;
        }
        else if(opchoice == 5)
        {
            q.display();
        }
        else
        {
            exit(0);
        }
        cout << "Do you want to performe any other operation\n";
        cin >> choice;
        if(!choice)
        {
            break;
        }
    }
    return 0;
}