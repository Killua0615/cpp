/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:31 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/03 03:45:07 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie() {
  std::cout << _name << " destroyed" << std::endl;
}
void Zombie::announce(void) {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
