#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAXNUM  100000

using namespace std;
typedef long long ll;

struct Point{

   ll x,y;
   ll p,q;

   Point(ll a, ll b): x(a), y(b), p(0), q(0) {}; 
   Point() {};
};

ll ccw(const Point &o, const Point &p, const Point &q){

    ll res = (p.x-o.x)*(q.y-o.y) - (p.y-o.y)*(q.x-o.x);
    return res;
}

ll det(const Point &p1, const Point &p2){
    ll res = (p1.p*p2.q - p1.q*p2.p);
    return res;
}

bool angle_sort(Point &p1, Point &p2){

    if(p1.p != 0 || p1.q != 0 || p2.p != 0 || p2.q != 0) {
        if(det(p1, p2) > 0) {
            return true;
        } else if(det(p1, p2) == 0) {
            return p1.p*p1.p + p1.q*p1.q < p2.p*p2.p + p2.q*p2.q;
        } else {
            return false;
        }
    }

    if(p1.y == p2.y){
        return p1.x < p2.x;
    }else{
        return p1.y < p2.y;
    }

}


int main(){

    int N;
    cin >> N;

    Point p[MAXNUM];
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        p[i] = Point(x,y);
    }

    vector<int> hull;
    sort(p,p+N,angle_sort);

    for(int i=1;i<N;i++){
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }

    sort(p+1,p+N,angle_sort);

    int st, mid, end = 2;
    hull.push_back(0); hull.push_back(1);

    while(end != N){
        while(hull.size() >= 2){
            mid = hull.back();
            hull.pop_back();
            st = hull.back();

            if(ccw(p[st],p[mid],p[end]) > 0){
                hull.push_back(mid);
                break;
            }
        }

        hull.push_back(end++);
    }

    cout << hull.size() << endl;

    return 0;
}
