#include<iostream>
#include<vector>
using namespace std;

void display(const vector <int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v;
    cout<<"Enter Vector Values (0 to stop):\n";
    while (true)
    {
        int value;
        cout<<"Enter Value : ";
        cin>>value;
        if(value==0)break;
        v.push_back(value);
    }
    display(v);
    
}