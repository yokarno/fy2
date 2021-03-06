// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "观音石");
        set("long", @LONG
由半山寺上来，过云门到天都峰下，看到一个亭亭玉立的石人，
活象一尊古装仕女，人称观音石。正面一块小石，恰如跪拜之童子，
这“小甚侏儒大娉婷”的两块巧石，正好构成“童子拜观音”。从
这里便开始了“盘空千万仞，险若上丹梯。迥入天都里，回看鸟道
低”的登顶过程。
LONG
        );
        set("exits", ([ 
  "eastdown"  : __DIR__"banshan",
  "westup" : __DIR__"yingke",
  "north" : __DIR__"jiyu",
]));
        set("objects", ([
        __DIR__"obj/guanyin" : 1,
	__DIR__"obj/xiaotong" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-560);
	set("coor/y",-510);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
