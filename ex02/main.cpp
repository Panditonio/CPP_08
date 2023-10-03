/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:12:30 by antoineherb       #+#    #+#             */
/*   Updated: 2023/07/20 05:50:11 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main( void ) {
    
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(455);
    mstack.push(12);
    mstack.push(235);
    mstack.push(77);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << "/*---------Further tests----------*/" << std::endl;
    std::cout << std::endl;

    std::cout << "/ ***** List ***** /" << std::endl;

    std::list< int > lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();
    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(455);
    lst.push_back(12);
    lst.push_back(235);
    lst.push_back(77);
    lst.push_back(0);

    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    ++it;
    --it;
    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << std::endl;
        ++lst_it;
    }
    std::list<int> l(lst);
    std::cout << std::endl;

    std::cout << "/ ***** Vector ***** /" << std::endl;

    std::vector<int> vstack;

    vstack.push_back(5);
    vstack.push_back(17);

    std::cout << vstack.back() << std::endl;

    vstack.pop_back();

    std::cout << vstack.size() << std::endl;

    vstack.push_back(3);
    vstack.push_back(5);
    vstack.push_back(737);
    vstack.push_back(455);
    vstack.push_back(12);
    vstack.push_back(235);
    vstack.push_back(77);
    vstack.push_back(0);

    std::vector<int>::iterator vit = vstack.begin();
    std::vector<int>::iterator vite = vstack.end();

    ++vit;
    --vit;

    while (vit != vite)
    {
        std::cout << *vit << std::endl;
        ++vit;
    }
    std::vector<int> v(vstack);

    return (0);
}