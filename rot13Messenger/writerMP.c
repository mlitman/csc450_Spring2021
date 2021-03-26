// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#define MAX 20
  
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;
  
int main()
{
    key_t key;
    int msgid;
  
    //message.mesg_text = (char*)malloc(MAX);

    // ftok to generate unique key
    key = ftok("progfile", 65);
  
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
  
    printf("What do you want to write? : ");
    fgets(message.mesg_text,MAX,stdin);
  
    //printf("%d\n", (int)sizeof(message));
    
    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    printf("Data send is : %s \n", message.mesg_text);

    struct mesg_buffer temp;
    temp.mesg_type = 2;
    for(int i = 2; i < 10; i++)
    {
        sprintf(temp.mesg_text, "%s %d", "hello", i);
       
        msgsnd(msgid, &temp, sizeof(temp), 0);
    }
    //fgets(mb2.mesg_text,MAX,stdin);
    

    // display the message

    return 0;
}