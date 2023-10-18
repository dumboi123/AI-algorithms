#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

struct Element
{
    int address;
    int value;
};

bool increaseE( const Element& a, const Element& b){
        return a.value <= b.value;
}

bool decreaseE( const Element& a, const Element& b){
        return a.value > b.value;
}

void readFile(int *a, int n,ifstream &ifs){
    for (int i = 0; i < n; i++)
        ifs>>a[i];  
}

void addEle(vector<Element> &mainvt,vector<Element> temp){
    for(auto x : temp)
        mainvt.push_back(x);
}

void Johnson(int *a,int *b,int n){
    vector<Element>tempA;
    vector<Element>tempB;
    vector<Element>AB;
    int totalA =0,totalB=0;
    for (int i = 0; i < n; i++)
    {
        Element temp;
        if(a[i] <= b[i]){
            temp.address =i;
            temp.value = a[i];
            tempA.push_back(temp);
        }
        else{
            temp.address =i;
            temp.value = b[i];
            tempB.push_back(temp); 
        }
            
    }
    sort(tempA.begin(), tempA.end(),increaseE);
    sort(tempB.begin(), tempB.end(), decreaseE);
    addEle(AB,tempA);
    addEle(AB,tempB);

    totalB+= AB[0].value;
    for (auto x : AB)
    {   
        totalA += a[x.address];
        if(a[x.address] > b[x.address]){
            if(totalA > totalB)
                totalB += (totalA - totalB);
        }
        totalB += b[x.address];
    }
    
    cout<<"Machine_1 total = "<<totalA;
    cout<<"\nMachine_2 total = "<<totalB;
}

int main()
{
    int n,*a,*b;
    ifstream ifs("Johnsona.txt");
    ifs >> n;
    a = new int[n], 
    b = new int[n];
    readFile(a,n,ifs); 
    readFile(b,n,ifs);    
    Johnson(a,b,n);
    ifs.close();
    return 0;
} 
