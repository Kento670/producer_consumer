# producer_consumer
**CS 33211 Operating Systems Programming Assignment #1**

**By: Kent Ogasawara**


## Description
This project implements the producer and consumer problem using C++, with the use of semaphores and pthreads for synchronization. The producer generates items and places them into the shared buffer (table), holding a max of 2 items. The consumer picks up the items from the buffer.

## Requirements
- C/C++ compiler on Linux/Unix environment.
- Semaphore and pthreads library support.

## Compilation

To compile the source files, run the following commands:

    g++ -c producer.cpp -pthread -o producer.o
    g++ -c consumer.cpp -pthread -o consumer.o
    g++ -o producer_consumer producer.o consumer.o -pthread
    ./producer_consumer

## Example Output
Here’s an example output using Ubuntu in VirtualBox:

    Produced: 83
    Consumed: 83
    Produced: 86
    Produced: 77
    Consumed: 86
    Produced: 15
    Consumed: 77
    Produced: 93
    Consumed: 15
    Produced: 35

    ctrl + c This will stop (terminate) a running program immediately.

