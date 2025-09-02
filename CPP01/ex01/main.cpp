/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:43 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:41:45 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
	delete[] h;
	return (0);
}
