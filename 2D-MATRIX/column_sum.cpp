#include<iostream>
using namespace std;

// int main()
// {
//     int rows, col, sum = 0, arr[1000][1000];
//     cout<<"Enter the rows and columns\n";
//     cin>>rows>>col;

//     for(int i = 0; i < rows; i++)
//     {
//         for(int j = 0; j < col; j++)
//         {
//             cin>>arr[i][j];
//         }
//     }

//     for(int i = 0; i < col; i++)
//     {
//         for(int j = 0; j < rows; j++)
//         {
//             sum = sum + arr[j][i];
//         }
//         cout<<sum<<" ";
//         sum = 0;
//     }
//     return 0;
// }

void minLengthWord(char input[], char output[]){
		// Write your code here
    int min = INT_MAX;
    int index=-1;
  
    for(int i =0; input[i] != '\0';){
        int j;
        int count = 0;
        for(j = i ; (input[j] != ' ' || input[j] != '\0'); j++){
            count++;
        }
       if(count<min){
           min =count;
           index = i;
        }
        if(input[j] == '\0'){
            break;
        } else {
            i = j+1;
        }
    }  
    int k=0;
    for(int i=index; (input[i] != ' ') || (input[i] != '\0'); i++){
        output[k] = input[i];
        k++;
    }
    output[k] = '\0';
}

int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
