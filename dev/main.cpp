/*
 * This example uses direct processing function,
 * to process dummy NMEA data from GPS receiver
 */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "lwgps/lwgps.h"
#include "lwgps/lwgps.hpp"

/* External function */
extern "C" int run_tests_time(void);
extern "C" int run_tests_main(void);

Lwgps::Lwgps gps;

int
main() {
    int ret = 0;
    ret |= run_tests_main();
    ret |= run_tests_time();

    printf("Done\r\n");
    return 0;
}
