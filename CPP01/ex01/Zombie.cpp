/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:53 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:41:55 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
}
Zombie::Zombie(std::string name) : _name(name)
{
}
Zombie::~Zombie()
{
}
void Zombie::setName(const std::string &name)
{
	_name = name;
}
void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
