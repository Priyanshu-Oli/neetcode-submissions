class Solution {
public:
    int getint(int n) {
        int sum =0;
        while(n>0){
            int digit = n%10;
            sum += digit*digit;
            n =n/10;
        }
            return sum;
        }
        bool isHappy(int n){
            int slow =n, fast =getint(n);
            while(fast !=1 &&slow!=fast){
                slow =getint(slow);
                fast =getint(getint(fast));
            }
        return fast==1;
        }
    
};