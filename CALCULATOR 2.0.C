#include <stdio.h>

int main()
{
    int choice;
    float num1, num2, result;

     printf("Enter first number: ");
            scanf("%f", &num1);

            printf("Enter second number: ");
            scanf("%f", &num2);
        
            
    do
    {
        //MENU DRIVEN PROGRAM
        printf("\n===== SIMPLE CALCULATOR =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1: //ADDITION
                result = num1 + num2;
                printf("Result = %.2f\n", result);
                break;

            case 2: // SUBTRACTION
                result = num1 - num2;
                printf("Result = %.2f\n", result);
                break;

            case 3: //MULTIPLICATION
                result = num1 * num2;
                printf("Result = %.2f\n", result);
                break;

            case 4:  //DIVISION 
                if (num2 != 0)
                {
                    result = num1 / num2;
                    printf("Result = %.2f\n", result);
                }
                else
                {
                    printf("Error! Division by zero not allowed.\n");
                }
                break;

            case 5: //EXIT
                printf("Exiting Calculator...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}