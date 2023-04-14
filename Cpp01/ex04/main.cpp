#include <fstream>
#include <iostream>

void	ft_replace(std::string &new_line, const std::string &s1,
		const std::string &s2)
{
	size_t s1_len = s1.length();
	size_t s2_len = s2.length();
	size_t pos = 0;
	while (1)
	{
		pos = new_line.find(s1, pos);
		if (pos == std::string::npos)
			break ;
		new_line.erase(pos, s1_len);
		new_line.insert(pos, s2);
		pos += s2_len;
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	std::ifstream read_file(av[1]);
	std::ofstream new_file(std::string(av[1]
				+ std::string(".replace")).c_str());
	std::string read_line;
	std::string new_line;
	if (!read_file.is_open())
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	while (std::getline(read_file, read_line))
		new_line += read_line + '\n';
	read_file.close();
	ft_replace(new_line, av[2], av[3]);
	new_file << new_line;
}
