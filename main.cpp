#include <iostream>
#include <cmath>
#include <thread>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <semaphore.h>

#include "Move.hpp"
#include "global.hpp"

sem_t sem1,sem2,sem3,sem4;
//#include <eigen3/Eigen/Core>
//#include <eigen3/Eigen/Dense>
//#include <pthread.h>

using namespace std;
time_t end_time; 

// 线程的运行函数
void MapBegin()
{
    //int x=1;
    //while (time(NULL) < end_time)
    
        system("clear");
        sem_wait(&sem1);
        for(i=0;i<20;i++)
        {
            for(j=0;j<20;j++)
            {
                
                if(i==0||i==19||j==0||j==19)
                {
                    Array[i][j]=1;
                }
            }
        } 
        sem_post(&sem2);
        //sleep(1);
     
}
void Print1()
{
    sem_wait(&sem2);
    for(i=0;i<20;i=i+4)
        {
            for(j=0;j<20;j++)
            {
                if(j<18)
                Array[i][j]=1;
            }

        }
    sem_post(&sem3);

}
void Print2()
{
    sem_wait(&sem3);
    for(i=2;i<20;i=i+4)
        {
            for(j=0;j<20;j++)
            {
                if(j>1)
                Array[i][j]=1;
            }
        }
    sem_post(&sem4);

}
void PrintMap()
{
    //while (time(NULL) < end_time)
    
        sem_wait(&sem4);
        for(i=0;i<20;i++)
        {
            for(j=0;j<20;j++)
            {
                if(Array[i][j]==1)
                {
                    cout<< "■" << " ";
                }
                else if(Array[i][j]==0)
                {
                    cout<< " " << " ";
                }
                else if(Array[i][j]==2)
                    cout<<"◯"<<" "; 
            }
            cout<<endl;
        }
        sem_post(&sem1);
        //sleep(1);
    
}

 
int main()
{
    /*int n;
    cout << "Input ArrayS:";
    cin >> n ;*/
    
    //end_time = time(NULL)+9;
    sem_init(&sem1,0,1);
    sem_init(&sem2,0,0);
    sem_init(&sem3,0,0);
    sem_init(&sem4,0,0);

    Array[1][1]=2;
    while (1)
    {     
        thread t1(MapBegin);
        thread t2(Print1);
        thread t3(Print2);
        thread t4(PrintMap);
        move();

        t1.join();
        t2.join(); 
        t3.join();
        t4.join();  
    }
    
    return 0;
    
}
