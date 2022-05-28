int comp_(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums,numsSize,sizeof(int),comp_);
    return nums[k-1];
}
