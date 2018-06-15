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

int close_mem(int pid1,int pid2);

// Header used for structuring data in shm segment.
typedef struct SharedMemorySegmentHeader {
    /**
     * Number of m toessages in the shm segment that this header resides in.
     */
    unsigned int msg_count;
    /**
     * pid of process that currently has exclusive access to the shm segment that this header resides in.
     */
    _Atomic pid_t pIdOfCurrent;
    /**
     * Index of most recently added message.
     */
    int newest;
    /**
     * Index of least recently added message.
     */
    int oldest;
} shm_header;
