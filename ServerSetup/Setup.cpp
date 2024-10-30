#include  <iostream>

#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    // creating socket
    /*
        - domain AF_INET: Specifies the communication domain or protocol family in this case IPv4
        - type SOCK_STREAM: 
            - Specifies the type of socket, which defines theå communication semantics.
            in this case we use SOCK_STREAM For a reliable, connection-oriented byte stream, typically used with TCP.
        - protocol 0: Setting protocol to 0 allows the system to choose the default protocol that matches domain and type in this case it use TCP
     */
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        std::cout << "The socket not opened\n";
    else
        std::cout << "sockect opened successfully\n";

    // initilize the environment for the sockaddr struct
    /*
        - sin_family: Specifies the communication domain or protocol family in this case IPv4
        - sin_port: specifies the port
            - The htons function is used to convert a 16-bit integer (typically a port number) from host byte order to network byte order.
        - sin_addr.s_addr: is the ip address
            - in case u don't know the ip address the INADDR_ANY will fill in the IP address for you.
    */
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    

    // binding socket.
    /*
        - Associate a socket with an IP address and port number
            - its okay to cast the sockaddr_in to sockaddr* because both have the same size
    */
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
    {
        std::cout << "fail to bind local port\n";
        exit(EXIT_FAILURE);
    }
    else
        std::cout << "successfully bind to local port\n";


    // Tell a socket to listen for incoming connections
    /*
        - The second parameter means how many pending connections you can have before the kernel starts rejecting new ones
    */
    if (listen(serverSocket, 5) < 0)
    {
        std::cout << "fail to listen for connection\n";
        exit(EXIT_FAILURE);
    }
    else
        std::cout << "successfully listen for connection\n";


    // accepting connection request
    /*
        - The accept() function shall extract the first connection on the queue of pending connections, 
            create a new socket with the same socket type protocol and address family as the specified socket, and allocate a new file descriptor for that socket.
    */
    int clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket < 0)
    {
        std::cout << "fail to accept connection\n";
        exit(EXIT_FAILURE);
    }
    else
        std::cout << "successfully connected\n";


    // recieving data
    const char* httpResponse = "HTTP/1.1 404 OK\r\nContent-Length: 13\r\n\r\nConnection OK!";
    send(clientSocket, httpResponse, strlen(httpResponse), 0);

    // Close the socket
    close(clientSocket);
    close(serverSocket);


    return 0;
}