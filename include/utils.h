#ifndef _UTILS_
#define _UTILS_

#include <iostream>
#include <string.h>

void usage(char *arg) {

    std::cout << "usage: " << arg << " -train " << endl;
    std::cout << "       " << arg << " -test  " << endl;
}

struct ConfigMgr
{
    int mode;

    ConfigMgr (int argc, char**argv) {

        initLocals();
        manageConfig(argc, argv);
    }

    void initLocals () {

        mode = 0;
    }

    void manageConfig (int argc, char**argv) {

        for (int i = 1; i < argc; i++) {

            if (strncmp(argv[i], "-train", 6) == 0) 
                mode = 1;
            else if (strncmp(argv[i], "-test", 5) == 0) 
                mode = 2;
            else if (strncmp(argv[i], "-use", 4) == 0) 
                usage(argv[0]);
        }
    }
};

#endif // _UTILS_
