/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:07:13 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/04 21:43:48 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int	levelIndex(const std::string &s)
{
	static const char	*names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					i;

	i = 0;
	while (i < 4)
	{
		if (s == names[i])
			return (i);
		++i;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	Harl	h;
	int		idx;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	//文字列 "DEBUG" "INFO" "WARNING" "ERROR" のどれかを 0〜3 に変換。該当しなければ -1 を返す。
	idx = levelIndex(argv[1]);
	switch (idx)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		h.debug();
		std::cout << std::endl;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		h.info();
		std::cout << std::endl;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		h.warning();
		std::cout << std::endl;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		h.error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
