/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:15:56 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 16:15:59 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string &value)
{
    firstName = value;
}

void Contact::setLastName(const std::string &value)
{
    lastName = value;
}

void Contact::setNickname(const std::string &value)
{
    nickname = value;
}

void Contact::setPhoneNumber(const std::string &value)
{
    phoneNumber = value;
}

void Contact::setDarkestSecret(const std::string &value)
{
    darkestSecret = value;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickName() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}
