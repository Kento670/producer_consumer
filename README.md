# producer_consumer
CS 33211 Operating Systems Programming Assignment #1

Description:
  This project implements the producer and consumer problem using C++, with the use of semaphores   and pthreads for synchronization. The producer generates items and places them into the shared    buffer (table), holding a max of 2 items. The consumer, picks up the items from the buffer. 

Requirements:
  C/C++ compiler on Linux/Unix environment.
  Semaphore and pthreads library support.

Compilation:
  To complie the producer and consumer programs:
  Compiling the source files:
    g++ -c producer.cpp -pthread -o producer.o
    g++ -c consumer.cpp -pthread -o consumer.o
  Linking the object files:
    g++ -o producer_consumer producer.o consumer.o -pthread
  Execution:
    ./producer_consumer

Documentation:
  Source codes:
    producer.cpp: Contains the implementation of the producer function and main function. Also     initializes semaphores, creates threads, and handles the synchornization.

  
