#include "args.h"

void ValueArgs::parseArgs(list<string> argv) {
    for(string value : argv) {
        if (value.length() == 0) {
            continue;
        }
        else if (value[0] == '-') {
            setLastKey(value);
        }
        else if (noLastKey()) {
            addArg(value);
        }
        else {
            setLastOption(value);
        }
    }
    
    setLastKey("");
}

Args& ValueArgs::parse(int argc, char* argv[]) {
    list<string> args;
    for(int i=1; i<argc; i++) {
        args.push_back(argv[i]);
    }

    parseArgs(args);

    return *this;
}


