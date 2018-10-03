#include <sstream>
#include <algorithm>

#include "snapithd.h"

/** ParseSHD 
 * Take the cmdline optiona and split it into a array so we know which cameras are shd cameras.
 * Only excepts true/false strings
 * 
 * bool* array set to the size of SHD_CAMERA_LEN to return the value
 * std::string the string to be parsed
 */

void ParseSHD(bool* barry,std::string cmdoption) {
    std::istringstream ss(cmdoption);
    std::string token;
    int pos = 0;

    while (std::getline(ss, token, ',')) {
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        // Make sure we don't read further than what we expect
        if (pos < SHD_CAMERA_LEN) {
            bool result = false; // anything we don't parse right will be defaulted to false
            if (token == "true") {
                result = true;
            }
            barry[pos] = result;
        }
        pos++;
    }
}
