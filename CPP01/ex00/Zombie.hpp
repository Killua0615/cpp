/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:37 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/03 10:18:13 by nateshim         ###   ########.fr       */
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
  // Constructs
	Zombie(std::string name);
  // Disstructs
	~Zombie();
  // Prints "<name>: BraiiiiiiinnnzzzZ..." to stdout.
	void announce(void);
};

//allocates a Zombie on the heap and returns its pointer
Zombie	*newZombie(std::string name);
//creates a Zombie with automatic storage (stack) and destroyed on return
void	randomChump(std::string name);

#endif
