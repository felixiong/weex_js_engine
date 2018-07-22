//
// Created by Darin on 23/05/2018.
//

#ifndef WEEXV8_WEEXTASKQUEUE_H
#define WEEXV8_WEEXTASKQUEUE_H


#include <deque>
#include "WeexTask.h"

class WeexTaskQueue {

public:
    ~WeexTaskQueue();

    void run(WeexTask *task);

    int addTask(WeexTask *task);

    WeexTask *getTask();

    void removeTimer(int id);

    int addTimerTask(String id, JSC::JSValue function);

    void start();

    void init();

    bool isInitOk = false;

public:
    WeexRuntime *weexRuntime;


private:
    int _addTask(WeexTask *task, bool front);

    std::deque<WeexTask *> taskQueue_;
    ThreadLocker threadLocker;
};


#endif //WEEXV8_WEEXTASKQUEUE_H
