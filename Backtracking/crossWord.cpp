#include<iostream>
#include<vector>
using namespace std;

char crossword[10][10];

bool isHorizontal(int row, int column, string word)
{
    int spaces = 0;
    for(int i = column; i < 10; i++)
    {
        if(crossword[row][i] == '+' || word.length() == spaces)
        {
            break;
        }
        else if(crossword[row][i] == '-' || crossword[row][i] == word[i - column])
        {
            ++spaces;
        }
    }
    if(spaces != word.length())
    {
        return false;
    }
    return true;
}

bool isVertical(int row, int column, string word)
{
    int spaces = 0;
    for(int i = row; i < 10; i++)
    {
        if(crossword[i][column] == '+' || word.length() == spaces)
        {
            break;
        }
        else if(crossword[i][column] == '-' || crossword[i][column] == word[i - row])
        {
            ++spaces;
        }
    }
    if(spaces != word.length())
    {
        return false;
    }
    return true;
}

void HorizontalFill(int row, int column, string word)
{
    for(int i = 0; i < word.length(); i++)
    {
        if(crossword[row][column + i] != '-') 
        {
            continue;
        }
        crossword[row][column + i] = word[i];
    }
    return;
}

void verticalFill(int row, int column, string word)
{
    for(int i = 0; i < word.length(); i++)
    {
        if(crossword[row + i][column] != '-')
        {
            continue;
        }
        crossword[row + i][column] = word[i];
    }
    return;
}

void UnfillHorizontal(int row, int column, string word)
{
    int i = 0;
    while(column < 10 && crossword[row][column] != '+' && i != word.length())
    {
        if(row > 0 && crossword[row - 1][column] != '-' && crossword[row - 1][column] != '+')
        {
            ++i;
            ++column;
            continue;
        }
        else if(row < 9 && crossword[row + 1][column] != '-' && crossword[row + 1][column] != '+')
        {
            ++i;
            ++column;
            continue;
        }
        crossword[row][column] = '-';
        ++column;
        ++i;
    }
    return;
}

void UnfillVertical(int row, int column, string word)
{
    int i = 0;
    while(row < 10 && crossword[row][column] != '+' &&  i != word.length())
    {
        if(column > 0 && crossword[row][column - 1] != '-' && crossword[row][column - 1] != '+')
        {
            ++i;
            ++row;
            continue;
        }
        else if(column < 9 && crossword[row][column + 1] != '-' && crossword[row][column + 1] != '+')
        {
            ++i;
            ++row;
            continue;
        }
        crossword[row][column] = '-';
        ++row;
        ++i;
    }
    return;
}

bool fillCrossswordhelper(string words[], int size)
{
    if(size == 0)
    {
        return true;
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(crossword[i][j] == '-' || crossword[i][j] == words[0][0])
            {
                if(isHorizontal(i, j, words[0]))
                {
                    HorizontalFill(i, j, words[0]);
                    bool ans = fillCrossswordhelper(words + 1, size - 1);
                    if(ans == true)
                    {
                        return ans;
                    }
                    UnfillHorizontal(i, j, words[0]);
                }
                if(isVertical(i, j, words[0]))
                {
                    verticalFill(i, j, words[0]);
                    bool ans = fillCrossswordhelper(words + 1, size - 1);
                    if(ans == true)
                    {
                        return true;
                    }
                    UnfillVertical(i, j, words[0]);
                }
            }
        }
    }
    return false;
}

int main()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> crossword[i][j];
        }
    }

    string wordlist, temp = "";
    cin >> wordlist;
    string words[7];
    int count = 0;

    for(int i = 0; i < wordlist.size(); i++)
    {
        if(wordlist[i] == ';')
        {
            words[count] = temp;
            ++count;
            temp = "";
        }
        else
        {
            temp += wordlist[i];
        }
    }

    words[count] = temp;
    ++count;


    fillCrossswordhelper(words, count);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << crossword[i][j];
        }
        cout << endl;
    }

    return 0;
}