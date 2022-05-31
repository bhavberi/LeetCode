

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int l = digitsSize - 1;
    int carry = 0;
    while(l>=0)
    {
        digits[l]+=1;
        if(digits[l]<10)
        {
            carry=0;
            break;
        }
        digits[l]-=10;
        carry = 1;
        --l;
    }
    // for(int i=0;i<digitsSize;++i)
    //     printf("%d",digits[i]);
    if(carry==0)
    {
        *returnSize = digitsSize;
        return digits;
    }
    else
    {
        int* ans = malloc((digitsSize+1)*sizeof(int));
        ans[0]=1;
        *returnSize = digitsSize+1;
        memcpy(&ans[1],digits,digitsSize*sizeof(int));
        return ans;
    }
}
