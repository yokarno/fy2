//mac's changlang.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
��ľ�������ѱ���ͺ��������ķ������ȼ������о�������˫
�ﳯĵ����ͼ���ľ����Ͻ�������������˻��ɴ�����������
һ����С�
LONG
  );
  set("exits",([
         "west" :__DIR__"qianyuan.c",
         "south":__DIR__"fudong.c",
               ]));
        set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
  set("coor/x",60);
	set("coor/y",2030);
	set("coor/z",30);
	setup();
  replace_program(ROOM);
}