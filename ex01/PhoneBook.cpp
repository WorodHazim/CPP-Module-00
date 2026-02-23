/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:16:43 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 16:16:44 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    count = 0;
    nextIndex = 0;
}

void PhoneBook::addContact(const Contact &c)
{
    contacts[nextIndex] = c;
    nextIndex = (nextIndex + 1) % 8;
    if (count < 8)
        count++;
}

int PhoneBook::getCount() const
{
    return count;
}

int PhoneBook::getStartIndex() const
{
    int start;

    if (count == 8)
        start = nextIndex;
    else
        start = 0;
    return start;
}

int PhoneBook::realIndexFromOrder(int order) const
{
    int start;
    int real;

    start = getStartIndex();
    real = (start + order) % 8;
    return real;
}

const Contact& PhoneBook::getContact(int order) const
{
    return contacts[realIndexFromOrder(order)];
}
