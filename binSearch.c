#include <stdio.h>
#include <stdlib.h>


int bSearch(int* tab, int key, int elem, int option);
int recSearch(int* tab, int key, int start, int end);


int main()
{
    int tab[] = {1,2,3,4,5,6,7,9};
    int key = 4;
    int result = bSearch(tab, key, sizeof(tab)/ sizeof(int) , 0);
    for (int i = -2; i < 18 ; i++)
    {
        key = i;
        result = bSearch(tab, key, sizeof(tab)/ sizeof(int) , 0);
        printf("Czy %d: %s\n", key, result ? "tak" : "nie");
        result = bSearch(tab, key, sizeof(tab)/ sizeof(int) , 1);
        printf("Czy %d: %s\n\n", key, result ? "tak" : "nie");
    }

    return 0;
}

int bSearch(int* tab, int key, int elem, int option)
{
    int result = 0;
    if (option == 1)    //inline
    {
        
        int start = 0;
        int end = elem;
        while(start <= end)
        {
            int half = start + (end - start + 1) / 2;
            if (key == tab[half])
            {
                result = 1;
                break;
            }
            else if(key < tab[half])
            {
                end = half - 1;
            }  
            else
            {
                start = half + 1;
            }
        }
    }
    else        //recursive
    {
        result = recSearch(tab,key,0,elem);
    }
    return result;
}


int recSearch(int* tab, int key, int start, int end)
{
    if (start > end)
        return 0;
    int half = start + (end - start + 1) / 2;
    if (key == tab[half])
        return 1;
    else if (key < tab[half])
        recSearch(tab,key,start,half - 1);
    else
        recSearch(tab, key, half + 1, end);
}