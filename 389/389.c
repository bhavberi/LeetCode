
char findTheDifference(char * s, char * t){
    int array1[26],array2[26];
    int i = 0;
    for(i=0;i<26;++i)
    {
        array1[i]=array2[i]=0;
    }
    for(i=0;i<strlen(s);++i)
    {
        ++array1[s[i]-'a'];
        ++array2[t[i]-'a'];
    }
    ++array2[t[i]-'a'];
    for(i=0;i<26;++i)
    {
        if(array1[i]!=array2[i])
            return ('a'+i);
    }
    return 'z';

}
