#include "Test.h"

SyncQueue<Base> mq;

void producer()
{
    random_device rd;
    default_random_engine gen = std::default_random_engine(rd());
    uniform_int_distribution<int> dis(1, 100);
    while (true) {
        Base b = {dis(gen)};
        cout << "producer: " << b.value() << endl;
        mq.put(b);
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void consumer()
{
    while (true) {
        Base b;
        mq.get(b);
        cout << "consumer: " << b.value() << endl;
    }
}

int main(int argc, char *argv[])
{
    printf("---------------------------------\n");
    Base a;
    a.print();
    printf("---------------------------------\n");
    // direct initialization
    Base b {11};
    b.print();
    printf("---------------------------------\n");
    // copy initialization
    Base c = 12;
    c.print();
    printf("---------------------------------\n");
    Base d = {13};
    d.print();
    printf("---------------------------------\n");
    Base e = Base {14};
    e.print();
    printf("---------------------------------\n");
    Base f = b;
    f.print();
    printf("---------------------------------\n");
    Base g = {c};
    g.print();
    printf("---------------------------------\n");
    Base h = Base {d};
    h.print();
    printf("---------------------------------\n");
    g = b;
    g.print();
    printf("---------------------------------\n");
    g = {c};
    g.print();
    printf("---------------------------------\n");
    g = Base {c};
    g.print();
    printf("---------------------------------\n");


    thread t1 {producer};
    t1.detach();
    thread t2 {consumer};
    t2.detach();
    this_thread::sleep_for(chrono::seconds(10));
    return 0;
}

