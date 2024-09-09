#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(const pair<string,int> &a, const pair<string,int> &b){
    return a.second > b.second;
}      
    
void sorting_pair(vector<pair<string,int>>&vec){
    sort(vec.begin(),vec.end(),comp);
}