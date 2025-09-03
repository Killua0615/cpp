/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:53 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/03 21:12:51 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Default constructor: required for "h = new Zombie[N];"
Zombie::Zombie() : _name("") {}
//creates a zombie already initialized with the given name
Zombie::Zombie(std::string name) : _name(name) {}
//called from delete[] h;
Zombie::~Zombie() {}


void Zombie::setName(const std::string &name) {
	_name = name;
}

void Zombie::announce(){
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
