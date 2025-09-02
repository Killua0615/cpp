/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:42:32 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:42:43 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : name_(name),
	weapon_(weapon)
{
}
void HumanA::attack() const
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
