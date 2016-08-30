#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>

#define SRV_FORT 1234 /*Номер порта сервера*/
#define BUF_SIZE 64/*Размер буфера для размещения принимаемых от клиента данных*/
#define TXT_QUEST "Who are you?\n"/*Вопрос клиенту*/


int main(void)
{
    int s, s_new;
    int from_len;
    char buf[BUF_SIZE];
    struct sockaddr_in sin, from_sin;
    s = socket (AF_INET, SOCK_STREAM, 0);/*Создается сокет в протоколе TCP/IP*/
    memset ((char*)&sin, '0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port - SRV_FORT;
    bind (s, (struct sockaddr *)&sin, sizeof(sin));
    listen(s, 3);
    while(1)
    {
        from_len = sizeof(from_sin);
        s_new = accept (s, &from_sin, from_len);
        write(s_new, TXT_QUEST, sizeof(TXT_QUEST));
        from_len = read (s_new, buf, BUF_SIZE);
        write(1, buf, from_len);
        shutdown(s_new,0);
        close(s_new);
     };

    return 0;
}

