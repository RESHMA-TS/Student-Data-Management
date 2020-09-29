#include <iostream>
#include <fstream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main(){

    char data[20];//consider the length of data as 20
    int n=0,option=0,count_n=0;
     //this is initial mark alloted to a subject
    string empty = "00";
    string Invigilator = "";
    //file name in which database is stored
    ifstream f("Example.txt");
    string line;

    //for count the total number if lines int the file
    for(int i = 0;std::getline(f,line);++i){
        count_n++;
    }
    //following while loop to print all available options in the database
    while(option !=6){
        cout<<"Available operations:"<<endl;
        cout<<"1.Add New Students"<<endl;
        cout<<"2.Student Login"<<endl;
        cout<<"3.Faculty Login"<<endl;
        cout<<"4.Invigilator Login"<<endl;
        cout<<"5.Admin View"<<endl;
        cout<<"6.Exit:"<<endl;

       cout<<"Enter option:"<<endl;
     cin>>option;

   if(option == 1){
   cout<<"Enter the number of students:";
   cin>>n;

   count_n = count_n + n;

   for(int i=0;i<n;i++){
    ofstream outfile;
         outfile.open("Example.txt",ios::app);
    //enter the data of a single student
    cout<<"Enter your Registration Number:"<<endl;
    cin>>data;
    outfile<<data<<"\t";

    cout<<"Enter your name:";
    cin>>data;
    int len = strlen(data);

    while (len < 20){
        data[len] = ' ';
        len = len + 1;
        }
    outfile << data << "\t";
    //Inserting empty data initially into the file
    outfile << empty << "\t";
    outfile << empty << "\t";

        cout << "Enter your Invigilator ID: "<<endl;
        cin >> Invigilator;

        outfile << Invigilator << endl;
    }}

    else if (option == 2){
        char regno[10];
        cout << "Enter your registration number: ";
        cin >> regno;
         ifstream infile;
        int check = 0;
        infile.open("Example.txt",ios::in);

        //This loop prints out the data according to the registration number specified.
        while (infile >> data){
        if (strcmp(data,regno) == 0){
            cout << "\nRegistration Number: " << regno << endl;
            infile >> data;
            cout << "Name: " << data<< endl;

            infile >>data;
            cout << "CSE2001 mark : " << data << endl;

            infile>>data;
            cout<<"CSE2002 mark: "<<data<<endl;

            infile>>data;
            cout<<"Invigilator ID: "<<data<<endl;

            infile.close();
            check = 1;}
        }
         if (check == 0){
            cout<<"Not found such registration number!"<<endl;}

    }

    //This loop is used to view and add marks to the database of a student.
    else if (option == 3){
        char subcode[7];
        cout << "Enter your subject code: ";
        cin >> subcode;
        string code1 = "CSE2001", code2 = "CSE2002",mark = "";
        ifstream infile;
        int check = 0;

        cout << "Available operations:"<<endl;
        cout<<"1. Add data about marks"<<endl
            <<"2. View data"<<endl
            <<"Enter the option: "<<endl;
        cin >> option;

          if (option == 1){
            cout << "Warning! You would need to add mark"<<endl
                 <<"details for all the students!" << endl;



           for(int i = 0;i < count_n;i++){
                fstream file("Example.txt");
            //The seek in file has been done according to the inserting data length.
            // It needs to adjusted accordingly for different lengths of data.

              if(strcmp(subcode,code1.c_str()) == 0){
                     file.seekp(26+37*i,std::ios_base::beg);
                   cout << "Enter the mark of student#" << (i+1) << " : ";
                cin >> mark;
                file.write(mark.c_str(),2);}

              if(strcmp(subcode,code2.c_str()) == 0){
                file.seekp(29+37*i,std::ios_base::beg);
                cout << "Enter the mark of student#" << (i+1) << " : ";
                cin >> mark;
                file.write(mark.c_str(),2);}
            }

        }

        //This loop is to view marks of a student.
        //The in file commands have been used to get a specific mark
        //only since the data has been separated by a tab space.

        else if(option == 2){
        infile.open("Example.txt",ios::in);
        if (strcmp(subcode,code1.c_str()) == 0){
            cout << "Registration number - Marks\n" << endl;
            while(infile >> data){
            cout << data;
            infile >> data;
            infile >> data;
            cout << " - " << data << endl;
            infile >> data;
            infile >> data;
            check = 1;
            }
        }

        infile.close();
        infile.open("Example.txt",ios::in);

        if(strcmp(subcode,code2.c_str()) == 0){
           cout << "Registration number - Marks\n" << endl;
            while(infile >> data){
            cout << data;
            infile >> data;
            infile >> data;
            infile >> data;
            cout << " - " << data << endl;
            infile >> data;
            check = 1;
            }
        }}

        infile.close();

        if (check == 0){
            cout << "No such subject code found!" << endl;
        }

    }

    //Displays all the details of student under the same invigilator ID.

    else if (option == 4){
        char invigid[7];
         cout << "Enter your invigilator ID: "<<endl;
         cin >> invigid;
            int check = 1;
        char temp1[100], temp2[100], temp3[100];
        char temp4[100], id[100];
        ifstream infile;
        infile.open("Example.txt",ios::in);

        while (infile >> temp1){
            infile >> temp2;
        infile >> temp3;
        infile >> temp4;
        infile >> id;

        if (strcmp(id,invigid) == 0){
            cout << "\nRegistration Number: " << temp1 << endl;
            cout << "Name: " << temp2 << endl;
            cout << "CSE2001 Mark: " << temp3 << endl;
            cout << "CSE2002 Mark: " << temp4 << endl;
            check = 1;
        }
        }

        if (check == 0){
            cout << "No such invigilator ID found!" << endl;
        }}

    //This loop acts as an admin

    else if(option == 5){
        char password[25];
        cout << "Enter the admin password: ";
        cin >> password;

        //This variable value can be changed according to your requirement
        //of the administrator password.

        string admin_pass = "admin";

        if (strcmp(password,admin_pass.c_str()) == 0){
            cout << "Reg No. \tName\tCSE2001\tCSE2002\t ID" << endl;
            ifstream infile;
            infile.open("Example.txt",ios::in);
            char data[20];

            while(infile >> data){
                cout << data << "\t";
                infile >> data;
                cout << data << "\t";
                infile >> data;
                cout << data << "\t";
                infile >> data;
                cout << data << "\t";
                infile >> data;
                cout << data << endl;
            }

        }
    }
}}

