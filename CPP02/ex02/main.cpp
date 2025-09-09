/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:29:07 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/09 21:43:33 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b( Fixed(5.05f) * Fixed(2) );

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;
  return 0;
}

//Made Fixed behave like a number; tested (+, -, *)
//a defaults to 0.0
//b is the value calculated using fixed-point arithmetic for 5.05 × 2 (≈ 10.1015625)

//++a increments the internal integer _raw by 1 (e.g. 00000000 → 00000001).
//The raw value of _raw is calculated as value = _raw / (1 << 8) (= _raw / 256).
//When _raw = 1, the actual number is 1 / 256 = 0.00390625

//a++ Postfix: Display before increase (= 1), display after a._raw=2

//Remaining at 2 duo to a++

//max(a, b) a(≈0.0078) and b(≈10.10) comparison → returns b
