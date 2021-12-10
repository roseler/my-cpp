#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

// Prototyping
void input();
void searchname();
void searchage();
void searchprogram();
void quit();
void displayall();
void search();
void deleteFile();
void editFile();

// Main Funtion
int main()
{   
      
   system ("title Basic Database by Group 9");
   system ("cls");
   system ("color 0A");
       int choice;
       cout << "1.Input a new name" << endl;
       cout << "2.Search Database for Informations" << endl;
       cout << "3.Clear Log" << endl;
       cout << "4.Edit file" << endl;
       cout << "5.Exit Program" << endl;
       cin >> choice;

switch (choice){
       case 1:
            input();
            break;
       case 2:
            search();
            break;
       case 3:
            deleteFile();
            break;
       case 4:
            editFile();
            break;
       case 5:
            quit();
            break;
            
       cin.get();
            

       }
       }
void editFile()
{
 string name, input, newName, decision;
 int age;
 char program[50];
 ifstream student("database.txt");
 if (!student.eof()){
student >> name >> age >> program;
}
 system("cls");
 
 cout << "Enter the name: ";
 cin >> input;

 if (input == name)
 {
     
     cout << "Name: "<< name << ' ' << "Age: " << age << ' '<< "Program: " << program << endl ;
     cout << "Is this the correct name[y][n]:";
     cin >> decision;
     if (decision == "y"){
     cout << "Enter the new name:";
     cin >> newName;
     name = newName;      
           } 
            
     student.close();
     }
    
     ofstream student2("database.txt", ios::app);
     student2 << "Name: "<< name << ' ' << "Age: " << age << ' '<< "Program: " << program << endl ;
     student2.close();
 system("pause");
 main();
     }
     
void input()
{       
 string name;
 int age; 
 char program[50];
 ofstream database("database.txt", ios::app);
 system("cls");
 cout << "Enter the new name" << endl;
 cin >> name;
 cin.sync();
 system("cls");
 cout << "Enter the age." << endl;
 cin >> age;
 system("cls");
 
 cout << "Enter the student's program" << endl;
 cin >> program;

        
 database << "Name: "<< name << ' ' << "Age: " << age << ' '<< "Program: " << program << endl ;     
 database.close(); 
 main();
     }
void searchname()
{
     ifstream student("database.txt");
     string name;
     string str, line;
     int age, offset;
     char program[50];
     system("CLS");
     cout << "Enter the student's name: ";
     cin >> str;
              
     while (student >> name >> age >> program){  
           if (str == name){
     system ("CLS");
     cout << "Student found" << endl;
     cout << "Name" << ' ' << "Age" << ' ' << "Program" << endl;
     cout << "---------------" << endl;     
     cout << "Name: "<< name << ' ' << "Age: " << age << ' '<< "Program: " << program << endl ;
     }
     }

            
     while (student >> name ){
                 if (str != name){
                 system ("CLS") ;   
                 cout << "Nobody under that name exists" << endl;     
                      
                      }
                      }
     system ("pause");
     main();
     
     
 }
void searchage()
 {
     ifstream student("database.txt");
     string name;
     int age ;
     int fage;
     char program[50];
     system ("CLS");
     cout << "Enter the age of student/s: ";
     cin >> fage;
     while (student >> name >> age >> program){
           if (fage == age){
                    system ("CLS");
                    cout << "Student(s) found" << endl;
                    cout << "Name" << ' ' << "Age" << ' ' << "Program" << endl;
                    cout << "---------------" << endl;
                    cout << "Name: "<< name << ' ' << "Age: " << age << ' '<< "Program: " << program << endl ;
                    }
                    }
     while (student >> age){      
           if (fage != age){
                    system ("CLS");
                    cout << "No student(s) found"<< endl;
                    
                    
                    }  
           }
           system ("pause");
           cin.get();
           main();
  }
void searchprogram()
{
     ifstream student ("database.txt");
     string name;
     int age ;
     char program[50];
     char fprogram[50];
     system ("CLS");
     cout << "Enter student's program: ";
     cin >> fprogram;
     while (student >> name >> age >> program){
           if (fprogram == program ){
                       system ("cls");
                       cout << "Student found"<< endl;
                       cout << "Name" << ' ' << "Age" << ' ' << "Program" << endl;
                       cout << "---------------" << endl;
                       cout << "Name: "<< name << ' ' << "Age: " << age << ' '<< "Program: " << program << endl ;
                       
                       }
                       }
     while (student >> program){
            if (fprogram != program){
                system ("CLS");
                cout << "No student(s) found" << endl;
                }
           }
     system("pause");
     cin.get();
     main();
 }
void quit()
{
 system ("CLS");
 cout << "Thank you for using Group 9 database" << endl;
 system ("pause");
 cin.get();
     } 
void displayall()
{
     ifstream student("database.txt");
     int age;
     char program[50];
     string name;
     system ("CLS");
     cout << "Entire student/s database"<< endl;
     cout << "Name" << ' ' << "Age" << ' ' << "Program" << endl;
     cout << "---------------" << endl;
     while (student >> name >> age >> program){
     cout << "Name: "<< name << " " << "Age: " << age << " " << "Program: " << program << endl ;
     }
     system ("pause");
     cin.get();
     main();
     
     }
void search()
{
     int age;
     string name;
     char program;
     int choice2;
     system ("CLS");
     
     cout << "1.Search by name" << endl;
     cout << "2.Search by age" << endl;
     cout << "3.Search by program" << endl;
     cout << "4.Display all students" << endl;
     cout << "5.Back" << endl;
     cout << "6.Exit program" << endl;
     cin >> choice2;
     
     
     switch (choice2){
            case 1:
                 searchname();
                 break;
            case 2:
                 searchage();
                 break;
            case 3:
                 searchprogram();
                 break;
            case 4:
                 displayall();
                 break;
            case 5:
                 main();
                 break;
            case 6:
                 quit();
                 break;
                 }
                 
            
            
            
            }
void deleteFile()
{
     
     string decision;
     cout << "Are you sure?[Y]es[N]o" << endl;
     cin >> decision;
     if (decision == "y"){
     ofstream student("database.txt");
     system("cls");
     cout << "Successfully Completed!" << endl;
     system("pause");
     student.close();
     main();
     }
     else{
          main();
          }
     }
