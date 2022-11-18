#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "strex.h"
#include "wtl.h"
#include "args.h"

string cmd = "cp (option)(path)(file) (file)";
string path = getImportPath();

int main(int argc, char* argv[]) {
    Args *args = new BooleanArgs();
    args->parse(argc, argv);

    if (args->hasOption("-h") || argc <= 1) {
        cerr << "Usage: wexport [OPTION]... DEST" << endl;
        cerr << "Options" << endl;
        cerr << "  -f,   force" << endl;
        cerr << "  -r,   copy directories recursively" << endl;
    }
    else {
        string option = "";
        if (args->hasOption("-r")) option += " -r";
        if (args->hasOption("-f")) option += " -f";
        option = strex::ltrim(option, " ");

        if (option.length() > 0) {
            option += " ";
        }

        cmd = strex::replaceAll(cmd, "(option)", option);
        cmd = strex::replaceAll(cmd, "(path)", path);
        cmd = strex::replaceAll(cmd, "(file)", args->getArg());
        system(cmd.c_str());
    }
}