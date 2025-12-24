#include "kato/log.hpp"
#include <thread>
#include <mutex>

std::mutex log_mutex;

void red_worker(unsigned int count)
{
    std::lock_guard<std::mutex> lock(log_mutex);
    for (size_t i = 0; i < count; i++)
        kato::log::cout << KATO_RED << "i = " << i << KATO_RESET << std::endl;
}

void green_worker(unsigned int count)
{
    std::lock_guard<std::mutex> lock(log_mutex);
    for (size_t i = 0; i < count; i++)
        kato::log::cout << KATO_GREEN << "i = " << i << KATO_RESET << std::endl;
}
void blue_worker(unsigned int count)
{
    std::lock_guard<std::mutex> lock(log_mutex);
    for (size_t i = 0; i < count; i++)
        kato::log::cout << KATO_BLUE << "i = " << i << KATO_RESET << std::endl;
}

int main()
{
    std::thread red_thread, green_thread, blue_thread;

    red_thread = std::thread(red_worker, 2);
    green_thread = std::thread(green_worker, 3);
    blue_thread = std::thread(blue_worker, 5);

    red_thread.join();
    green_thread.join();
    blue_thread.join();
}
