#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main()
{
    ifstream file;
    string word;
    int w_count = 0;

    char filename[30];

    cout<<"Enter File Name : ";
    cin>>filename;

    file.open(filename);
    if (file)
        while(!file.eof())
        {
            file>>word;
            cout<<word<<" ";
            w_count++;
        }
     else
        {
          cout<<"File not found";
          exit(0);
        }
    file.close();

    cout<<"\n\nTotal Words : "<<w_count;

    return 0;
}
