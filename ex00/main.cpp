/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:49:16 by antoineherb       #+#    #+#             */
/*   Updated: 2023/07/19 00:58:50 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <list>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Syntax : ./easyfind <int[0-9]>" << std::endl;
        return (1);
    }
    else {
        int         myInts[] = { 0, 1, 3, 5, 7, 9 };
        std::string tmp;
        
        std::vector<int>    iArray(myInts, myInts + sizeof(myInts) / sizeof(int));
        std::list<int>     iList(myInts, myInts + sizeof(myInts) / sizeof(int));
        tmp = argv[1];
        if (tmp.size() != 1 || !isdigit(tmp[0])) {
            std::cout << "Syntax : ./easyfind <int[0-9]>" << std::endl;
            return (1);
        }
        else {
            if (easyfind(iArray, std::atoi(argv[1])) && easyfind(iList, std::atoi(argv[1])))
                std::cout << argv[1] << " is in the containers" << std::endl;
            else
                std::cout << argv[1] << " is not in the containers" << std::endl;                
        }
    }
    return (0);
}