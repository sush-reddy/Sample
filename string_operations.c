#include <stdio.h>
#include <stdlib.h>

char* str_reverse(char *str)
{
    int n=0, i, j;
    char c;

    while(str[n++] != '\0');

    n--;  // no need to count null char
    printf("\n len is %d", n);
    n--;  // last index is len - 1
    printf("\n n = %d", n);

    i=0;
    j=n;
    printf("\nstr = %s", str);
    while(i<j)
    {printf("\n%c: %c", str[i], str[j]);
        c = str[i];
        str[i] = str[j];
        str[j] = c;

        i++;
        j--;
    }

    return str;
}

char* str_chr(char *str, char c)
{

    while(*str && (*str != c))
    {
          str++;
    }
    if (*str != '\0')
        return str;
    else
        return NULL;
}

int str_len(char* str)
{
    int len=0;

    while(*str != '\0')
    {
        str++;
        len++;
    }

    return len;

}

int str_cmp(char *s1, char *s2)
{

    while(*s1)
    {
        if (*s1 != *s2)
            break;
         s1++;
         s2++;

    }

    return (int)*s1 - (int)*s2;
}

char* str_cpy(char *s1, const char* s2)
{
    if (s1 == NULL)
        return NULL;

    while(*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1='\0';
    return s1;
}

char* str_cat(char* dest, char* src)
{
    if(!dest || !src)
        return NULL;

    while(*dest)
        dest++;
    while(*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}


 const char* str_str(const char* S1, const char* s2)
{
    int i, j, M, n;

    M = str_len(S1);
    n = str_len(s2);

    for(i = 0; i <= M-n; i++)
    {
        for(j = 0; (j < n) && (s2[j] == S1[i+j]); j++);
        if(j >= n) {
            printf("\n string %s found at %d in %s", S1+i, i, S1);
            return S1+i;
        }
    }
    return NULL;
}


// Alternate implementation
const char* str_str(const char* str, const char* substr)
{
    char *pattern, *begin;

    while(*str)
    {
        begin = str;
        pattern = substr;
        while(*str && *substr && *str == *pattern)
        {
            str++;
            pattern++;
        }
        if(*pattern == '\0')
            return begin;

        str = begin+1;
    }
    return NULL;
}
