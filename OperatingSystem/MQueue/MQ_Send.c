#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

#define ROUNDS 5
#define MAX_MSG 128

#define Q1 "/que1"   // A -> B
#define Q2 "/que2"   // B -> A

int main()
{
    mqd_t q1, q2;
    char msg[MAX_MSG];
    char buf[MAX_MSG];

    struct mq_attr attr = {0};
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_MSG;

    // ניקוי תורים ישנים מהרצות קודמות
    mq_unlink(Q1);
    mq_unlink(Q2);

    q1 = mq_open(Q1, O_CREAT | O_RDWR, 0660, &attr);
    if (q1 == (mqd_t)-1) { perror("mq_open q1"); exit(1); }

    q2 = mq_open(Q2, O_CREAT | O_RDWR, 0660, &attr);
    if (q2 == (mqd_t)-1) { perror("mq_open q2"); exit(1); }

    for (int i = 1; i <= ROUNDS; i++)
    {
        snprintf(msg, sizeof(msg), "PING %d", i);
        if (mq_send(q1, msg, strlen(msg) + 1, 0) == -1)
        {
            perror("mq_send q1");
            exit(1);
        }

        if (mq_receive(q2, buf, sizeof(buf), NULL) == -1)
        {
            perror("mq_receive q2");
            exit(1);
        }

        printf("A got: %s\n", buf);
    }

    mq_close(q1);
    mq_close(q2);

    mq_unlink(Q1);
    mq_unlink(Q2);

    return 0;
}
