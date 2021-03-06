// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N手中$w抡开，挟着呼呼风声，一招「树喧每每」，直取$n的各处要害！",
                "damage":               200,
                "dodge":                -540,
                "parry":                -500,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w斧风呼啸，一招「月现长空」，横空向$n$l劈去！",
                "damage":               150,
                "dodge":                -600,
                "parry":                -600,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w接连劈出，，一招「渊源不尽」，旋风般砍向$n$l！",
                "damage":               250,
                "dodge":                -510,
                "parry":                -540,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出一招「万派朝宗」，手中$w舞动，身随斧势，化作一溜烟尘，滚滚奔向$n的$l！",
                "damage":               210,
                "dodge":                -410,
                "parry":                -440,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "割伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="axe") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "axe" )
                return 
	notify_fail("你必须先找一把斧头或者是类似的武器，才能练斧法。\n");
        if( (int)me->query("kee") < 60 )
        return 
	notify_fail("你的体力不够练这门斧法，还是先休息休息吧。\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 25;}
 
string *parry_msg = ({
        "结果$n一招「禅心落寞」，挥动手中$v格开了$N的$w。\n",
        "结果$n手中$v一分，一招「入魔入佛」，斜劈$N的$w。\n",
        "结果$n手中$v抡动如飞，一招「洪波万里」，荡开$N的$w。\n",
        "结果$n手中$v飞速旋转，一招「不解成舟」，反扫$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n手中的$v舞动如飞，一招「不动不摇」，封住了$N的攻势。\n",
        "$n身影晃动，一招「千潭月朗」，反砍$N的下盘。\n",
        "$n身形一矮，一招「满地蒿蓬」，躲过$N的攻势。\n",
        "$n手中的$v自上而下，一招「始堪耕地」，反劈$N的要害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/wuche-axe/" + action;
}

