#include <stdio.h>
#include <string.h>
#include "meta.h"

int load_meta(const char *path, Meta *m) {
    FILE *fp = fopen(path, "r");
    if (!fp) return -1;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char key[64], val[192];
        if (sscanf(line, "%63[^=]=%191s", key, val) != 2) continue;

        if (strcmp(key, "id") == 0) {
            strncpy(m->id, val, sizeof(m->id));
        } else if (strcmp(key, "disk") == 0) {
            strncpy(m->disk, val, sizeof(m->disk));
        } else if (strcmp(key, "disk_format") == 0) {
            strncpy(m->disk_format, val, sizeof(m->disk_format));
        }
    }
    fclose(fp);
    return 0;
}
