#include <stdio.h> //Please tell me what's the problem???
#include <math.h>//problem solved
int main()
{
    int xA, xB, xC, yA, yB, yC;
    scanf("%d%d%d%d%d%d", &xA, &yA, &xB, &yB, &xC, &yC);
    int m = abs(xA - xB);
    int n = abs(yA - yB);
    char direction[1000];
    char strange[1000];
    if ((xB != xC) && (yA != yC))
    {
        for (int i = 1; i <= m; i++)
        {
            if (xA <= xB)
            {
                direction[i] = 'R';
            }
            else
            {
                direction[i] = 'L';
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (yA <= yB)
            {
                direction[m + j] = 'U';
            }
            else
            {
                direction[m + j] = 'D';
            }
        }
        printf("%d\n", m + n);
        for (int i = 1; i <= m + n; i++)
        {
            printf("%c", direction[i]);
        }
    }
    else if ((n == 0 && xA <xC&&xC <xB) || (n == 0 && xB <xC&&xC <xA))
    {
        strange[1] = 'U';
        strange[m + n + 2] = 'D';
        if (xA <= xB)
        {
            for (int i = 2; i < m + n + 2; i++)
            {
                strange[i] = 'R';
            }
        }
        else
        {
            for (int i = 2; i < m + n + 2; i++)
            {
                strange[i] = 'L';
            }
        }
        printf("%d\n", m + n + 2);
        for (int i = 1; i <= m + n + 2; i++)
        {
            printf("%c", strange[i]);
        }
    }
    else if ((m == 0 && yA < yC&&yC < yB) || (m == 0 && yB <yC&& yC< yA))
    {
        strange[1] = 'R';
        strange[m + n + 2] = 'L';
        if (yA <= yB)
        {
            for (int i = 2; i < m + n + 2; i++)
            {
                strange[i] = 'U';
            }
        }
        else
        {
            for (int i = 2; i < m + n + 2; i++)
            {
                strange[i] = 'D';
            }
        }
        printf("%d\n", m + n + 2);
        for (int i = 1; i <= m + n + 2; i++)
        {
            printf("%c", strange[i]);
        }
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            if (xA <= xB)
            {
                direction[n + i] = 'R';
            }
            else
            {
                direction[n + i] = 'L';
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (yA <= yB)
            {
                direction[j] = 'U';
            }
            else
            {
                direction[j] = 'D';
            }
        }
        printf("%d\n", m + n);
        for (int i = 1; i <= m + n; i++)
        {
            printf("%c", direction[i]);
        }
    }

    return 0;
}