/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:04 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/03 03:48:26 by nateshim         ###   ########.fr       */
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
