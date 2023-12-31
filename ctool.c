#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "fcntl.h"

/* 
Tests:
ctool create ctest1 -p 4 sh ps echoloop forkbomb
ctool start ctest1 vc0 sh

ctool create ctest2 -m 40000000 sh df free membomb
ctool start ctest2 vc1 sh

ctool create ctest3 -d 100000 sh ps free diskbomb
ctool start ctest3 vc2 sh

ctool create ctest4 sh ps echoloop
ctool start ctest4 vc3 echoloop a b
*/ 

void usage() {
    // printf(1, "usage: ctool create <name> [-p <max_processes>] [-m <max_memory>] [-d <max_disk>] prog [prog2.. ]\n");
    printf(1, "usage: ctool create container_id\n");
    exit();
}

void create(int argc, char *argv[]) {
    if(argc < 3) {
        usage();
    }

    int i = create_container(atoi(argv[2]));
    printf(1, "%d\n", i);
}

void tickstest() {
    int i, j;
    int n;
    uint ticks, t1, t2;

    n = 11;

    t1 = uptime();

    for (i = 0; i < n; i++) {
      for (j = 0; j< 100000; j++) {
        ;
      }
    }

    t2 = uptime();

    ticks = getticks();
    printf(1, "ticks = %d\n", ticks);
    printf(1, "t1    = %d\n", t1);
    printf(1, "t2    = %d\n", t2);
    printf(1, "t2-t1 = %d\n", t2-t1);

    exit();
}

int main(int argc, char *argv[]) {
    create(argc, argv);
    tickstest();
    exit();
}
