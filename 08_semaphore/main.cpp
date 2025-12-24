#include "kato/log.hpp"
#include <thread>
#include <semaphore.h>

sem_t sem_red;
sem_t sem_green;
sem_t sem_blue;

void red_worker(unsigned int count)
{
    sem_wait(&sem_red);
    for (size_t i = 0; i < count; i++)
        kato::log::cout << KATO_RED << "i = " << i << KATO_RESET << std::endl;
    sem_post(&sem_green);
}

void green_worker(unsigned int count)
{
    sem_wait(&sem_green);
    for (size_t i = 0; i < count; i++)
        kato::log::cout << KATO_GREEN << "i = " << i << KATO_RESET << std::endl;
    sem_post(&sem_blue);
}
void blue_worker(unsigned int count)
{
    sem_wait(&sem_blue);
    for (size_t i = 0; i < count; i++)
        kato::log::cout << KATO_BLUE << "i = " << i << KATO_RESET << std::endl;
}

int main()
{
    std::thread red_thread, green_thread, blue_thread;

    sem_init(&sem_red, 0, 1);
    sem_init(&sem_green, 0, 0);
    sem_init(&sem_blue, 0, 0);

    red_thread = std::thread(red_worker, 2);
    green_thread = std::thread(green_worker, 3);
    blue_thread = std::thread(blue_worker, 5);

    red_thread.join();
    green_thread.join();
    blue_thread.join();

    sem_destroy(&sem_red);
    sem_destroy(&sem_green);
    sem_destroy(&sem_blue);
}
