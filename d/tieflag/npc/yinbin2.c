// yinbin.c
inherit NPC;
int go_shishi(object);
void create()
{
    set_name("阴宾",({"yin bin","yin","bin"}));
    set("long","她面上蒙着轻红罗纱，隐约间露出面容轮廓，当真美得惊人，宛如烟笼芍药，雾里看花\n");
    set("gender","女性");
    set("age",42);
    set("int",20);
    set("per",35);
    set("cps",20);
    set("gin",200);
    set("max_gin",200);
    set("eff_gin",200);
    set("max_kee",400);
    set("eff_kee",400);
    set("kee",400);  
    set("max_sen",500);
    set("sen",500);    
    set("eff_sen",500);
    set("combat_exp",50000);
    set("max_atman",300);
    set("atman",300);
    set_skill("force",100);
    set_skill("nine-moon-force",20);
    set_skill("unarmed",100);
    set_skill("nine-moon-claw",40);
    set_skill("nine-moon-steps",40);
    set_skill("parry",50);
    set_skill("dodge",50);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",10);
    map_skill("force","nine-moon-force");
    map_skill("unarmed","nine-moon-claw");
    map_skill("dodge","nine-moon-steps");
    set("attitude", "friendly");
    set("inquiry",([
    	"那人" : (: go_shishi :),
    	"man" : (: go_shishi :),
    ]) );
    set("chat_chance",5);     
    set("chat_msg",({
          "阴宾说道：“谢谢你又来看我。”\n",
          "阴宾笑道：“我在这里过得很好。”\n",
          "阴宾问道：“你可是想见见那人？”\n",
          }) );

    setup();
    carry_object(__DIR__"obj/redcloth")->wear();
    carry_object(__DIR__"obj/redjin")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    command("lovelook");
    return 1;
} 
go_shishi()
{
      object me,shishi;
      string myfile;
	me=this_player();
      if (!(shishi=find_object("/d/tieflag/shishi")))
      	shishi=load_object("/d/tieflag/shishi");
      command("say 也好，让你去见见他吧。");
      tell_object(me,"阴宾手一挥，你忽然觉得天旋地转起来。\n");
      me->move(shishi);
      return 1;
}

