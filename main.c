#include <stdio.h>
#if DOCKER
#include <sys/utsname.h>
#endif
int main(void) {
#if DOCKER
    struct utsname u;
    uname(&u);
    printf("Hello, from %s!\r\n",u.sysname);
#else
    printf("Hello, from Simulator!\n");
#endif
    return 0;
}