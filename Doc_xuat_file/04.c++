#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

void DocFile(int **a, int m, int n,int count, int limit, ifstream &ifs){
    for (int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            count++;
            ifs>>a[i][j];
            if(count == limit) return;
        }
            
    }
}

void XuatMangFile( int m, ofstream &ofs){
    ofs<<"co tong "<<m<<" so nguyen to trong ma tran"<<endl;       
}

bool soNguyenTo(int a)
{
    if (a < 2)    
        return 0;

    for (int i = 2; i <= sqrt((float)a); i ++)
    {
        if (a%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main(){
    int **a, tongpt, m,n,count=0, z=0;
    ifstream ifs("array1.txt");
    ofstream ofs("array1.out");
    ifs>>tongpt;

    if(tongpt % 10 != 0) m = tongpt/10 +1;
    else m = tongpt/10;

    a=new int*[m];

    for(int i=0;i<m;i++){
        if(i== m-1) a[i]= new int[tongpt%10];
        else  a[i]= new int[10];
    }
       
    DocFile(a,m,10,count,tongpt,ifs);

    for (int i=0; i<m ; i++)
    {   
        if(i==m-1) n=tongpt%10;
        else n=10;
        for(int j=0; j<n; j++)
        {    
            if(soNguyenTo(a[i][j])) z++;                        
        }    
    }

    XuatMangFile(z,ofs);

    for(int i=0;i<m;i++) delete[] a[i];
    delete[] a;

    ofs.close();
    ifs.close();
}