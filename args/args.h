#include <string>
#include <map>
#include <list>

using namespace std;

class Args {
private:
    string lastKey;
    string arg;
    map<string, string> options;

protected:
    void addArg(string);
    void setLastKey(string);
    void setLastOption(string);
    bool noLastKey();

public:
    virtual Args& parse(int, char*[])=0;
    string getOption(string);
    bool hasOption(string);
    string getArg();
};

class BooleanArgs : public Args {
    void parseArgs(list<string>);

public:
    BooleanArgs() {};
    BooleanArgs(int argc, char* argv[]) {
        parse(argc, argv);
    }

    virtual Args& parse(int argc, char* argv[]);
};

class ValueArgs : public Args {
    void parseArgs(list<string>);

public:
    ValueArgs() {};
    ValueArgs(int argc, char* argv[]) {
        parse(argc, argv);
    }

    virtual Args& parse(int argc, char* argv[]);
};


