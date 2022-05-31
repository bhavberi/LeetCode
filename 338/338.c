bool isPowerOfTwo(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n+1;
    int* ans = calloc(*returnSize,sizeof(int));
    ans[0] = 0;
    for(int i=1;i<*returnSize;++i)
    {
        if(isPowerOfTwo(i))
            ans[i] = 1;
        else if(i%2 == 0)
            ans[i] = ans[i/2];
        else
            ans[i] = 1+ans[i/2];
    }
    // for(int i=0;i<*returnSize;++i)
    //     printf("%d-%d ",ans[i],i);
    return ans;
}
