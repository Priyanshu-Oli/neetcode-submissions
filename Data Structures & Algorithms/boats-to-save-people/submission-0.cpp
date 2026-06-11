class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    int l = 0 ;
    int r =people.size()-1;
    sort(people.begin(),people.end());
    int output=0;


    while(l<r){
        int sum = people[l]+people[r];
        
        if(sum<=limit){
            output+=1;
            l++;
            r--;
        }
        else if(sum>limit){
            output+=1;
            r--;
        }
        
    }  
    if(l==r)output++;
     return output;
    }
};