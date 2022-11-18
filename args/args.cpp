#include "args.h"
using namespace std;

void Args::addArg(string value) {
    if (arg == "") {
        arg = value;
    }
    else {
        arg += " " + value;
    }
}

void Args::setLastOption(string value = "") {
    if (lastKey != "") {
        options[lastKey] = value;
        lastKey = "";
    }
}

void Args::setLastKey(string key) {
    if (!hasOption(key)) setLastOption("");

    lastKey = key;
}

string Args::getOption(string key) {
    return hasOption(key) ? options[key] : "";
}

bool Args::hasOption(string key) {
    return (options.find(key) != options.end());
}

bool Args::noLastKey() {
    return (lastKey == "");
}

string Args::getArg() {
    return arg;
}