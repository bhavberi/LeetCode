

int strStr(char * haystack, char * needle){
    if (needle == NULL)
        return 0;
    int l = strlen(haystack);
    int l1 = strlen(needle);
    int found = -1;
    int a = 0;
    if (!strcmp(haystack, needle))
        return 0;
    for (int i = 0; i < l; ++i)
    {
        if (found == -1)
        {
            if (needle[a] == haystack[i])
            {
                ++a;
                found = i;
                if (l1 == 1)
                    return found;
            }
        }
        else
        {
            printf("%c%d%d ", haystack[i], i, a);
            // if(a==l1-1)
            //     return found;
            if (needle[a] == haystack[i] && a == l1 - 1)
                return found;
            else if (needle[a] != haystack[i])
            {
                i = found;
                found = -1;
                a = 0;
            }
            else
                ++a;
        }
    }
    printf("\n");
    return -1;

}
