/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:43:24 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 21:43:26 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	std::string type_;

  public:
	Weapon(const std::string &type);
	const std::string &getType() const;
	void setType(const std::string &t);
};

#endif
