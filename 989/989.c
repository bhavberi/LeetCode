int countDigit(int n) {
  return floor(log10(n) + 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* digits, int digitsSize, int k, int* returnSize){
    int l = digitsSize - 1;
    int carry = k;
    while(l>=0)
    {
        digits[l]+=carry;
        if(digits[l]<10)
        {
            carry=0;
            break;
        }
        carry = digits[l]/10;
        digits[l]-=(10*carry);
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
        int count = countDigit(carry);
        *returnSize = digitsSize+count;
        int* ans = malloc((digitsSize+count)*sizeof(int));
        while(count>0)
        {
            ans[count-1] = carry%10;
            carry/=10;
            count--;
        }
        memcpy(&ans[*returnSize-digitsSize],digits,digitsSize*sizeof(int));
        return ans;
    }
}
