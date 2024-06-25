#if 0
class DrawCircle {
public:
    void drawCircle(bool isDraw, bool isOutline, int x, int y, double radius) {
        if (x == 0 && y == 0) {
            _CheckInvalidZeroPoint(radius);
        }
        else {
            if (isDraw) {
                if (isOutline) {
                    circle_draw2(x, y, radius);
                }
                else {
                    circle_draw(x, y, radius);
                }
            }
            else {
                circleDelete(x, y, radius);
            }
        }
    }

private:
    void circle_draw(int x, int y, double radius) {
        //���� ȭ�鿡 �׸���.
    }

    void circleDelete(int x, int y, double radius) {
        //���� ȭ�鿡 �����.
    }

    void circle_draw2(int x, int y, double radius) {
        //�׵θ��� �ִ� ���� ȭ�鿡 �׸���.
    }

    void firstDraw(double radius) {
        //0, 0 �� �׸��� �׸��� ���ϵ��� ����ó��
        //���� ��� ���� �ʰ�, �ƹ��͵� ���� �ʴ´�.
    }
};
#else
struct Axis
{
    int x;
    int y;
    double radius;
};

class DrawCircle {
public:
    void drawCircle(Axis circle, bool isOutline) {
        _CheckInvalidZeroPoint(circle);

        if (isOutline) {
            _DrawCircleWithOutline(circle);
        }
        else {
            _DrawCircleWithoutOutline(circle);
        }
    }

    void drawCircleWithOutline(Axis circle)
    {

    }

    void deleteCircle(Axis circle) {
        //���� ȭ�鿡 �����.
    }

private:
    void _DrawCircleWithoutOutline(Axis circle) {
        //���� ȭ�鿡 �׸���.
    }

    void _DrawCircleWithOutline(Axis circle) {
        //�׵θ��� �ִ� ���� ȭ�鿡 �׸���.
    }

    void _CheckInvalidZeroPoint(Axis circle) {
        //0, 0 �� �׸��� �׸��� ���ϵ��� ����ó��
        //���� ��� ���� �ʰ�, �ƹ��͵� ���� �ʴ´�.
        if (circle.x == 0 && circle.y == 0) {

        }
    }
};
#endif