
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("厉青锋", ({ "li qingfeng","li" }) );
        set("gender", "男性" );
        set("age", 65);
	set("title", HIG "金弓银丸斩虎刀，追云捉月水上飘" NOR);
        set("per", 27);
        set("attitude", "peaceful");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("long",     "近三十年来天下武林中手脚最干净，名声最响亮的独行大盗。\n");
        set("combat_exp", 999999);
	set("pursuer",1);
        set_skill("unarmed", 120);
        set_skill("throwing", 100);
	set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);
        set_skill("demon-force", 100);
        set_skill("demon-strike", 80);
        set_skill("demon-steps", 10);
        setup();
        carry_object(__DIR__"obj/yinwan")->wield();
        carry_object("/obj/cloth")->wear();
}
void init()
{
	object me;
	add_action("do_answer","answer");
	me = this_player();
	if(interactive(me) 
	&& !me->query_temp("friend_to_xiao")) call_out("ask_him", 1,me );


} 
int ask_him(object me)
{
	if(environment(me) == environment())
	{
	tell_object(me,name()+"喝道：你是不是萧十一郎的朋友？（answer yes/no）\n");
	me->set_temp("asked_yes_no",1);
	};
	return 1;
}
int do_answer(string arg)
{
object me;
me =this_player();
if(!me->query_temp("asked_yes_no")) return 0;
me->delete_temp("asked_yes_no");
me->set_temp("friend_to_xiao","no");
if(!arg || arg != "yes")
return notify_fail(name()+"道：萧十一郎自以为武功天下第一，专横跋扈，为一女人乱杀无辜！
凡是他的朋友我都要杀！\n");
command("say 好！既然你是他的朋友，我就不妨多杀一个！\n");
kill_ob(me);
me->kill_ob(this_object());
me->set_temp("friend_to_xiao","yes");
return 1;
}
