1. Explain Semaphore.
- A semaphore is a program used to implement process synchroniation like mutual exclusion to prevent situations like race condition.
- It is initialized with a intial value which denotes no of process can access critical section at a time.
- It provides two operations:
  - wait: When a process enters a critical section it decrements semaphore value.
  - signal: When a provcess leaves critical section it increments semaphore value.
- When semaphore value is zero, any process that performs wait operation will be blocked until the another process increments semaphore value with signal operation.
- Types of semaphores:
  - Binary semaphores: It is also known as mutex lock, used to implement mutual exclusion. It is initialized with 1 and can have only two values 0 and 1.
  - Counting Semaphore: It can be used to control access to a given resource consisting of a finite number of instances. The semaphore is initialized to the number of resources available.
