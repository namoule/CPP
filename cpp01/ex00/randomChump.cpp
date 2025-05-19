/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:06:18 by jealefev          #+#    #+#             */
/*   Updated: 2025/05/19 14:06:19 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
    Zombie* zmb = new Zombie(name);
    std::cout << zmb->_name << ": BraiiiiiiinnnzzzZ...(created with random chump by " << this->_name << ")." << std::endl;
    delete zmb;
}