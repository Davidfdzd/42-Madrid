/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:45:07 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 15:52:19 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

static std::string replaceAll(const std::string&input, const std::string& s1, const std::string& s2)
{
    std::string out;
    std::size_t pos = 0;
    std::size_t found;

    while ((found = input.find(s1, pos)) != std::string::npos)
    {
        out.append(input, pos, found - pos);
        out.append(s2);
        pos = found + s1.length();
    }
    out.append(input, pos, std::string::npos);
    return out;
}

int main(int ac, char **av)
{
    if (ac != 4) 
    {
        std::cerr<<"Usage: ./sed_is_for_losers <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 is empty\n";
        return 1;
    }
    std::ifstream in (filename.c_str());
    if (!in.is_open())
    {
        std::cerr<<"Error: cannot open "<<filename<<"\n";
        return 1;
    }
    std::ostringstream oss;
    oss << in.rdbuf();
    std::string content = oss.str();
    in.close();

    std::string replaced = replaceAll(content, s1, s2);

    std::ofstream out((filename + ".replace").c_str());
    if (!out.is_open())
    {
        std::cerr << "Error: cannot create "<<filename<<".replace\n";
        return 1;
    }
    out << replaced;
    return 0;
}