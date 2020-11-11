// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "石笋杠");
        set("long", @LONG
这里石柱林立，形同竹笋，千姿百态。每当黎明破晓，旭日东升，朝
霞遍染群峰，烟云迷漫深壑，这种神奇瑰丽的画面使得慕名而来的人心悦
诚服。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"sanhua",
]));
        set("objects", ([
        __DIR__"npc/yan" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-620);
	set("coor/y",-510);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
