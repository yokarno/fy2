// chillgaze.c

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage;
	string msg;
	if( !me->is_fighting() )
		return notify_fail("［扭转乾坤］只能在战斗中使用。\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("你的内力不够。\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("你要对谁施展［扭转乾坤］？\n");
	}

	skill = me->query_skill("force");
	msg = HIR +me->name()+"双手转动，施展出［扭转乾坤］，企图用强烈的内力将$N的功势引向$n" NOR;
	me->add("force", -50);
	me->receive_damage("sen", 20);
	if(random((int)me->query("combat_exp") * skill/100) > random((int)target->query("combat_exp")))
        COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
	else
	{
	message_vision(msg+"！\n",target,target);
	message_vision("但是并没有成功！\n",me);
	}
	me->start_busy(1);
	return 1;
}

