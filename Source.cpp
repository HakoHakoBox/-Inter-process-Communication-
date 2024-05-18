#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int pp2c[2]; //from parent to child, parent write, child read
    int pc2p[2]; //from child to parent, child write, parent read

    pipe(pp2c);
    pipe(pc2p);

    int pid = 1234;
    pid = fork();

    char input_str[100] = "Parent Message String";
    char fixed_str[100] = "Child Message String";


    if (pid > 0) { //parent process
        cout << "Parent Process" << endl;
        char buffer[100];
        close(pp2c[0]);
        write(pp2c[1], input_str, strlen(input_str) + 1);
        close(pp2c[1]);
        close(pc2p[1]);

        read(pc2p[0], buffer, 100);
        cout << "This message from child: " << buffer << ". The parent printed this." << endl;
        close(pc2p[0]);
    }

    else { //child process
        cout << "Child Process" << endl;
        close(pp2c[1]);
        char buffer[100];
        read(pp2c[0], buffer, 100);
        cout << "This message from parent: " << buffer << ". The child printed this." << endl;
        close(pp2c[0]);
        close(pc2p[0]);
        write(pc2p[1], buffer, strlen(buffer) + 1);
        close(pc2p[1]);
    }

    return 0;
}
