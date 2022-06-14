#include "sed.hpp"

static string sed(string text, string s1, string s2)
{
	int		i = 0;
	string newtext;
	size_t pos = 0;
	size_t len = s1.length();

	while((pos = text.find(s1)) != string::npos)
	{
		newtext = text.substr(i, pos);
		newtext += s2;
		i = pos;
		text.erase(pos, len);
	}
	newtext += text.substr(i, s1.length());
	return (newtext);
}

static void replacefile(string file, string text)
{
	ofstream newfile;
	
	newfile.open(file + ".replace");
	newfile << text;
	newfile.close();
}

int	main(int argc, char **argv)
{
	string text;
	string line;
	ifstream file;

	if (argc != 4)
		return (-1);
	file.open(argv[1]);
	while (getline(file, line))
	{
		text += line;
		text += "\n";
	}
	text.pop_back();
	file.close();
	text = sed(text, (string)argv[2], (string)argv[3]);
	replacefile(argv[1], text);
	std::cout << text;
	return (0);
}