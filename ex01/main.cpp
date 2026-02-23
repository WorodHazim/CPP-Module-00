/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:16:25 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 21:16:42 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "utils.hpp"

int main()
{
    PhoneBook pb;
    std::string input;

    while (true)
    {
        std::cout << "Enter a command > ";
        if (!std::getline(std::cin, input))
            break;
        if (input == "ADD")
            doADD(pb);
        else if (input == "SEARCH")
            doSEARCH(pb);
        else if (input == "EXIT")
            return 0;
    }
    return 0;
}
