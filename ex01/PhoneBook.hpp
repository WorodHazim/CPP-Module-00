/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:16:54 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 23:28:57 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int count;
    int nextIndex;

public:
    PhoneBook();

    void addContact(const Contact &c);

    int getCount() const;
    int getStartIndex() const;
    int realIndexFromOrder(int order) const;
    const Contact& getContact(int order) const;
};
#endif
