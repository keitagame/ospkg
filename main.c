#include <stdio.h>
#include <stdlib.h>
#include "meta.h"
#include "util.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <package_dir> <target_disk>\n", argv[0]);
        return 1;
    }

    const char *pkgdir = argv[1];
    const char *disk = argv[2];

    char meta_path[512];
    snprintf(meta_path, sizeof(meta_path), "%s/meta.json", pkgdir);

    Meta m = {0};
    if (load_meta(meta_path, &m) != 0) {
        printf("Failed to load meta.json\n");
        return 1;
    }

    printf("Installing system: %s\n", m.id);

    char img_path[512];
    snprintf(img_path, sizeof(img_path), "%s/%s", pkgdir, m.disk);

    printf("Writing disk image...\n");
    if (write_disk_image(img_path, disk) != 0) {
        printf("Failed to write disk image\n");
        return 1;
    }

    printf("Install complete.\n");
    return 0;
}
