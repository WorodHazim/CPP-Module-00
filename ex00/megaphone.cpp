/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:05:52 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 23:27:24 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for(int i = 1; i < argc ; i++ )
    {
        for(int j = 0; argv[i][j]; j++)
        {
            std::cout << (char)std::toupper((unsigned char)argv[i][j]);
        }
        if(i != argc-1)
           std::cout << ' ';
    }
     std::cout << '\n';
     return 0;
}