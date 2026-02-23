/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:17:04 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 23:29:40 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

bool isOnlySpaces(const std::string &s)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] != ' ' && s[i] != '\t')
            return false;
    }
    return true;
}
bool readNonEmptyLine(const std::string &prompt, std::string &out)
{
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, out))
            return false;
        if (!out.empty() && !isOnlySpaces(out))
            return true;
    }
}
static void printField(const std::string &str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::right << std::setw(10) << str;
}
void doADD(PhoneBook &pb)
{
    Contact c;
    std::string tmp;

    std::cout << "Add a new contact\n";

    if (!readNonEmptyLine("First name: ", tmp)) return;
    c.setFirstName(tmp);

    if (!readNonEmptyLine("Last name: ", tmp)) return;
    c.setLastName(tmp);

    if (!readNonEmptyLine("Nickname: ", tmp)) return;
    c.setNickname(tmp);

    if (!readNonEmptyLine("Phone number: ", tmp)) return;
    c.setPhoneNumber(tmp);

    if (!readNonEmptyLine("Darkest secret: ", tmp)) return;
    c.setDarkestSecret(tmp);

    pb.addContact(c);
    std::cout << "Contact saved.\n";
}
void doSEARCH(PhoneBook &pb)
{
    std::string index;
    int intIndex;

    if (pb.getCount() == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }
    printField("index");      std::cout << '|';
    printField("first name"); std::cout << '|';
    printField("last name");  std::cout << '|';
    printField("nickname");   std::cout << '\n';
    for (int i = 0; i < pb.getCount(); i++)
    {
        const Contact& c = pb.getContact(i);

        std::cout << std::right << std::setw(10) << (i + 1) << '|';
        printField(c.getFirstName()); std::cout << '|';
        printField(c.getLastName());  std::cout << '|';
        printField(c.getNickName());  std::cout << '\n';
    }
    while (true)
    {
        std::cout << "Enter index: ";
        if (!std::getline(std::cin, index))
            return;
        std::stringstream ss(index);
        char extra;
        if (!(ss >> intIndex) || (ss >> extra))
        {
            std::cout << "Invalid index.\n";
            continue;
        }
        if (intIndex < 1 || intIndex > pb.getCount())
        {
            std::cout << "Index out of range.\n";
            continue;
        }
        break;
    }
    const Contact& con = pb.getContact(intIndex - 1);
    std::cout << "First name: " << con.getFirstName() << "\n";
    std::cout << "Last name: " << con.getLastName() << "\n";
    std::cout << "Nickname: " << con.getNickName() << "\n";
    std::cout << "Phone number: " << con.getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << con.getDarkestSecret() << "\n";
}

