#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{ 
    string line;
    int searchid;

    ifstream file("addMedicine.txt"); 
    //Open file in read mode
    ofstream newfile("temporary.txt");
    //make a temporary file to copy data from 1st file which we will not to delete

    cout<<"Enter the ID of the medicine which you want to delete : ";
    cin>>searchid;

   
   int a=0;
   while(getline(file,line))
   {
     if(line.find("Medicine ID: " + to_string(searchid))!= string::npos) //npos stands for no position
      {  a=1;
        for(int a=0;a<=5;a++)
        {    
          getline(file,line);
        }
        continue;
      }
      newfile<<line<<endl;
    }
    file.close();
    newfile.close();
    remove("addMedicine.txt");
    rename("temporary.txt","addMedicine.txt");
    if(a==1)
    cout<<"Delete medicine successfully "<<endl;
    else
    cout<<"Medicine not found"<<endl;
    return 0;
}
