#include "RequirementEngine.hpp"
#include "Player.hpp"
#include "Misc.h"
#include <list>

/** A quick and dirty program to fiddle with the requirements engine
 */

int main(int argc, char** argv) {
    std::unordered_map<string,RequirementEngine> res;
    std::list<Player*> players;

    try {
        json js;
        JSON_FROM_FILE(js, "testprogs/test/re-test.json");
        ItemFactory ifact("config/items");

        for(json p : js["players"])
            players.push_back(new Player(p));
        { auto reng = js["requirementGroups"];
        for(json::iterator it = reng.begin(); it != reng.end(); ++it)
            res.insert(std::make_pair(it.key(), RequirementEngine(it.value()))); }

        std::cerr << "REQENG CASES: " << res.size() << std::endl;
        std::cerr << "PLAYER CASES: " << players.size() << std::endl;

        for(Player* p : players) {
            for(auto& e : res) {
                std::cout << p->getName()  << " - "
                    << e.first << " - "  << e.second.valid(*p)
                    << std::endl;
            }
        }

    } catch (char const* ch) {
        std::cerr << ch << std::endl;
    }

    for(auto&  p : players)
        delete p;
    return 0;
}