#include "../libft/inc/libft.h"

int	main(void)
{
	ft_printf("> File System Explorer~#\n\n");
	ft_printf("> [0]/[Nothing] | Exit\n");
	ft_printf("> [1] 	   	| Show Path\n");
	ft_printf("> [2] 	   	| List Objects\n\n");

	int		loop;
	int		read_input;
	int		input;
	char	buffer[256];
	pid_t	pid;

	loop = 0;
	while (!loop)
	{
		ft_printf("> Enter option: ");
		read_input = read(0, buffer, sizeof(buffer) - 1);
		if (read_input > 0)
		{
			buffer[read_input] = '\0';//* Null terminate the buffer.
			input = ft_atoi(buffer);//* Convert the input character to an int.
			if (input == 0)
			{
				ft_printf("> Exiting...\n");
				return (0);
			}
			pid = fork();
			if (pid == 0)//* if child, do hard work
			{
				if (input == 1)
				{
					if (getcwd(buffer, sizeof(buffer)) != NULL)
						ft_printf("> Path:\n> %s\n", buffer);
					else
						ft_printf("> Error retreiving path.");
				}
				else if (input == 2)
				{
					ft_printf("> Objects:\n> ");
					system("ls");
				}
				exit(0);
			}
			else if (pid > 0)//* if parent, wait for child bruh
			{
				waitpid(pid, NULL, 0);
			}
			else
			{
				ft_printf("> Fork failed!\n");//* if fork failed, print fail
			}
		}
	}
	return (0);
}
