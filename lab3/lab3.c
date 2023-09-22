#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    int *shared_x = (int *)shmat(shmid, NULL, 0);
    *shared_x = 10;
    printf("Init Value: %d\n", *shared_x);

    if (fork() == 0)
    {
        *shared_x += 20;
        printf("Child(+20): %d\n", *shared_x);
    }
    else
    {
        wait(NULL);

        *shared_x *= 40;
        printf("Parent(*40): %d\n", *shared_x);

        shmdt(shared_x);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
