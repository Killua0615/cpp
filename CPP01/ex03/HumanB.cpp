/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:42:58 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:43:00 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name_(name), weapon_(0)
{
}
void HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}
void HumanB::attack() const
{
	if (!weapon_)
		return ;
	std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}
