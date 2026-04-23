#pragma once

typedef struct {
    char id[128];
    char disk[256];
    char disk_format[32];
} Meta;

int load_meta(const char *path, Meta *m);
