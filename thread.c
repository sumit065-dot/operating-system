#include <stdio.h>
#include <pthread.h>

// Structure to pass data to threads
typedef struct {
    int a;
    int b;
} numbers;

// Thread for addition
void* add(void* arg)
{
    numbers* num = (numbers*)arg;
    printf("Addition: %d + %d = %d\n", num->a, num->b, num->a + num->b);
    pthread_exit(NULL);
}

// Thread for multiplication
void* multiply(void* arg)
{
    numbers* num = (numbers*)arg;
    printf("Multiplication: %d * %d = %d\n", num->a, num->b, num->a * num->b);
    pthread_exit(NULL);
}

// Thread for division
void* divide(void* arg)
{
    numbers* num = (numbers*)arg;
    if (num->b != 0)
        printf("Division: %d / %d = %.2f\n", num->a, num->b, (float)num->a / num->b);
    else
        printf("Division not possible (divide by zero)\n");

    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2, t3;
    numbers num;

    // Input
    printf("Enter two numbers:\n");
    scanf("%d %d", &num.a, &num.b);

    // Create threads
    pthread_create(&t1, NULL, add, &num);
    pthread_create(&t2, NULL, multiply, &num);
    pthread_create(&t3, NULL, divide, &num);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("All threads executed successfully\n");
    return 0;
}
