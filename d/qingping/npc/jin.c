// XXDER@FY3
inherit NPC;
void create()
{
	set_name("金不畏" , ({ "buwei", "jin buwei", "jin" }) );
	set("long", "此人身高八尺，背阔三停，是条不折不扣的莽汉。\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 30);
        set("gender", "男性" );
	set("str", 35);
	set("cor", 30);
	set("cps", 25);
        create_family("清平山庄", 1, "弟子");
	set("combat_exp", 700000);
	set_skill("dodge", 50+random(50));
        set_skill("unarmed", 80);
        set_skill("sword", 65);
        set_skill("qingpingsword", 60);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 54);
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
