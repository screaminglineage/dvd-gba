#ifndef TOOLBOX_H
#define TOOLBOX_H

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

typedef u16 Color;

#define INLINE static inline

#define MEM_IO      0x04000000
#define MEM_VRAM    0x06000000

#define REG_VCOUNT *(volatile u16*)0x04000006

// Display Control Register
#define REG_DISPCNT     *((volatile u32*)(MEM_IO+0x0000))
#define DCNT_MODE0      0x0000
#define DCNT_MODE1      0x0001
#define DCNT_MODE2      0x0002
#define DCNT_MODE3      0x0003
#define DCNT_MODE4      0x0004
#define DCNT_MODE5      0x0005
// layers
#define DCNT_BG0        0x0100
#define DCNT_BG1        0x0200
#define DCNT_BG2        0x0400
#define DCNT_BG3        0x0800
#define DCNT_OBJ        0x1000


#define SCREEN_WIDTH   240
#define SCREEN_HEIGHT  160

#define vid_mem     ((u16*)MEM_VRAM)

INLINE void m3_plot(int x, int y, Color clr) {
    vid_mem[y*SCREEN_WIDTH + x] = clr;
}

#define BLACK   0x0000
#define RED     0x001F
#define LIME    0x03E0
#define YELLOW  0x03FF
#define BLUE    0x7C00
#define MAGENTA 0x7C1F
#define CYAN    0x7FE0
#define WHITE   0x7FFF

INLINE Color to_rgb15(u32 r, u32 g, u32 b) {
    return (b << 10) | (g << 5) | r;
}


#endif // TOOLBOX_H
