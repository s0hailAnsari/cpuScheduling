#include "firstComeFirstServe.h"
#include <iostream>
#include <queue>
#include <vector>
#include <firstComeFirstServe.h>
#define ARRAY_SIZE 5
using namespace std;

class cpuScheduler
{
private:
    //    vector <int> processTimeArray = {5, 2, 7, 3};
    vector<float> arrivalTimeArray = {0, 1, 2, 3, 4};
    vector<float> executionTimeArray = {2, 6, 4, 9, 12};
    vector<float> completionTimeArray = {0, 0, 0, 0, 0};
    vector<float> turnaroundTimeArray = {0, 0, 0, 0, 0};
    vector<float> waitingTimeArray = {0, 0, 0, 0, 0};

public:
    void FIFO();
    void showq(queue<float> gq);
    void swap(float *x1, float *y1, float *x2, float *y2);
    void selectionSort();
    void printArray();
    void calculateTurnaroundTime()
    {
        cout << "displaying array2: ";
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (i == 0)
            {
                completionTimeArray[0] = executionTimeArray[0];
                turnaroundTimeArray[0] = completionTimeArray[0] - arrivalTimeArray[0];
                //                waitingTimeArray[0] = turnaroundTimeArray[0] - arrivalTimeArray[0];
            }
            else
            {
                completionTimeArray[i] = completionTimeArray[i] + executionTimeArray[i];
                turnaroundTimeArray[i] = completionTimeArray[i] - arrivalTimeArray[i];
            }
        }

        for (int i = 0; i < ARRAY_SIZE; i++)
            waitingTimeArray[i] = turnaroundTimeArray[i] - arrivalTimeArray[i];
        cout << endl
             << "comp time";
        for (int i = 0; i < ARRAY_SIZE; i++)
            cout << completionTimeArray[i] << " ";
        cout << endl;
        cout << "turnaround: ";
        for (int i = 0; i < ARRAY_SIZE; i++)
            cout << turnaroundTimeArray[i] << " ";
        cout << endl;
        cout << "waiting";
        for (int i = 0; i < ARRAY_SIZE; i++)
            cout << waitingTimeArray[i] << " ";
        cout << endl;
    }
    void calculateWaitingTime();
};

void cpuScheduler::FIFO()
{
    cout << "displaying array: ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (i == 0)
            completionTimeArray[0] = arrivalTimeArray[0];
        else if (i == 1)
            completionTimeArray[1] = executionTimeArray[0];
        else
        {
            completionTimeArray[i] = completionTimeArray[i - 1] + executionTimeArray[i - 1];
        }
    }
    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << completionTimeArray[i] << " ";

    cout << endl;
}
void cpuScheduler::showq(queue<float> gq)
{
    queue<float> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
void cpuScheduler::swap(float *x1, float *y1, float *x2, float *y2)
{
    int temp1, temp2;
    temp1 = *x1;
    *x1 = *y1;
    *y1 = temp1;
    temp2 = *x2;
    *x2 = *y2;
    *y2 = temp2;
}
void cpuScheduler::selectionSort()
{
    int i, j, min_idx;
    for (i = 0; i < ARRAY_SIZE - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < ARRAY_SIZE; j++)
            if (arrivalTimeArray[j] < arrivalTimeArray[min_idx])
                min_idx = j;
        swap(&arrivalTimeArray[min_idx], &arrivalTimeArray[i], &executionTimeArray[min_idx], &executionTimeArray[i]);
    }
    printArray();
}

//void cpuScheduler::calculateTurnaroundTime(){
//
//}

void cpuScheduler::printArray()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << arrivalTimeArray[i] << " " << executionTimeArray[i] << " " << endl;
}


firstComeFirstServe::firstComeFirstServe()
{
    //cout<<"hey there";
    cpuScheduler object;
    cout << "Before" << endl;
    object.printArray();
    cout << "After" << endl;
    object.selectionSort();
    object.FIFO();
    object.calculateTurnaroundTime();
    queue<float> q;
    q.push(10);
    q.push(20);
    q.pop();
    q.push(30);
    object.showq(q);
    cout<<"\n";
}

firstComeFirstServe::~firstComeFirstServe()
{
    //dtor
}
