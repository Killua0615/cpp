/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:30:00 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/09 21:36:38 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
private:
  Fixed const _x;
  Fixed const _y;
public:
  Point();
  Point(float x, float y);
  Point(Point const& other);
  Point& operator=(Point const& other);
  ~Point();
  Fixed const& getX() const;
  Fixed const& getY() const;
};

#endif
