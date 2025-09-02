/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:04 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:41:07 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie s("stack");
	s.announce();

	Zombie *h = newZombie("heap");
	h->announce();
	delete h;

	randomChump("stack(auto)");
	return (0);
}