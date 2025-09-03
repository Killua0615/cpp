/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:41:04 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/03 10:32:18 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie s("stack");
	s.announce();

  //Heap (caller is responsible for deleting)
	Zombie *h = newZombie("heap");
	h->announce();
	delete h;

  //Temporary (stack) inside the function, destroyed on return
	randomChump("stack(auto)");
	return (0);
}

//1)s.announce(); — announces the stack zombie.
//2)h->announce(); — announces the heap zombie.
//3)delete h; — calls the heap zombie’s destructor → prints heap destroyed.
//4)Call randomChump("stack(auto)"):
//5)inside: z.announce(); — announces the temporary stack(auto) zombie.
//6)on function return: z goes out of scope → prints stack(auto) destroyed.
//7)End of main() — s goes out of scope → prints stack destroyed (last).