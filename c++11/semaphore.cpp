#include <mutex>
#include <condition_variable>

class semaphore
{
public:
    semaphore(int value = 1) : count_(value), wakeup_(0)
    {

    }

    ~semaphore()
    {
        count_ = 1;
        wakeup_ = 0;
    }

    void wait()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        --count_;
        while (count_ < 0)
            cnd_.wait(lock);
    }

    void signal()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        ++count_;
        if (count_ <= 0)
            cnd_.notify_one();
    }

    //more fast.
    void waitP()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if (--count_ < 0)
        {
            cnd_.wait(lock, [&]()->bool { return wakeup_ > 0; });
            --wakeup_;   //me wakeup
        }
    }

    void signalV()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if (++count_ <= 0)
        {
            ++wakeup_;
            cnd_.notify_one();  //have some thread suspend
        }
    }

private:
    int count_;
    int wakeup_;
    std::mutex mutex_;
    std::condition_variable cnd_;
};
