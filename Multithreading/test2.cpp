#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include "socketcan.h"

using namespace std;

#define NUM_THREADS 5

// Struct with data for vcan
struct can_data
{
    const int can_id{123};
    const int can_length{8};
    // Can value
    int can_value[8] = {0};
};

void *sendSocet(void *threadarg)
{
    // create socketcan object from the socketcan class
    scpp::SocketCan sockat_can;

    // Check if status is ok, exit and write errr if not
    if (sockat_can.open("vcan0") != scpp::STATUS_OK)
    {
        cout << "Cannot open vcan0." << endl;
        cout << "Check whether the vcan0 interface is up!" << endl;
        exit(-1);
    }

    struct can_data *input_data;
    input_data = (struct can_data *)threadarg;
    // create canframe object from the socketcan class
    scpp::CanFrame cf_to_write;

    // set the can ID
    cf_to_write.id = input_data->can_id;
    // set the lengt in bytes for the can
    cf_to_write.len = input_data->can_length;

    for (int i = 0; i < input_data->can_length; ++i)
        cf_to_write.data[i] = input_data->can_value[i];

    auto write_sc_status = sockat_can.write(cf_to_write);
    if (write_sc_status != scpp::STATUS_OK)
        cout << "something went wrong on socket write, error code :"
             << int32_t(write_sc_status) << endl;
    else
        cout << "Message was written to the socket " << endl;

    pthread_exit(NULL);
}

int main()
{
    scpp::SocketCan sockat_can;
    // Create array of type pthread_t and size: NUM_THREADS
    pthread_t threads[NUM_THREADS];
    // Create a struct with data for vcan message
    struct can_data cd[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        cout << "main() : creating thread, " << i << endl;

        // Set the random can values
        for (int j = 0; j < cd[i].can_length; ++j)
        {
            // cout << "first for!!";
            cd[i].can_value[j] = rand() % 256;
        }

        // pthread_create(pos1, pos2, pos3, pos4)
        // pos1 =  thread[i] =>
        // An opaque, unique identifier for the new thread returned by the subroutine.
        // pos2 = NULL =>
        // An opaque attribute object that may be used to set thread attributes.
        // You can specify a thread attributes object, or NULL for the default values.
        // pos3 = PrintHello =>
        // The C++ routine/function that the thread will execute once it is created.
        // pos4 = (void *)i =>
        // A single argument that may be passed to start_routine. It must be passed by reference
        // s a pointer cast of type void. NULL may be used if no argument is to be passed.

        rc = pthread_create(&threads[i], NULL, sendSocet, (void *)&cd[i]);
        //  rc = pthread_create(&threads[i], NULL, sendSocet, (void *)i);

        // Error if no pthread created
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}