

bool digitCount(char * num){
    int *a = calloc(10,sizeof(int));
    int i=0;
    while(num[i])
        a[num[i++]-'0']+=1;
    i=0;
    while(num[i])
    {
        if(a[i] != num[i]-'0')
            return false;
        ++i;
    }
    return true;
}
