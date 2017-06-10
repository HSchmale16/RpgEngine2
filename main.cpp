#include "include/Session.hpp"
#include "include/ItemFactory.hpp"
#include <ctime>
#include "lib/tinydir.h"

int main(int argc, char** argv) {
    srand(time(nullptr));
    ItemFactory ifact("config/items");
    ifact.listItems(std::cout);
    Location l("config/locations/test1.json");
    l.dump(std::cout);
    Session s(&l);
    std::string line;
    while(getline(std::cin, line)) {
        s.parseCommand(line, std::cout);
        if(s.quit())
            break;
    }
    return 0;
}