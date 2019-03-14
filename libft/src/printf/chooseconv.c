/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooseconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:34:09 by ygarrot           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/14 13:19:34 by ygarrot          ###   ########.fr       */
=======
/*   Updated: 2019/03/10 11:53:28 by ygarrot          ###   ########.fr       */
>>>>>>> 481ff8ddf501b92bad1b4a18c1ccd2425b20ff35
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*chooseconv(va_list va, t_arg *list)
{
	if (list->conv == 14)
		return ("%");
	if (list->conv == 6)
		return (convuimx(va_arg(va, unsigned long)));
	if (list->conv == 10 && list->specifier != 3)
		return (convc(va_arg(va, int)));
	if (list->conv == 11 || list->conv == 10)
		return (convwchar(va_arg(va, wchar_t)));
	if (list->conv == 12 && list->specifier != 3)
		return ((char*)va_arg(va, void*));
	if (list->conv == 13 || list->conv == 12)
<<<<<<< HEAD
		return (convwstr((wchar_t*)va_arg(va, void*)));
=======
		return (convwstr(va_arg(va, wchar_t*)));
>>>>>>> 481ff8ddf501b92bad1b4a18c1ccd2425b20ff35
	if (list->conv > 6 && list->conv < 10)
		return (convsigned(va, list));
	return (convunsigned(va, list));
}

char	*convsigned(va_list va, t_arg *list)
{
	if (list->specifier == 3 || list->conv == 8)
		return (convim(va_arg(va, long)));
	if (list->specifier == 0)
		return (convim(va_arg(va, int)));
	if (list->specifier == 1)
		return (convim(va_arg(va, int)));
	if (list->specifier == 2)
<<<<<<< HEAD
		return (convim(va_arg(va, long)));
=======
		return (convim(va_arg(va, long long)));
>>>>>>> 481ff8ddf501b92bad1b4a18c1ccd2425b20ff35
	if (list->specifier == 4)
		return (convim(va_arg(va, size_t)));
	if (list->specifier == 5)
		return (convim(va_arg(va, intmax_t)));
	return (convim(va_arg(va, int)));
}

char	*convunsigned(va_list va, t_arg *list)
{
	int			x;
	char		*(*um[3])(uintmax_t);

	um[0] = convuim;
	um[1] = convuimo;
	um[2] = convuimx;
	x = (list->conv == 5) ? 2 : 0;
	if (list->specifier == 3 || (list->conv > 2 && list->conv < 5))
	{
		return (um[list->conv > 2 ? list->conv - 3 : list->conv](
		va_arg(va, unsigned long)));
	}
	if (list->specifier == 0)
		return (um[x ? x : list->conv](va_arg(va, int)));
	if (list->specifier == 1)
		return (um[x ? x : list->conv](va_arg(va, int)));
	if (list->specifier == 2)
		return (um[x ? x : list->conv](va_arg(va, unsigned long long)));
	if (list->specifier == 4)
		return (um[x ? x : list->conv](va_arg(va, uintmax_t)));
	if (list->specifier == 5)
		return (um[x ? x : list->conv](va_arg(va, size_t)));
	return (um[x ? x : list->conv](va_arg(va, uintmax_t)));
}
