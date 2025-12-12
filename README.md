# Philosophers

Classic process synchronization problem with threads that simulates the behavior of dining philosophers.

## Description

The project implements the dining philosophers problem, where multiple philosophers share forks around a table. Each philosopher needs two forks to eat, which requires careful synchronization to avoid deadlocks and ensure that everyone can eat.

## The Problem

- N philosophers sit around a circular table
- There are N forks, one between each pair of philosophers
- A philosopher alternates between thinking and eating
- To eat, needs both forks (left and right)
- After eating, releases both forks
- The goal is for all philosophers to eat without deadlock

## Included Files

- `*.c` - Implementation with POSIX threads
- `*.h` - Header files
- Synchronization logic with mutexes

## Compilation

```bash
make              # Compile philo
make clean        # Clean object files
make fclean       # Clean everything
make re           # Recompile from scratch
```

## Usage

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

## Parameters

| Parameter | Description | Unit |
|---|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) | N/A |
| `time_to_die` | Maximum time without eating | milliseconds |
| `time_to_eat` | Time it takes to eat | milliseconds |
| `time_to_sleep` | Time it takes to sleep | milliseconds |
| `number_of_times_each_philosopher_must_eat` | (Optional) How many times each must eat | N/A |

### Example

```bash
./philo 5 800 200 200
# 5 philosophers, die if not eating in 800ms, eat 200ms, sleep 200ms

./philo 4 410 200 200 7
# 4 philosophers, each must eat 7 times
```

## Philosopher States

- **Thinking:** Waiting to take the forks
- **Eating:** Has taken both forks
- **Sleeping:** Resting after eating
- **Dead:** If doesn't eat before timeout

## Requirements

- C compiler (gcc, clang, etc.)
- POSIX threads (pthread)
- Make
- Linux or macOS

## Features

- Implementation with POSIX threads
- Synchronization via mutexes
- Monitoring of philosopher lifespan
- Deadlock detection
- Event logging with timestamp

## Synchronization Mechanism

- Each fork is protected by a mutex
- Each philosopher takes the left fork, then the right one
- Mutexes are released after eating
- A monitor thread supervises lifespan

## Output

The program prints events like:
```
timestamp X is thinking
timestamp X has taken a fork
timestamp X is eating
timestamp X is sleeping
timestamp X died
```

## Important Notes

- Synchronization is critical to avoid race conditions
- Timeout should be reasonable for the system
- In bonus version there may be variants of the problem

---

Last updated: December 2025
