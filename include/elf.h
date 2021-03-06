#ifndef _ELF_H
#define _ELF_H 

#include "types.h"

#define ELF_MAGIC 0x464C457FU   /* "\x7FELF" in little endian */

typedef struct elf_header_s {
    u32 e_magic;   // must equal ELF_MAGIC
    u8 e_elf[12];
    u16 e_type;
    u16 e_machine;
    u32 e_version;
    u32 e_entry;
    u32 e_phoff;
    u32 e_shoff;
    u32 e_flags;
    u16 e_ehsize;
    u16 e_phentsize;
    u16 e_phnum;
    u16 e_shentsize;
    u16 e_shnum;
    u16 e_shstrndx;
} elf_header_t;

typedef struct elf_prog_header_s {
    u32 p_type;
    u32 p_offset;
    u32 p_va;
    u32 p_pa;
    u32 p_filesz;
    u32 p_memsz;
    u32 p_flags;
    u32 p_align;
} elf_prog_header_t;

typedef struct elf_section_header_s {
    u32 sh_name;
    u32 sh_type;
    u32 sh_flags;
    u32 sh_addr;
    u32 sh_offset;
    u32 sh_size;
    u32 sh_link;
    u32 sh_info;
    u32 sh_addralign;
    u32 sh_entsize;
} elf_section_header_t;

// Values for Proghdr::p_type
#define ELF_PROG_LOAD       1

// Flag bits for Proghdr::p_flags
#define ELF_PROG_FLAG_EXEC  1
#define ELF_PROG_FLAG_WRITE 2
#define ELF_PROG_FLAG_READ  4

// Values for Secthdr::sh_type
#define ELF_SHT_NULL        0
#define ELF_SHT_PROGBITS    1
#define ELF_SHT_SYMTAB      2
#define ELF_SHT_STRTAB      3

// Values for Secthdr::sh_name
#define ELF_SHN_UNDEF       0

#endif
