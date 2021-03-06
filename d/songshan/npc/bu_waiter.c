// TIE@FY3
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("沈壁君", ({ "shen bijun","shen" }) );
	set("gender", "女性" );
	set("age", 22);
	set("long",
		"无垢山庄的庄夫人，因静极思动，就跑到这里来做点小生意。\n");
	set("combat_exp", 900000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板娘");
	set("vendor_goods", ([
		__DIR__"obj/bu1" : 10,
		__DIR__"obj/bu2" : 30,
		__DIR__"obj/bu3" : 10,
		__DIR__"obj/bu4" : 5,
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "沈壁君道了个万福，笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，要买什么？\n");
			break;
		case 1:
			say( "沈壁君似乎自言自语道：这位" + RANK_D->query_respect(ob)
				+ "，最近有没有听到关于萧十一郎的消息？\n");
			break;
		case 2:
			say( "沈壁君向你问道：这位" + RANK_D->query_respect(ob)
				+ "，好久没有回无垢山庄了，有什么消息吗？\n");

			break;
	}
}
