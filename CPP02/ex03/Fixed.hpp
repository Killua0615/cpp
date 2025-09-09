/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:29:37 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/09 21:38:18 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>


class Fixed {
private:
  int              _raw;
  static const int _fracBits;
public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  Fixed(int n);
  Fixed(float f);

  int   getRawBits(void) const;
  void  setRawBits(int const raw);
  float toFloat(void) const;
  int   toInt(void) const;
};

#endif
