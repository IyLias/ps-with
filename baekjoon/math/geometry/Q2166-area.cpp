#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Vector{

 long long x;
 long long y;
 long long z;
};


Vector cross_product(const Vector& v1, const Vector& v2){
 
 Vector result_vector = {0,0,v1.x*v2.y-v1.y*v2.x};


 return result_vector;
}

int main(){
 
 vector<Vector> v;
 int N;

 cin >> N;
 for(int i=0;i<N;i++){
    Vector p = {.x=0, .y=0, .z=0};
    cin >> p.x >> p.y;

    v.push_back(p);
 }
 
 Vector origin = v[0];
 long double area = 0.0;
 for(int i=1;i<N-1;i++){
    Vector v1 = {v[i].x-origin.x,v[i].y-origin.y}, v2={v[i+1].x-origin.x, v[i+1].y-origin.y};

    Vector area_vector = cross_product(v1,v2);
    area += (area_vector.z/2.0);
 }
 
 printf("%.1Lf\n", abs(area));
 return 0;
}
