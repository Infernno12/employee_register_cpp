#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main(){
    int a, i=0;
    string text, old, password1, pass, name, password0, age, emp_id, word, word1, id;
    string creds[4], cp[4];

    cout<< "     Security System        "<<endl;

    cout<<"_______________________________"<<endl;
    cout<<"|                             |"<<endl;
    cout<<"|         1.Register          |"<<endl;
    cout<<"|         2.Login             |"<<endl;
    cout<<"|         3.Change Password   |"<<endl;
    cout<<"|         4.End Program       |"<<endl;
    cout<<"|_____________________________|"<<endl<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter Your Choice:- ";
        cin>>a;
        switch(a){
            /* case 1: for registration */
            case 1:{
                cout<<"_______________________________"<<endl;
                cout<<"|                              |"<<endl;
                cout<<"|           Register           |"<<endl;
                cout<<"|______________________________|"<<endl<<endl;
                cout<<"Please enter your Employee_id:- ";
                cin>>id;
                cout<<"Please enter your name:- ";
                cin>>name;
                cout<<"Please enter the password:- ";
                cin>>password0;
                cout<<"Please enter your age:- ";
                cin>>age;
            /* creating a object of ofstream class so that we can create and write in a file */
                ofstream of1;

            /* now using object to open the file and save the credential */
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<id<<"\n";
                    of1<<name<<"\n";
                    of1<<password0<<"\n";
                    of1<<age;
                    cout<<"Registration successfull"<<endl;
                }

                break;
            }
            /* case2: for Login*/
            case 2:{
                i=0;

                cout<<"_______________________________"<<endl;
                cout<<"|                              |"<<endl;
                cout<<"|           Login              |"<<endl;
                cout<<"|______________________________|"<<endl<<endl;

            /* creating a object of ifstream class so that we can read from a file */
                ifstream of2;

            /* now using the object to open the file and matching the credential */
                of2.open("file.txt");
                cout<<"Please enter the Employee_id:- ";
                cin>>emp_id;
                cout<<"Please enter the password:- ";
                cin>>pass;

                if(of2.is_open())//for open
                {
                    while(!of2.eof()){// for end of file
                        while(getline(of2, text)){//for line by line reading
                            istringstream iss(text);//this object is used to stream the string and store it using the extraction operator
                            iss>>word;
                            creds[i]=word;
                            i++;
                        }

                        if(emp_id==creds[0] && pass==creds[2])
                        {
                            cout<<"---Log in successfull---";
                            cout<<endl<<endl;

                            cout<<" Details: "<<endl;

                            cout<<" Employee_id: "+ id<<endl;
                            cout<<" Name: "+ name<<endl;
                            cout<<" Password: "+ password0<<endl;
                            cout<<" Age: "+ age<<endl;
                        }else{
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|           1. Press 2 to Login             |"<<endl;
                            cout<<"|           2. Press 3 to Change Password   |"<<endl;
                            break;
                        }
                    }
                }

                break;
            }
            /* case 3: for password Change */
            case 3:{
                i=0;

                cout<<"--------------------------Change Password--------------------------"<<endl;

                    ifstream of0;
                    of0.open("file.txt");
                    cout<<"Enter the old password:- ";
                    cin>>old;
                    if(of0.is_open()){
                        while(!of0.eof()){
                            while(getline(of0, text)){
                                istringstream iss(text);
                                iss>>word1;
                                cp[i]=word1;
                                i++;
                            }

                            if(old == cp[2]){
                                of0.close();
                                ofstream of1;
                                of1.open("file.txt");
                                if(of1.is_open()){
                                    cout<<"Enter your new password:- ";
                                    cin>>password0;
                                    cout<<"Enter your password again:- ";
                                    cin>>password1;

                                    if(password0==password1){
                                        of1<<cp[0]<<"\n";
                                        of1<<cp[1]<<"\n";
                                        of1<<password0<<"\n";
                                        of1<<age;
                                        cout<<"Password changed successfully"<<endl;
                                    }else{
                                        of1<<cp[2]<<"\n";
                                        of1<<old;
                                        cout<<"Password do not match"<<endl;
                                    }
                                }
                            }else{
                                cout<<"Please enter a valid password"<<endl;
                                break;
                            }
                        }
                    }

                break;
            }
            /* case 4: for end program */
            case 4:{
                cout<<"____________Thankyou!____________";
                break;
            }

            default:
             cout<<"Enter a valid choice";
        }
    }while(a != 4);
    return 0;
}
