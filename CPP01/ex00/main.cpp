/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:06:24 by jealefev          #+#    #+#             */
/*   Updated: 2025/05/19 14:06:25 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include "Zombie.hpp"

int main(void)
{
    Zombie first("first");
    first.announce();
    Zombie* second = first.newZombie("second");
    second->announce();
    second->randomChump("third");
    delete second;
    return 0;
}
