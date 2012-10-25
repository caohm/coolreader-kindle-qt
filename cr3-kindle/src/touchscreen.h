#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

#include "device.h"

#define MIN_SWIPE_PIXELS 200

class TouchScreen
{
public:
    TouchScreen();

    typedef enum TOUCH_TYPE {
        TAP_SINGLE = 0,
        TAP_TWO,
        TAP_TWO_READER,
        TAP_LONG,
        TAP_LONG_READER
    } TouchType;

    typedef enum SWIPE_TYPE {
        SWIPE_ONE = 0,
        SWIPE_ONE_READER
    } SwipeType;

    typedef enum SWIPE_GESTURE {
        SWIPE_UP = 0,
        SWIPE_RIGHT,
        SWIPE_DOWN,
        SWIPE_LEFT
    } SwipeGesture;

    typedef enum AREA { // left to right, top to bootom
        TOP_LEFT = 0,
        TOP_MIDDLE,
        TOP_RIGHT,
        LEFT,
        CENTER,
        RIGHT,
        BOTTOM_MIDDLE
    } Area;

    Area getPointArea(int x, int y);
    Qt::Key getAreaAction(int x, int y, TouchType t);
    Qt::Key getSwipeAction(int x, int y, int oldX, int oldY, SwipeType t);
private:
    int rightMargin, rpx;
    int leftMargin, lpx;
    int topMargin, tpx;
    int bottomMargin, bpx;

    int w;
    int h;

    static const Qt::Key TAP_ACTIONS[][7];
    static const Qt::Key SWIPE_ACTIONS[][4];
};

#endif // TOUCHSCREEN_H