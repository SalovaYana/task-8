#include <stdio.h>
#include <stdlib.h>
int sravn=0, perest = 0;
void bubblesort (int *a, int n)
{
int  i, j, b;

 for (i=0; i < n-1; i++)
    {
        for (j=0; j < n-i-1; j++)
        { sravn++;
            if (printf("%d %d\n", j,j+1),  a[j] > a[j+1])
            {
                b = a[j];
                a[j] = a[j+1];
                a[j+1] = b;
                perest++;
            }
        }
    }
}
void quicksort(int *a, int first, int last)
{
    int  el, t, m,
                   f=first,
                   l=last;

    el=a[(first+last)/2];
    m=a[el];

    do
    {
        while (f!=el && a[f] < a[el])
        {
            sravn++;
            f++;
        }

        if (f != el)
            sravn++;


        while (l!=el && a[l] > a[el])
        {
            sravn++;
            l--;
        }


        if (l != el)
            sravn++;


        if (f <= l)
        {
            if (f != l)
            {
                t = a[f];
                a[f] = a[l];
                a[l] = t;
                perest++;



                if(f==el)
                    f++;

                if(l==el)
                    l--;

            }

            f++;
            l--;
        }
        printf("\n sravn = %d perest = %d", sravn, perest) ;
    }

    while (f <= l);

    if (first < l)
        quicksort(a, first, l);

    if (last > f)
        quicksort(a, f, last);

}

void insertsort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                perest++;
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
            sravn++;
        }
    }
}

void print_menu()
{

    printf("\nWhat do you want to use?\n");
    printf("1. Quicksort\n");
    printf("2. insretsort\n");
    printf("3. bubblesort\n");

}

int main()
{
    int variant;
    int  *a, n, i;


    printf("vvedi kol-vo elementov massiva \n");
    scanf("%d", &n);

    int first = 0, last = n-1;

    a = (int*) malloc(n*sizeof(int));

    printf("vvedi massiv \n");
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);



        print_menu(); // выводим меню на экран

     printf("viberi nomer = ");
     scanf("%d", &variant);

        switch (variant)
        {
        case 1:
            quicksort(a, first, last) ;
            break;

        case 2:
           insertsort(a, n);
            break;

        case 3:
           bubblesort(a, n);
            break;

        }

    printf("\nsort massive:\n");


    for(i=0; i<n; i++)
        printf("%d  ", a[i]);

    printf("\n sravn = %d perest = %d", sravn, perest);


}


