#include <iostream>
#include <string>
using namespace std;

//메서드 체이님
class Cut
{
public:
    class Builder
    {
    public:
        Builder& setStyle(string style)
        {
            this->style = style;
            return *this;
        }
        Builder& setFront(int front)
        {
            this->front = front;
            return *this;
        }
        Builder& setBack(int back)
        {
            this->back = back;
            return *this;
        }
        Builder& setSide(int side)
        {
            this->side = side;
            return *this;
        }

        Cut build()
        {
            // error handling
            return Cut(style, front, back, side);
        }
    private:
        string style;
        int front;
        int back;
        int side;
    };

    void show()
    {
        cout << style << endl
             << front << endl
             << back << endl
             << side << endl;
    }

private:
    string style;
    int front;
    int back;
    int side;

    Cut(string style, int front, int back, int side)
        : style{ style }, front{ front }, back{ back }, side{ side } {}
};
#if 0
int main()
{
    /*
    Cut a{ "abc", 10, 20, 5 };

    Cut b;

    b.setStyle("abc");
    b.setFront(10);
    b.setBack(20);
    b.setSide(5);
    */

    Cut c = Cut::Builder().setStyle("abc").setFront(10).setBack(20).setSide(5).build();
    c.show();
}
#endif