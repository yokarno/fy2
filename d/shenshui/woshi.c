// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "裨女卧室");
        set("long", @LONG
这是宫中裨女的卧室，轻罗帐，绿牙床，屋中陈设不多，但全部恰到好
处，正中的桌上一个青瓷官窑花瓶中错落有致的插着几束刚刚采来得野花，
为屋子凭添了一丝春意。
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"gong",
  "east" : __DIR__"woshi2",
]));
	set("coor/x",210);
	set("coor/y",12350);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
