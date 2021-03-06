#include "ds.h"

int num_convert_alphbet(const char *str)
{
    if (!str || !*str)
        return 0;

    int len = strlen(str);
    int cur = str[len - 1] != '0', next = 1, tmp = 0;
    for (int i = len - 2; i >= 0; i--) {
        if (str[i] == '0') {
            next = cur;
            cur = 0;
        } else {
            tmp = cur;
            if ((str[i] - '0') * 10 + str[i + 1] - '0' <= 26) 
                cur += next;
            next = tmp;
        }
    }
    return cur;
}

int check(const char *num)
{
    if (!num)
        return 0;

    if (!*num)
        return 1;

    if (*num == '0')
        return 0;

    int res = check(num + 1);
    if (num[1] && (*num - '0') * 10 + num[1] - '0' <= 26)
        res += check(num + 2);
    return res;
}
char *gen_case(int len)
{
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++)
        str[i] = randWithRange(0, 10) + '0';
    str[len] = 0;
    return str;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 1000; i++) {
        char *str = gen_case(5);
        int n1 = num_convert_alphbet(str);
        int n2 = check(str);
        if (n1 != n2) {
            printf("n1 = %d n2 = %d %s\n", n1, n2, str);
            break;
        }
    }
}
