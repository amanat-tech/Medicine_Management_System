#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Function of Regisrter
void f_register() 
{   string username , password;
    ofstream file("login.txt",ios::app);
    cout<<" Register your Account "<<endl;
    cout<<" Username :  "<<endl;
    cin>>username;
    cout<<" Password :   "<<endl;
    cin>>password;
    file<<username<<" "<<password<<endl;
    file.close();
    cout<<endl<<" Registration Successful "<<endl;
}

//Function of Login
void f_login()
{ string username ;
  string a ,b ;//The two variable are used to read username and pasword in file
  int find=0;
  cout<<" Enter Username : "<<endl;
  cin>>username;
  ifstream file("login.txt");
  while(file >> a >> b )
  if(a==username)
  {
    find=1; 
    break ;
  }
 file.close();
 if(find==1)
 cout<<" You have already registered. "<<endl;
 else{
 cout<<" Invalid Username ."<<endl;
 cout<<" No account find with this username ."<<endl;}
 
}

//main function
int main(){
 int a;
 do{
  cout<<" -----Login and Registration Center------"<<endl;
  cout<<"Press 1 for Registration "<<endl;
  cout<<"Press 2 for login "<<endl;
  cout<<"Press 3 for Exit "<<endl;
  cin>>a;
  switch(a)
  {
   case 1:
   f_register() ;
   break;
   case 2:
   f_login();
   break;
   case 3:
   cout<<" Program Exit 🤝"<<endl;
   break;
   default:
   cout<<" Invalid choice ";
  }
 } while(a<3);
 return 0;
}