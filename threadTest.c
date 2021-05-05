#include <stdio.h>
#include <unistd.h> //Header sleep
#include <string.h>
#include <pthread.h>
#include <stdlib.h>


void *printRandom() {
    sleep(2);
    printf("Printing thingie using thread!\n");

    return NULL;
}

int main(void) {

    printRandom();

    pthread_t thread_id;
    printf("Before thread\n");
    
    //Create the thread
    pthread_create(&thread_id, NULL, printRandom, NULL);

    pthread_join(thread_id, NULL);
    printf("After thread\n");

    return 0;
}