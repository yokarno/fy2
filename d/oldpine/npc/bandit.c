// bandit.c

inherit NPC;

void create()
{
        set_name("土匪", ({ "bandit" }) );
        set("gender", "男性");
        set("age", 33);
        set("long",
                "这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 600);
        set("score", 60);
        set("attitude", "aggressive");
        set_skill("sword", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        setup();
        carry_object(__DIR__"obj/short_sword")->wield();
        add_money("silver", 3);
}
