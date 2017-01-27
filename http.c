#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>  // for struct sockaddr_in AF_IN
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>  // for inet_pton
#include <netinet/in.h> // for IPPROTO_TCP

#define PORT "80"
#define BAIDU_IP "119.75.217.56"
#define GET_INFO "GET / HTTP/1.1\r\nHost: www.baidu.com:80\r\n\r\n"

int main()
{
    int sock_local;
    in_port_t port = atoi(PORT);
    struct sockaddr_in server;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    sock_local = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    assert(sock_local > 0);

    int retVal = -1;
    retVal = inet_pton(AF_INET, BAIDU_IP, &server.sin_addr.s_addr);
    assert(retVal == 1);

    if (connect(sock_local, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    ssize_t nByte = send(sock_local, GET_INFO, strlen(GET_INFO), 0);
    if( nByte <= 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    char BUF[BUFSIZ];
    size_t recived_len = 0;
    while ((recived_len = recv(sock_local, BUF, BUFSIZ-1, 0)) > 0)
    {
        int statu;
        BUF[recived_len] = '\0';
        printf("%s", BUF);
        statu = (recived_len==BUFSIZ-1) ? 0 : 1;
        if (statu) break;
    }
    if (recived_len < 0)
    {
        perror("recv");
    }

    //close(sock_local);
    return 0;
}

/*OUTPUT :

[root@localhost student]# gcc http.c
[root@localhost student]# ./a.out
HTTP/1.1 200 OK
Date: Mon, 21 Dec 2015 06:05:45 GMT
Content-Type: text/html
Content-Length: 14613
Last-Modified: Wed, 03 Sep 2014 02:48:32 GMT
Connection: Keep-Alive
Vary: Accept-Encoding
Set-Cookie: BAIDUID=7FF13FA470C4D628DE7B69223126F35A:FG=1; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
Set-Cookie: BIDUPSID=7FF13FA470C4D628DE7B69223126F35A; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
Set-Cookie: PSTM=1450677945; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
Set-Cookie: BDSVRTM=0; path=/
P3P: CP=" OTI DSP COR IVA OUR IND COM "
Server: BWS/1.1
X-UA-Compatible: IE=Edge,chrome=1
Pragma: no-cache
Cache-control: no-cache
BDPAGETYPE: 1
BDQID: 0xde4cca3e00038868
BDUSERID: 0
Accept-Ranges:  none

*/
