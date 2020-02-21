#ifndef TOMATBOOT_UEFI_PARSE_CONFIG_H
#define TOMATBOOT_UEFI_PARSE_CONFIG_H

#include <Base.h>
#include <Uefi.h>
#include <Protocol/DevicePath.h>

typedef enum boot_protocol {
    BOOT_LINUX,
    BOOT_TBOOT,
    BOOT_UEFI,
    BOOT_MB2,
} boot_protocol_t;

typedef struct boot_module {
    struct boot_module* next;
    const CHAR8* path;
    const CHAR8* tag;
} boot_module_t;

typedef struct boot_entry {
    boot_protocol_t protocol;
    const CHAR8* name;
    const CHAR8* path;
    const CHAR8* cmd;
    EFI_DEVICE_PATH_PROTOCOL* device_path;
    UINTN modules_count;
    boot_module_t* modules;
} boot_entry_t;

typedef struct boot_entries {
    UINTN count;
    boot_entry_t* entries;
} boot_entries_t;

extern boot_entries_t boot_entries;

EFI_STATUS get_boot_entries(boot_entries_t* config);
// TODO: void free_boot_entries(boot_entries_t* config);

typedef struct boot_config {
    INT32 boot_delay;
    INT32 default_os;
    INT32 gfx_mode;
} boot_config_t;

void load_boot_config(boot_config_t* config);
void save_boot_config(boot_config_t* config);

#endif //TOMATBOOT_UEFI_PARSE_CONFIG_H
