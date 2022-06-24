#include <bits/stdc++.h>

using namespace std;

class Person{
    public:
        ~Person(){
            cout << "Person deconstructor " << endl;
        }
};

void usePerson()
{
    // 在堆中开辟空间
    Person *person1 = new Person();
    Person *person2 = new Person();
    shared_ptr<Person> sharedptr1(person1);
    shared_ptr<Person> sharedptr2(person2);

}

void lock(Mutex* pm);   // lock mutex pointed to by pm
void unlock(Mutex* pm); 