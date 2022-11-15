#include "udp/send.cpp"

int main()
{
    c_node_web::Transmit trans;
    trans.init("127.0.0.1");
    int num =1000;
    int posision[4]={1,2,3,4};
    while(1)
    {
        
        trans.rpm(num,1);
        trans.rpm(num,2);
        trans.rpm(num,3);
        trans.rpm(num,4);
        trans.pitch(num,1);
        trans.pitch(num,2);
        trans.pitch(num,3);
        trans.pitch(num,4);
        trans.yaw(num,1);
        trans.yaw(num,2);
        trans.yaw(num,3);
        trans.yaw(num,4);
        trans.send(4,posision[0]);
        trans.send(3,posision[1]);
        trans.send(2,posision[2]);
        trans.send(1,posision[3]);
      
        usleep(20000);
    }
    return 0;
}