#include "struct.h"

void rotateElems(Rect* rect, int length) {

    const char temp = rect[0].color;
    for (int i = 0; i < length - 1; i++) {

        /*const char temp = rect[i + 1].color;*/
        rect[i].color = rect[i +1].color;
    }
    rect[length-1].color = temp;
}
