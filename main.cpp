#include "include/Session.hpp"
#include "include/ItemFactory.hpp"
#include <ctime>
#include "lib/tinydir.h"

int main(int argc, char** argv) {
    srand(time(nullptr));
    ItemFactory ifact("config/items");
    ifact.listItems(std::cout);
    return 0;
}