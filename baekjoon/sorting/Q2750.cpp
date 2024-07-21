#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

 int N;
 cin >> N;

 vector<int> nums;
 for(int i=0;i<N;i++){
    int num;
    cin >> num;
    nums.push_back(num);
 }

 for(int i=0;i<N-1;i++)
    for(int j=i+1;j<N;j++){
       if(nums[i] > nums[j]){
	  int temp = nums[i];
	  nums[i] = nums[j];
	  nums[j] = temp;
       }
    }

 for(int i=0;i<N;i++)
    cout << nums[i] << endl;

 return 0;
}
