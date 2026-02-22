#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define ROUNDS 5
#define MAX_MSG 128

#define Q1 "/que1"   // A -> B
#define Q2 "/que2"   // B -> A

int main()
{
    mqd_t q1, q2;
    char buf[MAX_MSG];
    char msg[MAX_MSG];

    // פותחים תורים קיימים (אם תריץ B לפני A זה ייכשל)
    q1 = mq_open(Q1, O_RDWR);
    if (q1 == (mqd_t)-1) { perror("mq_open q1 (run A first)"); exit(1); }

    q2 = mq_open(Q2, O_RDWR);
    if (q2 == (mqd_t)-1) { perror("mq_open q2 (run A first)"); exit(1); }

    for (int i = 1; i <= ROUNDS; i++)
    {
        if (mq_receive(q1, buf, sizeof(buf), NULL) == -1)
        {
            perror("mq_receive q1");
            exit(1);
        }

        printf("B got: %s\n", buf);

        snprintf(msg, sizeof(msg), "PONG %d", i);
        if (mq_send(q2, msg, strlen(msg) + 1, 0) == -1)
        {
            perror("mq_send q2");
            exit(1);
        }
    }

    mq_close(q1);
    mq_close(q2);

    return 0;
}
