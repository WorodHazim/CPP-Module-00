/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:17:12 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 21:00:45 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "PhoneBook.hpp"

bool isOnlySpaces(const std::string &s);
bool readNonEmptyLine(const std::string &prompt, std::string &out);
void doADD(PhoneBook &pb);
void doSEARCH(PhoneBook &pb);

#endif
