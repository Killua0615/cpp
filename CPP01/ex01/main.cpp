/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:43 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/03 21:06:34 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//This code allocates a horde of Zombies on the heap
//assigns the same name to each one
//makes them announce themselves
//and then deletes the entire array to free memory
int	main(void)
{
	int		n;
	Zombie	*h;
	int		i;

	n = 3;
	h = zombieHorde(n, "horde");
	if (!h)
		return (0);
	i = 0;
	while (i < n)
	{
		h[i].announce();
		i++;
	}
  // Very important: arrays allocated with new[] must be freed with delete[].
	delete[] h;
	return (0);
}
