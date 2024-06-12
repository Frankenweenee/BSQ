#include "bsq.h"

int	open_map(char *argv)
{
	int fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		error_control("file no open\n", NULL, fd);
	}
	return fd;
}

int	size_map(char *argv)
{
	int	size;
	int	fd;
	char	buffer;
	fd = open_map(argv);
	size = 0;
	while (read(fd, &buffer, 1))
	{
		size++;
	}
	close(fd);
	printf("tamaño del archivo: %d\n", size); // pruebas, hay que borrar
	return (size);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		size_map(argv[1]);
	}
	return (0);
}


int	row_number(char *argv)
{
	int		i;
	int		fd;
	char	*buffer;
	int		num_lin;
	fd = open_map(argv);
	i = 0;
	num_lin = 0;
	buffer = malloc(80 * sizeof(char));
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[i] < '0' || buffer[i] > '9')
			break;
		num_lin = num_lin * 10 + (buffer[i] - '0');
		i++;
	}
	free (buffer);
	close(fd);
	printf("numero de lineas: %d" , num_lin);
	return (num_lin);
}
/*
int	colum_number(char *argv)
{
	char	*buf;
	int		i;
	int		fd;

	fd = open_map(argv);
	i = 0;
	buf = malloc(ft_size_file(argv) * sizeof(char));
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break;
		i++;
	}
	free (buf);
	close(fd);
	return (i + 1);
}

char	create_map(char *argv)
{
	char	**buf;
	int		i;
	int		fd;
	int		cols;
	int		ret;
	int		rows;

	i = 0;
	ret = 0;
	fd = open_map(argv);
	cols = colum_number(argv);
	rows = row_number(argv);
	if ((buffer = malloc(rows * sizeof(char*))) == NULL)
		return NULL ;
	while (i < cols)
		if ((buffer[i] = malloc(cols * sizeof(char))) == NULL)
			return NULL;
		i++;
	i = 0;
	while (i < rows)
		if ((ret = read(fd, buffer[i], cols)) == - 1)
			return NULL;
		buffer[i++][cols - 1] = '\0';
	close (fd);
	return (buf);
}*/