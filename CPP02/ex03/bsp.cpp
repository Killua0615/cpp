/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:29:20 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/09 21:38:09 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float sign(Point const& a, Point const& b, Point const& p){
  float ax=a.getX().toFloat(), ay=a.getY().toFloat();
  float bx=b.getX().toFloat(), by=b.getY().toFloat();
  float px=p.getX().toFloat(), py=p.getY().toFloat();
  return (bx-ax)*(py-ay) - (by-ay)*(px-ax);
}

bool bsp(Point const a, Point const b, Point const c, Point const p){
  float s1 = sign(a,b,p);
  float s2 = sign(b,c,p);
  float s3 = sign(c,a,p);
  if (s1 == 0.f || s2 == 0.f || s3 == 0.f) return false;
  bool pos = (s1 > 0.f) && (s2 > 0.f) && (s3 > 0.f);
  bool neg = (s1 < 0.f) && (s2 < 0.f) && (s3 < 0.f);
  return pos || neg;
}
