//XX
inherit NPC;
void create()
{
	set_name("琴儿" , ({ "qiner", "qin er", "girl" }) );
	set("long", "一位十一二岁的小丫头，明亮的大眼睛十分灵活并且惹人喜爱。\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 12);
        set("gender", "女性" );
        set("chat_chance", 20);
        set("chat_msg", ({
            (: random_move :)
        }) );
	set("str", 35);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/cloth")->wear();
        carry_object("/u/chuenyu/obj/yellow_flower")->wear();
}
