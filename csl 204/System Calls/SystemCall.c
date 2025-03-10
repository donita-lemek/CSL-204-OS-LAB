#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int c = 0;
    while (c != 1) {
        printf("....MENU.....\n");
        printf("1. Create Process\t2. List Directory\t3. File Status\t4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            __pid_t p;
            p = fork();
            if (p < 0) {
                printf("Fork Failed\n");
                return EXIT_FAILURE;
            } else if (p == 0) {
                printf("Child Process, PID: %d\n", getpid());
                char *args[] = {"/bin/ls", "-l", NULL};
                execvp(args[0], args);
                perror("execvp");
                exit(EXIT_FAILURE);
            } else {
                printf("Parent Process, PID: %d\n", getpid());
                printf("Waiting for Child Process: PID of Child: %d\n", p);
                int status;
                wait(&status);
                sleep(2);
            }
        } else if (choice == 3) {
            char filename[256];
            struct stat filestat;
            printf("Enter the file name: ");
            scanf("%s", filename);
            if (stat(filename, &filestat) == -1) {
                perror("Error retrieving file information");
                continue;
            }
            printf("File: %s\n", filename);
            printf("Device ID: %ld\n", (long)filestat.st_dev);
            printf("Inode: %ld\n", (long)filestat.st_ino);
            printf("User ID: %d\n", filestat.st_uid);
            printf("Group ID: %d\n", filestat.st_gid);
            printf("Size: %ld bytes\n", (long)filestat.st_size);
            printf("Blocks: %ld\n", (long)filestat.st_blocks);
            printf("Last access time: %s", ctime(&filestat.st_atime));
            printf("Last modification time: %s", ctime(&filestat.st_mtime));
            printf("Last status change time: %s", ctime(&filestat.st_ctime));
        } else if (choice == 2) {
            DIR *d;
            struct dirent *dir;
            d = opendir(".");
            if (d == NULL) {
                printf("Could not open current directory\n");
                continue;
            }
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("Current working dir: %s\n", cwd);
            }
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        } else if (choice == 4) {
            printf("End of program...\n");
            c = 1;
        } else {
            printf("Wrong choice\n");
        }
    }
    return EXIT_SUCCESS;
}

