// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "半山寺");
        set("long", @LONG
黄山险峻，过去少有人烟，最早来此者多为出家苦修的僧人，所
以黄山之上寺庙甚多。半山寺因为出了一位擅长山水的大画家“雪庄
和尚”而名声居众寺之首。至今寺内尚有其真迹留传。由半山寺南行
下山便是醉石，继续攀爬可去天都峰。
LONG
        );
        set("exits", ([ 
  "westup"  : __DIR__"guanyin",
  "eastdown" : __DIR__"qingluan",
  "southdown" : __DIR__"zuishi",
]));
        set("outdoors", "huangshan");
	set("coor/x",-550);
	set("coor/y",-510);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
