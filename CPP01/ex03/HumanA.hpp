/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:42:52 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:42:54 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
	std::string name_;
	Weapon &weapon_;

  public:
	HumanA(const std::string &name, Weapon &weapon);
	void attack() const;
};

#endif
