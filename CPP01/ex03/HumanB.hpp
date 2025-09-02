/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:43:03 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:43:05 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	std::string name_;
	Weapon *weapon_;

  public:
	HumanB(const std::string &name);
	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif
