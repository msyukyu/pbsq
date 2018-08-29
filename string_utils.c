/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:58:30 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/29 17:58:32 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_atoi(char *str)
{
	int i;
	int resultat;
	int	max;

	i = -1;
	resultat = 0;
	max = ft_strlen_modif(str);
	if (str[0] < '0' || str[0] > '9')
		return (0);
	while (str[++i] >= '0' && str[i] <= '9' && i < max - 3)
		resultat = resultat * 10 + str[i] - '0';
	if ((str[i] < '0' || str[i] > '9') && i < max - 3)
		resultat = 0;
	return (resultat);
}

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (dest[i] != '\0')
		i++;
	while (src[i2] != '\0')
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen_modif(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
