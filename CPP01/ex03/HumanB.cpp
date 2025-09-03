/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:42:58 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/04 03:18:00 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

//initialize, sets weapon_ to 0 (null), (C++98 uses 0; in modern C++ you’d use nullptr)
HumanB::HumanB(const std::string &name) : name_(name), weapon_(0) {}
void HumanB::setWeapon(Weapon &weapon){
  //Stores the address, can change equip and switching to another weapon later.
	weapon_ = &weapon;                    
}
void HumanB::attack() const{
	if (!weapon_) //if == 0 return;
		return ;
	std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}
