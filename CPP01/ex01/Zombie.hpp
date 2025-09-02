/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:58 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:42:00 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	std::string _name;

  public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName(const std::string &name);
	void announce();
};

Zombie	*zombieHorde(int N, std::string name);

#endif
