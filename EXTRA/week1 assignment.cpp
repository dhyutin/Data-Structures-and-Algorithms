#include <iostream>

using namespace std;

void sum(int*p,int n,int d[])
{
    int i;
    *p=0;
    for(i=0;i<n;++i)
    {
        *p+=d[i];
    }
}
int main()
{   int N=40;
    int i;
    int accum=0;
    int data[N];
    for(i=0;i<N;++i)
    {
        data[i]=i;
        sum(&accum,N,data);
    }
    cout<<"sum is "<<accum<<endl;

}