#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  int w,h,p,q,t;
  cin >> w >> h >> p >> q >> t;
  
  int x,y;
  
  // calculate x
  if ((p+t) % w == 0){
      /*if ((p+t)/w % 2 == 1)
         x = w;
      else 
         x = 0; */
         
      x = (p+t)/w % 2 == 1 ? w : 0;
      
  } else{
      x = (p+t)/w % 2 == 1 ? abs(w-((p+t)%w)) : (p+t)%w;
  }
  
  // calculate y
  if ((q+t) % h == 0){
      /*if ((q+t)/h % 2 == 1)
         y = h;
      else 
         y = 0; */
         
      y = (q+t)/h % 2 == 1 ? h : 0;
      
  } else{
      y = (q+t)/h % 2 == 1 ? abs(h-((q+t)%h)) : (q+t)%h;
  }
  
  cout << x << " " << y << endl;
  
  // p+t / w = k 
  // 0 < p+t <= w  => p+t
  // w < p+t <= 2w => |w-((p+t)%w)|
  
  // if (p+t) % w == 0 
  // (p+t)/w % 2 == 1
  // then w else 0
  
  // else 
  // if (p+t)/w % 2 == 1 then |w-((p+t)%w)| else (p+t)%w
  
  return 0;
}
