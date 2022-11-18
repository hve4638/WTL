#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include "strex.h"
using namespace std;

class WTL {
private:
    map<string, string> dict;
    string *filePath;

    void init() {
        char *home = getenv("HOME");

        filePath = new string(home);
        filePath->append("/.wtlconfig");
    }

    void readAndParse() {
        ifstream ifs;
        char line[512] = { 0, };

        ifs.open(*filePath, ios::in);
        if (ifs) {
            while (ifs.getline(line, 512)) {
                parseLine(line);
            }
        } else if (writeDefault()) {
            readAndParse();
        } else {
            exit(-1);
        }
    }

    bool parseLine(const char* line) {
        vector<string> splited = strex::split(line, ':');
        string key = strex::trim(splited[0], " ");
        string value = strex::trim(splited[1], " ");
        dict.insert({key, value});
        return true;
    }

    bool writeDefault() {
        ofstream ofs(*filePath);
        if (ofs.fail()) {
            cerr << "Write Error!" << endl;
            return false;
        } else {
            ofs << "export-path : /mnt/c/wtl/" << endl;
            ofs << "import-path : /mnt/c/wtl/" << endl;
            return true;
        }
    }

public:
    static WTL* wtl;
    WTL() {
        init();
        readAndParse();
    }
    ~WTL() {
        delete filePath;
    }

    string get(const char* str) {
        if (dict.find(str) != dict.end()) {
            return dict[str];
        } else {
            return "";
        }
    }
};
WTL* WTL::wtl = NULL;

WTL& getWTL() {
    if (WTL::wtl == NULL) {
        WTL::wtl = new WTL();
    }
    return *WTL::wtl;
}

string getImportPath() {
    WTL &wtl = getWTL();
    return wtl.get("import-path");
}

string getExportPath() {
    WTL &wtl = getWTL();
    return wtl.get("export-path");
}
