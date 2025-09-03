/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:42:05 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/03 21:05:26 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*h;
	int		i;

	if (N <= 0)
		return (NULL);
	h = new Zombie[N]; //Zombie::Zombie() is called N times here
	i = 0;
	while (i < N)
	{
		h[i].setName(name);
		i++;
	}
	return (h);
}
