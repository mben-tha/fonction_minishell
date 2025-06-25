#include <stdio.h>
#include <stdlib.h>

int len_clean_space(char *str);

char    *clean_space(char *str)
{
    int     len;
    char    *res;
    int     i;
    int     j;

    j = 0;
    i = 0;
    len = len_clean_space(str);
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    while (str[i] == ' ')
        i++;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            while (str[i] == ' ')
                i++;
            if (!str[i])
                break ;
            res[j++] = ' ';
        }
        else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
        {
            if (i != 0 && str[i-1] != ' ')
                res[j++] = ' ';
            res[j++] = str[i];
            if (str[i+1] && str[i+1] != ' ')
                res[j++] = ' ';
            i++;
        }
        else
        {
            res[j++] = str[i];
            i++;
        }
    }
    res[i] = '\0';
    return res;
}

int len_clean_space(char *str)
{
    int i;
    int len;

    len = 0;
    i = 0;
    while (str[i] == ' ')
        i++;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            while (str[i] == ' ')
                i++;
            if (!str[i])
                return len;
            len++;
        }
        else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
        {
            if (i != 0 && str[i-1] != ' ')
            {
                len++;
                
            }
            if (str[i+1] && str[i+1] != ' ')
                    len++;
            i++;
            len++;
        }
        else
        {
            i++;
            len++;
        }
    }
    return len;
}

int main(int ac, char **av)
{
    char *test;

    test = clean_space(av[1]);
    printf("%sY\n", test);

    // printf("%dY\n", len_clean_space(av[1]));
}