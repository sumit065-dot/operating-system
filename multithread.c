#include <stdio.h>
#include <pthread.h>

// Thread function
void* thread_function(void* arg)
{
    printf("Hello from the thread!\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id;

    // Create thread
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0)
    {
        printf("Thread creation failed\n");
        return 1;
    }

    // Wait for thread to finish
    pthread_join(thread_id, NULL);

    printf("Thread execution completed\n");
    return 0;
}
