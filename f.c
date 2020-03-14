/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:36:29 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/13 16:59:35 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/src/ft_printf.h"
#include "libft/libft.h"

int		check_files(char **av)
{
	int	count;
	int	i;
	int	len;
	int	j;

	count = 0;
	i = 1;
	while (av[i])
	{
		len = ft_strlen(av[i]) - 1;
		if (av[i][len] && av[i][len] == 'r' &&
			av[i][len - 1] && av[i][len - 1] == 'o' &&
			av[i][len - 2] && av[i][len - 2] == 'c' &&
			av[i][len - 3] && av[i][len - 3] == '.')
			count++;
		i++;
	}
	return (count);
}

int		is_cor_file(char *av)
{
	int	len;

	len = ft_strlen(av) - 1;
	if (av[len] && av[len] == 'r' &&
		av[len - 1] && av[len - 1] == 'o' &&
		av[len - 2] && av[len - 2] == 'c' &&
		av[len - 3] && av[len - 3] == '.')
		return (1);
	return (0);
}

int		is_num_neg(char *s)
{
	int i;

	i = -1;
	if (s[0] == '-')
		i++;
	while (s[++i])
		if (ft_isdigit(s[i]) == 0)
			return (0);
	return (1);
}

int		is_num(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) == 0)
			return (0);
	return (1);
}

int		get_n_args(char **av, char ***args)
{
	int n;
	int i;

	i = 0;
	while (av[++i])
	{
		if (!ft_strcmp(av[i], "-n"))
		{
			i++;
			if (is_num(av[i]) && (n = ft_atoi(av[i])) &&
				n > 0 && n <= check_files(av))
			{
				if ((*args)[n - 1] || !is_cor_file(av[++i]))
					return (-1);
				(*args)[n - 1] = ft_strdup(av[i]);
			}
			else
				return (-2);
		}
	}
	return (1);
}

int		get_dump(char **av, int *i, int *dump, int *dump_found)
{
	if ((*dump_found) == 1 || !av[(*i) + 1] || !is_num_neg(av[(*i) + 1]))
		return (-3);
	(*dump) = (av[(*i) + 1]) ? ft_atoi(av[(*i) + 1]) : 0;
	(*dump_found) = 1;
	(*i) += 2;
	return ((*dump));
}

int		get_other_args(char **av, char ***args, int *dump, int ac)
{
	int i;
	int j;
	int dump_found;

	i = 0;
	dump_found = 0;
	while (av[++i] && i < ac)
	{
		i += (av[i] && !ft_strcmp(av[i], "-n")) ? 3 : 0;
		if (av[i] && !ft_strcmp(av[i], "-dump"))
			if (((*dump) = get_dump(av, &i, dump, &dump_found)) < 0)
				return (-3);
		i += (av[i] && !ft_strcmp(av[i], "-n")) ? 3 : 0;
		if (av[i] && !is_cor_file(av[i]))
			return (-4);
		if (av[i] && (j = -1))
			while (++j < 4)
				if (!(*args)[j])
				{
					(*args)[j] = ft_strdup(av[i]);
					break ;
				}
	}
	return (1);
}

int		check_dups(char **args)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = i;
		if(args[i])
			while (++j < 4)
				if (args[j] && !ft_strcmp(args[i], args[j]))
					return (1);
	}
	return (0);
}

void	free2d(char ***s)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_strdel(&(*s)[i]);
		i++;
	}
	free(*s);
}

int		return_err(char ***args)
{
	free2d(args);
	return (0);
}

int		get_args(int ac, char **av, char ***args, int *dump)
{
	int		err;
	int		i;

	if (ac > 1 && check_files(av) <= 4 && check_files(av) > 0)
	{
		if (!((*args) = ft_memalloc(sizeof(char*) * 4)))
			return (0);
		if ((err = get_n_args(av, args)) < 0)
		{
			ft_printf("ERROR %d\n", err);
			return (return_err(args));
		}
		if ((err = get_other_args(av, args, dump, ac)) < 0 || check_dups(*args))
		{
			ft_printf("ERROR %d\n", err);
			return (return_err(args));
		}
	}
	else
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	char	**args;
	int		err;
	int		i;
	int		dump;

	if (get_args(ac, av, &args, &dump))
	{
		i = -1;
		while (++i < 4)
			if (args[i])
				ft_printf("%d %s\n", i, args[i]);
		ft_printf("dump = %d", dump);
		free2d(&args);
	}
	else
	{
		ft_printf("ERROR\n");
	}
	return (0);
}
