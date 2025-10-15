#include "kato/log.hpp"
#include "kato/function.hpp"
#include "kato/CCfits_addons.hpp"

int main()
{
    kato::log::cout << kato::function::CCfitsTypeToString(FLOAT_IMG) << std::endl;
    return 0;
}