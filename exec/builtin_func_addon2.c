#include "../include/minishell.h"

void	handle_builtin_error(char *path, char *func_name)
{
	g_glob.g_status = 1;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(func_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
}

int	wrong_export_arg(char *arg, char *func_name)
{
	int		i;

	if (!arg || !arg[0] || arg[0] == '_')
		return (EXIT_FAILURE);
	i = -1;
	while (arg[++i])
	{
		if (!ft_isprint(arg[i]))
			return (EXIT_FAILURE);
		if (!ft_isalpha(arg[0]))
		{
			handle_builtin_error(arg, func_name);
			return (g_glob.g_status);
		}
	}
	return (EXIT_SUCCESS);
}

int	wrong_unset_arg(char *arg, char *func_name)
{
	int		i;

	if (!arg || !arg[0] || arg[0] == '_')
		return (EXIT_FAILURE);
	i = -1;
	while (arg[++i])
	{
		if (!ft_isprint(arg[i]))
			return (EXIT_FAILURE);
		if (!ft_isalpha(arg[0]) && \
			(ft_isalnum(arg[0]) || (arg[i] == '=' || arg[0] == '=')))
		{
			handle_builtin_error(arg, func_name);
			return (EXIT_FAILURE);
		}
		else if (arg[i] == '=')
		{
			handle_builtin_error(arg, func_name);
			return (g_glob.g_status);
		}
	}
	return (EXIT_SUCCESS);
}
