#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Medicine
{
 int id;
 string name;
 int quantity;
 int price;
 string mfDate;
 string exDate;
};

//--------Add_Medicine ka function---------
void addMedicine(int q)
{
 Medicine med;
 ofstream file("addMedicine.txt",ios::app);
 cout<<"-----Add Medicine Detail -----"<<endl;
 for(int z=1; z<=q; z++)
   {
     cout<<"Enter Medicine ID :  ";cout<<endl;
     cin>>med.id;
     cin.ignore();
     cout<<"Enter Medicine name :  ";cout<<endl;
     getline(cin,med.name);
     cout<<"Enter Medicine Price :  ";cout<<endl;
     cin>>med.price;
     cin.ignore();
     cout<<"Enter Medicine Quantity :  ";cout<<endl;
     cin>>med.quantity;
     cin.ignore();
     cout<<"Enter Manufacturing date (Day/Month/Year) :  ";cout<<endl;
     getline(cin,med.mfDate);
     cout<<"Enter Expiry date (Day/Month/Year) :  ";cout<<endl;
     getline(cin,med.exDate);
     //-----File ma data ks tra dekha ga-----
     file<<"Medicine ID: "<<med.id<<endl;
     file<<"Medicine Name: "<<med.name<<endl;
     file<<"Medicine Price: "<<med.price<<endl;
     file<<"Medicine Quantity: "<<med.quantity<<endl;
     file<<"Medicine ManuDate: "<<med.mfDate<<endl;
     file<<"Medicine ExDate: "<<med.exDate<<endl;
     file<<" -----------------------------------------"<<endl;
     cout<<" -----------------------------------------"<<endl;
   }
cout<<" Medicines successfully Added "<<endl;
file.close();
}

//------Add_Medicine ka main function ------
int main()
{ int i;
    do{
      cout<<" Welcome here "<<endl;
      cout<<" Press 1 to add mdicine :  ";cout<<endl;
      cout<<" Press 2 to exit :  ";
      cin>>i;
      switch(i)
       {
         case 1:
         {  int q;
           cout<<"How many medicine do you want to added in file : "<<endl;
           cin>>q;
           addMedicine(q);
           break;
         }
         case 2:
         cout<<" Program exit "<<endl;
         break;
         default:
         cout<<"Invalid choice ";
       }
    }while(i!=2);

return 0;
}