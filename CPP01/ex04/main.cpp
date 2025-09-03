/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:43:33 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/04 05:28:12 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static void	die(const std::string &m)
{
	std::cerr << m << std::endl;
	std::exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		die("usage: ./sed <filename> <s1> <s2>");
	const std::string inname = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	if (s1.empty())
		die("error: s1 must not be empty");
  // Open the input file in read+binary mode (C++98: use .c_str() to get const char*)
	std::ifstream in(inname.c_str(), std::ios::in | std::ios::binary);
	if (!in)
		die("error: cannot open input file");
	std::ostringstream buf;
  //Copy all bytes from in.rdbuf() into 'buf'
	buf << in.rdbuf();
  //Get the whole file as a string from 'buf'.
	std::string content = buf.str();
  // Open the output file <name>.replace in write+binary mode 
	std::ofstream out((inname + ".replace").c_str(),
		std::ios::out | std::ios::binary);
	if (!out)
		die("error: cannot open output file");
	std::string::size_type pos = 0;
	std::string::size_type prev = 0;
	while (true)
	{
    //same strcpy()
    // Search for the next occurrence of s1 starting at 'prev'
		pos = content.find(s1, prev);
		if (pos == std::string::npos)
			break ;
    out << content.substr(prev, pos - prev); // write text before the match
    out << s2;                               // write replacement
    prev = pos + s1.size();                  // continue after the match
	}
  //Write the rest
	out << content.substr(prev);
	return (0);
}

//cat > t1.txt <<'EOF'
//hello foo world foo!
//EOF
//./sed t1.txt foo bar
//cat t1.txt.replace
// → hello bar world bar!