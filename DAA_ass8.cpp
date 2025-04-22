#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        static bool compare(const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1]; 
        }
    
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            sort(boxTypes.begin(), boxTypes.end(), compare);
            
            int totalUnits = 0; 
            for(int i=0;i<boxTypes.size();i++){
                int boxes= boxTypes[i][0];
                int boxcontent = boxTypes[i][1];
                if(boxes <= truckSize){
                    totalUnits = totalUnits + boxes*boxcontent ;
                    truckSize = truckSize - boxes;
                }
                else{
                    totalUnits += truckSize * boxcontent; 
                    break; 
                }
            }
            return totalUnits;
        }
    };