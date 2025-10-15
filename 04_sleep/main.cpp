#include "kato/function.hpp"

int main()
{
    kato::function::InterruptibleSleep(std::chrono::seconds(10));
    return 0;
}