// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ȥ��������ؼ�·��ѱ��ʻ���������ȴ�������ϵó��Ļ�
�䣬ֻ������Щ���ޱȵ����ޣ��ޱȵ����������������벻������Į֮
�У����������Ļ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"valley",
	]));
        set("objects", ([
                __DIR__"npc/qu" : 1,
		__DIR__"npc/ji" : 1,
       ]) );
        set("outdoors", "fengyun");
        set("coor/x",-1090);
	set("coor/y",70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}