#include <iostream>
#include <cstdlib>
using namespace std;
class IntArray {
    int sz;
    int *Arr;
    public:
    IntArray(int s) 
    {  
        sz = s;
        Arr = new int[sz];
    }
//    int operator[](int x);
    int& operator[](int x);
    friend ostream& operator<<(ostream& os, const IntArray& ia);
    friend istream& operator>>(istream& is, IntArray& ia);
};

//int IntArray ::operator[](int x) 
int& IntArray ::operator[](int x) 
{
    if(x < 0 || x >= sz)
    {
        cout << "out of range" << endl;
        exit(0);
    }
    else
        return Arr[x];
}

ostream& operator<<(ostream& os, const IntArray& ia) 
{
    for(int j = 0; j < ia.sz; j++) 
    {
        os << ia.Arr[j];
        if(j != ia.sz -1)
            os << ", ";
    }
    os << endl;
    return os;
}
istream& operator>>(istream& is, IntArray& ia)
{
    for(int j = 0; j < ia.sz; j++)
        is >> ia.Arr[j];
    return is;
}
int main() 
{
    int size, value;
    cout << "Enter array size :\n";
    cin >> size;
    IntArray I(size);
    cin >> I;
    cout << I;
    value = I[2];
    cout << value <<endl;
//    value = I[-3];
//    value = I[size];
//    cout << value <<endl;

    I[1] = 3;
    
    
    cout << I;        
    I[-2] = 0;
    return 0;
}
