#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t forks[5];

void think(int philosopher_id) { 
printf("Philosopher %d is thinking.\n", philosopher_id);
sleep(1); }

void eat(int philosopher_id) { 
printf("Philosopher %d is eating.\n", philosopher_id); 
sleep(2); }

void *philosopher(void *arg) {
int id = *(int *)arg;
while (1) {
think(id);
sem_wait(&forks[id]);  
sem_wait(&forks[(id + 1) % 5]);
eat(id);
sem_post(&forks[id]);  
sem_post(&forks[(id + 1) % 5]);
} }

fint main() {
pthread_t philosophers[5];
int ids[5];
for (int i = 0; i < 5; i++) { 
sem_init(&forks[i], 0, 1); 
ids[i] = i; 
}
for (int i = 0; i < 5; i++) {
pthread_create(&philosophers[i], NULL, philosopher, &ids[i]); 
}
for (int i = 0; i < 5; i++) { 
pthread_join(philosophers[i], NULL);
 }
return 0; }


