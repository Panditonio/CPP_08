/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:37:47 by antoineherb       #+#    #+#             */
/*   Updated: 2023/09/28 21:47:31 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void ) {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << "/*---------Further tests----------*/" << std::endl;
    std::cout << std::endl;

    Span spp = Span(10000);
    std::vector<int>    v;
    for (int i = 1; i < 5000; i++)
        v.push_back(i);
    v.push_back(20000);

    spp.addX(v.begin(), v.end());
    std::cout << spp.shortestSpan() << std::endl;
    std::cout << spp.longestSpan() << std::endl;
    std::cout << std::endl;
    std::cout << spp << std::endl;
    std::cout << std::endl;
    
    return (0);
}