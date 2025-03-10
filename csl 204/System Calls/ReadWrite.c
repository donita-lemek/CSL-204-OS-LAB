#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FILE_NAME "example.txt"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    fd = open(FILE_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file for reading");
        return 1;}
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("Error reading from the file");
        close(fd);
        return 1;}
    buffer[bytes_read] = '\0';
    printf("\nExisting content of the file '%s':\n%s\n", FILE_NAME, buffer);
    if (close(fd) == -1) {
        perror("Error closing the file after reading");
        return 1;}
    char user_input[BUFFER_SIZE];
    printf("Enter text to append to the file (Press Enter to finish, Ctrl+D to stop input):\n");
    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        perror("Error reading input");
        return 1;}
    size_t input_length = strlen(user_input);
    if (user_input[input_length - 1] == '\n') {
        user_input[input_length - 1] = '\0';}
    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening the file for appending");
        return 1;}
    ssize_t bytes_written = write(fd, user_input, strlen(user_input));
    if (bytes_written == -1) {
        perror("Error writing to the file");
        close(fd);
        return 1;}
    printf("Successfully appended %ld bytes to the file '%s'.\n", bytes_written, FILE_NAME);
    if (close(fd) == -1) {
        perror("Error closing the file after appending");
        return 1;    }
    fd = open(FILE_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file for reading after appending");
        return 1;    }
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("Error reading from the file after appending");
        close(fd);
        return 1;    }
    buffer[bytes_read] = '\0';
    printf("\nUpdated content of the file '%s':\n%s\n", FILE_NAME, buffer);
    if (close(fd) == -1) {
        perror("Error closing the file after reading");
        return 1;}
    return 0;}


