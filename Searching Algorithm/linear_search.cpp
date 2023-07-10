#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0 ; i<n ; i++) cin>>a[i];
    cout<<"Initial Array: ";
    for (int i=0 ; i<n ; i++) cout<<a[i]<<" ";
    cout<<endl;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout<<"Sorted Array: ";
    for (int i=0 ; i<n ; i++) cout<<a[i]<<" ";
    cout<<endl;
    int f;
    cout<<"Enter a value to find: ";
    cin>>f;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if(f==a[i]) index = i;
    }
    if(index==-1)cout<<"Value Not Found\n";
    else cout<<"Value found at index: "<<index<<endl;
}