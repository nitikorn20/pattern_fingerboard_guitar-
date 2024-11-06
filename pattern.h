#ifndef PATTERN_H
#define PATTERN_H

// กำหนดโครงสร้างสี RGB
typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Color;

static const Color COLOR_RED = {255, 0, 0};       // สีแดง
static const Color COLOR_GREEN = {0, 255, 0};     // สีเขียว
static const Color COLOR_BLUE = {0, 0, 255};      // สีน้ำเงิน
static const Color COLOR_YELLOW = {255, 255, 0};  // สีเหลือง
static const Color COLOR_PURPLE = {128, 0, 128};  // สีม่วง
static const Color COLOR_WHITE = {255, 255, 255}; // สีขาว
// เพิ่มสีใหม่ที่จำแหน่งนี้

typedef struct
{
    int led_positions[154]; // ตำแหน่งของ LED ที่จะติด (สูงสุด 154 ตำแหน่งต่อ segment)
    int led_count;          // จำนวน LED ใน segment นี้
    Color led_color;        // สีของ segment ในรูปแบบ RGB
} Segment;

// กำหนด pattern สำหรับคอร์ด
typedef struct
{
    const char *chord_name; // ชื่อคอร์ด
    int segment_count;      // จำนวน segment ที่มีในคอร์ดนี้
    Segment segments[5];    // ข้อมูล segment (สูงสุด 5 segment ต่อคอร์ด)
} ChordPattern;

// ตัวอย่างการกำหนดคอร์ด C โดยใช้ตัวแปรสีที่ลูกค้าสามารถแก้ไขได้
static const ChordPattern pattern_example = {
    .segment_count = 2, // จำนวน segment
    .segments = {
        {.led_positions = {00, 01, 242}, .led_count = 3, .led_color = COLOR_RED}, // Segment 0 ใช้สีแดง
        {.led_positions = {51, 61}, .led_count = 2, .led_color = COLOR_GREEN}     // Segment 1 ใช้สีเขียว
    }};

#endif // PATTERN_H
