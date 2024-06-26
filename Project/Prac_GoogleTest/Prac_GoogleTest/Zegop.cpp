class Zegop
{
public:
    Zegop(int num) :num{ num }
    {
    }
    int getZegop()
    {
        num *= num;
        return num;
    }
private:
    int num;
};