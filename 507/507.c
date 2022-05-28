#import <math.h>

bool checkPerfectNumber(int n){
    if (n==1) return false;
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum+=i;
            if (n / i != i)
                sum += n/i;
        }
    }
    return sum==n;
}
