// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "排云亭");
        set("long", @LONG
观西海云的最佳处。黄山云海历来五分，东西南北海加天海，
其中西海云多为层状，好似排涛叠浪，排云亭是为观云而建，也因
云而名，在这里可以尽览黄山四奇之云海的妙处。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"shizi",
  "north" : __DIR__"sanhua",
  "east" : __DIR__"feilai",
]));
        set("outdoors", "huangshan");
	set("coor/x",-610);
	set("coor/y",-530);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
