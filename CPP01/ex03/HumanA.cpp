/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:42:32 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/04 03:09:32 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//initialize, conect with weapon, no copy,
HumanA::HumanA(const std::string &name, Weapon &weapon) : name_(name),
	weapon_(weapon) {}

void HumanA::attack() const {
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
