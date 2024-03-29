/*
Author: Harshit Tiwari
Date: 30-03-2022
https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool SubsetSum(vector<int> arr, int Sum, int n, vector<vector<bool>> &dp);
int minSubsetSumDiff(vector<int> arr,int n,int sum);

int main(){
    int n;  cin>>n;            //Total number of nummbers in arr
    vector<int> arr;           //Given array of numbers
    for(int i=0;i<n;i++){
        int k; cin>>k;
        arr.push_back(k);
    }   

    int sum=0;  
    for(int i=0;i<n;i++)
        sum=sum+arr[i];

    cout<<minSubsetSumDiff(arr,n,sum)<<endl;

    return 0;
} 
bool SubsetSum(vector<int> arr, int Sum, int n, vector<vector<bool>> &dp){
    //Initialization of dp matrix
    for(int i=0; i<n+1; i++){
        for(int j=0; j<Sum+1; j++){
            if(i==0) //i.e. n=0 i.e. arr is empty
                dp[i][j]=false;
            if(j==0) //i.e. Sum=0 
                dp[i][j]=true;
        }
    }

    // Iterative code for choice diagram:
    for(int i=1; i<n+1; i++){
        for(int j=1; j<Sum+1; j++){
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else 
                dp[i][j]= dp[i-1][j];
        }
    }

    return dp[n][Sum];  //returning the last element of dp matrix
}

int minSubsetSumDiff(vector<int> arr,int n,int sum){

    //dp matrix to store answers for the subproblems initialized with true
    vector<vector<bool>> dp(n+1,vector<bool> (sum+1,true));
    SubsetSum(arr,sum,n,dp);

    // The last row of dp matrix now contains 'true' for the values of 'sum'
    // which are a possible value for a subset sum
    vector<int> vec;            //To store the possible values of sum1
    for(int i=0; i<=(sum+1)/2;i++){
        if(dp[n][i]==true) //Looking for true values in last row of dp matrix
            vec.push_back(i);
    }
    
    //To store the value of minimum difference 
    int diff=  abs(sum-2*vec[vec.size()-1]);
    return diff;   
}