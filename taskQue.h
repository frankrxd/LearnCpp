#include <queue>
#include <functional>
using std::queue;
using std::function;

using TaskCallback = std::function<void>;

class TaskQue {
public:
    TaskQue(size_t size)
    :_size(size)
    ,_mutex()
    ,_notFull(&_mutex)
    ,_notEmpty(&_mutex)
    { }

    bool full() const{
        return _taskQue.size()==_size;
    }
    bool empty() const{
        return _taskQue.empty();
    }
    void push(TaskCallback& cb) {
        _mutex.lock();

        _notFull.wait();//满的时候阻塞

        _taskQue.push(cb);

        _notEmpty.notyfy();
        _mutex.unlock();
    }
    TaskCallback pop() {
        _mutex.lock();
        _notEmpty.wait();
        TaskCallback cb =  _taskQue.front();
        _taskQue.pop();
        _notFull.notify();
        _mutex.unlock();
        return cb;
    }
    void wakeup(){
        if(!_isExit) {
            _isExit = true;
        }
        _notEmpty.notifyall();
    }

// Condition : wait   
// signal(通知一个)  notify
// broadcast(通知所有阻塞的队列) 
private:
    size_t _size;
    queue<TaskCallback> _taskQue;
    Mutex _mutex;
    Condition _notFull;
    Condition _notEmpty;
    bool _isExit;
    //线程间通信；
};