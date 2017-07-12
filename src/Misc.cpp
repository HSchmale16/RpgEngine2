#include "../include/Misc.h"

/** Modified from: https://stackoverflow.com/a/26210475/4335488
 */
std::string removeComments(std::string input, std::string commentDelim) {
    size_t nFPos = 0;
    while(true) {
        nFPos = input.find(commentDelim, nFPos);
        if(nFPos != std::string::npos) {
            size_t to = input.find('\n', nFPos);
            input.erase(nFPos, to - nFPos);
        } else
            break;
    }
    return input;
}