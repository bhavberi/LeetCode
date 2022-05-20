// Using Binary Form of n
// Like x^5 = (x*x*x*x) * (__) * (x) & 5 = 101
// So we would start from right end and if it is 1 , then multiply by x and make it 0
// If it is 0 on right end, change x for x^2, and left shift n by 1 to repeat the process

double myPow(double x, int n){
    double ans = 1;
    long n1 = n;
    if(n<0) 
        n1=-n1;
    int i = 0;
    while(n1 > 0)
    {
        if(n1 & 1L)
        {
            // printf("1. %lf %lf\n",ans,x);
            ans *= x;
            --n1;
        }
        else
        {
            // printf("2. %lf %lf\n",ans,x);
            x*=x;
            n1 /= 2;
        }
    }
    if(n<0)
        return 1.0/ans;
    return ans;
    
}
