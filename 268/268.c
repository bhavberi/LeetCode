

int missingNumber(int* nums, int numsSize){
    int x = numsSize;
    for(int i=0;i<numsSize;++i)
    {
        x^=i;
        x^=nums[i];
    }
    return x;

}
