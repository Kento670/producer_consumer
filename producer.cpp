#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 2

int buffer[BUFFER_SIZE] = {0}; // Shared buffer
int in = 0; // Index for the next produced item
int out = 0; // Index for the next consumed item

sem_t empty; // Semaphore to count empty slots
sem_t full;  // Semaphore to count full slots
pthread_mutex_t mutex; // Mutex for mutual exclusion

// Function to simulate production of an item
void* producer(void* arg) {
    while (true) {
        int item = rand() % 100; // Produce a random item
        sem_wait(&empty); // Wait for an empty slot
        pthread_mutex_lock(&mutex); // Lock the mutex

        buffer[in] = item; // Place item in the buffer
        std::cout << "Produced: " << item << std::endl;

        in = (in + 1) % BUFFER_SIZE; // Move to the next index

        pthread_mutex_unlock(&mutex); // Unlock the mutex
        sem_post(&full); // Signal that an item has been produced
        sleep(1); // Simulate production time
    }
    return nullptr;
}

int main() {
    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, nullptr);

    pthread_t prodThread, consThread;

    // Create the producer and consumer threads
    extern void* consumer(void* arg); // Declare the consumer function
    pthread_create(&prodThread, nullptr, producer, nullptr);
    pthread_create(&consThread, nullptr, consumer, nullptr);

    // Join threads (this will block forever in this example)
    pthread_join(prodThread, nullptr);
    pthread_join(consThread, nullptr);

    // Cleanup (not reachable in this infinite loop)
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
