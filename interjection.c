#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

char VER[] = "1.2";

char* GNU = NULL;
char* Linux = NULL;

void cleanExit(int err) {
    fflush(stdout);
    if (GNU != NULL) free(GNU);
    if (Linux != NULL) free(Linux);
    exit(err);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, cleanExit);
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--version")) {
            if (argc > 2) {fprintf(stderr, "Incorrent number of options passed.\n"); cleanExit(1);}
            printf("Stallman Interjection Text Generator %s\n", VER);
            printf("Copyright (C) 2021 PQCraft\n");            
            cleanExit(0);
        } else
        if (!strcmp(argv[i], "--help")) {
            if (argc > 2) {fprintf(stderr, "Incorrent number of options passed.\n"); cleanExit(1);}
            printf("Usage: interject [options]\n");
            printf("Options:\n");
            printf("  --help              Shows the help screen.\n");
            printf("  --version           Shows the version info.\n");
            printf("  --gnu <text>        Changes all occurrences of 'GNU' to <text>.\n");
            printf("  --linux <text>      Changes all occurrences of 'Linux' to <text>.\n");
            cleanExit(0);
        } else
        if (!strcmp(argv[i], "--gnu")) {
            if (GNU != NULL) {fprintf(stderr, "Cannot define 'GNU' more than once.\n"); cleanExit(1);}
            i++;
            if (i > argc - 1) {fprintf(stderr, "No value specified for 'GNU'.\n"); cleanExit(1);}
            GNU = (char *)malloc(strlen(argv[i]) + 1);
            strcpy(GNU, argv[i]);
        } else
        if (!strcmp(argv[i], "--linux")) {
            if (Linux != NULL) {fprintf(stderr, "Cannot define 'Linux' more than once.\n"); cleanExit(1);}
            i++;
            if (i > argc - 1) {fprintf(stderr, "No value specified for 'Linux'.\n"); cleanExit(1);}
            Linux = (char *)malloc(strlen(argv[i]) + 1);
            strcpy(Linux, argv[i]);
        } else {
            fprintf(stderr, "Invalid option: %s\n", argv[i]);
            cleanExit(1);
        }
    }
    if (GNU == NULL) {GNU = malloc(4); strcpy(GNU, "GNU");}
    if (Linux == NULL) {Linux = malloc(6); strcpy(Linux, "Linux");}
    printf(
        "I'd just like to interject for a moment.\n"
        "What you're referring to as %s, is in fact, %s/%s, or as I've recently taken to calling it, %s plus %s.\n"
        "%s is not an operating system unto itself, but rather another free component of a fully functioning %s system made useful by the %s corelibs, shell utilities and vital system components comprising a full OS as defined by POSIX.\n"
        "Many computer users run a modified version of the %s system every day, without realizing it.\n"
        "Through a peculiar turn of events, the version of %s which is widely used today is often called \"%s\", and many of its users are not aware that it is basically the %s system, developed by the %s Project.\n"
        "There really is a %s, and these people are using it, but it is just a part of the system they use.\n"
        "%s is the kernel: the program in the system that allocates the machine's resources to the other programs that you run.\n"
        "The kernel is an essential part of an operating system, but useless by itself; it can only function in the context of a complete operating system.\n"
        "%s is normally used in combination with the %s operating system: the whole system is basically %s with %s added, or %s/%s.\n"
        "All the so-called \"%s\" distributions are really distributions of %s/%s.\n",
        Linux, GNU, Linux, GNU, Linux,
        Linux, GNU, GNU,
        GNU,
        GNU, Linux, GNU, GNU,
        Linux,
        Linux,
        Linux, GNU, GNU, Linux, GNU, Linux,
        Linux, GNU, Linux
    );
    cleanExit(0);
}
