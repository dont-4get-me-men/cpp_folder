
#include <iostream>
#include <vector>

using namespace std;

// merge sort from "Introdution to algorithm"
void merge_sort_asc ( vector<int> &nums, int l, int r );
void print_vector ( vector<int> nums );
void print_part_of_vector ( vector<int> nums, int l, int r );
void merge_arrays_asc ( vector<int> &nums, int l, int m, int r );

int main(void){
  vector<int> nums = {5,4,3,6,8,9};
  print_vector(nums);
  merge_sort_asc(nums,0,nums.size()-1);
  print_vector(nums);
  return 0;
}

void merge_arrays_asc(vector<int> &nums,int l,int m,int r){
  vector<int> left,right;
  int i,j,k;
  
  for(int i = l; i <= m; i++) left.push_back(nums[i]);
  for (int i = m+1; i <= r; i++) right.push_back(nums[i]);
  
  i = 0;
  j = 0;
  k = 0;

  while ( k <= r-l ){
    if ( i == left.size() ) {
      nums[l+k]=right[j];
      j++;
    }
    else if ( j == right.size() ){ 
      nums[l+k]=left[i];
      i++;
    }
    else if ( left[i] <= right[j] ){
      nums[l+k] = left[i];
      i++; 
    }
    else {
      nums[l+k] = right[j];
      j++;  
    }
    k++;
  } 
}

void merge_sort_asc(vector<int> &nums,int l,int r){
  if (l<r){
    int m = (l+r)/2;
    merge_sort_asc(nums,l,m);
    merge_sort_asc(nums,m+1,r);
    merge_arrays_asc(nums,l,m,r);
 }
}
void print_vector(vector<int> nums){
  for (int i = 0; i < nums.size(); i++) cout<<nums[i]<<' ';
  cout<<endl;
}

void print_part_of_vector(vector<int> nums, int l, int r){
  for(int i = l; i < r; i++) cout<<nums[i]<<' ';
  cout<<endl;
}
