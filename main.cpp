#include "include/Session.hpp"
#include "include/ItemFactory.hpp"
#include <ctime>
#include "lib/tinydir.h"

int main(int argc, char** argv) {
    srand(time(nullptr));
    // load up the items into static memory
    ItemFactory ifact("config/items");
    ifact.listItems(std::cout);
    try {
        Location l("config/locations/test1.json");
        l.dump(std::cout);
        Session s(&l, std::cout);
        std::string line;
        while(getline(std::cin, line)) {
            s.parseCommand(line);
            if(s.quit())
                break;
        }
    } catch(const char* chr) {
        std::cout << chr << std::endl;
    }
    return 0;
}
