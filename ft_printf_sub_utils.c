int ft_strlen(char *s)
{
	int length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}