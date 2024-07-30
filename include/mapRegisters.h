#ifndef __MAP_REGISTERS_H__
#define __MAP_REGISTERS_H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>

#define NUM_REGISTERS 16
#define FILE_PATH "registers.bin"
#define FILE_SIZE 1024

typedef struct {
    unsigned short *registradores[NUM_REGISTERS];
} Hardware;

extern Hardware hardware;

char* registers_map(const char* file_path, int file_size, int* fd);
int registers_release(void* map, int file_size, int fd);
int initializeRegisters();

#endif // __MAP_REGISTERS_H__
