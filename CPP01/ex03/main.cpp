/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:43:07 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/04 03:06:25 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void)
{
	{//reference; not possivable null
		Weapon club("crude spiked club");        // creates a weapon named club, set a type_
		HumanA bob("Bob", club);                 //creates bob with a reference to club
		bob.attack();                            //shows "Bob attacks with their crude~~"
		club.setType("some other type of club"); //update the club
		bob.attack();
	}
	{//pointer; need to care null
		Weapon club("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
