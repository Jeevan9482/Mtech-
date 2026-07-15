#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int s, ns, n[3], r[3];
    struct sockaddr_in a;
    socklen_t len = sizeof(a);

    s = socket(AF_INET, SOCK_STREAM, 0);
    a.sin_family = AF_INET;
    a.sin_addr.s_addr = INADDR_ANY;
    a.sin_port = htons(PORT);

    bind(s, (struct sockaddr *)&a, sizeof(a));
    listen(s, 1);

    ns = accept(s, (struct sockaddr *)&a, &len);

    read(ns, n, sizeof(n));

    r[0] = n[0] + n[1] + n[2];
    r[1] = n[0] - n[1] - n[2];
    r[2] = n[0] * n[1] * n[2];

    write(ns, r, sizeof(r));

    close(ns);
    close(s);
    return 0;
}
