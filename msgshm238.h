#include <stdatomic.h>
// TODO update to proper size, for now keep low so that we can experiment with breaking long payloads into multiple messages
#define MAX_PAYLOAD_SIZE 32

typedef struct msgTag {
    /**
     * Sender's (process) ID
     */
    int senderId;
    /**
     * (Proccess) ID of receiver.
     */
    int rcvrId;
    /**
     * The message's payload. Fixed size. Longer payloads will have to be split into multiple messages.
     */
    char payload[MAX_PAYLOAD_SIZE];
} msg;

/**
 * Send message with contents pointed to by 'payload' to process with pid 'receiverId'.
 */
void send(char * payload, int receiverId);

/**
 * Read (receive) a message sent by process with pid 'senderId'.
 */
msg *recv(int senderId);

/****
* Close - return int
**/
int close_mem(int pid_other_proc);
