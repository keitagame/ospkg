#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int write_disk_image(const char *img, const char *disk) {
    char cmd[512];
    snprintf(cmd, sizeof(cmd),
        "dd if='%s' of='%s' bs=4M status=progress && sync",
        img, disk
    );
    return system(cmd);
}
