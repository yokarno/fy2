
#include <ansi.h>
inherit ROOM;

void create()
{
	object		item, con;

	set("short", "山崖边");
	set("long", @LONG
前面是一道深不见底的万丈深渊。下面白云缭绕，什么都看不见，
就连死人的幽灵都看不见。难道那幽灵山庄就在这万丈深渊之下？
LONG
	);
	set("exits", ([
                "west" : __DIR__"forest7",
                "south" : __DIR__"forest6",
	]));
	set("objects", ([
                __DIR__"obj/rock" : 1,
	]));
	set("outdoors", "ghost");
	set("coor/x",-1190);
	set("coor/y",-100);
	set("coor/z",-20);
	setup();
}

void init()
{
	if(this_object()->query("exits/east"))
		delete("exits/east");
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("rock", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/pipe");
                item->move(con);
	}
        if(query("exits/east"))
		delete("exits/east");
}

void pipe_notify()
{
        object ob;

        message("vision", HIY "\n白云之间忽然出现了一个人，什么人能凌空站在白云里？\n" NOR, this_object() );
        message("vision", HIY "你走到崖边才发现，白云里有条很粗的钢索，横贯了两旁的山崖。\n" NOR, this_object() );
        set("exits/east", __DIR__"bridge" );
}

