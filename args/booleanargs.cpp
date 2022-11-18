#include "args.h"

void BooleanArgs::parseArgs(list<string> argv) {
    for(string value : argv) {
        if (value.length() == 0) {
            continue;
        }
        else if (value[0] == '-') {
            setLastKey(value);
        }
        else {
            addArg(value);
        }
    }
    
    setLastKey("");
}

Args& BooleanArgs::parse(int argc, char* argv[]) {
    list<string> args;
    for(int i=1; i<argc; i++) {
        args.push_back(argv[i]);
    }

    parseArgs(args);

    return *this;
}


