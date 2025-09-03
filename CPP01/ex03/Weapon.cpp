/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:43:19 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/04 02:48:25 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//Construct a Weapon and initialize its internal type(&type)
Weapon::Weapon(const std::string &type) : type_(type) {}

//`type_` is private; use getter(getType()) to access it
const std::string &Weapon::getType() const {
	return (type_);
}

//Update the weapon's type string
void Weapon::setType(const std::string &t) {
	type_ = t;
}
