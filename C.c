#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>


#define SRV_HOST "delta"
#define SRV_PORT 1234
#define CLNT_PORT 1235
#define BUF_SIZE 64
#define TXT_ANSW "I am your client\n"
#define h_addr h_addr_list[0]
int main()
{
    int s;
    int from_len;
    char buf[BUF_SIZE];
    struct hostent *hp;
    struct sockaddr_in clnt_sin, srv_sin;
    s = socket (AF_INET, SOCK_STREAM, 0 );
    memset ((char *)&clnt_sin, '\0', sizeof(clnt_sin));
    clnt_sin.sin_family = AF_INET;
    clnt_sin.sin_addr.s_addr = INADDR_ANY;
    clnt_sin.sin_port = CLNT_PORT;
    bind (s,(struct sockaddr *)&clnt_sin, sizeof(clnt_sin));

    memset ((char *)&srv_sin, '\0', sizeof(srv_sin));
    hp = gethostbyname (SRV_HOST);
    srv_sin.sin_family = AF_INET;
    memcpy ((char *)&srv_sin.sin_addr, hp -> h_addr, hp -> h_length);
    srv_sin.sin_port = SRV_PORT;
    connect(s, &srv_sin,sizeof(srv_sin));
    from_len = recv (s, buf,BUF_SIZE,0);
    write (1, TXT_ANSW, sizeof(TXT_ANSW),0);
    send (s, TXT_ANSW, sizeof(TXT_ANSW),0);
    close (s);
    exit(0);

    return 0;
}



