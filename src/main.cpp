#include "muQhttpd2.h"
#include <cstring>

int
main(int argc, char* argv[])
{
    char confFile[512];

    /*  1. 解析命令行参数 */

    if (argc != 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            fprintf(stderr, "Usage:\n  %s -C|--conf-file conf-file] ", argv[0]);
            exit(EXIT_FAILURE);
        }

        if (argc == 3 &&
            (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--confdir") == 0)) {
            strncpy(confFile, argv[2], 511);
        } else {
            fprintf(stderr, "Usage:\n  %s -C|--conf-file conf-file] ", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    /*  2. 启动 muQhttpd2 */

    muQhttpd2 muQ;
    muQ.start(confFile);
}
