#include<iostream>
using namespace std;
#include<bits/stdc++.h>
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int>& output){
        //base case
        if(target == 0){
            ans.push_back(output);
            return;
        }

        int prev = -1;
        for(int j=i; j<candidates.size(); j++){
            if(candidates[j] != prev && candidates[j] <= target){
                output.push_back(candidates[j]);
                solve(candidates, target-candidates[j], j+1, ans, output);
                output.pop_back();
                prev = candidates[j];
            }
        }

    }


    int solve1(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        int i = 0;
        solve(candidates, target, i, ans, output);
        return ans.size();
    }
    int main(){
        int n;
        cin>>n;
        int target;
        cin>>target;
        vector<int>r(n);
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            r[i]=num;
        }
        
        cout<<solve1(r,target);

    }