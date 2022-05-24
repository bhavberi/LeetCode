// From Q7 Reverse a Number
#include <limits.h>
int reverse(int x){
    short int neg = 0;
    if(x<=INT_MIN || x>INT_MAX)
        return 0;
    if(x<0)
    {
        neg = 1;
        x = -x;
    }
    int ans = 0;
    while(x!=0){
        int digit = x%10;
        if(ans > INT_MAX/10 || ans <= INT_MIN/10)
            return 0;
        ans = ans*10 + digit;
        if(ans >= INT_MAX || ans <= INT_MIN)
            return 0;
        x/=10;
    }
    if(neg) 
        return -ans;
    return ans;
}

// Main Code
bool isPalindrome(int x){
    if(x<0) return false;
    if(x == reverse(x)) return true;
    return false;

}
