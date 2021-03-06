#include "game/MeleeBattle.h"
#include "game/ICharacter.h"

#include "utils/log/loguru.hpp"

void MeleeBattle::BeginFight()
{
	int damageAttacker, damageDefender;

	// KE: Simple battle loop until winner is determine
	while (m_HeroAttacker.GetHealth() > 0
		&& m_HeroDefender.GetHealth() > 0)
	{
		if (m_HeroAttacker.GetHealth() > 0)
		{
			damageAttacker = m_HeroAttacker.DealDamage();
			m_HeroDefender.GetDamaged(damageAttacker);
		}
		if (m_HeroDefender.GetHealth() > 0)
		{
			damageDefender = m_HeroDefender.DealDamage();
			m_HeroAttacker.GetDamaged(damageDefender);
		}
	}
}

void MeleeBattle::LogResults() const
{
	if(m_HeroAttacker.GetHealth() > 0)
	{
		LOG_F(INFO, "Attacker Won");
	}
	else
	{
		LOG_F(INFO, "Attacker Lost");
	}

	if(m_HeroDefender.GetHealth() > 0)
	{
		LOG_F(INFO, "Defender Won");
	}
	else
	{
		LOG_F(INFO, "Defender Lost");
	}
}
