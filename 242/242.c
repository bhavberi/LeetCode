

bool isAnagram(char * s, char * t){
    int *ch = (int*) calloc(26,sizeof(int));
    int *ch1 = (int*) calloc(26,sizeof(int));
    int i=0;
    while(s[i]!=NULL)
    {
        ch[s[i]-'a']+=1;
        ++i;
    }
    i=0;
    while(t[i]!=NULL)
    {
        ch1[t[i]-'a']+=1;
        ++i;
    }
    for(i=0;i<26;++i)
    {
        if(ch[i]!=ch1[i])
            return false;
    }
    return true;
}
