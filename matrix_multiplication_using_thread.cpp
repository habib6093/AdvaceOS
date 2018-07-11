#include<iostream>
#include <thread>
#include <fstream>


using namespace std;


class matrix{
  public:
   int mat[100][100];
	
};



matrix matrix_multiply(matrix one,matrix two,int size)
{
   matrix obj;
   
   for(int i=1;i<=size;i++)
   {
     int temp=1,result=0;
     
     for(int j=1;j<=size;j++)
     {
       result+=one.mat[i][j]*two.mat[j][temp];	
       
       
       if(j==size&&temp<=size)
        {
          
          obj.mat[i][temp]=result;
          result=0;
          temp++;
          j=0;
        }
        
     }
     
   }
   
   return obj;
}



void do_all(matrix one,matrix two,int size,int thread_number)
{
     std::thread::id this_id = std::this_thread::get_id();
     cout<<"...thread no: ---> "<<thread_number<<"  and thread id:---> "<<this_id<<endl;
     matrix temp=matrix_multiply(one,two,size);
     
     for(int i=1;i<=size;i++)
     {
      for(int j=1;j<=size;j++)
        {
           cout<<temp.mat[i][j]<<" ";
        }
       cout<<endl;
      }	
}





int main()
{
   ifstream cin("one.txt");	/// read from one.txt file
	
   int n,size; //number of matrix and size
   cin>>n>>size;
   
   matrix ob[n+1];
   
   for(int i=1;i<=n;i++)
   {
     for(int a=1;a<=size;a++)
     {
       for(int b=1;b<=size;b++)
        {
          int m;
          cin>>m;
          ob[i].mat[a][b]=m;
        }
     }
   }
   
   
   int count=1;
   thread th[n/2+1];
   
   for(int x=1;x<=n;x+=2)
   {
     th[count]=thread(do_all,ob[x],ob[x+1],size,count);
     count++;
   }
   
   for(int x=1;x<count;x++)
   {
      th[x].join();
   }
   
  cin.close();
  return 0;
   
}





/*
4 2 // number of matrix and matrix size 

1 2
3 4

2 0
1 2

2 0
1 2

1 2
3 4

*/
