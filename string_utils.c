int     ft_atoi(char *str)
{
	int i;
	int resultat;

	i = -1;
	resultat = 0;
	if (str[0] < '0' || str[0] > '9')
		return (0);
	while (str[++i] >= '0' && str[i] <= '9')
		resultat = resultat * 10 + str[i] - '0';
	return (resultat);
}

void ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
}

char    *ft_strcat(char *dest, char *src)
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
