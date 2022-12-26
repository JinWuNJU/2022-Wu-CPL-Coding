#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char palindrome[n];
    for (int i = 1; i <= n; i++)
    {
        scanf("%c", &palindrome[i]);
    }
    char known[200];
    for (int i = 1; i <= 200; i++)
    {
        if (i % 2 == 0 && i % 20 != 0)
        {
            known[i] = ((i % 20) / 2 - 1) % 10 + 48;
        }
        else if (i % 20 == 0)
        {
            known[i] = 9 + 48;
        }
        else
        {
            known[i] = i / 20 + 48;
        }
    }
    int count = 0;
    char output[n + 2 * count];
    for (int i = 1, j = n; i <= j; i++, j--)
    {
        if (palindrome[i] == 63 && palindrome[j] != 63)
        {
            palindrome[i] = palindrome[j];
            output[i + count] = palindrome[i];
        }
        else if (palindrome[j] == 63 && palindrome[i] != 63)
        {
            palindrome[j] = palindrome[i];
            output[i + count] = palindrome[i];
        }
        else if (palindrome[i] == 63 && palindrome[j] == 63)
        {
            count++;
            output[i + count - 1] = known[2 * count - 1];
            output[i + count] = known[2 * count];
        }
        else
        {
            output[i + count] = palindrome[i];
        }
        
    }for (int i = 1, j = n + 2 * count; i <= j; i++, j--)
        {
            output[j] = output[i];
        }
    for (int i = 1; i <= n + 2 * count; i++)
    {
        printf("%c", output[i]);
    }
    return 0;
}
/*#include<stdio.h>//to prove the mark number of a string starts from 0
int main(){
    char known[201];
    known[0]=77;
   for (int i = 1; i <= 200; i++)
    {
        if (i % 2 == 0 && i % 20 != 0)
        {
            known[i] = ((i % 20) / 2 - 1) % 10 + 48;
        }
        else if (i % 20 == 0)
        {
            known[i] = 9 + 48;
        }
        else
        {
            known[i] = i / 20 + 48;
        }
    }printf("%c",known[200]);
   
    return 0;
}*/