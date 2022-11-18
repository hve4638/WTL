#include <string>
#include <vector>
#include <sstream>
using namespace std;

namespace strex {
    vector<string> split(string str, char Delimiter) {
        istringstream iss(str);
        string buffer;
        vector<string> result;

        while (getline(iss, buffer, Delimiter)) {
            result.push_back(buffer);
        }

        return result;
    }

    string& ltrim(string& s, const char* t = " \t\n\r\f\v") {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

    string& rtrim(string& s, const char* t = " \t\n\r\f\v") {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    string& trim(string& s, const char* t = " \t\n\r\f\v") {
        return ltrim(rtrim(s, t), t);
    }

    string replaceAll(string str, const string from, const string to) {
        size_t start_pos = 0;

        while ((start_pos = str.find(from, start_pos)) != string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
        return str;
    }
}
