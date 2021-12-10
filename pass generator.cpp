#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>

using namespace std;

void gen_pass(int n)
{
    int i;
    srand(time(0));
    string x = "QW$%AxcvbnERTlkjhgfdsapoiuytSDFYUIOP30@#mGHJKLMN987564!BVCXZzrewq12&*-+?/";
    while(n)
    {
        i = rand() % x.length();
        cout<<x[i];
        n--;
    }
}

int main()
{
   int n;

   cout<<"Enter password length : ";
   cin>>n;

   gen_pass(n);

    return 0;
}
