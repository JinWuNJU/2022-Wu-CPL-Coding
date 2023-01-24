#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 10005

typedef struct File
{
    char name[15];
    int tot;
    bool isErased;
    int next[3];
}File;
File file[N];
int tot;

int findfile(char* name)
{
    for (int i = 2; i <= tot; ++i)
        if (strcmp(name, file[i].name) == 0)
            return i;
    return -1;
}

int query(int pos)
{
    int sum = 1;
    for (int i = 1; i <= file[pos].tot; ++i)
    {
        sum += file[file[pos].next[i]].isErased ? 0 : query(file[pos].next[i]);
    }
    return sum;
}

void erase(int pos)
{
    file[pos].isErased = true;
    if (!file[pos].tot)
        return;
    for (int i = 1; i <= file[pos].tot; ++i)
    {
        erase(file[pos].next[i]);
    }
}

int main(int argc, char *argv[])
{
    int n, q;
    scanf("%d%d", &n, &q);
    tot = 1;
    file[tot].name[0] = file[tot].name[1] = file[tot].name[2] = '~';
    file[tot].name[3] = '\0';
    char a[15], b[15];
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s%s", a, b);
        ++tot;
        strcpy(file[tot].name, a);
        int bpos = findfile(b);
        file[bpos].next[++file[bpos].tot] = tot;
    }
    for (int i = 1; i <= q; ++i)
    {
        scanf("%s%s", a, b);
        int pos = findfile(b);
        if (strcmp(a, "query") == 0)
        {
            printf("%d\n", query(pos));
        }
        else
        {
            erase(pos);
        }
    }
    return 0;
}