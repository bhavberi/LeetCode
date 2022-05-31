

int lengthOfLastWord(char * s){
    int length = 0,i=1;
    if(s[0]!=' ')
        length = 1;
    while(s[i]!='\0'){
        if(s[i]!=' '){
            if(s[i-1]==' ')
                length = 0;
            length++;
        }
        ++i;
    }
    return length;
}
