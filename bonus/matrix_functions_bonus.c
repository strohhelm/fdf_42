/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:52:16 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 20:30:38 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

t_matrix	scale_matrix(t_point scale)
{
	t_matrix	m;

	m.d.x = scale.x;
	m.d.y = 0;
	m.d.z = 0;
	m.e.x = 0;
	m.e.y = scale.y;
	m.e.z = 0;
	m.f.x = 0;
	m.f.y = 0;
	m.f.z = scale.z;
	return (m);
}

t_matrix	x_rot_matrix(double x_angle)
{
	t_matrix	m;
	double		rad;

	rad = x_angle * (M_PI / 180.0);
	m.d.x = 1;
	m.d.y = 0;
	m.d.z = 0;
	m.e.x = 0;
	m.e.y = cos(rad);
	m.e.z = -sin(rad);
	m.f.x = 0;
	m.f.y = sin(rad);
	m.f.z = cos(rad);
	return (m);
}

t_matrix	y_rot_matrix(double y_angle)
{
	t_matrix	m;
	double		rad;

	rad = y_angle * (M_PI / 180.0);
	m.d.x = cos(rad);
	m.d.y = 0;
	m.d.z = sin(rad);
	m.e.x = 0;
	m.e.y = 1;
	m.e.z = 0;
	m.f.x = -sin(rad);
	m.f.y = 0;
	m.f.z = cos(rad);
	return (m);
}

t_matrix	z_rot_matrix(double z_angle)
{
	t_matrix	m;
	double		rad;

	rad = z_angle * (M_PI / 180.0);
	m.d.x = cos(rad);
	m.d.y = -sin(rad);
	m.d.z = 0;
	m.e.x = sin(rad);
	m.e.y = cos(rad);
	m.e.z = 0;
	m.f.x = 0;
	m.f.y = 0;
	m.f.z = 1;
	return (m);
}
