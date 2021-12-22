#include<iostream>
#include<stack>
using namespace std;

class textEditor
{
    string input;
    stack<string> deleted;
    stack<int> append;
    public:
    textEditor()
    {
        this -> input = "";
    }
    void appendChar(string W)
    {
        input += W;
        append.push(W.length());
    }
    void deletechar(int k)
    {
        int count = 0, len = input.length();
        string temp = "";
        while(count < k)
        {
            temp = input[len - 1] + temp;   
            --len;
            ++count;
        }
        deleted.push(temp);
        if(len == 0)
        {
            input = "";
        }
        else
        {
            input = input.substr(0, len);
        }
    }
    void print(int k)
    {
        cout << input[k - 1] << endl;
    }
    void undoDelete()
    {
        int count = 0;
        string temp = deleted.top();
        deleted.pop();
        input = input + temp;
    }
    void undoInsert()
    {
        int len = input.length();
        len -= append.top();
        if(len == 0)
        {
            input = "";
        }
        else
        {
            input = input.substr(0,len);
        }
        append.pop();
    }
    void last()
    {
        cout << input[input.length() - 1] << endl;
    }
};

int main()
{
    textEditor t;
    stack<int> undocount;
    int queries, choice;
    cin >> queries;
    string input;
    while(queries)
    {
        cin >> choice;
        if(choice == 1)
        {
            cin >> input;
            t.appendChar(input);
            undocount.push(1);
        }
        else if(choice == 2)
        {
            int k;
            cin >> k;
            t.deletechar(k); 
            undocount.push(2);
        }
        else if(choice == 3)
        {
            int pos;
            cin >> pos;
            t.print(pos);
        }
        else if(choice == 4)
        {
            if(undocount.top() == 1)
            {
                t.undoInsert();
            }
            else
            {
                t.undoDelete();
            }
            undocount.pop();
        }
        else if(choice == 5)
        {
            t.last();
        }
        else 
        {
            exit(0);
        }
        queries -= 1;
    }
    return 0;  
}