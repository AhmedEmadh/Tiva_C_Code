#define  data_port 'a'
#define ctrl_port  'b' 
#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define FirstRow          0x80
#define SecondRow         0xC0
#define RS 0x20 
#define RW 0x40
#define EN 0x80
void LCD_VSEND_COMMEND(char commend);
void lcd_move_cursorOff(char row,char colum);//used in position 
void lcd_clear_screen(void);//clear screen
void LCD_VSEND_String(char *data) ;//send string
void LCD_VSEND_Char(char Char);//send char
void LCD_VSEND_COMMEND(char commend);
void lcd_init(void);

