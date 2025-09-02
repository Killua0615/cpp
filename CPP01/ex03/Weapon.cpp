/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:43:19 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:43:21 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type_(type)
{
}
const std::string &Weapon::getType() const
{
	return (type_);
}
void Weapon::setType(const std::string &t)
{
	type_ = t;
}
