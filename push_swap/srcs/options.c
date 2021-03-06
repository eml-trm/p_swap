/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 14:11:13 by etermeau          #+#    #+#             */
/*   Updated: 2015/09/16 14:11:16 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_option(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'v')
		{
			options()->active = 1;
			options()->v = 1;
		}
		else if (str[i] == 'n')
		{
			options()->active = 1;
			options()->n = 1;
		}
		else
			error_code(2);
		i++;
	}
}

t_opt	*options(void)
{
	static t_opt	*opt = NULL;

	if (!opt)
	{
		if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
			error_code(1);
		opt->v = 0;
		opt->n = 0;
		opt->moves = 0;
		opt->active = 0;
	}
	return (opt);
}

void	apply_opt_n(void)
{
	if (options()->n)
	{
		ft_putstr("\nResolve in ");
		ft_putnbr(options()->moves);
		ft_putstr(" moves\n");
	}
}

void	apply_opt_v(t_lst *lsta, t_lst *lstb)
{
	if (options()->v)
		print_lst(lsta, lstb);
}
