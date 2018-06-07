#include <stdio.h>
//#include <mpi.h>
#include <stdlib.h>
#include <unistd.h>
#include "msgshm238.h"

void strings() {
    char str[] = "no notion of 'wrapper' String class/struct like in java;\nstrings are declared as char arrays.\n";
    printf("%s", str);
}

int main(void) {

//    char * str1 = "string1";
//    char * str2 = "string2";
//    send(str1, 42);
//    send(str2, 42);

    // Note: attempts to read messages sent by self
//    msg* msg1 = recv(42);
//    printf("read message: { senderId=%d; rcvrId=%d; payload='%s'; }\n", msg1->senderId, msg1->rcvrId, msg1->payload);
//    msg* msg2 = recv(42);
//    printf("read message: { senderId=%d; rcvrId=%d; payload='%s'; }\n", msg2->senderId, msg2->rcvrId, msg2->payload);
    // There should be no more messages left in buffer at this point.
    // Make sure we handle this corner case.
//    msg* msg3 = recv(42);
//    if (NULL == msg3) {
//        printf("buffer empty, recv() returned NULL\n");
//    } else {
//        printf("read message: { senderId=%d; rcvrId=%d; payload='%s'; }\n", msg3->senderId, msg3->rcvrId, msg3->payload);
//    }


//    char * str1 = "string1";
//    char * str2 = "string2";
    
//    char * str = malloc(sizeof(*str));
    
    printf("PID: %d Running\n",getpid());
    printf("enter s to send and r to receive : ");
    char ch;
    scanf("%c",&ch);
    char str[1024];
    
    if(ch == 's'){
        int receiver_id;
        printf("enter receiver id: ");
        scanf("%d",&receiver_id);
        while(1) {
            printf("enter string to send:");
            scanf("%s",str);
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
            }
        }
    }

    return 0;
}


