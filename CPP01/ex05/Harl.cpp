/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:43:50 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/02 22:00:21 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info() {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning() {
  std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string& level) {
  typedef void (Harl::*Fn)();
  struct Pair { const char* name; Fn fn; };
  static const Pair table[4] = {
    { "DEBUG", &Harl::debug },
    { "INFO", &Harl::info },
    { "WARNING", &Harl::warning },
    { "ERROR", &Harl::error }
  };
  int i = 0;
  while (i < 4) {
    if (level == table[i].name) {
      Fn f = table[i].fn;
      (this->*f)();
      return;
    }
    ++i;
  }
}
