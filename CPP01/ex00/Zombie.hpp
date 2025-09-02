/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:37 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:41:40 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif