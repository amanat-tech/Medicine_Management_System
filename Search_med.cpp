#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{ 
    string line, searchname;
    int id, quantity, price;
    string exDate, mfDate;

    ifstream file("addMedicine.txt"); //Open file in read mode

   cout<<"Enter Medicine name that you want to research: ";
   getline(cin,searchname);

   while(getline(file,line))
   {
     if(line.find("Medicine Name:")!=string::npos) 
     //check karna ka 'Medicine Name:' line ma majood ha ya nahi and npos stands for no position
      {
        string FileName=line.substr(15);  //Medicine Name: (15 character) ka bad wala text nikalne ka liya
        if(FileName==searchname)
        {
          cout<<"-------------------------------------"<<endl;
          cout<<"Medicine Name: "<<FileName<<endl;
          getline(file,line);cout<<"Price : "<<line<<endl;
          getline(file,line);cout<<"Quantity : "<<line<<endl;
          getline(file,line);cout<<"ManuDate : "<<line<<endl;
          getline(file,line);cout<<"ExDate : "<<line<<endl;
          cout<<"-------------------------------------"<<endl;
          file.close();
          return 0;
        }
      }
   }
 cout<<"Record Not Found "<<endl;
 file.close();
 return 0;
}
