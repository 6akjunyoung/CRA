#include <iostream>

using namespace std;

class Single
{
public:
    static Single& getInstance()
    {
        static Single instance;
        return instance;
    }

    void setValue(int n)
    {
        val = n;
    }

    void showValue()
    {
        cout << val << endl;
    }

private:
    int val = 0;

    Single() {}
    Single& operator=(const Single& other) = delete;
    Single(const Single& other) = delete;
};

#if 0
int main()
{
    Single& temp1 = Single::getInstance();
    Single& temp2 = Single::getInstance();

    temp1.setValue(1);
    temp2.showValue();

    // Single t2{ temp2 }; //<<<<< Singleton이지만 복사를 막도록 해야한다.
}
#endif