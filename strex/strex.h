#pragma once
#include <string>
#include <vector>
using namespace std;

namespace strex {
    vector<string> split(string, char);
    string& ltrim(string& str, const char*);
    string& rtrim(string& str, const char*);
    string& trim(string& str, const char*);
    string replaceAll(string str, const string from, const string to);
}