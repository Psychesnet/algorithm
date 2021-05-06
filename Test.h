#ifndef TEST_H
#define TEST_H
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <random>
#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

class Base
{
    protected:
        int bbb {};
    public:
        Base(const int b=0) {
            cout << "default constructor" << endl;
            bbb=b;
        }
        virtual ~Base() {};
        virtual void print() const {
            cout << "bbb is " << bbb << endl;
        }
        int value() const {
            return bbb;
        }

        // copy constructor
        Base(const Base &b) {
            cout << "copy constructor" << endl;
            bbb = b.value();
        }
        // copy assignment
        Base &operator=(const Base &b) {
            cout << "copy assignment" << endl;
            bbb = b.value();
            return *this;
        }
};

template<typename T>
class SyncQueue {
    public:
            void put(const T& v) {
                lock_guard<mutex> lck(mtx);
                q.push_back(v);
                cond.notify_one();
            }
            void put(T&& v) {
                lock_guard<mutex> lck(mtx);
                q.push_back(v);
                cond.notify_one();
            }
            void get(T& v) {
                unique_lock<mutex> lck(mtx);
                cond.wait(lck, [this] {return !q.empty();});
                v = q.front();
                q.pop_front();
            }
    private:
            mutex mtx;
            condition_variable cond;
            list<T> q;
};


#endif /* TEST_H */
