// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <stdlib.h>
#include "send.hpp"
#include <errno.h>

namespace c_node_web
{

Transmit::Transmit()
{
    m_red = 'r';
    m_blue = 'b';
    m_green = 'g';
    m_yellow = 'y';
    m_eraser = 'e';
    m_digit =0;
    m_integer=0;
}

void Transmit::send(int color_id,int position)
{

    
    // Send send;
    char id='0'+position;
        
        if(color_id==0)
        {
            char string[4];
            sprintf(string,"%c%c",id,m_eraser);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
        else if(color_id == 1)
        {
            char string[4];
            sprintf(string,"%c%c",id,m_red);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
        else if(color_id == 2)
        {
            char string[4];
            sprintf(string,"%c%c",id,m_blue);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
        else if(color_id == 3)
        {
            char string[4];
            sprintf(string,"%c%c",id,m_green);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
        else if(color_id ==4)
        {
            char string[4];
            sprintf(string,"%c%c",id,m_yellow);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
}

void Transmit::init(char ip[])
{
    // SrcAddr.sin_family = AF_INET;
    // SrcAddr.sin_port = htons(12346);
    // SrcAddr.sin_addr.s_addr = inet_addr(ip);

    // if((socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
    // {
    //     printf("map_viwerのsocket");
    //     exit(2);
    // }

    DstAddr.sin_family = AF_INET;
    DstAddr.sin_port = htons(12345);
    DstAddr.sin_addr.s_addr = inet_addr(ip);
   
    //送り元
    // Srcsock = socket(AF_INET, SOCK_DGRAM, 0);
    //送り先
    DstAddrsock = socket(AF_INET, SOCK_DGRAM, 0);
    if(DstAddrsock < 0) 
    {
        perror("socket");
        exit(2);
    }
    char str[8] = "_______";
        // CSType_delay_ms(10);
  
}

void Transmit::rpm(int i_power,int num)
{
    int digit=0;
    m_integer = i_power;
    while(m_integer != 0)
    {
        m_integer /= 10;
        digit++;
    }
    char c_power[digit];
    char str[digit+3];
    snprintf(c_power,10,"%d",i_power);
    sprintf(str,"P%d%d",num,i_power);
    sendto(DstAddrsock, str, sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
}

void Transmit::pitch(float i_angle,int num)
{
    m_integer = i_angle;
    while(m_integer != 0)
    {
        m_integer /= 10;
        m_digit++;
    }
    char c_angle[m_digit+3];
    char str[m_digit+6];
    snprintf(c_angle,10,"%2f",i_angle);
    sprintf(str,"A%d%2f",num,i_angle);
    sendto(DstAddrsock, str, sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    m_digit = 0;
}

void Transmit::yaw(float i_angle,int num)
{
    m_integer = i_angle;
    while(m_integer != 0)
    {
        m_integer /= 10;
        m_digit++;
    }
    char c_angle[m_digit+3];
    char str[m_digit+6];
    snprintf(c_angle,10,"%2f",i_angle);
    sprintf(str,"Y%d%2f",num,i_angle);
    sendto(DstAddrsock, str, sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    m_digit =0;
}
}
// int Send::position(const int n)
// {
//    for(int i=0;i<=9;i++)
//    {
//     if(i==n)
//     {
//         return i;
//     }
//    }
// }