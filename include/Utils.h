#ifndef _UTILS_
#define _UTILS_

#include <iostream>
#include <string.h>

void usage(char *arg) {

    std::cout << "usage: " << arg << " -train " << endl;
    std::cout << "       " << arg << " -test  " << endl;
    std::cout << "       " << arg << " -use  " << endl;
}

struct ConfigMgr
{
    int mode;
    int err_code;
    string err_msg;

    ConfigMgr (int argc, char**argv) {

        initLocals();
        manageConfig(argc, argv);
    }

    void initLocals () {

        mode = 0;
        err_code = -1;
    }

    void manageConfig (int argc, char**argv) {

        if (argc == 1)
        {
            usage(argv[0]);
            err_code = 0;
            err_msg = "No input found";
        }

        for (int i = 1; i < argc; i++) {

            if (strncmp(argv[i], "-train", 6) == 0) 
                mode = 1;
            else if (strncmp(argv[i], "-test", 5) == 0) 
                mode = 2;
            else if (strncmp(argv[i], "-use", 4) == 0) 
                usage(argv[0]);
            else
            {
                err_code = i;
                err_msg = "Invalid param: " + string(argv[i]);
            }
        }
    }

    int is_ok() {
        return err_code;
    }

    int is_ok(string& errStr) {
        errStr = err_msg;
        return err_code;
    }
};

#endif // _UTILS_
