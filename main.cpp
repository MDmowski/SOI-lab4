#include "consumer.cpp"
#include "oProd.cpp"
#include "producer.cpp"
#include "specialProducer.cpp"
#include <thread>
#include <unistd.h>

int main()
{
    buffer A(20, 'A');
    buffer B(20, 'B');
    buffer C(20, 'C');
    std::thread prodA(producer, std::ref(A));
    usleep(500);
    std::thread prodB(producer, std::ref(B));
    usleep(500);
    std::thread prodC(producer, std::ref(C));
    usleep(500);
    std::thread sProd(specialProducer, std::ref(A), std::ref(B), std::ref(C));
    usleep(500);
    std::thread consA(Aconsumer, std::ref(A), std::ref(B), std::ref(C), 70);
    usleep(500);
    std::thread consB(Bconsumer, std::ref(A), std::ref(B), std::ref(C), 70);
    usleep(500);
    std::thread consC(Cconsumer, std::ref(A), std::ref(B), std::ref(C), 70);
    usleep(500);
    std::thread oProd(oProducer, std::ref(A), std::ref(B), std::ref(C), 500);

    prodA.join();
    prodB.join();
    prodC.join();
    sProd.join();
    consA.join();
    consB.join();
    consC.join();
    oProd.join();
}