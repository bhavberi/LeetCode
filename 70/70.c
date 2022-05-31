

int climbStairs(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int x = 1;
    int y = 2;
    int z;
    while(n-2>0)
    {
        z=x+y;
        x=y;
        y=z;
        --n;
    }
    return z;
}
