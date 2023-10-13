#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

void DocFile(int **a, int m, int n, ifstream &ifs){
    for (int i=0; i<m ; i++){
        for(int j=0; j<n; j++)
            ifs>>a[i][j];
    }
}

void XuatMangFile( int m, int n, ofstream &ofs, int songto, int *b, int*c){
    ofs<<"co tong "<<songto<<" so nguyen to trong ma tran"<<endl;
    for (int i=0; i<m ; i++)
        ofs<<"Tong pt dong "<<i<<" = "<<b[i]<<endl;
    ofs<<"switch" <<endl;
    for(int i=0; i<n; i++)
        ofs<<"Tong pt cot "<<i<<" = "<<c[i]<<endl;        
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
    int **a, *b,*c, m, n, z=0;
    string s;
    ifstream ifs("array2.txt");
    ofstream ofs("array2.out");
    ifs>>m>>s>>n;
    cout<<s<<" "<<n;
    a = new int*[m];
    b = new int [m];
    c = new int [n];
    for(int i=0;i<m;i++)
        a[i]= new int[n];
    DocFile(a,m,n,ifs);
    for (int i=0; i<m ; i++)
    {
        b[i]=0;
        for(int j=0; j<n; j++)
        {
            if(soNguyenTo(a[i][j])) z++;
            b[i]+=a[i][j];                          
        }    
    }
    for (int i=0; i<n ; i++){
        c[i]=0;
        for(int j=0; j<m; j++) c[i]+=a[j][i];
    }
    XuatMangFile(m,n,ofs,z,b,c);
    for(int i=0;i<m;i++)
        delete []a[i];
    delete[] a;
    delete[] b;
    delete[] c;
    ofs.close();
    ifs.close();
}