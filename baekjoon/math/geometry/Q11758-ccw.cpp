#include <stdio.h>
#include <iostream>
#include <algorithm>


using namespace std;

struct Vector{

 int x;
 int y;
 int z;
};


Vector cross_product(const Vector& v1, const Vector& v2){
 
 Vector result_vector = {0,0,v1.x*v2.y-v1.y*v2.x};


 return result_vector;
}

int main(){

 Vector p1,p2,p3;

 cin >> p1.x >> p1.y;
 cin >> p2.x >> p2.y;
 cin >> p3.x >> p3.y;

 // p2-p1 and p3-p2
 
 Vector v1 = {p2.x-p1.x, p2.y-p1.y,0}, v2 = {p3.x-p2.x, p3.y-p2.y,0};
 
 Vector result = cross_product(v1,v2);

 if(result.z < 0)
   cout << "-1\n" << endl;
 else if(result.z > 0)
   cout << "1\n" << endl;
 else 
   cout << "0\n" << endl;

 return 0;
}
