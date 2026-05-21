#include <stdio.h>

// Function for matrix addition
void add(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, result[10][10];

    printf("\nAddition Matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix multiplication
void multiply(int a[10][10], int b[10][10], int r1, int c1, int c2)
{
    int i, j, k, result[10][10];

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] += a[i][j] * b[k][j];
            }
        }
    }

    printf("\nMultiplication Matrix:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function for transpose
void transpose(int a[10][10], int r, int c)
{
    int i, j;

    printf("\nTranspose Matrix:\n");

    for(i = 0; i < c; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10];
    int r, c, i, j, choice;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter First Matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter Second Matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n1. Addition");
    printf("\n2. Multiplication");
    printf("\n3. Transpose");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            add(a, b, r, c);
            break;

        case 2:
            multiply(a, b, r, c, c);
            break;

        case 3:
            transpose(a, r, c);
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}