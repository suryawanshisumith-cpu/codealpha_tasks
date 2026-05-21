#include <stdio.h>

struct Bank
{
    int accNo;
    char name[20];
    int pin;
    float balance;
};

void create()
{
    FILE *fp;
    struct Bank b;

    fp = fopen("bank.txt", "wb");

    printf("Enter Account Number: ");
    scanf("%d", &b.accNo);

    printf("Enter Name: ");
    scanf("%s", b.name);

    printf("Set PIN: ");
    scanf("%d", &b.pin);

    printf("Enter Balance: ");
    scanf("%f", &b.balance);

    fwrite(&b, sizeof(b), 1, fp);

    fclose(fp);

    printf("Account Created\n");
}

void deposit()
{
    FILE *fp;
    struct Bank b;

    int pin;
    float amount;

    fp = fopen("bank.txt", "rb+");

    if(fp == NULL)
    {
        printf("Create Account First\n");
        return;
    }

    fread(&b, sizeof(b), 1, fp);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if(pin == b.pin)
    {
        printf("Enter Amount: ");
        scanf("%f", &amount);

        b.balance += amount;

        rewind(fp);

        fwrite(&b, sizeof(b), 1, fp);

        printf("Deposit Successful\n");
    }
    else
    {
        printf("Wrong PIN\n");
    }

    fclose(fp);
}

void withdraw()
{
    FILE *fp;
    struct Bank b;

    int pin;
    float amount;

    fp = fopen("bank.txt", "rb+");

    if(fp == NULL)
    {
        printf("Create Account First\n");
        return;
    }

    fread(&b, sizeof(b), 1, fp);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if(pin == b.pin)
    {
        printf("Enter Amount: ");
        scanf("%f", &amount);

        if(amount <= b.balance)
        {
            b.balance -= amount;

            rewind(fp);

            fwrite(&b, sizeof(b), 1, fp);

            printf("Withdraw Successful\n");
        }
        else
        {
            printf("Low Balance\n");
        }
    }
    else
    {
        printf("Wrong PIN\n");
    }

    fclose(fp);
}

void balance()
{
    FILE *fp;
    struct Bank b;

    int pin;

    fp = fopen("bank.txt", "rb");

    if(fp == NULL)
    {
        printf("Create Account First\n");
        return;
    }

    fread(&b, sizeof(b), 1, fp);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if(pin == b.pin)
    {
        printf("\nAccount Number: %d", b.accNo);
        printf("\nName: %s", b.name);
        printf("\nBalance: %.2f\n", b.balance);
    }
    else
    {
        printf("Wrong PIN\n");
    }

    fclose(fp);
}

void search()
{
    FILE *fp;
    struct Bank b;

    int acc;

    fp = fopen("bank.txt", "rb");

    if(fp == NULL)
    {
        printf("Create Account First\n");
        return;
    }

    fread(&b, sizeof(b), 1, fp);

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    if(acc == b.accNo)
    {
        printf("\nAccount Found\n");

        printf("Account: %d\n", b.accNo);
        printf("Name: %s\n", b.name);
        printf("Balance: %.2f\n", b.balance);
    }
    else
    {
        printf("Account Not Found\n");
    }

    fclose(fp);
}

int main()
{
    int ch;

    do
    {
        printf("\n===== BANK SYSTEM =====\n");

        printf("1.Create Account\n");
        printf("2.Deposit\n");
        printf("3.Withdraw\n");
        printf("4.Balance Enquiry\n");
        printf("5.Search Account\n");
        printf("6.Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                balance();
                break;

            case 5:
                search();
                break;

            case 6:
                printf("Thank You\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(ch != 6);

    return 0;
}