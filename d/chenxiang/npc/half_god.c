inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
string sysmsg;
void create()
{
	set_name(HIY "�������" NOR, ({ "tianji", "Tian ji", "Tian" }) );

	set("gender", "����");
	set("age", 99);
	set("long",
		"�������������ף��׷�ͯ�ա��ڱ�������������һ��
�����Ϲ٣�С��֮�ϣ�����������а�����¶��ɰ�����������������ͽ�����ޣ�������\n");
	set("attitude", "peaceful");
        set("skill_public",1);
	set("str", 26000);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������������̳��˼��ڣ�������\n",
        }) );

	set("force", 40000);
	set("max_force", 80000);
	set("force_factor", 1000);

	set("combat_exp", 10000000);
	set("score", 200000);

	set_skill("unarmed", 120);
	set_skill("force", 100);
	set_skill("iron-cloth", 100);
	set_skill("yiqiforce", 30);
	set_skill("dagger",200);
	set_temp("apply/attack",300);
	set_temp("apply/damage",30000);
	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");

	create_family("��ң��", 1, "��ʦ");
	set("title", "����Ұ��");
	setup();

	carry_object(__DIR__"obj/jade-ring")->wear();
	carry_object(__DIR__"obj/jade-pin")->wear();
	carry_object(__DIR__"obj/jade-boots")->wear();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
}
int accept_fight(object me)
{
        command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
}
int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
	string test;
	mapping quest;
	val = ob->value();
	if (val && val >10000 && val < 20000)
	{
		       who->set("quest", 0 );
       	 	tell_object(who,"�������˵�����ðɣ������������˰ɣ���\n");
		who->delete_temp("quest_number");
		return 1;
	}
        if(!(quest =  who->query("quest")))
	{
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
	return 0;
	}
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"�������˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                        return 1;
        }
        else
        {
        tell_object(who,"�������˵������ϲ�㣡���������һ������\n");
	exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+1;
// put a cap
	if(exp > 150) exp = 150;
	exp = exp * (int) who->query_temp("quest_number");
	pot = exp / 5 + 1;
//	due to weekly quest, each quet worth 20
//	score = quest["score"]/2 + random(quest["score"]/2);
	score = -1;
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("score",score);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ��\n" NOR);
	who->set("quest", 0 );
                        return 1;
        }
                return 1;
}
void attempt_apprentice(object me)
{
	switch(random(4)) {
		case 0:
message_vision("$N��$nЦ�ʵ���ʲô���Ľ���\n", this_object(),me);
			break;
		case 1:
message_vision("$N��$nЦ�ʵ���ʲô�ǣ��в������Ҳ�������һ�������ȶ�����\n", this_object(),me);	
			break;
		case 2:
message_vision("$N��$nЦ�ʵ��������Σ����Σ���ʲô��\n", this_object(),me);		
			break;
		case 3:
message_vision("$N��$nЦ�ʵ�����ѧ����߾�����ʲô��\n", this_object(),me);
			break;
	}
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}

int give_quest(string arg)
{
	mapping quest ;
	object me;
	int j, combatexp, timep, lvl=0;
        mixed *local;
        int  t;
	string tag = "40000000";
 string *levels = ({
                        "0",
                        "4000",
                        "8000",
                        "16000",
                        "32000",
                        "64000",
                        "128000",
                        "256000",
                        "512000",
                        "1024000",
                        "1536000",
                        "2304000",
                        "3456000",
                        "5184000",
                        "7776000",
                        "11664000",
                        "17496000",
                        "26244000",
			"40000000"
        });
	if( ! arg || !sscanf(arg, "%d", lvl))
	lvl = 0;
	if(lvl<0) lvl=0;
	me = this_player();
// Let's see if this player is a ghost
	if((int)me->query("combat_exp") >= 100000)
	{
		write("��������Ѿ���������κ������ˣ�\n");
		return 1;
	}
	if((int) me->is_ghost())
	{
		write("���겻��Ҫ����\n");
		return 1;
	}

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
	{
	if( ((int) me->query("task_time")) >  time() )
		return 0;
	else
		me->set("kee", me->query("kee")/2+1);
		me->delete_temp("quest_number");
	}
	combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                                tag = levels[j];
				if(j < (sizeof(levels)- lvl)) tag = levels[j+lvl];
                                break;
                        }
        }
        if(!random(40) ) tag = "_new";
	if(!random(10) ) tag = "_common";
	quest = QUEST_D(tag)->query_quest();
//	to use less mem...
//	timep = quest["time"];	
	timep = 600;   // each quest give 10 mins.
// A factor here to make time random
	timep = random(timep/2)+timep/2;
	time_period(timep, me);
	if (quest["quest_type"] == "Ѱ")
	{
        tell_object(me,"�һء�"+quest["quest"]+"����������ˡ�\n" NOR);
	sysmsg +="�һء�"+quest["quest"]+"����";
	}
	        if (quest["quest_type"] == "ɱ")
        {
        tell_object(me,"���������ɱ�ˡ�"+quest["quest"]+"����\n" NOR);
	sysmsg +="ɱ�ˡ�"+quest["quest"]+"����";
        }
 	me->set("quest", quest);
	me->set("task_time", (int) time()+(int) timep);
	if((int)me->query_temp("quest_number") < 5)
	me->add_temp("quest_number",1);
	CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)��%s", 
	me->query("name"),me->query("id"),sysmsg));

return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"˵����\n����" + time + "��");
	sysmsg = "��" + time + "��";
        return 1;
}