#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 2

extern int buffer[BUFFER_SIZE]; // Shared buffer
extern int in, out; // Indexes for the buffer

extern sem_t empty; // Semaphore to count empty slots
extern sem_t full;  // Semaphore to count full slots
extern pthread_mutex_t mutex; // Mutex for mutual exclusion

// Function for consumpting an item
void* consumer(void* arg) {
    while (true) {
        sem_wait(&full); // Wait for a full slot
        pthread_mutex_lock(&mutex); // Lock the mutex

        int item = buffer[out]; // Remove item from the buffer
        std::cout << "Consumed: " << item << std::endl;

        buffer[out] = 0; // Clear the consumed item if needed
        out = (out + 1) % BUFFER_SIZE; // Move to the next index

        pthread_mutex_unlock(&mutex); // Unlock the mutex
        sem_post(&empty); // Signal that an item has been consumed
        sleep(2); // Simulate consumption time
    }
    return nullptr;
}

