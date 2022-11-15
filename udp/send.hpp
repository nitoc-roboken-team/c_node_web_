#ifndef UDP_SENDHPP
#define UDP_SENDHPP
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <iostream>




namespace c_node_web
{
class Transmit
{
private:
    int Srcsock;
    struct sockaddr_in SrcAddr;
    int DstAddrsock;
    struct sockaddr_in DstAddr;
    char m_red;
    char m_blue;
    char m_green;
    char m_yellow;
    char m_eraser;
    int m_digit;
    int m_integer;
    const void *i;
    // char cyan[7] = "cyan__";
    // char pink[7] = "pink__";
   
public:
    Transmit(void);
    // int position(const int n);
    // void send(char str1[],const int num1,char str2[],const int num2,char str3[],const int num3,char str4[],const int num4);
    void init(char ip[]);
    void send(int color_id,int position);
    void rpm(int power,int position);
    void pitch(float angle,int position);
    void yaw(float angle, int position);
    

};
}
#endif /*UDP_SENDHPP*/