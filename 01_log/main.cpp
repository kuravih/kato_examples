#include "kato/log.hpp"

int main()
{

    kato::log::cout << "This is a normal log message." << std::endl;
    kato::log::cout << "Another log entry: " << 42 << " and some text." << std::endl;

    kato::log::cerr << "Something went wrong!" << std::endl;
    kato::log::cerr << "This is an error message!" << std::endl;

    kato::log::cout << KATO_BLACK << "This is black" << KATO_RESET << std::endl;
    kato::log::cout << KATO_RED << "This is red" << KATO_RESET << std::endl;
    kato::log::cout << KATO_GREEN << "This is green" << KATO_RESET << std::endl;
    kato::log::cout << KATO_YELLOW << "This is yellow" << KATO_RESET << std::endl;
    kato::log::cout << KATO_BLUE << "This is blue" << KATO_RESET << std::endl;
    kato::log::cout << KATO_MAGENTA << "This is magenta" << KATO_RESET << std::endl;
    kato::log::cout << KATO_CYAN << "This is cyan" << KATO_RESET << std::endl;
    kato::log::cout << KATO_WHITE << "This is white" << KATO_RESET << std::endl;

    kato::log::cerr << KATO_RED << "This is a red error" << KATO_RESET << std::endl;

    for (size_t i = 0; i < 100; i++)
    {
        kato::log::cout << KATO_GREEN << "Running " << kato::log::spinner() << KATO_RESET << std::flush;
        usleep(100000);
        std::cout << "\r\33[2K";
    }

    return 0;
}