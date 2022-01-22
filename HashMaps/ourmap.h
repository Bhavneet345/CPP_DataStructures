#include<iostream>
using namespace std;
template<typename v>

class node
{
    public:
    v value;
    string key;
    node<v> *next;
    node(string key, v value)
    {
        this -> key = key;
        this -> value = value;
        this -> next = nullptr;
    }
    ~node()
    {
        delete this -> next;
    }
};

template<typename v>
class map
{
    node<v>**bucket;
    int size, num_bucket;
    void rehashing()
    {
        node<v> **temp = bucket;
        node<v> **newtemp = new node<v>*[2 * num_bucket];
        bucket = newtemp;
        for(int i = 0; i < 2 * num_bucket; i++)
        {
            bucket[i] = nullptr;
        }
        int oldcount = num_bucket;
        num_bucket *= 2;
        size = 0;
        for(int i = 0; i < oldcount; i++)
        {
            node<v> *head = temp[i];
            while(head != nullptr)
            {
                insert(head -> key, head -> value);
                head = head -> next;
            }
        }
        for(int i = 0; i < oldcount; i++)
        {
            delete temp[i];
        }
        delete [] temp;
        return;
    }
    public:
    map(int num)
    {
        size = 0;
        bucket = new node<v>*[num];
        num_bucket = num;
        for(int i = 0; i < num; i++)
        {
            bucket[i] = nullptr;
        }
    }
    ~map()
    {
        for(int i = 0; i < num_bucket; i++)
        {
            delete bucket[i];
        }
        delete [] bucket;
    }
    int getSize()
    {
        return size;
    }
    private:
    int getbucketIndex(string key)
    {
        int hashcode = 0, currentCoeff = 1;
        for(int i = key.length(); i >= 0; i--)
        {
            hashcode += key[i] * currentCoeff;
            hashcode %= num_bucket;
            currentCoeff *= 37;
            currentCoeff %= num_bucket;
        }
        return hashcode % num_bucket;
    }
    public:
    double getloadFactor()
    {
        double loadfactor = (1.0 * size) / num_bucket;
        return loadfactor;
    }
    void insert(string key, v value)
    {
        int bucketIndex = getbucketIndex(key);
        node<v> *head = bucket[bucketIndex];
        while(head != nullptr)
        {
            if(head -> key == key)
            {
                head -> value = value;
                return;
            }
            head = head -> next;
        }
        head = bucket[bucketIndex];
        node<v> *newnode = new node<v>(key, value);
        newnode -> next = head;
        bucket[bucketIndex] = newnode;
        ++size;
        if(getloadFactor() > 0.7)
        {
            rehashing();
        }
        return;
    }
    v getvalue(string key)
    {
        int bucketIndex = getbucketIndex(key);
        node<v> *head = bucket[bucketIndex];
        while(head != nullptr)
        {
            if(head -> key == key)
            {
                return head -> value;
            }
            head = head -> next;
        }
        return 0;
    }
    v deleteKey(string key)
    {
        int bucketIndex = getbucketIndex(key);
        node<v> *head = bucket[bucketIndex];
        node<v> *prev = nullptr;
        while(head != nullptr)
        {
            if(head -> key == key)
            {
                if(prev == nullptr)
                {
                    bucket[bucketIndex] = head -> next;
                }
                else
                {
                    prev -> next = head -> next;
                }
                v value = head -> value;
                head -> next = nullptr;
                delete head;
                --size;
                return value;
            }
            prev = head;
            head = head -> next;
        }
        return 0;
    }
};