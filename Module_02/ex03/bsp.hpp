/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:50:51 by tiago             #+#    #+#             */
/*   Updated: 2024/07/13 12:18:31 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Point.hpp"

bool BSP(Point A, Point B, Point C, Point Point);
void bspMessage(bool BSP, Point A, Point B, Point C, Point Point);