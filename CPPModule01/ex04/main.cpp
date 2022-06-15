#include "sed.hpp"

static string sed(string text, string s1, string s2)
{
	size_t pos = 0;
	size_t len = s1.length();

	while((pos = text.find(s1)) != string::npos)
	{
		text.erase(pos, len);
		text.insert(pos, s2);
	}
	return (text);
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
	if (!file)
		return (-1);
	while (getline(file, line))
	{
		text += line;
		text += "\n";
	}
	text.pop_back();
	file.close();
	text = sed(text, (string)argv[2], (string)argv[3]);
	replacefile(argv[1], text);
	return (0);
}