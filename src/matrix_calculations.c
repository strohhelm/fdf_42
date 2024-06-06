/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:49:46 by pstrohal          #+#    #+#             */
/*   Updated: 2024/06/06 16:58:21 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//		m:					p:		new:
//		d |x	y	z|		|x|			|x|
//		e |x	y	z|		|y|			|y|
//							|z|			|z|
//
t_point	point_matrix(t_point p, t_matrix m)
{
	t_point		new;

	new.x = m.d.x * p.x + m.d.y * p.y + m.d.z * p.z;
	new.y = m.e.x * p.x + m.e.y * p.y + m.e.z * p.z;
	new.z = m.f.x * p.x + m.f.y * p.y + m.f.z * p.z;
	return (new);
}

//		m1 :			m2:					m:
//		d |x	y	z|		d |x	y	z|		d |x	y	z|
//		e |x	y	z|		e |x	y	z|		e |x	y	z|
//		f |x	y	z|		f |x	y	z|		f |x	y	z|
//
t_matrix	matrix_multiply(t_matrix m1, t_matrix m2)
{
	t_matrix	m;

	m.d.x = m1.d.x * m2.d.x + m1.d.y * m2.e.x + m1.d.z * m2.f.x;
	m.d.y = m1.d.x * m2.d.y + m1.d.y * m2.e.y + m1.d.z * m2.f.y;
	m.d.z = m1.d.x * m2.d.z + m1.d.y * m2.e.z + m1.d.z * m2.f.z;
	m.e.x = m1.e.x * m2.d.x + m1.e.y * m2.e.x + m1.e.z * m2.f.x;
	m.e.y = m1.e.x * m2.d.y + m1.e.y * m2.e.y + m1.e.z * m2.f.y;
	m.e.z = m1.e.x * m2.d.z + m1.e.y * m2.e.z + m1.e.z * m2.f.z;
	m.f.x = m1.f.x * m2.d.x + m1.f.y * m2.e.x + m1.f.z * m2.f.x;
	m.f.y = m1.f.x * m2.d.y + m1.f.y * m2.e.y + m1.f.z * m2.f.y;
	m.f.z = m1.f.x * m2.d.z + m1.f.y * m2.e.z + m1.f.z * m2.f.z;
	return (m);
}

t_matrix	get_full_matrix(t_point angle, t_point scale)
{
	t_matrix	m;

	m = matrix_multiply(scale_matrix(scale), x_rot_matrix(angle.x));
	m = matrix_multiply(m, z_rot_matrix(angle.z));
	return (m);
}
