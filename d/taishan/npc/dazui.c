#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李大嘴", ({ "dazui" }) );
        set("gender", "男性");
        set("combat_exp", 500000);
        set("title", HIW "恶人" NOR);
        set("long",
		"恶人谷中的一员，好吃人肉，邪功盖世\n"
	);
        set_skill("move", 50);
        set_skill("dodge", 200);
	set_skill("unarmed",250);
	set("str",55);
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{
	object		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() && !random(5)) {
		add_action("do_accept", "accept");
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{
		message_vision(HIY "\n$N对$n说道：我可以将你师傅的内力全部
吸出来给你，怎么样？（accept yes/no）\n" NOR, this_object(), me);
	return 1;
}

int do_accept(string arg)
{
	if( arg != "yes" &&  arg != "no") 
                return notify_fail("你要接受什么？\n");
	if( arg == "yes") {
	message_vision( HIY "$N说道：好！今夜午时见！\n" NOR, this_object());
	this_player()->set("marks/不忠", 1);
	}
	else {
        message_vision( HIY "$N说道：真是不是抬举！拿命来！\n" NOR, this_object());
        this_player()->set("marks/忠", 1);
	kill_ob(this_player());
        }

	return 1;
}

