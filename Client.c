#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int s, n[3] = {5, 3, 2}, r[3];
    struct sockaddr_in a;

    s = socket(AF_INET, SOCK_STREAM, 0);

    a.sin_family = AF_INET;
    a.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &a.sin_addr);

    connect(s, (struct sockaddr *)&a, sizeof(a));

    write(s, n, sizeof(n));
    read(s, r, sizeof(r));

    printf("Sum = %d\nDifference = %d\nProduct = %d\n",
           r[0], r[1], r[2]);

    close(s);
    return 0;
}
