/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:17 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/03 10:21:28 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Heap-allocate a Zombie so the caller controls its lifetime, and returned pointer when done
Zombie* newZombie(std::string name) {
  return new Zombie(name);
}
