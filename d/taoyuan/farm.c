inherit ROOM;
void create()
{
        set("short", "��ȳ�");
        set("long", @LONG
�����Ĵ�ȳ��Ͼ��ȵ�����һ��Ƴγεĵ���������һ�����Ƶ���Ȼ����ڿ�
�ǿ��ǵ�ת�ţ�����ũ�˶�����������һ�߳Է�������ʱ��ע���ŷ�ֹ��ȸ��͵�Թ�
��������ȳ����Ϸ��ż����Ѿ������˵���Ϳ��ӡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"nongjia",
	]) );

   set("objects", ([
      __DIR__"obj/bowl": 1,
      __DIR__"npc/farmer":3,
   ]) );

   set("outdoors","taoyuan");
   set("coor/x",190);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}


void reset()
{
        object *inv;
        object item1, bowl;
        ::reset();
        bowl = present("bowl", this_object());
        inv = all_inventory(bowl);
        if( !sizeof(inv)) {
        item1 = new(__DIR__"obj/fishbone");
        item1->move(bowl);
        }
}
