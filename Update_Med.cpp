#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{ 
    string line, searchname;

    ifstream file("addMedicine.txt"); //Open file in read mode

   cout<<"Enter the name of the medicine which you want to update : ";
   getline(cin,searchname);

   while(getline(file,line))
   {
     if(line.find("Medicine Name:")!=string::npos) 
     //check karna ka 'Medicine Name:' line ma majood ha ya nahi and npos stands for no position
      {
        string FileName = line.substr(15);  //Medicine Name: (15 character) ka bad wala text nikalne ka liya
        if(FileName==searchname)
        {
          cout<<"-------------------------------------"<<endl;
          getline(file,line);
          getline(file,line);
          cout<<" Current quantity of this Medicine :"<<line.substr(19)<<endl;
          int quantity = stoi(line.substr(19));  //stio() function is used to convert (string to integer).
          int b;
          cout<<" How much more quqntity shouid be added to this medicine ? ";
          cin>>b;
          int updatequantity= quantity+b;
          cout<<" Update quantity of this Medicine :"<<updatequantity<<endl;

          //------------------------------------------------------------------------------------------

          // ----uper quqntity ko update kiya ha ,ab update quantity of file ma store karwana ha-----
          ofstream newfile("tem.txt"); // temporary file to store update quantity
          file.clear();//pahla flag clear karan
          file.seekg(0);//move the curser back to the beginning (first line) to read the file from start
          string line2;
          while(getline(file,line2))
          {
            if(line2.find("Medicine Name: " + searchname)!= string::npos) // medicine ka name newfile ma likhta ha
            {
              newfile<<line2<<endl;
              getline(file,line2); 
              newfile<<line2<<endl; 
              getline(file,line2);
              newfile<<"Medicine Quantity: "<<updatequantity<<endl;
            }
            else
            newfile<<line2<<endl;// baqi sara data(dosri medicines ka) wasa he copy kro.
          }
         file.close();
         newfile.close();
         //----------------------------------------------------------------------------------------
         //uper pahli file ka data dosri file ma copy be ho gya ha or update be hp gya ha
         //ab muja pahli file ko remove karna ha or dosri ka nam change karna ha

         remove("addMedicine.txt");// ya function pahli file ko remove ke deta ha
         if(rename("tem.txt","addMedicine.txt")==0)//ya function tem.txt file ka name change kr ka addMedicine.txt ..
         cout<<"Successfully updated "<<endl;
         else
         cout<<"File Could not be uloaded"<<endl;
         cout<<"-------------------------------------"<<endl;
          return 0;
        }
      }
   }
 cout<<"Record Not Found "<<endl;
 file.close();
 return 0;
}
