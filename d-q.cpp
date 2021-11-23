#include <iostream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{

    string line;
    ifstream myfile;
    myfile.open("tcp-example.tr");

   if(!myfile.is_open()) {
      perror("Error open");
      exit(EXIT_FAILURE);
   }



   int n=0;


    ofstream file;
  file.open ("enqueue.cwnd");

   ofstream file2;
  file2.open ("dequeue.cwnd");

static double b[500000];
   static double a[500000];
   static double w[500000];
     //  double b1[60000];
int i=0;
int j=0;
   float time;

    while(getline(myfile, line)) {



    if(line.at(0)=='+'&& line.find("NodeList/0/") != std::string::npos)
    {


          n++;

          int count=2;
          string m1="";
          while(line.at(count)!='/')
          {
           m1.push_back(line.at(count));

              count++;
          }
           file <<m1<<"\t\t";
           file<<n;
         double num_double = std::stod(m1);
         a[i]=num_double;
         i++;
          file<<"\n";
    }

     if(line.at(0)=='-'&& line.find("NodeList/0/") != std::string::npos)
    {

        n--;

          int count=2;
          string m2="";
          while(line.at(count)!='/')
          {
           m2.push_back(line.at(count));

              count++;
          }

       double num_double = std::stod(m2);
         b[j]=num_double;
         j++;


    }
    }
      file.close();
      myfile.close();
    for(int i=0;i<j;i++)
    {

        w[i]=b[i]-a[i];
    }
for(int i=0;i<j-1;i++)
{
        file2 <<b[i]<< "\t\t"<<w[i];
        file2<<"\n";
}
      file2.close();

    return 0;
}
