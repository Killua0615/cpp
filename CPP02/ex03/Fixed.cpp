/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:29:28 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/09 21:58:38 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0) {}
Fixed::Fixed(const Fixed& other) : _raw(other._raw) {}
Fixed& Fixed::operator=(const Fixed& other){ if(this!=&other) _raw=other._raw; return *this; }
Fixed::~Fixed() {}

Fixed::Fixed(int n){ _raw = n << _fracBits; }
Fixed::Fixed(float f) {
    float scaled = f * static_cast<float>(1 << _fracBits);
    if (scaled >= 0)
        _raw = static_cast<int>(scaled + 0.5f);
    else
        _raw = static_cast<int>(scaled - 0.5f);
}

int   Fixed::getRawBits(void) const { return _raw; }
void  Fixed::setRawBits(int const raw){ _raw = raw; }
float Fixed::toFloat(void) const { return static_cast<float>(_raw) / static_cast<float>(1 << _fracBits); }
int   Fixed::toInt(void) const { return _raw >> _fracBits; }
