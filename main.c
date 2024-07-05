#include "toolbox.h"


void vid_vsync() {
    while(REG_VCOUNT >= 160);   // wait till VDraw
    while(REG_VCOUNT < 160);    // wait till VBlank
}


INLINE Color change_color(Color color) {
    return (color << 1) ^ (color >> 1);
}


int main() {
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

    int size = 20;
    int starty = (SCREEN_HEIGHT - size) / 2;
    int startx = (SCREEN_WIDTH - size) / 2;
    
    int velx = 1;
    int vely = 1;

    Color color = CYAN;
    while (1) {
        int endy = size+starty; 
        int endx = size+startx;

        for (int y=starty; y<endy; y++) {
            for (int x=startx; x<endx; x++) {
                m3_plot(x, y, color);
            }
        }
        vid_vsync();
        for (int y=starty; y<endy; y++) {
            for (int x=startx; x<endx; x++) {
                m3_plot(x, y, BLACK);
            }
        }

        int newy = starty + vely;
        if (newy < 0 || newy + size >= SCREEN_HEIGHT) {
            color = change_color(color);
            vely = -vely;
        }
        int newx = startx + 1;
        if (newx < 0 || newx + size >= SCREEN_WIDTH) {
            color = change_color(color);
            velx = -velx;
        } 

        startx += velx;
        starty += vely;
    }
    
    return 0;
}
