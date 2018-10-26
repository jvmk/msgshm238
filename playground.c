#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "msgshm238.h"
#include <string.h>

// Playground for exercising the library.

int main(void) {
    printf("PID: %d Running\n",getpid());
    printf("enter s to send and r to receive : ");
    char ch;
    scanf("%c",&ch);
    char str[1024];
    int val;
    char cls;

    if(ch == 's'){
        int receiver_id;
        printf("enter receiver id: ");
        scanf("%d",&receiver_id);
        while(1) {
            printf("enter string to send:");
            scanf("%s",str);

            if(strcmp(str,"close") == 0)
            {
                val = close_mem(receiver_id);
                printf("%d\n",val);
                if(val == 0){
                    printf("shared memory closed\n");
                    break;
                }
                else {
                  printf("shared memory has unread element, Can't close\n");
                }
            }
            send(str, receiver_id);
        }
    }
    else if(ch == 'r'){
        int sender_id;
        printf("enter sender id : ");
        scanf("%d",&sender_id);
        while(1) {
            msg* msg1 = recv(sender_id);
            if (msg1 != NULL) {
                printf("read message: { senderId=%d; rcvrId=%d; payload='%s'; }\n", msg1->senderId, msg1->rcvrId, msg1->payload);
                free(msg1);
            }

        }
    }
    return 0;
}
